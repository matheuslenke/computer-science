//
// Created by Matheus Lenke on 09/12/19.
//
#include <stdio.h>
#include <stdlib.h>

#define QTD_SEMANAS 200
#define QTD_DIAS 5
#define MANHA 0
#define TARDE 1

typedef struct dia {
    int manha[4];
    int tarde[4];
    int inicio;
    int quantidade_horas;
}tDia;

typedef struct semana{
    tDia dias[QTD_DIAS];
    int quantidade_dias;
} tSemana;

typedef struct agenda {
    tSemana semanas[QTD_SEMANAS];
    int quantidade_semanas;
} tAgenda;

typedef struct compromisso {
    int semana;
    int dia;
    int hora;
    int horasvagas;
    int manha;
    int tarde;
} tCompromisso;

tAgenda* inicializaAgenda() {
    tAgenda* agenda = (tAgenda*)malloc( sizeof(tAgenda));
    agenda->quantidade_semanas = 0;
    agenda->semanas->quantidade_dias = 0;
    for(int i = 0; i< QTD_SEMANAS; i ++) {
        agenda->semanas[i].quantidade_dias = 0;
        for(int j = 0; j< QTD_DIAS; j ++) {
            agenda->semanas[i].dias[j].quantidade_horas = 0;
        }
    }
    return agenda;
}

tAgenda* insereAgenda(tAgenda* agenda, int horario) {
    int i = agenda->quantidade_semanas;
    int j = agenda->semanas[i].quantidade_dias;
    int k = agenda->semanas[i].dias[j].quantidade_horas;
    if (k < 4) {
        agenda->semanas[i].dias[j].manha[k] = horario;
        agenda->semanas[i].dias[j].quantidade_horas++;
    } else {
        agenda->semanas[i].dias[j].tarde[k - 4] = horario;
        if(k == 7){
            if(agenda->semanas[i].quantidade_dias == QTD_DIAS - 1) {
                agenda->quantidade_semanas++;
            }
            else agenda->semanas[i].quantidade_dias++;

        }
        else agenda->semanas[i].dias[j].quantidade_horas++;

    }
    return agenda;
}

tAgenda* leAgenda(tAgenda* agenda) {
    char hora;
    int horainteira;
    char parada;

    scanf("%c", &hora);
    horainteira = (int)hora - '0';
    agenda = insereAgenda(agenda, horainteira);
    while(hora != ' ') {
        scanf("%c", &hora);
        if(hora == ' ') break;
        horainteira =(int) hora - '0';
       agenda = insereAgenda(agenda, horainteira);

    }

    return agenda;
}
//int retornaHorasVagas(tDia dia, ) {
//    if(dia.manha[0] == 0 && dia.manha[1] == 0 && dia.manha[2] == 0 && dia.manha[3] == 0) {
//        return 4;
//    }
//    if(dia.manha[0] == 0 && dia.manha[1] == 0 && dia.manha[2] == 0)
//
//}
void imprimeCompromisso(tCompromisso compromisso){
    int i = compromisso.semana;
    int j = compromisso.dia;
    int k;
    if(compromisso.manha == 1) {
        k = compromisso.hora;
    }
    else {
        k = compromisso.hora + 6;
    }

    switch(j) {
        case 0: {
            printf("Semana %d, Segunda-feira, %d:00 horas.", i + 1, k + 8);
            break;
        }
        case 1: {
            printf("Semana %d, Terca-feira, %d:00 horas.", i + 1, k + 8);
            break;
        }
        case 2: {
            printf("Semana %d, Quarta-feira, %d:00 horas.", i + 1, k + 8);
            break;
        }
        case 3: {
            printf("Semana %d, Quinta-feira, %d:00 horas.", i + 1, k + 8);
            break;
        }
        case 4: {
            printf("Semana %d, Sexta-feira, %d:00 horas.", i + 1, k + 8);
            break;
        }
    }

}
void marcaCompromisso(tAgenda* agenda) {
    int horas_compromisso;
    int podemarcar = 0;
    tCompromisso compromisso;
    compromisso.horasvagas = 7;
    compromisso.manha = 0;
    compromisso.tarde = 0;
    int marcou = 0;
    int inicio = 0;
    int anterior = 0;

    scanf("%d", &horas_compromisso);
    tDia aux;
    int horasvagas = 0;

    for(int i = 0; i<=agenda->quantidade_semanas; i++) {
        for(int j = 0; j<=agenda->semanas[i].quantidade_dias; j++) {
            for(int k = 0; k<agenda->semanas[i].dias[j].quantidade_horas; k++){
                if(k<4 && agenda->semanas[i].dias[j].manha[k] == 0 ) {
                    for(int h = 0; h < 4 ; h++) {
                        horasvagas = 0;
                        if(agenda->semanas[i].dias[j].manha[h] == 0) {
                            inicio = h;
                            anterior = 0;
                            horasvagas++;
                            h++;
                            while(anterior == 0 && h < 4) {
                                if(agenda->semanas[i].dias[j].manha[h] == 1) {
                                    anterior = 1;
                                    h--;
                                    horasvagas--;

                                }
                                h++;
                                horasvagas++;
                            }
                        }
                        if(horasvagas < horas_compromisso) podemarcar = 1;
                        if(podemarcar == 0){
                            if(horasvagas < compromisso.horasvagas) {
                                compromisso.semana = i;
                                compromisso.dia = j;
                                compromisso.hora = inicio;
                                compromisso.horasvagas = horasvagas;
                                compromisso.manha = 1;
                                compromisso.tarde = 0;
                                marcou = 1;
                            }
                        }
                        horasvagas = 0;
                        podemarcar = 0;
                        k = h;
                    }
                }
                else if (agenda->semanas[i].dias[j].tarde[k - 4] == 0 ) {
                    for(int h = 0; h < 4; h++) {
                        horasvagas = 0;
                        if(agenda->semanas[i].dias[j].tarde[h] == 0) {
                            anterior = 0;
                            horasvagas++;
                            inicio = h;
                            h++;
                            while(anterior == 0 && h<4) {
                                if(agenda->semanas[i].dias[j].tarde[h] == 1) {
                                    anterior = 1;
                                    h--;
                                    horasvagas--;
                                }
                                h++;
                                horasvagas++;
                            }
                        }
                        if(horasvagas < horas_compromisso) podemarcar = 1;
                        if(podemarcar == 0){
                            if(horasvagas < compromisso.horasvagas) {
                                compromisso.semana = i;
                                compromisso.dia = j;
                                compromisso.hora = inicio;
                                compromisso.horasvagas = horasvagas;
                                compromisso.tarde = 1;
                                compromisso.manha = 0;
                                marcou = 1;
                            }
                        }
                        horasvagas = 0;
                        podemarcar = 0;
                        k = h + 4;
                    }
                }
            }
        }
    }
    if(marcou == 0) {
        printf("Nao ha espaco na agenda para este compromisso!");
        return;
    }
    imprimeCompromisso(compromisso);
}

int main ( ) {
    tAgenda* agenda = inicializaAgenda();
    agenda =  leAgenda(agenda);
    marcaCompromisso(agenda);
}
