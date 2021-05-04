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
    static void precedence(char);
    static void print_optr(char);
    static void new_expr();

    int declare = 0;
    int scope_level = -1;
    int addr = 0;
    int top = -1;
    char type[10], printype[10];
    table *tb_stack[10];

    char sign[100];
    char ptable[2][13] = {{'|', '&', '<', '>', 'a', 'b', 'c', 'd', '+', '-', '*', '/', '%'},
                          {'0', '1', '2', '2', '2', '2', '2', '2', '3', '3', '4', '4', '4'}};
    estack *exprs;
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
    | Expr {  while(exprs -> top > -1)
                 print_optr(exprs -> stk[exprs -> top--]); }
    | Block
    | IfStmt
    | LoopStmt
    | PrintStmt
;

NewScope
    : { create_symbol();
        new_expr(); }
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
        strcpy(printype, "int");
    }
    | FLOAT_LIT {
        printf("FLOAT_LIT %f\n", $<f_val>$);
        strcpy(printype, "float");
    }
;


Expr
    : AndExpr or Expr
    | AndExpr
;

or
    : OR { precedence('|'); }
;

AndExpr
    : CmprExpr and AndExpr
    | CmprExpr
;

and
    : AND { precedence('&'); }
;

CmprExpr
    : CmprExpr Cmpr AddExpr 
    | AddExpr
;

Cmpr
    : '<' { precedence('<'); }
    | '>' { precedence('>'); }
    | SMALL_EQU { precedence('a'); }
    | BIG_EQU { precedence('b'); }
    | EQUAL { precedence('c'); }
    | NOT_EQUAL { precedence('d'); }
;

AddExpr
    : MulExpr Add AddExpr
    | MulExpr 
;

Add
    : '+' { precedence('+'); }
    | '-' { precedence('-'); }
;

MulExpr
    : UnaExpr Mul MulExpr 
    | UnaExpr 
;

Mul
    : '*' { precedence('*'); }
    | '/' { precedence('/'); }
    | '%' { precedence('%'); }
;

UnaExpr
    : SignOpt Atom { printf("%s", sign); strcpy(sign, ""); }
    | Reverse Boolean { printf("%s", sign); strcpy(sign, ""); strcpy(printype, "bool"); }
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
    |
;

Reverse
    : '!' Reverse { char s[100] = "NOT\n";
                    strcat(s, sign);
                    strcpy(sign, s); 
                  }   
    | 
;

Atom
    : Ident
    | Ident OneArith
    | OneArith Ident
    | Literal
    | BracExpr Expr BracExpr
    | '[' Expr ']'
;

OneArith
    : INC { printf("INC\n"); }
    | DEC { printf("DEC\n"); }
;

Boolean
    : TRUE { printf("TRUE\n"); }
    | FALSE { printf("FALSE\n"); }
;

PrintStmt
    : PRINT '(' Expr LeavePrint { printf("PRINT %s\n", printype); }
;

LeavePrint
    : ')' { while(exprs -> top > -1)                                                      
                 print_optr(exprs -> stk[exprs -> top--]); }
;

BracExpr
    : '(' { new_expr(); }
    | ')' { estack * p = exprs;
            exprs = exprs -> next;
            while(p -> top > -1)
                print_optr(p -> stk[p -> top--]);
            free(p); }
;

%%

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

void new_expr()
{
    estack *p = (estack *)malloc(sizeof(estack));
    memset(p -> stk, '\0', 100);
    p -> top = -1;
    p -> next = exprs;
    exprs = p;
}

void precedence(char c)
{
    if(exprs -> top != -1)
    {
        int ci, i;
        for(int i = 0; i < 13; i++)
            if(c == ptable[0][i])
            {
                ci = ptable[1][i];
                break;
            }
        for(i = 12; ptable[1][i] >= ci; i--)
            if(exprs -> top > -1 && exprs -> stk[exprs -> top] == ptable[0][i])
            {
                print_optr(exprs -> stk[exprs -> top--]);
                i = 12;
            }
    }
    exprs -> stk[++exprs -> top] = c;
}

void print_optr(char optr)
{
    switch(optr)
    {
        case '|':
            printf("OR\n");
            break;
        case '&':
            printf("AND\n");
            break;
        case '<':
            printf("LSS\n");
            break;
        case '>':
            printf("GTR\n");
            break;
        case 'a':
            printf("LEQ\n");
            break;
        case 'b':
            printf("GEQ\n");
            break;
        case 'c':
            printf("EQL\n");
            break;
        case 'd':
            printf("NEQ\n");
            break;
        case '+':
            printf("ADD\n");
            break;
        case '-':
            printf("SUB\n");
            break;
        case '*':
            printf("MUL\n");
            break;
        case '/':
            printf("QUO\n");
            break;
        case '%':
            printf("REM\n");
    }

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
