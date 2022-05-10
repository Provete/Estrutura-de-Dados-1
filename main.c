#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct String
{
    char* data;
    unsigned int size;
} String;

String* CreateString(const char string[])
{
    String* returnString;
    returnString->size = strlen(string);

    returnString->data = (char*) malloc(returnString->size+1);

    strcpy(returnString->data, string);
    returnString->data[returnString->size] = '\0';

    return returnString;
} 

void PrintString(const String* const string)
{
    printf("%s\n", string->data);
}

void FreeString(String* string)
{
    free(string->data);
    string->size = 0;
}

int main()
{
    String* nome = CreateString("Ruanzin viado");
    printf("String possui %d characteres\n", nome->size);
    PrintString(nome);

    FreeString(nome);
    return 0;
}