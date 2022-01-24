%option outfile="scanner.c"
%option noyywrap
%option nounput
%option noinput
%option yylineno

%{
#include "parser.h" // For the token types from bison.
#include "tables.h"
StrTable* stringsTable;
VarTable* variablesTable;
%}

ignore      [ \t\n]+
comment    \{[^}]*\}
ID [a-zA-Z][a-zA-Z0-9]*
real_val [0-9]+"."[0-9]+ 
str_val  \"[^"]*\"
%%

{ignore} { }
{comment} { }

"begin"     { return START; }
"bool"      { return BOOL; }
"else"      { return ELSE; }
"end"      { return END; }
"false"     {return FALSE; }
"if"      { return IF; }
"int"     { return INT; }
"program"    { return PROGRAM; }
"read"    { return READ; }
"real"      { return REAL; }
"repeat"    { return REPEAT; }
"string"    { return STRING; }
"then"    { return THEN; }
"true"      { return TRUE; }
"until"      { return UNTIL; }
"var"     { return VAR; }
"write"      { return WRITE; }

";"       { return SEMI;}
":="      { return ASSIGN; }
"="      { return EQ; }
"<"       { return LT; }
"+"       { return PLUS; }
"-"       { return MINUS; }
"*"       { return TIMES; }
"/"       { return OVER; }
"("       { return LPAR; }
")"       { return RPAR; }

[0-9]+  { return INT_VAL; }
{real_val}     {return REAL_VAL;}
{str_val}    { add_string(stringsTable, strdup(yytext));  return STR_VAL; }
{ID}      { return ID; }

.       { printf("LEXICAL ERROR (%d): Unknown symbol %s\n", yylineno , yytext);
          exit(EXIT_FAILURE); }

%%