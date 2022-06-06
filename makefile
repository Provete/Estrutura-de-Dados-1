final.o: main.o  listaencadeadacomdescritor.o 
	gcc main.o listaencadeadacomdescritor.o -o .\release\final.o

main.o: .\sources\main.c
	gcc -c .\sources\main.c -o main.o

listaencadeada.o: .\sources\listaencadeada.c
	gcc -c .\sources\listaencadeada.c -o listaencadeada.o

listaencadeadacomdescritor.o: ./sources/lista_encadeada_com_descritor.c
	gcc -c .\sources\lista_encadeada_com_descritor.c -o listaencadeadacomdescritor.o

execute: .\release\final.o
	.\release\final.o

clean:
	rm -r *.o
	rm -r .\release\final.o