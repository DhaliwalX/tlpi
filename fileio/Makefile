CC?=gcc

fileio: copy seek_io

copy: copy.c
	${CC} -c copy.c -o ${out_dir}/copy.o
	${CC} ${out_dir}/error_functions.o ${out_dir}/getnum.o ${out_dir}/copy.o -o ${out_dir}/$@

seek_io: seek_io.c
	${CC} -c seek_io.c -o ${out_dir}/seek_io.o
	${CC} ${out_dir}/error_functions.o ${out_dir}/getnum.o ${out_dir}/seek_io.o -o ${out_dir}/$@