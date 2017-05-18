#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "myconst.h"

const char *messagePattern = "MESSAGE FROM pid=%d";
char messageBuffer[MAX_FIFO_MESSAGE_SIZE];

int main( int argc, char *argv[] )
{
    if( argc != 2 )
    {
	fprintf( stderr, "E: Need argument: {fifopath}\n" );
	return 1;
    }

    int fd;
    SYSCALLREPORTSETRETURN( fd, open(argv[1], O_WRONLY), 1 );
    int s=snprintf(messageBuffer,MAX_FIFO_MESSAGE_SIZE,messagePattern,getpid());
    int wb;
    SYSCALLREPORTSETRETURN( wb, write(fd,&s,sizeof(int)), 1 );
    printf("Write to pipe %d bytes\n", wb);
    SYSCALLREPORTSETRETURN( wb, write(fd,messageBuffer,s), 1 );
    printf("Write to pipe %d bytes\n", wb);
    SYSCALLREPORT( close(fd) )
    return 0;
}
