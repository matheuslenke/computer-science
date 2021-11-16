%{ /* Reconhece Número hexadecimal */
  #include <stdio.h>
  #include <ctype.h>
%}

%%
[A-Z]{3}\-[0-9]{4}     { ECHO; printf(" Placa reconhecido"); } 
.*                     { ECHO; printf(" Não é uma placa"); } 
<<EOF>> {printf("\n");return 0;}
%%

int main() {
  yylex();
  return 0;
}

/* Definindo esta funcao nao precisa compilar com -lfl */
int yywrap() {
  return 1;
}