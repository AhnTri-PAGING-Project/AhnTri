#include "initrd.h"

//------------------------------
#define FILE_NAME_LEN 100
#define OWNER_NUMERIC_ID 8
#define GROUP_NUMERIC_ID 8
#define FILESIZE_LEN 12
#define SECTOR_SIZE 512
#define OWNER_USER_NAME_SIZE 32
#define OWNER_GROUP_NAME_SIZE 32
//-------------------------------

initrd_header_t *initrd_header;         //Thanks for the issue fix, u/DeanoBurrito!
initrd_file_header_t *file_headers[9];
fs_node_t initrd_root;
fs_node_t initrd_dev;
fs_node_t root_nodes[9];
int nroot_nodes;

struct dirent dirent;

enum tar_file_types{
  norfilei = 0,
  norfileii = '0',
  hardlink = '1',
  symlink = '2',
  chardev = '3',
  blockdev = '4',
  dir = '5',
  namedpipefifo = '6',
};

typedef struct tarheader{
        uint32_t filename[FILE_NAME_LEN];
        uint32_t filmode;
        uint32_t owneruid[OWNER_NUMERIC_ID];
        uint32_t groupuid[GROUP_NUMERIC_ID];
        uint32_t fsize[FILESIZE_LEN];
        uint32_t modt[12];
        uint32_t checksum[8];
        uint8_t type;
        uint8_t linkedfile[100];
        uint8_t sign[6];        // Which is gonna be ustar\0
        uint8_t ver[2];         // Gotta be 00
        uint8_t owneruname[OWNER_USER_NAME_SIZE];
        uint8_t ownergname[OWNER_GROUP_NAME_SIZE];
        uint32_t devmajornum[8];
        uint32_t devminornum[8];
        uint32_t filenameprefix[155];
} tar_header_t;

int oct2bin(unsigned char *str, int size) {
    int n = 0;
    unsigned char *c = str;
    while (size-- > 0) {
        n *= 8;
        n += *c - '0';
        c++;
    }
    return n;
}
/*

extern char _binary_ahntri_initrd_kerneldisk_start;
extern char _binary_ahntri_initrd_kerneldisk_size;
extern char _binary_ahntri_initrd_kerneldisk_end;

void initinitrd(){
  uint8_t initrd_start = (uint8_t)&_binary_ahntri_initrd_kerneldisk_start;
  uint8_t initrd_size = (uint8_t)&_binary_ahntri_initrd_kerneldisk_size;
  uint8_t initrd_end = (uint8_t)&_binary_ahntri_initrd_kerneldisk_end;
}
*/
/*
// Going to use later
// 미래에 사용예정
int tar_lookup(unsigned char *archive, char *filename, char **out) {
    unsigned char *ptr = archive;
    while (!memcmp(ptr + 257, "ustar", 5)) {
        int filesize = oct2bin(ptr + 0x7c, 11);
        if (!memcmp(ptr, filename, strlen(filename) + 1)) {
            *out = ptr + 512;
            return filesize;
        }
        ptr += (((filesize + 511) / 512) + 1) * 512;
    }
    return 0;
}
*/

static struct dirent *initrd_readdir(fs_node_t node, uint32_t index)
{
   if(strcmp(node.name, "initrd")==0 && index == 0) {
     strcpy(dirent.name, "dev");
     dirent.name[3] = 0;
     dirent.ino = 0;
     return &dirent;
   }
   if (index-1 >= nroot_nodes) {
       return 0;
   }
   strcpy(dirent.name, root_nodes[index-1].name);
   dirent.name[strlen(root_nodes[index-1].name)] = 0;
   dirent.ino = root_nodes[index-1].inode;
   return &dirent;
}

static fs_node_t *initrd_finddir(fs_node_t node, char *name)
{
   if (strcmp(name, "initrd")==0){
       return &initrd_dev;
   }
   int i;
   for (i = 0; i < nroot_nodes; i++){
       if (!strcmp(name, root_nodes[i].name)){
           return &root_nodes[i];
       }
   }
   return 0;
}

fs_node_t fs_array[9];

fs_node_t init_initrd(uint32_t loc){
  int i;
  initrd_header = (initrd_header_t*)loc;
  strcpy(fs_array[0].name, "initrd");
  fs_array[0].mask    = 0;
  fs_array[0].uid     = 0;
  fs_array[0].gid     = 0;
  fs_array[0].inode   = 0;
  fs_array[0].length  = 0;
  fs_array[0].flags   = FS_DIRECTORY;
  fs_array[0].read    = 0;
  fs_array[0].open    = 0;
  fs_array[0].close   = 0;
  fs_array[0].readdir = &initrd_readdir;
  fs_array[0].finddir = &initrd_finddir;
  fs_array[0].ptr     = 0;
  fs_array[0].impl    = 0;
  strcpy(fs_array[1].name, "dev");
  fs_array[1].mask    = 0;
  fs_array[1].uid     = 0;
  fs_array[1].gid     = 0;
  fs_array[1].inode   = 0;
  fs_array[1].length  = 0;
  fs_array[1].flags   = FS_DIRECTORY;
  fs_array[1].read    = 0;
  fs_array[1].open    = 0;
  fs_array[1].close   = 0;
  fs_array[1].readdir = &initrd_readdir;
  fs_array[1].finddir = &initrd_finddir;
  fs_array[1].ptr     = 0;
  fs_array[1].impl    = 0;
  nroot_nodes         = 9;
  for(i=0; i<9; i++){
    file_headers[i]->offset += loc;
    strcpy(root_nodes[i].name, file_headers[i]->name);
    root_nodes[i].mask = 0;
    root_nodes[i].uid = 0;
    root_nodes[i].gid = 0;
    root_nodes[i].length = file_headers[i]->length;
    root_nodes[i].inode = i;
    root_nodes[i].read = NULL;
    root_nodes[i].write = 0;
    root_nodes[i].readdir = 0;
    root_nodes[i].finddir = 0;
    root_nodes[i].open = 0;
    root_nodes[i].close = 0;
    root_nodes[i].impl = 0;
  }
}
