SMILEICXX		?= mpic++
PYTHONCONFIG	?= python3-config

CFLAGS 		+= -std=c++11

LDFLAGS 	+=
####################################################
#add subdirs
DIRS 		= $(shell find * -type d)
#add include directives for subdirs
CFLAGS 		+= $(DIRS:%=-I%)



PYSCRIPTS := $(shell find Python -name \*.py)
PYHEADERS := $(PYSCRIPTS:.py=.pyh)

#collect all cpp files
SRCS := $(shell find . -name \*.cpp)
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)


CFLAGS		+=$(shell $(PYTHONCONFIG) --includes)
PATH_Python = $(shell $(PYTHONCONFIG) --prefix)
LDFLAGS 	+= -L${PATH_Python}/lib $(shell $(PYTHONCONFIG) --ldflags)


ifeq ($(config),debug)
	CFLAGS += -g -pg -Wall -D__DEBUG -O3# -shared-intel
else
	CFLAGS += -O3#  -xHost -ipo
endif



###############################################################
EXEC		= ccp
default: $(EXEC)

help:
	@echo 'Usage                 : make [clean] [openmp={gnu|intel}] [config=debug]'
	@echo 'Environment variables : SMILEICXX (c++ compiler) HDF5_ROOT_DIR (HDF5 dir with /include and /lib)'

release:
	make

debug:
	make config=debug

clean:
	rm -f $(OBJS) $(DEPS) $(PYHEADERS) $(EXEC)

distclean: clean
	rm -f $(EXEC)

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif

# this generates a .h file containing a char[] with the python script in binary then
#you can just include this file to get the contents
%.pyh: %.py
	@ echo "Creating binary char for $< : $@"
	@ xxd -i $< > $@

%.d: %.cpp $(PYHEADERS)
	@ echo "Checking dependencies for $<"
# create and modify dependecy file .d to take into account the location subdir
	@ $(SMILEICXX) $(CFLAGS) -MM $< 2>/dev/null | sed -e "s@\(^.*\)\.o:@$(shell  dirname $<)/\1.d $(shell  dirname $<)/\1.o:@" > $@

%.o : %.cpp
	$(SMILEICXX) $(CFLAGS) -c $< -o $@

$(EXEC): $(PYHEADERS) $(OBJS)
	$(SMILEICXX) $(CFLAGS) -o $(EXEC) $(OBJS) $(LDFLAGS)

# DO NOT DELETE
