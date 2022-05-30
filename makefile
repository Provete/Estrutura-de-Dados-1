final.o: main.o listaencadeada.o
	gcc main.o listaencadeada.o -o .\release\final.o

main.o: .\sources\main.c
	gcc -c .\sources\main.c -o main.o

listaencadeada.o: .\sources\listaencadeada.c
	gcc -c .\sources\listaencadeada.c -o listaencadeada.o

execute: .\release\final.o
	.\release\final.o