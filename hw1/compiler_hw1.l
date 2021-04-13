/* Definition section */
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define YY_NO_UNPUT
    #define YY_NO_INPUT

    int line_num = 1;
    int comment_num = 0;
%}

%START CMT
/* Define regular expression label */
letter [a-zA-Z_]
digit [0-9]
cmt "/*"|"*/"
int "int"
float "float"
bool "bool"
string "string"
true "true"
false "false"
cpp_cmt "//"[^\n]*
c_cmt "/*"([^*]|\*+[^*/])*\*+"/"
id {letter}+({letter}|{digit})*
strlit "\""(("\\"+"\"")|[^"])*"\""
inumber {digit}+
fnumber ({digit}*\.{digit}+)
and "&&"
or "||"
inc "++"
dec "--"
assign "="
add_imme "+="
sub_imme "-="
mul_imme "*="
quo_imme "/="
rem_imme "%="
bigger ">"
smaller "<"
big_eql ">="
small_eql "<="
equal "=="
nequal "!="
if "if"
else "else"
print "print"
for "for"
while "while"
break "break"
return "return"
void "void"
continue "continue"

/* Rules section */

%%

{cpp_cmt}   { printf("%-8s \t %s\n", yytext, "C++ Comment"); comment_num++; }
{c_cmt}     { int cur = 0, pre = 0;
              while(1)
              {
                  if(!yytext[cur] || yytext[cur] == '\n')
                  {
                      comment_num++;
                      char s[cur - pre + 20];
                      for(int i = 0; i < cur - pre + 20; i++)
                          s[i] = '\0';
                      for(int i = pre; i < cur; i++)
                          s[i - pre] = yytext[i];
                      strcat(s, " \t ");
                      strcat(s, "C Comment");
                      printf("%-8s\n", s);
                      pre = cur + 1;
                      if(!yytext[cur])
                          break;
                      else
                          line_num++;
                  }
                  cur++;
              } }
"+"         { printf("%-8s \t %s\n", yytext, "ADD"); }
"-"         { printf("%-8s \t %s\n", yytext, "SUB"); }
"/"         { printf("%-8s \t %s\n", yytext, "QUO"); }
"*"         { printf("%-8s \t %s\n", yytext, "MUL"); }
{int}       { printf("%-8s \t %s\n", yytext, "INT"); }
{float}     { printf("%-8s \t %s\n", yytext, "FLOAT"); }
{bool}      { printf("%-8s \t %s\n", yytext, "BOOL"); }
{string}    { printf("%-8s \t %s\n", yytext, "STRING"); }
{true}      { printf("%-8s \t %s\n", yytext, "TRUE"); }
{false}     { printf("%-8s \t %s\n", yytext, "FALSE"); }
{if}        { printf("%-8s \t %s\n", yytext, "IF"); }
{else}      { printf("%-8s \t %s\n", yytext, "ELSE"); }
{print}     { printf("%-8s \t %s\n", yytext, "PRINT"); }
{for}       { printf("%-8s \t %s\n", yytext, "FOR"); }
{while}     { printf("%-8s \t %s\n", yytext, "WHILE"); }
{break}     { printf("%-8s \t %s\n", yytext, "BREAK"); }
{return}    { printf("%-8s \t %s\n", yytext, "RETURN"); }
{void}      { printf("%-8s \t %s\n", yytext, "VOID"); }
{continue}  { printf("%-8s \t %s\n", yytext, "CONTINUE"); }
{id}        { printf("%-8s \t %s\n", yytext, "IDENT"); }
{strlit}    { printf("%-8s \t %s\n", "\"", "QUOTA");
              char s[strlen(yytext)];
              for(int i = 1; i < strlen(yytext); i++)
                  s[i - 1] = yytext[i];
              s[strlen(yytext) - 2] = '\0';
              printf("%-8s \t %s\n", s, "STRING_LIT");
              printf("%-8s \t %s\n", "\"", "QUOTA");
            }
{inumber}   { printf("%-8s \t %s\n", yytext, "INT_LIT"); }
{fnumber}   { printf("%-8s \t %s\n", yytext, "FLOAT_LIT"); }
";"         { printf("%-8s \t %s\n", yytext, "SEMICOLON"); }
","         { printf("%-8s \t %s\n", yytext, "COMMA"); }
"%"         { printf("%-8s \t %s\n", yytext, "REM"); }
{and}       { printf("%-8s \t %s\n", yytext, "AND"); }
{or}        { printf("%-8s \t %s\n", yytext, "OR"); }
{inc}       { printf("%-8s \t %s\n", yytext, "INC"); }
{dec}       { printf("%-8s \t %s\n", yytext, "DEC"); }
"!"         { printf("%-8s \t %s\n", yytext, "NOT"); }
"("         { printf("%-8s \t %s\n", yytext, "LPAREN"); }
")"         { printf("%-8s \t %s\n", yytext, "RPAREN"); }
"{"         { printf("%-8s \t %s\n", yytext, "LBRACE"); }
"}"         { printf("%-8s \t %s\n", yytext, "RBRACE"); }
{assign}    { printf("%-8s \t %s\n", yytext, "ASSIGN"); }
{add_imme}  { printf("%-8s \t %s\n", yytext, "ADD_ASSIGN"); }
{sub_imme}  { printf("%-8s \t %s\n", yytext, "SUB_ASSIGN"); }
{mul_imme}  { printf("%-8s \t %s\n", yytext, "MUL_ASSIGN"); }
{quo_imme}  { printf("%-8s \t %s\n", yytext, "QUO_ASSIGN"); }
{rem_imme}  { printf("%-8s \t %s\n", yytext, "REM_ASSIGN"); }
{bigger}    { printf("%-8s \t %s\n", yytext, "GTR"); }
{smaller}   { printf("%-8s \t %s\n", yytext, "LSS"); }
{big_eql}   { printf("%-8s \t %s\n", yytext, "GEQ"); }
{small_eql} { printf("%-8s \t %s\n", yytext, "LEQ"); }
{equal}     { printf("%-8s \t %s\n", yytext, "EQL"); }
{nequal}    { printf("%-8s \t %s\n", yytext, "NEQ"); }
[\n]        { line_num++; }
[" ""\t"]      { ;}

<<EOF>>     { yyterminate(); }


%%
/*  C Code section */
/*
{strlit}    { if(is_cmt || is_pcmt)
                  REJECT
              else
                  printf("%-8s \t %s\n", yytext, "STRING_LIT"); }
"\""        { printf("%-8s \t %s\n", yytext, "QUOTA");
              if(is_str == '\"')
                  is_str = '\0';
              else
                  is_str = '\"'; }
*/

int yywrap(void)
{
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    yylex();
    printf("\nFinish scanning,\n");
    printf("total line: %d\n", line_num);
    printf("comment line: %d\n", comment_num);
    fclose(yyin);
    return 0;
}
