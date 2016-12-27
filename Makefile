CC?=gcc
CFLAGS=

export out_dir=$(shell pwd)/out

all:
	make -C ./lib
	make -C ./fileio
	make -C ./proc
	make -C ./users
	make -C ./time