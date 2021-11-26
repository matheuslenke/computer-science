%option outfile="scanner.c"
%option noyywrap
%option nounput
%option noinput
%{
#include "parser.h" // For the token types from bison.
%}
%%
a  { yylval = atoi(yytext); return STRING; }
"("     { return LEFT_PARENTHESIS; }
")"     { return RIGHT_PARENTHESIS; }
"\n"    { return ENTER; }
" "     { /* ignore spaces */ }
.       { printf("LEXICAL ERROR: Unknown symbol %s\n", yytext);
          exit(EXIT_FAILURE); }
