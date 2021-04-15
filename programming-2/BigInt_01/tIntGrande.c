#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compara(char* n1,char* n2 ) {

    if(strlen(n1) == strlen(n2) && strcmp(n1,n2) == 0) {
        printf("IGUAL");
        return;
    }
    if(strlen(n1) == strlen(n2) && strcmp(n1,n2) == 1) {
        printf("MAIOR");
        return;
    }
    if(strlen(n1) == strlen(n2) && strcmp(n1,n2) == -1) {
        printf("MENOR");
        return;
    }
    if(strlen(n1) != strlen(n2) && strlen(n1) > strlen(n2)){
        printf("MAIOR");
    }
    if(strlen(n1) != strlen(n2) && strlen(n1) < strlen(n2)){
        printf("MENOR");
    }
}

int main(int argc, char const *argv[])
{
   char n1[102], n2[102];
   scanf("%s", n1);
  // printf("%s\n", n1);
   scanf("%s", n2);
  // printf("%s\n", n2);
  compara(n1,n2);
    return 0;
}
