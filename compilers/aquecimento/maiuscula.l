%{ /* Reconhece e troca maiúsculas */
  #include <stdio.h>
  #include <ctype.h>
%}

%%
[A-Z]       { putchar(tolower(*yytext)); } 
%%

int main() {
  yylex();
  return 0;
}

/* Definindo esta funcao nao precisa compilar com -lfl */
int yywrap() {
  return 1;
}