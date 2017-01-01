syslim: t_sysconf

t_sysconf: t_sysconf.c
	${CC} $^ -c -o ${out_dir}/$@.o
	${CC} ${out_dir}/$@.o ${out_dir}/error_functions.o ${out_dir}/getnum.o -o ${out_dir}/$@