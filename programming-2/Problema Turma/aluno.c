#include <stdio.h>
#include "aluno.h"
#include "data.h"
#include "turma.h"


void lerAluno(tAluno* aluno, FILE* file) {
        fscanf(file, "%s %s %d %f",
        &aluno->nome,
        &aluno->matricula,
        &aluno->idade,
        &aluno->cr
        );
        aluno->data_ingresso = lerData(file);
        aluno->data_nascimento = lerData(file);

}

void apresentarAluno(tAluno* aluno) {
   
    printf("%s %s %d %f",
        aluno->nome,
        aluno->matricula,
        aluno->idade,
        aluno->cr,
    );
    apresentarData(aluno->data_ingresso);
    apresentarData(aluno->data_nascimento);

}

void compararNome(tAluno* aluno1, tAluno* aluno2) {
    tAluno aux;

    if (strcmp(aluno1.nome,aluno2.nome) > 0) {
        aux = aluno1;
        aluno1 = aluno2;
        aluno2= aux;
    }
}

void compararIngresso(tAluno* aluno1, tAluno* aluno2) {
    tAluno aux;
    
    if (aluno1->data_ingresso.ano > aluno2->data_ingresso.ano) {
        aux = aluno1;
        aluno1 = aluno2;
        aluno2= aux;
    }
    else if (aluno1->data_ingresso.ano == aluno2->data_ingresso.ano) {

        if(aluno1->data_ingresso.mes > aluno2->data_ingresso.mes) {
            aux = aluno1;
            aluno1 = aluno2;
            aluno2= aux;
        }
        else if(aluno1->data_ingresso.mes == aluno2->data_ingresso.mes) {

            if(aluno1->data_ingresso.dia > aluno2->data_ingresso.dia) {

            aux = aluno1;
            aluno1 = aluno2;
            aluno2= aux;

            }
        }
    }
     
}

void compararMatricula();

void compararCR(tAluno* aluno1, tAluno* aluno2) { 
    tAluno aux;

    if (aluno1->cr < aluno2->cr) {
        aux = aluno1;
        aluno1 = aluno2;
        aluno2= aux;
    }
}

    



void ehAniversario(tAluno* aluno, data_hoje) {
    if(aluno->data_nascimento == data_hoje){
        return 0;
    }
    else return 1;
}

void ehExcelente();