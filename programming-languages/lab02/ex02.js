class Complex {
    constructor(real, imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    static add(Im1, Im2) {
        const real = Im1.real + Im2.real;
        const imaginary = Im1.imaginary + Im2.imaginary;

        const complex = new Complex(real, imaginary);
        return complex;
    }

    static multiply(Im1, Im2) {
        const real = Im1.real * Im2.real;
        const imaginary = Im1.imaginary * Im2.imaginary;

        const complex = new Complex(real, imaginary);
        return complex;
    }

    getReal() {
        return this.real;
    }

    getImaginary() {
        return this.imaginary;
    }

    setReal(real) {
        this.real = real;
    }

    setImaginary(imaginary) {
        this.imaginary = imaginary;
    }

    toString() {
        return `${this.real} + ${this.imaginary}i`;
    }
}

const complex1 = new Complex(2, 30);

const complex2 = new Complex(5, 2);

const soma = Complex.multiply(complex1, complex2);

console.log(soma.toString());

console.log(complex1.getImaginary());

console.log(complex2.imaginary);