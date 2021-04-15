'use strict'
const prompt = require('prompt-sync')();

let a = prompt("Escreva o valor de a: ");

let b = prompt("Escreva o valor de b: ");

let c = prompt("Escreva o valor de c: ");

if((a && isNaN(a)) ||( b && isNaN(b) )|| (c && isNaN(c))) {
    console.log("Não é um número válido!");
}
else {

    const delta = (b * b) -( 4 * a * c);
    
    if(delta < 0) {
        console.log("Delta negativo! Solução nos números complexos apenas");
    }
    else {
        const x1 = (-b + Math.sqrt(delta)) / (2 * a);
        
        const x2 = (-b - Math.sqrt(delta)) / (2 * a);
        
        console.log(`O resultado é: x1=${x1} e x2=${x2}`);
    
    }
}
