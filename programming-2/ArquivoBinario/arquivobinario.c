#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    char str[100] = "Primeiralinha \n Segundalinha \n Terceiralinha";

    float x = 37.6, y;

     /*Opening file for writing in binary mode*/
     FILE *file, *flutuante;
     
     if (!(texto = fopen("bintext.txt", "wb"))) {
         printf("Erro bintext.txt");
         exit(1);
     }

    fwrite (str, sizeof(char), strlen(str), texto);
    fclose ( texto);

     if (!(flutuante = fopen("float.txt", "wb"))) {
         printf("Erro float.txt");
         exit(1);
     }


     fwrite(&x, sizeof(float), 1 , flutuante);
     fclose (flutuante);

     fread(&x, sizeof(float), 1, flutuante);
     fclose (flutuante);

    return 0;
}
