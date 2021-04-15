"use strict"

const prompt = require('prompt-sync')();

let numero = prompt("Insira um número para calcular seu cosseno: ");

const calculaFatorial = function(numeroFatorial) {
    let fatorial = 1;
    for(let i = 1; i <= numeroFatorial; i++) {
        fatorial = fatorial * i;
    }
    console.log(numeroFatorial, fatorial);
    return fatorial;
}

if(!numero || isNaN(numero)) {
    console.log("Número inválido!");
}
else {
    let cosseno = 1;
    let soma = false;
    for(let i = 1; i<=20; i++) {
        if(!soma) {
            cosseno = cosseno - (Math.pow(numero, 2*i) / calculaFatorial(2*i));
        } else {
            cosseno = cosseno + (Math.pow(numero, 2*i) / calculaFatorial(2*i));
        }
        soma = !soma;
    }

    console.log(`O cosseno é: ${cosseno}`);
}