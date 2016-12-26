CC?=gcc

proc: mem_segments necho

mem_segments: mem_segments.c
	${CC} mem_segments.c -o ${out_dir}/mem_segments

necho: necho.c
	${CC} $^ -o ${out_dir}/$@
