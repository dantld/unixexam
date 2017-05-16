#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include "myconst.h"

int main( int argc, char *argv[] )
{
    if( argc != 3 )
    {
	fprintf( stderr, "E: Need argument: {fifopath} {create | remove}\n" );
	return 1;
    }

    if( strcmp( argv[2], MKFIFO_CREATE ) == 0 ) {
	SYSCALLEXIT( mkfifo( argv[1], 0600 ), 1 )
    }
    else if( strcmp( argv[2], MKFIFO_REMOVE ) == 0 ) {
	SYSCALLEXIT( unlink( argv[1] ), 2 )
    }
    else
    {
	fprintf(stderr,"E: Unknown verb \"%s\" for mkfifo\n", argv[2] );
	return 3;
    }

    return 0;
}

