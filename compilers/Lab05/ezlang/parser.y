%output "parser.c"
%defines "parser.h"
%define parse.error verbose // Give proper messages when a syntax error is found.
%define parse.lac full      // Enable LAC to improve syntax error handling.

%{
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "parser.h"
#include "tables.h"

int yylex(void);
// Primitive error handling.
int yylex_destroy(void);
void yyerror (char const *s);

void new_var();
Type check_var();

Type unify_bin_op(Type l, Type r,
                  const char* op, Type (*unify)(Type,Type));

void check_assign(Type l, Type r);
void check_bool_expr(const char* cmd, Type t);

extern char *yytext;
extern int yylineno;
extern StrTable* stringsTable;
extern VarTable* variablesTable;
Type type;
char* id;
%}


%define api.value.type { AST* } 
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

type-spec: 
  BOOL   {  type = BOOL_TYPE;  } 
| INT    {  type = INT_TYPE;   }
| REAL   {  type = REAL_TYPE;  } 
| STRING {  type = STR_TYPE;   };

stmt-sect: START stmt-list END

stmt-list: stmt | stmt-list stmt 

stmt: 
  ifstmt 
| repeat-stmt 
| assign-stmt 
| read-stmt 
| write-stmt

assign-stmt: 
  ID { $1 = check_var(); } ASSIGN expr SEMI { check_assign($1, $4); }
;

ifstmt: 
  IF expr THEN stmt-list END                  { check_bool_expr("if", $2);  }
| IF expr THEN stmt-list ELSE stmt-list END   { check_bool_expr("if", $2);  }

read-stmt: 
  READ ID { check_var(); } SEMI
;

repeat-stmt: 
  REPEAT stmt-list UNTIL expr { check_bool_expr("repeat", $4);  }
;

write-stmt:
  WRITE expr SEMI
;

expr:
  expr LT expr     { $$ = unify_bin_op($1, $3, "<", unify_comp); }
| expr EQ expr     { $$ = unify_bin_op($1, $3, "=", unify_comp); }
| expr PLUS expr   { $$ = unify_bin_op($1, $3, "+", unify_plus); }
| expr MINUS expr  { $$ = unify_bin_op($1, $3, "-", unify_other_arith); }
| expr TIMES expr  { $$ = unify_bin_op($1, $3, "*", unify_other_arith); }
| expr OVER expr   { $$ = unify_bin_op($1, $3, "/", unify_other_arith); }
| LPAR expr RPAR   { $$ = $2; }
| TRUE             { $$ = BOOL_TYPE;  }
| FALSE            { $$ = BOOL_TYPE;  }
| INT_VAL          { $$ = INT_TYPE;   }
| REAL_VAL         { $$ = REAL_TYPE;  }
| STR_VAL          { $$ = STR_TYPE;   }
| ID               { $$ = check_var(); }
;

%%

Type check_var() {
  int index = lookup_var(variablesTable, yytext);
  if (index == -1) {
            printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n",
                yylineno, yytext);
        exit(EXIT_FAILURE);
  }
  return get_type(variablesTable, index);
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

// ----------------------------------------------------------------------------

// Type checking and inference.

void type_error(const char* op, Type t1, Type t2) {
    printf("SEMANTIC ERROR (%d): incompatible types for operator '%s', LHS is '%s' and RHS is '%s'.\n",
           yylineno, op, get_text(t1), get_text(t2));
    exit(EXIT_FAILURE);
}

Type unify_bin_op(Type l, Type r,
                  const char* op, Type (*unify)(Type,Type)) {
    Type unif = unify(l, r);
    if (unif == NO_TYPE) {
        type_error(op, l, r);
    }
    return unif;
}

void check_assign(Type l, Type r) {
    if (l == BOOL_TYPE && r != BOOL_TYPE) type_error(":=", l, r);
    if (l == STR_TYPE  && r != STR_TYPE)  type_error(":=", l, r);
    if (l == INT_TYPE  && r != INT_TYPE)  type_error(":=", l, r);
    if (l == REAL_TYPE && !(r == INT_TYPE || r == REAL_TYPE)) type_error(":=", l, r);
}

void check_bool_expr(const char* cmd, Type t) {
    if (t != BOOL_TYPE) {
        printf("SEMANTIC ERROR (%d): conditional expression in '%s' is '%s' instead of '%s'.\n",
           yylineno, cmd, get_text(t), get_text(BOOL_TYPE));
        exit(EXIT_FAILURE);
    }
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

    print_str_table(stringsTable); printf("\n\n");
    print_var_table(variablesTable);printf("\n\n");

    free_str_table(stringsTable);
    free_var_table(variablesTable);
    yylex_destroy();

    return 0;
}

