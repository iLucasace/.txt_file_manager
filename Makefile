all: file_simulation/*.c ram_simulation/*.c main.c
	gcc file_simulation/*.c ram_simulation/*.c main.c -o Gerenciador.out