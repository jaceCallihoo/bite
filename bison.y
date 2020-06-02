%{

#include <stdio.h>

#define NUMREG 10

int yyerror(char *s);
int yylex();

void printReg();


char reg[NUMREG] = {0};
unsigned char pc = 0;

%}

%token REG
%token NUM
%token ADD AND OR BEQ SL SR J MOV LB SB
%token NL
%token EOL

%%

code: 
    | code line NL { printReg(); }
    ;

line: 
    | ADD REG val val { reg[$2] = $3 + $4; }
    | AND REG val val { reg[$2] = $3 & $4; }
    | OR REG val val { reg[$2] = $3 | $4; }
    | BEQ val val val { if ($3 == $4) pc = $2; }
    | SL REG val val { reg[$2] = $3 << $4; }
    | SR REG val val { reg[$2] = $3 >> $4; }
    | J val { pc = $2; }
    | MOV REG val { reg[$2] = $3; }
    | LB REG val {  }
    | SB REG val {  }
    ;

val: NUM
   | REG { $$ = reg[$1]; }
   ;

%%

void main()
{
  yyparse();
}

int yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}


void printReg() {

        for (int i = 0; i < NUMREG; i++) {
                printf("%d ", reg[i]);
        }
        printf("\n\n");
}

