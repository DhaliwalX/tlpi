CC?=gcc
AR?=ar

libcommon.a: error_functions.o getnum.o
	${AR} rs ${out_dir}/$@ ${out_dir}/error_functions.o ${out_dir}/getnum.o

error_functions.o: error_functions.c
	${CC} -c $^ -o ${out_dir}/$@

getnum.o: getnum.c
	${CC} -c $^ -o ${out_dir}/$@

