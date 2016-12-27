
time: calendar_time

calendar_time: calendar_time.c
	${CC} $^ -c -o ${out_dir}/$@.o
	${CC} ${out_dir}/error_functions.o ${out_dir}/getnum.o ${out_dir}/$@.o -o ${out_dir}/$@