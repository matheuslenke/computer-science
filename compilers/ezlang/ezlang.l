%{ /* EZLang */
  #include <stdio.h>
  #include <ctype.h>
%}
%option yylineno

ignore      [ \t\n]+
comment    \{[^}]*\}
ID [a-zA-Z][a-zA-Z0-9]*

%%
{ignore} { }
{comment} { }

"program"    { printf("%d: %s -> PROGRAM\n", yylineno, yytext); }
"begin"    { printf("%d: %s -> BEGIN\n", yylineno, yytext); } 
"then"    { printf("%d: %s -> THEN\n", yylineno, yytext); }
"var"     { printf("%d: %s -> VAR\n", yylineno, yytext); }
"int"     { printf("%d: %s -> INT\n", yylineno, yytext); }
";"       { printf("%d: %s -> SEMI\n", yylineno, yytext);}
"read"    { printf("%d: %s -> READ\n", yylineno, yytext); }
"repeat"    { printf("%d: %s -> REPEAT\n", yylineno, yytext); }
"if"      { printf("%d: %s -> IF\n", yylineno, yytext); }
"until"      { printf("%d: %s -> UNTIL\n", yylineno, yytext); }
"write"      { printf("%d: %s -> WRITE\n", yylineno, yytext); }
"end"      { printf("%d: %s -> END\n", yylineno, yytext); }
[0-9]+  { printf("%d: %s -> INT_VAL\n", yylineno, yytext); }
{ID}      { printf("%d: %s -> ID\n", yylineno, yytext); }

":="      { printf("%d: %s -> ASSIGN\n", yylineno, yytext); }
"= "      { printf("%d: %s -> EQ\n", yylineno, yytext); }
"<"       { printf("%d: %s -> LT\n", yylineno, yytext); }
"+"       { printf("%d: %s -> PLUS\n", yylineno, yytext); }
"-"       { printf("%d: %s -> MINUS\n", yylineno, yytext); }
"*"       { printf("%d: %s -> TIMES\n", yylineno, yytext); }
"/"       { printf("%d: %s -> BAR\n", yylineno, yytext); }
"("       { printf("%d: %s -> SYMBOL\n", yylineno, yytext); }
")"       { printf("%d: %s -> SYMBOL\n", yylineno, yytext); }
";"       { printf("%d: %s -> SEMI\n", yylineno, yytext); }
.        { printf("LEXICAL ERROR (%d): Unknown symbol %s\n", yylineno, yytext);
              exit(EXIT_FAILURE); }
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