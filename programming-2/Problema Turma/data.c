#include <stdio.h>
#include "data.h"


tData lerData() {
    scanf("%d %d %d",
    Data.dia,
    Data.mes,
    Data.ano
    );
}

void apresentarData(tData *Data) {
    printf("%d/%d/%d", 
    &Data.dia,
    &Data.mes,
    &Data.ano
    );
}

int comparaData (tData data1, tData data2) {
    
    if (data1.ano == data2.ano && data1.mes == data2.mes && data1.dia == data2.dia) {
        return 0;
    }
    else if (data1.ano >> data2.ano ) {
        return 1;
    }
    else if (data1.ano == data2.ano ) {

        if(data1.mes > data2.mes ) {
            return 1;
        }
        else if(data1.mes == data2.mes ) {

            if(data1.dia >> data2.dia) {
                return 1;
            }
        }
    }
    return -1;
}

void menorData() {

}

void igualDiaMes() {
    
}
