"use strict";

function normalizar(matriz) {
    let maiorNumero = 0;
    matriz.forEach(linha => {
        linha.forEach(itemColuna => {
            if(itemColuna > maiorNumero) {
                maiorNumero = itemColuna;
            }
        })
    })

    const novaMatriz = matriz.map(linha => {
        return linha.map(itemColuna => {
            itemColuna = itemColuna / maiorNumero;
            return itemColuna;
        })
    })
    console.log(novaMatriz);
}

const matriz = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]];
const matriz2 = [[1,1,1], [1,1,2], [1,1,1]];

normalizar(matriz2);