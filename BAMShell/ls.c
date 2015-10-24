#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char const *argv[])
{
    if(argc!=2) perror("stat");
    int file;
    struct stat st;
    if (stat(argv[1], &st) == -1)   perror("stat");
    switch (st.st_mode & S_IFMT) {
    case S_IFBLK:  printf("b"); break;
    case S_IFCHR:  printf("c"); break;
    case S_IFDIR:  printf("d"); break;
    case S_IFIFO:  printf("p"); break;
    case S_IFLNK:  printf("l"); break;
    case S_IFREG:  printf("-"); break;
    case S_IFSOCK: printf("s"); break;
    default:       printf("u"); break;
    }

    static const char *rwx[] = {"---", "--x", "-w-", "-wx",
    "r--", "r-x", "rw-", "rwx"};
    static char bits[10];
    strcpy(&bits[0], rwx[(st.st_mode >> 6)& 7]);
    strcpy(&bits[3], rwx[(st.st_mode >> 3)& 7]);
    strcpy(&bits[6], rwx[(st.st_mode & 7)]);
    bits[11]='c';
    if (st.st_mode & S_ISUID)
        bits[2] = (st.st_mode & S_IXUSR) ? 's' : 'S';
    if (st.st_mode & S_ISGID)
        bits[5] = (st.st_mode & S_IXGRP) ? 's' : 'l';
    if (st.st_mode & S_ISVTX)
        bits[8] = (st.st_mode & S_IXUSR) ? 't' : 'T';
    bits[9] = '\0';

    printf("%s ", bits);

   // printf("%ld ", (long) st.st_ino);//I-node number 

   // printf("%lo ",(unsigned long) st.st_mode); //mode

    printf("%ld ", (long) st.st_nlink);//link count
    printf("%s ",getpwuid(st.st_uid)->pw_name);//ownership UID
    printf("%s ",getgrgid(st.st_gid)->gr_name);//ownership UID/GID

    //printf("%ld ",
    //(long) st.st_blksize);//preferredI/O BLOCK SIZE in bytes
    printf("%lld ",
        (long long) st.st_size);//file size in bytes
    //printf("%lld ",
     //(long long) st.st_blocks);//blocks allcated

    printf("%s ",ctime(&st.st_ctime));//last status change
    printf("%s ",ctime(&st.st_atime));//last file access
    printf("%s ",ctime(&st.st_mtime));//last file modification
    printf("%s\n", *argv[1] );
    return 0;
}