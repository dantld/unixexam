include ../Makefile.utils
include ../Makefile.project
include ../Makefile.include

SHM01=shm01

##
## Application environment
##
OBJECTS=
STAGE01=$(SHM01)

all : $(STAGE01)

$(SHM01) : $(SHM01).o $(OBJECTS)

clean :
		-@rm -f $(SHM01)

run : all
	./$(SHM01)
