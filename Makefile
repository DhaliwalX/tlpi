CC?=gcc
CFLAGS=

dirs := lib fileio proc users time async

export out_dir=$(shell pwd)/out

run_make :=	$(make -C ./$(1))

all:
	make -C ./lib
	make -C fileio
	make -C proc
	make -C users
	make -C time
	make -C async