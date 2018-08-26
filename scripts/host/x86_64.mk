export CC:=gcc
export CPP:=g++
export LD:=ld

export RM:=rm -rf

export CFLAGS:=-I$(TOPDIR)/output/include
export LDFLAGS:=-lev -L$(TOPDIR)/output/lib
export INSTALL_DIR:=$(TOPDIR)/output
