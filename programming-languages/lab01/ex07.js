"use strict"

const prompt = require('prompt-sync')();

let n = prompt("Insira um número para calcular seu Fibonnacci: ");


console.log("A sequência de fibonnaci é:");

function fib(n) {
    if (isNaN(n) || n <= 0) {
        return NaN;
    }
    
    let t1 = 0;
    let t2 = 1;
    for (let i = 1; i < n; i++) {
        let seguinte = t1 + t2;
        t1 = t2;
        t2 = seguinte;
    }
    
    return t1;
}


for (let i = 1; i <= 20; i++) {
    console.log(`i = ${i} -- fib(i) = ${fib(i)}`);
}
