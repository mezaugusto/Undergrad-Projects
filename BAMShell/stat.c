#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
int main(int argc, char const *argv[])
{
	if(argc!=2)	perror("stat");
	int file;
	struct stat st;
	if (stat(argv[1], &st) == -1)	perror("stat");
   	switch (st.st_mode & S_IFMT) {
    case S_IFBLK:  printf("b"); break;
    case S_IFCHR:  printf("c"); break;
    case S_IFDIR:  printf("d"); break;
    case S_IFIFO:  printf("p"); break;
    case S_IFLNK:  printf("l"); break;
    case S_IFREG:  printf("-"); break;
    case S_IFSOCK: printf("s");	break;
    default:       printf("u");	break;
    }
    printf("I-node number:            %ld\n", (long) st.st_ino);

   printf("Mode:                     %lo (octal)\n",
            (unsigned long) st.st_mode);

   printf("Link count:               %ld\n", (long) st.st_nlink);
    printf("Ownership:                UID=%ld   GID=%ld\n",
            (long) st.st_uid, (long) st.st_gid);

   printf("Preferred I/O block size: %ld bytes\n",
            (long) st.st_blksize);
    printf("File size:                %lld bytes\n",
            (long long) st.st_size);
    printf("Blocks allocated:         %lld\n",
            (long long) st.st_blocks);

   printf("Last status change:       %s", ctime(&st.st_ctime));
    printf("Last file access:         %s", ctime(&st.st_atime));
    printf("Last file modification:   %s", ctime(&st.st_mtime));


    printf("\n");
	return 0;
}