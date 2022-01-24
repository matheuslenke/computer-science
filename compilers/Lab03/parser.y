%output "parser.c"
%defines "parser.h"
%define parse.error verbose // Give proper messages when a syntax error is found.
%define parse.lac full      // Enable LAC to improve syntax error handling.

%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "tables.h"
#include "types.h"

int yylex(void);
// Primitive error handling.
int yylex_destroy(void);
void yyerror (char const *s);

void new_var();
void check_var();

extern char *yytext;
extern int yylineno;
extern StrTable* stringsTable;
extern VarTable* variablesTable;
Type type;
char* id;
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

var-decl: type-spec ID { new_var(); } SEMI

type-spec: BOOL { type = BOOL_TYPE; } 
| INT { type = INT_TYPE; }
| REAL { type = REAL_TYPE; } 
| STRING { type = STR_TYPE; };

stmt-sect: START stmt-list END

stmt-list: stmt | stmt-list stmt 

stmt: 
  ifstmt 
| repeat-stmt 
| assign-stmt 
| read-stmt 
| write-stmt

assign-stmt: ID { check_var(); } ASSIGN expr SEMI

ifstmt: IF expr THEN stmt-list END
| IF expr THEN stmt-list ELSE stmt-list END

read-stmt: READ ID { check_var(); } SEMI

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
| ID { check_var(); }
;

%%

void check_var() {
  int index = lookup_var(variablesTable, yytext);
  if (index == -1) {
            printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n",
                yylineno, yytext);
        exit(EXIT_FAILURE);
  }
}

void new_var() {
  int index = lookup_var(variablesTable, yytext);
  if (index != -1) {
        printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n",
                yylineno, yytext, get_line(variablesTable, index));
        exit(EXIT_FAILURE);
  }
  add_var(variablesTable, yytext , yylineno, type);
}

// Primitive error handling.
void yyerror (char const *s) {
    printf("SYNTAX ERROR (%d): %s\n", yylineno, s);
    exit(EXIT_FAILURE);
}

int main(void) {
    stringsTable = create_str_table();
    variablesTable = create_var_table();
    yyparse(); 
    printf("PARSE SUCCESSFUL! \n\n\n");
    yylex_destroy();
    print_str_table(stringsTable);
    printf("\n\n");
    print_var_table(variablesTable);
    printf("\n\n");
    free_str_table(stringsTable);
    free_var_table(variablesTable);
    return 0;
}

