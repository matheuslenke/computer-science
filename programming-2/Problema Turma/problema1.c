#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Define variable structs
typedef struct tData {
    int dia;
    int mes;
    int ano;

}tData;

typedef struct tAluno {
    char nome[20];
    char matricula[10];
    int idade;
    float cr;
    tData data_ingresso;
    tData data_nascimento;
}tAluno;

typedef struct tTurma {
    tAluno alunos[4];
    int quantidade_alunos;
}tTurma;

tData lerData(FILE *file) {
        tData data;
        fscanf(file, "%d %d %d",
        &data.dia,
        &data.mes,
        &data.ano
        );
    return data;
}

void lerArquivo(FILE *file, tTurma *turma, tData *data_hoje ) {
int i=0;
    //Reading all .txt file data

    *data_hoje = lerData(file);

    do {
        fscanf(file, "%s %s %d %f",
        turma->alunos[i].nome,
        turma->alunos[i].matricula,
        &turma->alunos[i].idade,
        &turma->alunos[i].cr
        );
        turma->alunos[i].data_ingresso= lerData(file);
        turma->alunos[i].data_nascimento = lerData(file);

        i++;
    } while(strcmp(turma->alunos[i-1].matricula, "0") != 0 );
    turma->quantidade_alunos=i-1;
}

void imprimirAlunos(tTurma *turma) {
    for(int i=0; i<=turma->quantidade_alunos-1;i++) {

        printf("%s %s %d %f Ingresso: %d/%d/%d Nascimento: %d/%d/%d \n",
        turma->alunos[i].nome,
        turma->alunos[i].matricula,
        turma->alunos[i].idade,
        turma->alunos[i].cr,
        turma->alunos[i].data_ingresso.dia,
        turma->alunos[i].data_ingresso.mes,
        turma->alunos[i].data_ingresso.ano,
        turma->alunos[i].data_nascimento.dia,
        turma->alunos[i].data_nascimento.mes,
        turma->alunos[i].data_nascimento.ano
        );
    }

}

void Ordenar_nome(tTurma *turma) {
    tAluno aux;
    //Percorrendo o vetor de alunos, comparando cada elemento com todos os outros
    for(int i=0;i<turma->quantidade_alunos-1;i++ ) {
        for(int j=i+1;j<turma->quantidade_alunos;j++) {
            //Comparando a posição i com a j para saber qual nome vem antes
            if (strcmp(turma->alunos[i].nome,turma->alunos[j].nome) > 0) {
                aux = turma->alunos[i];
                turma->alunos[i] = turma->alunos[j];
                turma->alunos[j]= aux;
            }
        }

    }

}
void Ordenar_ingresso(tTurma *turma) {
    tAluno aux;
    //Percorrendo o vetor de alunos, comparando cada elemento com todos os outros
    for(int i=0;i<turma->quantidade_alunos-1;i++ ) {
        for(int j=i+1;j<turma->quantidade_alunos;j++) {
            //Comparando a posição i com a j para saber qual ingresso vem antes
            if (turma->alunos[i].data_ingresso.ano > turma->alunos[j].data_ingresso.ano) {
                aux = turma->alunos[i];
                turma->alunos[i] = turma->alunos[j];
                turma->alunos[j]= aux;
            }
            else if (turma->alunos[i].data_ingresso.ano == turma->alunos[j].data_ingresso.ano) {

                if(turma->alunos[i].data_ingresso.mes > turma->alunos[j].data_ingresso.mes) {
                    aux = turma->alunos[i];
                    turma->alunos[i] = turma->alunos[j];
                    turma->alunos[j]= aux;
                }
                else if(turma->alunos[i].data_ingresso.mes == turma->alunos[j].data_ingresso.mes) {

                    if(turma->alunos[i].data_ingresso.dia > turma->alunos[j].data_ingresso.dia) {

                    aux = turma->alunos[i];
                    turma->alunos[i] = turma->alunos[j];
                    turma->alunos[j]= aux;

                    }
                }
            }
        }
    }
}

void Ordenar_CR(tTurma *turma) {
    tAluno aux;
    //Percorrendo o vetor de alunos, comparando cada elemento com todos os outros
    for(int i=0;i<turma->quantidade_alunos-1;i++ ) {
        for(int j=i+1;j<turma->quantidade_alunos;j++) {
            //Comparando a posição i com a j para saber qual nome vem antes
            if (turma->alunos[i].cr < turma->alunos[j].cr) {
                aux = turma->alunos[i];
                turma->alunos[i] = turma->alunos[j];
                turma->alunos[j]= aux;
            }
        }

    }

}
                        

void main (void) {
    
    FILE *file;
    //Creating variable from struct created
    tTurma turma;
    tData data_hoje;
    //Open File
    file = fopen("alunos.txt", "r");

    if (file == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
        return;
    } 
    else {
        lerArquivo(file, &turma, &data_hoje);
        printf("Quantidade de alunos: %d \n", turma.quantidade_alunos);
        imprimirAlunos(&turma);
        Ordenar_nome(&turma);
        printf("\n Alunos ordenados por nome: \n");
        imprimirAlunos(&turma);
        printf("\n Alunos ordenados por ingresso:\n");
        Ordenar_ingresso(&turma);
        imprimirAlunos(&turma);
        printf("\n Alunos ordenados por CR:\n");
        Ordenar_CR(&turma);
        imprimirAlunos(&turma);
    }


}

