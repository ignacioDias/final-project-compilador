#ifndef TREE_H
#define TREE_H
#define MAX_QUEUE_SIZE 100

#include <stdbool.h>

// Enumeración para operadores
typedef enum Token {
    YYUNDEF = 257,                 /* "invalid token"  */
    INTV = 258,                    /* INTV  */
    TRET = 259,                    /* TRET  */
    TDECL = 260,                   /* TDECL  */
    TVOID = 261,                   /* TVOID  */
    TMAIN = 262,                   /* TMAIN  */
    TR = 263,                      /* TR  */
    FAL = 264,                     /* FAL  */
    TID = 265,                     /* TID  */
    TMENOR = 266,                  /* TMENOR  */
    TMAYOR = 267,                  /* TMAYOR  */
    TIGUAL = 268,                  /* TIGUAL  */
    TMENOS = 269,                  /* TMENOS  */
    TMAS = 270,                    /* TMAS  */
    TMULT = 271,                   /* TMULT  */
    TDIV = 272,                    /* TDIV  */
    TMOD = 273,                    /* TMOD  */
    TOR = 274,                     /* TOR  */
    TNEG = 275,                    /* TNEG  */
    TAND = 276,                    /* TAND  */
    EXTERN = 277,                  /* EXTERN  */
    TWHILE = 278,                  /* TWHILE  */
    TIF = 279,                     /* TIF  */
    THEN = 280,                    /* THEN  */
    TELSE = 281,                   /* TELSE  */
    TTYPE = 282,                   /* TTYPE  */
    UMINUS = 283    
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

TData * newData(Token id, Type type, int val, char* nom);
Tree * newTree(TData *data, Tree *leftChild, Tree *rightChild);
void enqueue (Queue * q, Tree * item);
int is_empty (Queue * q);
Tree *dequeue (Queue * q);
void printTree (Tree * root);
void auxiliarPrintInfo(Tree *tree, int level, bool isLast[]);
void printBranch(int level, bool isLast[]);
#endif