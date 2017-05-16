#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "myconst.h"

char messageBuffer[MAX_FIFO_MESSAGE_SIZE];

int main( int argc, char *argv[] )
{
    if( argc != 2 )
    {
	fprintf( stderr, "E: Need argument: {fifopath}\n" );
	return 1;
    }
    int fd;
    SYSCALLREPORTSETRETURN( fd, open(argv[1], O_RDONLY), 1 );
    int s = MAX_FIFO_MESSAGE_SIZE;
    int rb;
    int msgSize;
    SYSCALLREPORTSETRETURN( rb, read(fd,&msgSize,sizeof(int)), 1 );
    printf( "Readed bytes: %d, message size %d\n", rb, msgSize );
    SYSCALLREPORTSETRETURN( rb, read(fd,messageBuffer,msgSize), 1 );
    printf( "Readed bytes: %d\n", rb );
    printf( "%s\n", messageBuffer );
    return 0;
}