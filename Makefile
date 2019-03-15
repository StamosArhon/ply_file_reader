CC= gcc
CFLAGS= -c -Wall

all: ply_reader

ply_reader:	main.o header.o vertex.o faces.o ply_file_data_tree.o
						$(CC) main.o header.o vertex.o faces.o ply_file_data_tree.o -o ply_reader

main.o:	main.c header.h vertex.h faces.h ply_file_data_tree.h
				$(CC) $(CFLAGS) -c main.c

header.o: header.c header.h
					$(CC) $(CFLAGS) -c header.c

vertex.o:	vertex.c vertex.h
					$(CC) $(CFLAGS) -c vertex.c

faces.o:	vertex.c vertex.h ply_file_data_tree.h
					$(CC) $(CFLAGS) -c faces.c

ply_file_data_tree.o:	ply_file_data_tree.c ply_file_data_tree.h
											$(CC) $(CFLAGS) -c ply_file_data_tree.c

clean:
			rm -rf *o ply_reader
