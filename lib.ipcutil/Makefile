include ../Makefile.utils
include ../Makefile.project
include ../Makefile.include

LIBIPCUTIL=libipcutil.so

##
## Application environment
##
OBJECTS=common-ipc.o

all : $(LIBIPCUTIL)

$(LIBIPCUTIL) : $(OBJECTS)
	$(CC) -shared -o $(LIBIPCUTIL) $(OBJECTS)

clean :
	-@rm -f $(LIBIPCUTIL)
