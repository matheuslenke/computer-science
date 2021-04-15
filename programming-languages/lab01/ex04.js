'use strict'
const prompt = require('prompt-sync')();


let peso = prompt("Escreva um peso em newtons na Terra: ");
console.log(`Você tem as seguintes opções de converter o peso:
1-Mercurio
2-Vênus
3-Marte
4-Júpiter
5-Saturno
6-Urano
7-Netuno`)
let planeta = prompt(`
Escolha um: `);


const convertePeso = function(peso, planeta){
    let pesoConvertido = 0;
    switch(Number(planeta)) {
        case 1: 
            pesoConvertido = parseFloat(peso) * 0.37;
            break;
        case 2: 
            pesoConvertido = peso * 0.88;
            break;
        case 3: 
            pesoConvertido = peso * 0.38;
            break;
        case 4:
            pesoConvertido = peso * 2.64;
            break;
        case 5:
            pesoConvertido = peso * 1.15;
            break;
        case 6:
            pesoConvertido = peso * 1.17;
            break;
        case 7:
            pesoConvertido = peso * 1.18;
            break;
    }

    return pesoConvertido;
}

if((peso && isNaN(peso)) || Number(peso < 0) || ( planeta && isNaN(planeta) ) || planeta < 0 || planeta > 7) {
    console.log("Não é um número válido!");
}
else {
    const pesoConvertido = convertePeso(peso, planeta);
    console.log(`O peso convertido é: ${pesoConvertido}`);
}

