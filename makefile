# Project: Project1
# Makefile created by Dev-C++ 5.11
BASH     = $(GITDIR)/usr/bin
GIT      = $(GITDIR)/bin/git.exe

INCDIR   = $(PROJECTDIR)/include/
DEPDIR   = $(PROJECTDIR)/dep/
SRCDIR   = $(PROJECTDIR)/src/
BUILDDIR = $(PROJECTDIR)/build/
RELEASEDIR = $(PROJECTDIR)/release/

CPP      = g++.exe
CC       = gcc.exe
LD       = ld.exe
WINDRES  = windres.exe
strip    = strip.exe # This variable has the paths to the objects files that will be generated in the build directory
LINKOBJ  = $(PROJECTDIR)/build/main.o
#-static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
LIBS     = -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic
INCS     =
CXXINCS  = -I $(INCDIR) -I $(DEPDIR)
OUTPUTDIR = $(PROJECTDIR)/bin/
BIN      = $(OUTPUTDIR)/Output.exe
CXXFLAGS = $(CXXINCS) $(GITDETAILS) -Ofast -std=c++17 -w -Wall -Wextra -pedantic
CFLAGS   = $(INCS)
RM       = rm.exe -f

SOURCES = $(shell $(BASH)/find $(SRCDIR) -name "*.cpp")
OBJECTS = $(SOURCES:$(SRCDIR)%.cpp=$(BUILDDIR)%.o)

CLIGCORE=  $(BUILDDIR)cligCore.o
CLIGSRC =  $(shell $(BASH)/find $(SRCDIR)/cligCore/ -name "*.cpp")
CLIGOBJ =  $(CLIGSRC:$(SRCDIR)%.cpp=$(BUILDDIR)%.o)


GIT_VERSION := $(shell $(GIT) -C $(PROJECTDIR) --no-pager describe --tags --always)
GIT_COMMIT  := $(shell $(GIT) -C $(PROJECTDIR) rev-parse --verify HEAD)
GIT_DATE    := $(firstword $(shell $(GIT) -C $(PROJECTDIR) --no-pager show --date=iso-strict --format="%ad" --name-only))
BUILD_DATE  := $(shell $(BASH)/date --iso=seconds)

ifneq ($(strip $(shell $(GIT) -C $(PROJECTDIR) status --porcelain)),)
 GIT_VERSION := $(GIT_VERSION)-D
endif

GITDETAILS = -D GIT_VERSION=\"$(GIT_VERSION)\" -D GIT_COMMIT=\"$(GIT_COMMIT)\" -D GIT_DATE=\"$(GIT_DATE)\" -D BUILD_DATE=\"$(BUILD_DATE)\"



.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJECTS) $(BIN)

executable: $(bin)
object: $(CLIGCORE)

debug:
	echo $(OBJECTS)

$(BUILDDIR)%.o: $(SRCDIR)%.cpp
	$(BASH)/mkdir -p $(@D)
	$(CPP)  -c -o $@ $< $(LIBS) $(CXXFLAGS)

$(BIN): $(CLIGCORE)
	$(BASH)/mkdir -p $(@D)
	$(CPP) -o $@ $(CXXLAGS) $^ $(LIBS)
#$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

$(CLIGCORE): $(CLIGOBJ) $(LINKOBJ)
	$(LD) -r $^ -o $(BUILDDIR)cligCore.o

createRelease: $(CLIGCORE)
	$(BASH)/mkdir -p $(RELEASEDIR)
	$(BASH)/cp $(CLIGCORE) $(RELEASEDIR)
	$(BASH)/cp $(INCDIR)/clig.hpp $(RELEASEDIR)
