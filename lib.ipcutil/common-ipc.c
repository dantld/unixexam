#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <myconst.h>
#include <myutils-ipc.h>

void printShmIdDs(
		const struct shmid_ds *p )
{
    char buffer[MAX_LENGTH_SHMID_DS] = "";
    printf( "%s\n", shmIdDs2Text( p, buffer, MAX_LENGTH_SHMID_DS ));
}

/**
 * Dump structure shmid_ds to text string
 */
char* shmIdDs2Text(
		const struct shmid_ds *p,
		char *txtBuff,
		int   txtBuffSize )
{
    char atimeBuf[MAX_LENGTH_CTIME]     = "";
    char dtimeBuf[MAX_LENGTH_CTIME]     = "";
    char ctimeBuf[MAX_LENGTH_CTIME]     = "";
    char ipcPermBuf[MAX_LENGTH_IPCPERM] = "";
    char shmidBuf[MAX_LENGTH_SHMID_DS]  = "";

    ctime_r( &(p->shm_atime), atimeBuf );
    ctime_r( &(p->shm_dtime), dtimeBuf );
    ctime_r( &(p->shm_ctime), ctimeBuf );

    char *s = NULL;
    if( (s = strrchr(atimeBuf,'\n')) != NULL ) *s = 0;
    if( (s = strrchr(dtimeBuf,'\n')) != NULL ) *s = 0;
    if( (s = strrchr(ctimeBuf,'\n')) != NULL ) *s = 0;

    assert( txtBuffSize >= snprintf(
	txtBuff,
	txtBuffSize,
	"Permissions         : %s\n"
	"Size                : %d bytes\n"
	"Last attach time    : %s\n"
	"Last detach time    : %s\n"
	"Last change time    : %s\n"
	"Creator pid         : %d\n"
	"Last shmat/shmdt pid: %d\n"
	"Number of attaches  : %d"
	,
       ipcPerm2Text(&(p->shm_perm),ipcPermBuf,MAX_LENGTH_IPCPERM), /* Ownership and permissions */
       p->shm_segsz,	/* Size of segment (bytes) */
       atimeBuf,   	/* Last attach time */
       dtimeBuf,   	/* Last detach time */
       ctimeBuf,   	/* Last change time */
       p->shm_cpid, 	/* PID of creator */
       p->shm_lpid, 	/* PID of last shmat(2)/shmdt(2) */
       p->shm_nattch	/* No. of current attaches */
    ));
    return txtBuff;
}

char* ipcPerm2Text(
		const struct ipc_perm *p,
		char *txtBuff,
		int   txtBuffSize )
{
    assert( txtBuffSize >= snprintf(
	txtBuff, txtBuffSize,
	"key(0x%X) owner(%d/%d) creator(%d/%d) mode(0%o) seq(%d)"
	,
	p->__key,    /* Key supplied to shmget(2) */
	p->uid,      /* Effective UID of owner */
	p->gid,      /* Effective GID of owner */
	p->cuid,     /* Effective UID of creator */
	p->cgid,     /* Effective GID of creator */
	p->mode,     /* Permissions + SHM_DEST and SHM_LOCKED flags */
	p->__seq    /* Sequence number */
    ));
    return txtBuff;
}
