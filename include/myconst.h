#ifndef __MYCONST_H_
#define __MYCONST_H_


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