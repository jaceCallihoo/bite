%{

#include <stdio.h>

#define NUMREG 10

char reg[NUMREG] = {0};



void printReg() {

	for (int i = 0; i < NUMREG; i++) {
		printf("%d ", reg[i]);
	}

}

%}

%token REG
%token NUM
%token ADD AND OR BEQ SL SR J MOV LW SW
%token EOL

%%

code: 
    | code line EOL { printReg(); }
    ;

line: 
    | ADD REG val val { reg[$2] = $3 + $4; }

val: NUM
   | REG { $$ = reg[$1]; }


%%

void main()
{
  yyparse();
}

int yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}

