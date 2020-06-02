%{

#include <stdio.h>
#include "bison.tab.h"

/*
enum tokenType {

	REG = 258,
	NUM = 259,
	ADD = 260,
	AND = 261,
	OR = 262,
	BEQ = 263,
	SL = 264,
	SR = 265,
	MOV = 266,
	J = 267,
	LB = 268,
	SB = 269,
	NL = 270

};
*/

int yylval;

int regToNum(const char * text);

%}


%%

\$[0-9]+	{ yylval = regToNum(yytext); return REG; }
[0-9]+		{ yylval = atoi(yytext); return NUM; }
"ADD" 		{ return ADD; }
"AND"		{ return AND; }
"OR"		{ return OR; }
"BEQ"		{ return BEQ; }
"SL"		{ return SL; }
"SR"		{ return SR; }
"MOV"		{ return MOV; }
"J"		{ return J; }

"LB"		{ return LB; }
"SB"		{ return SB; }

\n		{ return NL; }
[ \t]		{ }
.		{ printf("unknown\n"); }



%%

/*
int main(int argc, char **argv)
{
  int tok;

  while(tok = yylex()) {
    printf("%d", tok);
    if(tok == NUM) printf(" = %d\n", yylval);
    else if (tok == REG) printf ( " = $%d\n", yylval);
    else printf("\n");
  }
}
*/

// returns the register number of a regsiter token 
int regToNum(const char * text) {
	
	char temp[sizeof(text) - 1];
	for (int i = 1; i < sizeof(text); i++)
		temp[i-1] = text[i];

	return atoi(temp);
}



