#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	if(argc!=2)	perror("stat");
	int file;
	char modo[7];
	struct stat st;
	struct group *grp;
	struct passwd *pwd;
	static const char *rwx[] = {"---", "--x", "-w-",
	"-wx","r--","r-x","rw-","rwx"};
    static char bits[11];
	if (stat(argv[1], &st) == -1)	perror("stat");
	printf("  File: \"%s\"\n", argv[1]);
	printf("  Size: %lld\tFile Type: ", (long long) st.st_size);
   	switch (st.st_mode & S_IFMT)
   	{
	    case S_IFBLK:  printf("Special Block File\n"); break;
	    case S_IFCHR:  printf("Character\n"); break;
	    case S_IFDIR:  printf("Directory\n"); break;
	    case S_IFIFO:  printf("Pipe or FIFO\n"); break;
	    case S_IFLNK:  printf("Symbolic Link"); break;
	    case S_IFREG:  printf("Regular File\n"); break;
	    case S_IFSOCK: printf("Socket\n");	break;
	    default:       printf("Unknown\n");	break;
    }
    snprintf(modo,sizeof(modo),"%lo", (unsigned long) st.st_mode);
    modo[0]=' ';
    modo[1]='(';
    printf("  Mode:%s/",modo);
    strcpy(&bits[1], rwx[(st.st_mode >> 6)& 7]);
    strcpy(&bits[4], rwx[(st.st_mode >> 3)& 7]);
    strcpy(&bits[7], rwx[(st.st_mode & 7)]);
    if (st.st_mode & S_ISUID)
        bits[3] = (st.st_mode & S_IXUSR) ? 's' : 'S';
    if (st.st_mode & S_ISGID)
        bits[6] = (st.st_mode & S_IXGRP) ? 's' : 'l';
    if (st.st_mode & S_ISVTX)
        bits[9] = (st.st_mode & S_IXUSR) ? 't' : 'T';
    bits[10] = '\0';
    switch (st.st_mode & S_IFMT)
    {
	    case S_IFBLK:  bits[0]='b'; break;
	    case S_IFCHR:  bits[0]='c'; break;
	    case S_IFDIR:  bits[0]='d'; break;
	    case S_IFIFO:  bits[0]='p'; break;
	    case S_IFLNK:  bits[0]='l'; break;
	    case S_IFREG:  bits[0]='-'; break;
	    case S_IFSOCK: bits[0]='s';	break;
	    default:       bits[0]='u';	break;
	}
	printf("%s)\t",bits);
	printf("Uid:(%4ld/%s)\t", (long) st.st_uid,
		getpwuid(st.st_uid)->pw_name);
	printf("Gid:(%4ld/%s)\n", (long) st.st_gid,
		getgrgid(st.st_gid)->gr_name);
    printf("Device: %d,%d\t", 
    	(int)(((unsigned int) (st.st_dev) >> 8) & 0xff),
    	(int)((st.st_dev) & 0xff));
    printf("Inode: %ld\t", (long) st.st_ino);
	printf("Links: %ld\n", (long) st.st_nlink);
    printf("Access: %s", ctime(&st.st_atime));
    printf("Modify: %s", ctime(&st.st_mtime));
	printf("Change: %s", ctime(&st.st_ctime));
	return 0;
}