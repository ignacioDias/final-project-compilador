#ifndef TREE_H
#define TREE_H
#define MAX_QUEUE_SIZE 100

#include <stdbool.h>

// Enumeración para operadores
typedef enum Token {
    T_YYUNDEF = 257,                 /* "invalid token"  */
    T_INTV = 258,                    /* INTV  */
    T_RET = 259,                    /* TRET  */
    T_DECL = 260,                   /* TDECL  */
    T_VOID = 261,                   /* TVOID  */
    T_MAIN = 262,                   /* TMAIN  */
    T_TRUE = 263,                      /* TR  */
    T_FAL = 264,                     /* FAL  */
    T_ID = 265,                     /* TID  */
    T_MENOR = 266,                  /* TMENOR  */
    T_MAYOR = 267,                  /* TMAYOR  */
    T_IGUAL = 268,                  /* TIGUAL  */
    T_MENOS = 269,                  /* TMENOS  */
    T_MAS = 270,                    /* TMAS  */
    T_MULT = 271,                   /* TMULT  */
    T_DIV = 272,                    /* TDIV  */
    T_MOD = 273,                    /* TMOD  */
    T_OR = 274,                     /* TOR  */
    T_NEG = 275,                    /* TNEG  */
    T_AND = 276,                    /* TAND  */
    T_EXTERN = 277,                  /* EXTERN  */
    T_WHILE = 278,                  /* TWHILE  */
    T_IF = 279,                     /* TIF  */
    T_THEN = 280,                    /* THEN  */
    T_ELSE = 281,                   /* TELSE  */
    T_INT = 282,                   /* TINT  */
    T_BOOL = 283,                  /* TBOOL  */
    T_ASIGN = 284,                   /* TASIGN  */
    T_PROGRAM = 285,                /* TPROGRAM */
    T_UMINUS = 286,
    T_FUNCTION = 287,
    T_METHODCALL = 288
} Token;

typedef enum Type {
    NO_TYPE,
    VOID,
    INTEGER,
    BOOL
} Type;
// Definición de la estructura TData
typedef struct {
    Token token;
    int value;
    char *name;
    Type type;
} TData;

// Definición de la estructura Tree
typedef struct BT {
    TData *info;
    struct BT *hi;
    struct BT *hd;
} Tree;

typedef struct Queue {
  Tree *items[MAX_QUEUE_SIZE];
  int front;
  int rear;
} Queue;


TData* newData(Token id, Type type, int val, char* nom);
Tree* newTree(TData *data, Tree *leftChild, Tree *rightChild);
void enqueue (Queue *q, Tree *item);
int is_empty (Queue *q);
Tree* dequeue (Queue *q);
void printTree (Tree *root);
void auxiliarPrintInfo(Tree *tree, int level, bool isLast[]);
void printBranch(int level, bool isLast[]);
#endif