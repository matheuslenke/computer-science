'use strict'
const prompt = require('prompt-sync')();

let durationTime = prompt("Escreva um tempo em segundos ");

if(isNaN(durationTime) || durationTime < 0) {
    console.log("Não é um número válido!");
}

const resto = parseInt(durationTime % 3600);

const hours = parseInt((durationTime - resto) / 3600);

const seconds = parseInt(resto % 60);

const minutes = parseInt(resto - seconds) / 60;

const zeroPad = (num, places) => String(num).padStart(places, '0')

console.log(`O tempo é de: ${zeroPad(hours,2)}:${zeroPad(minutes,2)}:${zeroPad(seconds,2)}` );
