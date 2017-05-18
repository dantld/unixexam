#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include <myconst.h>
#include <myutils.h>

int main( int argc, char *argv[] )
{
    key_t ourIpcKey;
    SYSCALLREPORTSETEXIT( ourIpcKey, ftok( FTOK_PATH, FTOK_SHM_01 ), 1 );
    printf( "We`ve got key id (0x%0X) from ftok call\n", ourIpcKey );

    int shmId;
    SYSCALLREPORTSET( shmId, shmget( ourIpcKey, SYSV_SHM_SIZE, SYSV_SHM_PROTMODE|IPC_CREAT|IPC_EXCL ) );
    if( shmId < 0 )
    {
	if( errno == EEXIST )
	{
	    printf("Shared memory (0x%x) already exist, so just open it\n",ourIpcKey);
	    SYSCALLREPORTSETEXIT( shmId, shmget( ourIpcKey, SYSV_SHM_SIZE, 0 ), 1 );
	}
	else
	{
	    return 2;
	}
    }

    struct shmid_ds shmStat;
    SYSCALLEXIT( shmctl( shmId, IPC_STAT, &shmStat ), 1 );
    printShmIdDs( &shmStat );

    return 0;
}

