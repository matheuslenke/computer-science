"use strict"

console.log("Tabela de temperaturas: ");

console.log("Celsius | Fahrenheit")
for(let temperaturaEmC = -100; temperaturaEmC<=100; temperaturaEmC+=5) {
    const temperaturaEmFahrenheit = ((9/5) * temperaturaEmC ) + 32;
    console.log(`${temperaturaEmC} | ${temperaturaEmFahrenheit}`)
}