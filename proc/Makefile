CC?=gcc

proc: mem_segments necho environ modify_env

mem_segments: mem_segments.c
	${CC} mem_segments.c -o ${out_dir}/mem_segments

necho: necho.c
	${CC} $^ -o ${out_dir}/$@

environ: display_env.c
	${CC} $^ -o ${out_dir}/$@

modify_env: modify_env.c
	${CC} -c $^ -o ${out_dir}/$@.o
	${CC} ${out_dir}/error_functions.o ${out_dir}/getnum.o ${out_dir}/$@.o -o ${out_dir}/$@
