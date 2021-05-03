/*	Definition section */
%{
    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }


    /* Symbol table function - you can add new function if needed. */
    static void create_symbol(/* ... */);
    static void insert_symbol(char *);
    static int lookup_symbol(char *);
    static void dump_symbol(/* ... */);

    int declare = 0;
    int scope_level = -1;
    int addr = 0;
    int top = -1;
    char type[10];
    char sign[100];
    table *tb_stack[10];
%}

%define parse.error verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    /* ... */
}

/* Token without return */
%token INT FLOAT BOOL STRING
%token SEMICOLON
%token  Block IfStmt LoopStmt
%token PRINT 
%token INC DEC
%token BIG_EQU SMALL_EQU EQUAL NOT_EQUAL
%token AND OR
%token TRUE FALSE

/* Token with return, which need to specify type */
%token <i_val> INT_LIT 
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <s_val> IDENT

/* Nonterminal with return, which need to sepcify type */

/* Yacc will start at this nonterminal */
%start Program


/* Grammar section */
%%

Program
    : NewScope StatementList EndScope
;

StatementList
    : Statement ';' StatementList
    | Statement ';'
;

Statement
    : DeclarationStmt 
    | Expr
    | Block
    | IfStmt
    | LoopStmt
    | PrintStmt
;

NewScope
    : { create_symbol(); }
;

EndScope
    : { dump_symbol(); }
;

DeclarationStmt
    : Type Ident LitInit
;

Type
    : TypeName { /*$1 = $$;*/
                 declare = 1; }
;

TypeName
    : INT { strcpy(type, "int"); } 
    | FLOAT { strcpy(type, "float"); }
    | STRING { strcpy(type, "string"); }
    | BOOL { strcpy(type, "bool"); }
;

Ident
    : IDENT { if(declare)
              {
                  insert_symbol($<s_val>$);
                  printf("> Insert {%s} into symbol table (scope level: %d)\n", $<s_val>$, scope_level); 
                  declare = 0;
              }
              else
              {
                  int ad = lookup_symbol($<s_val>$);
                  if(ad == -1)
                      printf("error\n");
                  else
                      printf("IDENT (name=%s, address=%d)\n", $<s_val>$, ad);
              }
            }
;

LitInit
    : '=' Literal {}
    |
;

Literal
    : INT_LIT {
        printf("INT_LIT %d\n", $<i_val>$);
    }
    | FLOAT_LIT {
        printf("FLOAT_LIT %f\n", $<f_val>$);
    }
;

Expr
    : AndExpr OR Expr { printf("OR\n"); }
    | AndExpr
;

AndExpr
    : CmprExpr AND AndExpr { printf("AND\n"); }
    | CmprExpr
;

CmprExpr
    : CmprExpr '<' AddExpr { printf("LSS\n"); }
    | CmprExpr '>' AddExpr { printf("GTR\n"); }
    | CmprExpr SMALL_EQU AddExpr { printf("LEQ\n"); }
    | CmprExpr BIG_EQU AddExpr { printf("GEQ\n"); }
    | CmprExpr EQUAL AddExpr { printf("EQL\n"); }
    | CmprExpr NOT_EQUAL AddExpr { printf("NEQ\n"); }
    | AddExpr
;

AddExpr
    : MulExpr '+' AddExpr { printf("ADD\n"); }
    | MulExpr '-' AddExpr { printf("SUB\n"); }
    | MulExpr
;

MulExpr
    : UnaExpr '*' MulExpr { printf("MUL\n"); }
    | UnaExpr '/' MulExpr { printf("QUO\n"); }
    | UnaExpr '%' MulExpr { printf("REM\n"); }
    | UnaExpr
;

UnaExpr
    : SignOpt Atom { printf("%s", sign); }
    | Reverse Boolean { printf("%s", sign); }
;

SignOpt
    : '+' SignOpt { char s[100] = "POS\n";
                    strcat(s, sign);
                    strcpy(sign, s);
                  }
    | '-' SignOpt { char s[100] = "NEG\n";
                    strcat(s, sign);
                    strcpy(sign, s);
                  }
    | { strcpy(sign, ""); }
;

Reverse
    : '!' Reverse { strcat(sign, "NOT\n"); }
    | { strcpy(sign, ""); }
;

Atom
    : Ident
    | Literal
    | '(' Expr ')'
    | '[' Expr ']'
;

Boolean
    : TRUE { printf("TRUE\n"); }
    | FALSE { printf("FALSE\n"); }
;

PrintStmt
    : PRINT '(' Expr ')' { ;}
;


%%
/*
Expr
    : UnaryExpr ArithExpr
    | '(' Expr ')' ArithExpr
;

UnaryExpr
    : SignOpt Operand UnaryOptr
;

Operand
    : Ident
    | Literal
;

SignOpt
    : '+'
    | '-'
    | '!'
    |
;

UnaryOptr
    : INC { printf("INC\n"); }
    | DEC { printf("DEC\n"); }
    |
;

ArithExpr
    : AddExpr
    | MultiExpr
    | RemExpr
    |
;

AddExpr
    : '+' Expr { printf("ADD\n"); }
    | '-' Expr { printf("SUB\n"); }
;

MultiExpr
    : '*' Expr { printf("MUL\n"); }
    | '/' Expr { printf("QUO\n"); }
;

RemExpr
    : '%' Expr { printf("REM\n"); }
;


*/

/* C code section */
static void create_symbol(/* ... */)
{
    tb_stack[++top] = (table *)malloc(sizeof(table));
    tb_stack[top] -> scope_level = ++scope_level;
    tb_stack[top] -> top = -1;
}

static void insert_symbol(char *id)
{
    int t = ++tb_stack[top] -> top;
    tb_stack[top] -> stack[t] = (entry *)malloc(sizeof(entry));
    tb_stack[top] -> stack[t] -> addr = addr;
    tb_stack[top] -> stack[t] -> line = yylineno;
    strcpy(tb_stack[top] -> stack[t] -> id_name, id);
    strcpy(tb_stack[top] -> stack[t] -> type, type);
    addr++;
}

static int lookup_symbol(char *id)
{
    for(int i = top; i >= 0; i--)
        for(int j = 0; j <= tb_stack[i] -> top; j++)
            if(!strcmp(tb_stack[i] -> stack[j] -> id_name, id))
                return tb_stack[i] -> stack[j] -> addr;
    return -1;
}

static void dump_symbol(/* ... */)
{
    printf("> Dump symbol table (scope level: %d)\n", scope_level--);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n", "Index", "Name", "Type", "Address", "Lineno", "Element type");
    for(int i = 0; i <= tb_stack[top] -> top; i++)
    {
        entry *e = tb_stack[top] -> stack[i];
        printf("%-10d%-10s%-10s%-10d%-10d%s\n", i, e -> id_name, e -> type, e -> addr, e -> line, "-");
        free(e);
    }
    free(tb_stack[top]);
    top--;
}

int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    yyparse();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}
