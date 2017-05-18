.PHONY: all run clean test depends
.SUFFIXES: .d

include ../Makefile.utils
include ../Makefile.project
include ../Makefile.include

MKFIFO01=mkfifo01
READER01=fiford01
WRITER01=fifowr01

##
## Application environment
##
FIFOFILE=fifo01
STAGE01=$(MKFIFO01) $(READER01) $(WRITER01)

all : $(DEPENDS) $(STAGE01)

$(MKFIFO01) : $(MKFIFO01).o

$(READER01) : $(READER01).o

$(WRITER01) : $(WRITER01).o

clean :
		-@rm -f $(MKFIFO01) $(READER01) $(WRITER01)
		-@rm -f *.o
		-@rm -f *.d

run : all
	./$(MKFIFO01) $(FIFOFILE) create
	./$(WRITER01) $(FIFOFILE)&
	./$(READER01) $(FIFOFILE)
	./$(MKFIFO01) $(FIFOFILE) remove

ifneq ($(MAKECMDGOALS),clean)
include $(DEPENDS)
endif

