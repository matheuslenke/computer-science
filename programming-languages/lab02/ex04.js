"use strict";

class Forma {
    constructor() {
        if (this.calcularPerimetro === undefined) {
            throw new TypeError("Classe não implementa o método 'calcularPerimetro'!");
        }
	
        if (this.calcularArea === undefined) {
            throw new TypeError("Classe não implementa o método 'calcularArea'!");
        }
    }
}

class Quadrilatero extends Forma {
    constructor(l1, l2, l3, l4) {
        super();
        
        if (this.constructor === Quadrilatero) {
            throw new TypeError("Classe abstrata 'Quadrilatero' não pode ser instanciada diretamente!"); 
        }
        
        this.lados = [l1, l2, l3, l4];
    }
    
    calcularPerimetro() {
        return this.lados.reduce((a, b) => a + b, 0);
    }
}

class Retangulo extends Quadrilatero {
    constructor(base, altura) {
        super(base, altura, base, altura);
    }
    
    get base() {
        return this.lados[0];
    }
    
    get altura() {
        return this.lados[1];
    }
    
    calcularArea() {
        return this.base * this.altura;
    }
    
    toString() {
        return `Retângulo de base ${this.base} e altura ${this.altura}:\n` +
               `\tPerímetro = ${this.calcularPerimetro()}\n` +
               `\tÁrea = ${this.calcularArea()}\n`;   
    }
}

class Quadrado extends Retangulo {
    constructor(lado) {
        super(lado, lado);
    }
    
    get lado() {
        return this.lados[0];
    }
    
    toString() {
        return `Quadrado de lado ${this.lado}:\n` +
               `\tPerímetro = ${this.calcularPerimetro()}\n` +
               `\tÁrea = ${this.calcularArea()}\n`;   
    }
}

class Circulo extends Forma {
    constructor(raio) {
        super();
        this.raio = raio;
    }
    
    calcularPerimetro() {
        return 2 * Math.PI * this.raio;
    }
    
    calcularArea() {
        return Math.PI * this.raio * this.raio;
    }
    
    toString() {
        return `Círculo de raio ${this.raio}:\n` +
               `\tPerímetro = ${this.calcularPerimetro()}\n` +
               `\tÁrea = ${this.calcularArea()}\n`;   
    }
}

let formas = [];
formas.push( new Quadrado(4.0) );
formas.push( new Retangulo(2.5, 6.0) );
formas.push( new Circulo(3.0) );
formas.forEach( forma => console.log(forma) );
