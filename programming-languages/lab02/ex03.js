class ContaCorrente {
    constructor() {
        this.saldo = 0;
    }

    getSaldo() {
        return this.saldo;
    }

    changeSaldo(value) {
        if(value < 0) {
            if(this.saldo + value < 0) {
                console.log("Não é possível o saldo ficar abaixo de 0!");
            } else {
                this.saldo = this.saldo + value;
            }
        } else if(value > 0) {
            this.saldo = this.saldo + value;
        }
    }
}

const minhaConta = new ContaCorrente();

minhaConta.changeSaldo(100);
console.log(minhaConta.getSaldo())
minhaConta.changeSaldo(-100);
console.log(minhaConta.getSaldo())
minhaConta.changeSaldo(-100);
console.log(minhaConta.getSaldo())

class ContaEspecial extends ContaCorrente {
    changeSaldo(value) {
        if(value < 0) {
            if(this.saldo + value < 0) {
                this.saldo = (this.saldo + value) * 1.01;
            } else {
                this.saldo = this.saldo + value;
            }
        } else if(value > 0) {
            this.saldo = this.saldo + value;
        }
    }
}

const minhaContaEspecial = new ContaEspecial();

minhaContaEspecial.changeSaldo(100);
console.log(minhaContaEspecial.getSaldo())
minhaContaEspecial.changeSaldo(-100);
console.log(minhaContaEspecial.getSaldo())
minhaContaEspecial.changeSaldo(-100);
console.log(minhaContaEspecial.getSaldo())