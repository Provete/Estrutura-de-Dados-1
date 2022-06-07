final.o: main.o  listaencadeadacomcabeçacalda.o
	gcc main.o listaencadeadacomcabeçacalda.o -o .\release\final.o

main.o: .\sources\main.c
	gcc -c .\sources\main.c -o main.o

listaencadeada.o: .\sources\listaencadeada.c
	gcc -c .\sources\listaencadeada.c -o listaencadeada.o

listaencadeadacomdescritor.o: ./sources/lista_encadeada_com_descritor.c
	gcc -c .\sources\lista_encadeada_com_descritor.c -o listaencadeadacomdescritor.o

listaencadeadacomcabeçacalda.o: .\sources\lista_encadeada_com_cabeça_calda.c
	gcc -c .\sources\lista_encadeada_com_cabeça_calda.c -o listaencadeadacomcabeçacalda.o

execute: .\release\final.o
	.\release\final.o

clean:
	rm -r *.o
	rm -r .\release\final.o