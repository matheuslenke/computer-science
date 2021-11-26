%output "parser.c"
%defines "parser.h"
%define parse.error verbose // Give proper messages when a syntax error is found.
%define parse.lac full      // Enable LAC to improve syntax error handling.

%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

int yylex(void);
// Primitive error handling.
int yylex_destroy(void);
void yyerror (char const *s);

extern char *yytext;
extern int yylineno;
%}



%token PROGRAM ID SEMI BOOL INT REAL STRING START END IF THEN ELSE REPEAT ASSIGN READ LT EQ PLUS MINUS TIMES OVER TRUE FALSE INT_VAL STR_VAL VAR UNTIL WRITE LPAR RPAR REAL_VAL

%left LT EQ
%left PLUS MINUS
%left TIMES OVER

%start program

%%
program: PROGRAM ID SEMI vars-sect stmt-sect

vars-sect: VAR opt-var-decl

opt-var-decl: %empty | var-decl-list

var-decl-list: var-decl | var-decl-list var-decl 

var-decl: type-spec ID SEMI

type-spec: BOOL | INT | REAL | STRING

stmt-sect: START stmt-list END

stmt-list: stmt | stmt-list stmt 

stmt: 
  ifstmt 
| repeat-stmt 
| assign-stmt 
| read-stmt 
| write-stmt

assign-stmt: ID ASSIGN expr SEMI

ifstmt: IF expr THEN stmt-list END
| IF expr THEN stmt-list ELSE stmt-list END

read-stmt: READ ID SEMI

repeat-stmt: REPEAT stmt-list UNTIL expr


write-stmt: WRITE expr SEMI

expr:
  expr LT expr
| expr EQ expr
| expr PLUS expr
| expr MINUS expr
| expr TIMES expr
| expr OVER expr
| LPAR expr RPAR
| TRUE
| FALSE
| INT_VAL
| REAL_VAL
| STR_VAL
| ID
;

%%

// Primitive error handling.
void yyerror (char const *s) {
    printf("SYNTAX ERROR (%d): %s\n", yylineno, s);
    exit(EXIT_FAILURE);
}

int main(void) {
    yyparse(); 
    printf("PARSE SUCCESSFUL! ");
    yylex_destroy();
    return 0;
}

