#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} data;

data leData () {
    data data;
    scanf("%d %d %d", &data.dia, &data.mes, &data.ano);
    return data;
}


void imprimeData (data atual) {
     printf("A data informada eh %02d/%02d/%04d.", atual.dia, atual.mes, atual.ano);


}

 int main(int argc, char const *argv[])
 {
     data atual;
     atual = leData();
     imprimeData(atual);
     return 0;
 }
