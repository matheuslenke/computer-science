%{ /* Reconhece Número hexadecimal */
  #include <stdio.h>
  #include <ctype.h>
%}
digit [0-9a-fA-F] 
%%
0[xX]{digit}{0,8} { printf(" -> Hexadecimal");}
.*    { printf("-> Não é Hexadecimal"); } 
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