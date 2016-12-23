CC?=gcc

copy: copy.c
	${CC} -c copy.c -o ${out_dir}/copy.o
	${CC} ${out_dir}/error_functions.o ${out_dir}/getnum.o ${out_dir}/copy.o -o ${out_dir}/$@
