#ifndef _DATA
    #define _DATA

    //Define data struct
typedef struct tData {
    int dia;
    int mes;
    int ano;

}tData;

tData lerData();

void apresentarData(tData);

int comparaData (tData,tData);

void menorData();

void igualDiaMes();


#endif
