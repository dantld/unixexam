#ifndef __MYCONST_H_
#define __MYCONST_H_

/**
 * Maximum length of buffer for (a|c)time calls.
 */
#define MAX_LENGTH_CTIME 32

/**
 * Maximum length of buffer for text repersentation
 * of struct ipc_perm
 */
#define MAX_LENGTH_IPCPERM 72

/**
 * Maximum length of buffer for text repersentation
 * of struct shmid_ds
 */
#define MAX_LENGTH_SHMID_DS 512

/**
 * mkfifo - command
 * Create fifo pipe.
 */
#define MKFIFO_CREATE "create"

/**
 * mkfifo - command
 * Remove fifo pipe.
 */
#define MKFIFO_REMOVE "remove"

/**
 * Define the maximum length of message for sending through the fifo pipes
 */
#define MAX_FIFO_MESSAGE_SIZE 2048


/**
 * ftok path name
 */
#define FTOK_PATH "../README.md"

/**
 * ftok project Id shared memory type 01
 */
#define FTOK_SHM_01 1

/**
 * System V shared memory size
 */
#define SYSV_SHM_SIZE 0x8000

/**
 * System V shared memory protect mode
 */
#define SYSV_SHM_PROTMODE 0600

/**
 * Call system call statement if return value is negative just report
 * return value available as value
 */
#define SYSCALLREPORTSET(value,stmt) \
	{\
	value = stmt;\
	if( value < 0 ) \
	{\
	fprintf( stderr, "E: System call failed (%s:%d) \"" #stmt "\" : %s\n", __FILE__, __LINE__,strerror(errno) );\
	}\
	}

/**
 * Call system call statement if return value is negative report and exit with value as exitcode
 */
#define SYSCALLREPORTSETEXIT(value,stmt,exitcode) \
	{\
	value = stmt;\
	if( value < 0 ) \
	{\
	fprintf( stderr, "E: System call failed (%s:%d) \"" #stmt "\" : %s\n", __FILE__, __LINE__,strerror(errno) );\
	exit(exitcode);\
	}\
	}

/**
 * Call system call statement if return value is negative report and exit return with value as retcode
 */
#define SYSCALLREPORTSETRETURN(value,stmt,retcode) \
	{\
	value = stmt;\
	if( value < 0 ) \
	{\
	fprintf( stderr, "E: System call failed (%s:%d) \"" #stmt "\" : %s\n", __FILE__, __LINE__,strerror(errno) );\
	return retcode;\
	}\
	}

/**
 * Call system call statement if return value is negative just report on stderr
 */
#define SYSCALLREPORT(stmt) \
	{\
	int r = stmt;\
	if( r < 0 ) \
	{\
	fprintf( stderr, "E: System call failed (%s:%d) \"" #stmt "\" : %s\n", __FILE__, __LINE__,strerror(errno) );\
	}\
	}

/**
 * Call system call statement if return value is negative exit with exitcode value
 */
#define SYSCALLEXIT(stmt,exitcode) \
	{\
	int r = stmt;\
	if( r < 0 ) \
	{\
	fprintf( stderr, "E: System call failed (%s:%d) \"" #stmt "\" : %s\n", __FILE__, __LINE__,strerror(errno) );\
	exit(exitcode);\
	}\
	}

/**
 * Call system call statement if return value is negative return with retcode value
 */
#define SYSCALLRETURN(stmt,retcode) \
	{\
	int r = stmt;\
	if( r < 0 ) \
	{\
	fprintf( stderr, "E: System call failed (%s:%d) \"" #stmt "\" : %s\n", __FILE__, __LINE__,strerror(errno) );\
	return retcode;\
	}\
	}

#endif // __MYCONST_H_