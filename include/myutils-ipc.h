#ifndef __MYUTILS_IPC__H__
#define __MYUTILS_IPC_H__

#include <sys/shm.h>

/**
 * Dump structure shmid_ds to stdout
 */
void printShmIdDs(
		const struct shmid_ds *p );

/**
 * Dump structure shmid_ds to text string
 */
char* shmIdDs2Text(
		const struct shmid_ds *p,
		char *txtBuff,
		int   txtBuffSize );

/**
 * Dump structure ipc_perm to text string
 */
char* ipcPerm2Text(
		const struct ipc_perm *p,
		char *txtBuff,
		int   txtBuffSize );

#endif //__MYUTILS_IPC_H__
