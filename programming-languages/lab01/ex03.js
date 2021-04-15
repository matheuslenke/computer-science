'use strict'
const prompt = require('prompt-sync')();

const notas = [];

let a = prompt("Escreva a primeira nota do aluno: ");
notas.push(Number(a));

let b = prompt("Escreva a segunda nota do aluno: ");
notas.push(Number(b));

let c = prompt("Escreva a terceira nota do aluno: ");
notas.push(Number(c));

function verificaAprovado(nota){
    if(nota >= 7) {
        console.log(`Aluno aprovado com nota ${nota}`);
    } else {
        console.log(`Aluno em recuperação!`);
    }
}

if((a && isNaN(a)) ||( b && isNaN(b) )|| (c && isNaN(c))) {
    console.log("Não é um número válido!");
}
else {

    const media = notas.reduce((Accumulator, nota) => {
        return (Accumulator + nota) / 2;
    }, 0)

    verificaAprovado(media);
}

