#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../calc-sintaxis.tab.h"
#include "../libraries/tree.h"
#define MAX_QUEUE_SIZE 100

// Función para crear un nuevo nodo
TData* newData(Token token, Type type, int value, char* name) {
    TData *newData = (TData*)malloc(sizeof(TData)); 
    newData->token = token;
    newData->type = type;
    newData->name = (char*)malloc(sizeof(char) * strlen(name) + 1);
    strcpy(newData->name, name);
    newData->value = value;
    return newData;
}

Tree* newTree(TData *data, Tree *leftChild, Tree *rightChild) {
    Tree *tree = (Tree*)malloc(sizeof(Tree));
    tree->info = data;
    tree->hi = leftChild;
    tree->hd = rightChild; 
    return tree;
}

void printBranch(int level, bool isLast[]) {
    for (int i = 0; i < level; i++) {
        printf("    ");  // Simula una rama a la izquierda
    }
}
void auxiliarPrintInfo(Tree *tree, int level, bool isLast[]) {
    printBranch(level - 1, isLast);
    if (level > 0) {
        if (isLast[level - 1]) {
            printf("└── ");  // Si es el último hijo
        } else {
            printf("├── ");  // Si no es el último hijo
        }
    }
    // Mostrar información del nodo
    if (tree->info->token == T_YYUNDEF) {
        printf("UNDEF");
    } else if (tree->info->token == T_INTV) {
        printf("INTEGER");
    } else if (tree->info->token == T_DECL) {
        printf("DECL");
    } else if (tree->info->token == T_RET) {
        printf("RETURN");
    } else if (tree->info->token == T_VOID) {
        printf("VOID");
    } else if (tree->info->token == T_MAIN) {
        printf("MAIN");
    } else if (tree->info->token == T_TRUE) {
        printf("TRUE");
    } else if (tree->info->token == T_FAL) {
        printf("FALSE");
    } else if (tree->info->token == T_ID) {
        printf("ID");
    } else if (tree->info->token == T_MENOR) {
        printf("LESS");
    } else if (tree->info->token == T_MAYOR) {
        printf("MORE");
    } else if (tree->info->token == T_IGUAL) {
        printf("EQUALS");
    } else if (tree->info->token == T_MENOS) {
        printf("MINUS");
    } else if (tree->info->token == T_MAS) {
        printf("PLUS");
    } else if (tree->info->token == T_MULT) {
        printf("PRODUCT");
    } else if (tree->info->token == T_DIV) {
        printf("DIVITION");
    } else if (tree->info->token == T_MOD) {
        printf("MODULE");
    } else if (tree->info->token == T_ASIGN) {
        printf("ASIGN");
    } else if (tree->info->token == T_PROGRAM) {
        printf("PROGRAM");
    } else if (tree->info->token == T_OR) {
        printf("OR");
    } else if (tree->info->token == T_NEG) {
        printf("NEGATION");
    } else if (tree->info->token == T_AND) {
        printf("AND");
    } else if (tree->info->token == T_EXTERN) {
        printf("EXTERN");
    } else if (tree->info->token == T_WHILE) {
        printf("WHILE");
    } else if (tree->info->token == T_IF) {
        printf("IF");
    } else if (tree->info->token == T_THEN) {
        printf("THEN");
    } else if (tree->info->token == T_ELSE) {
        printf("ELSE");
    } else if (tree->info->token == T_BOOL) {
        printf("BOOL");
    } else if (tree->info->token == T_INT) {
        printf("INT");
    } else if (tree->info->token == T_UMINUS) {
        printf("UMINUS");
    }
    if(tree->info->type == INTEGER){
        printf(" - Type: INTEGER");
    } else if(tree->info->type == BOOL){
        printf("- Type: BOOL");
    } else if(tree->info->type == VOID) {
        printf("- Type: VOID");
    } else {
        printf(" - NO TYPE");
    }
    printf(" (%s, %d)\n", tree->info->name, tree->info->value);
}

// Función bfs que respeta el formato tree
void printTree(Tree *root) {
    Queue q;
    q.front = -1;
    q.rear = -1;
    // Arreglo auxiliar para llevar el seguimiento de los nodos que son últimos
    bool isLast[MAX_QUEUE_SIZE][MAX_QUEUE_SIZE] = {false};
    // Encolar el nodo raíz con level 0 y marcando que es el único y último
    enqueue(&q, root);
    int actualLevel[MAX_QUEUE_SIZE] = {0};
    isLast[0][0] = true;
    while (!is_empty(&q)) {
        Tree *actualNode = dequeue(&q);
        int level = actualLevel[q.front];
        // Mostrar la información del nodo
        auxiliarPrintInfo(actualNode, level, isLast[q.front]);
        // Encolar los hijos
        if (actualNode->hi != NULL) {
            enqueue(&q, actualNode->hi);
            actualLevel[q.rear] = level + 1;
            isLast[q.rear][level] = actualNode->hd == NULL;  // Si no hay hijo derecho, es el último
        }
        if (actualNode->hd != NULL) {
            enqueue(&q, actualNode->hd);
            actualLevel[q.rear] = level + 1;
            isLast[q.rear][level] = true;  // El hijo derecho siempre es el último
        }
    }
}

void enqueue (Queue *q, Tree *item) {
  if (q->rear == MAX_QUEUE_SIZE - 1) {
      printf ("Queue Overflow\n");
      exit (EXIT_FAILURE);
    }
  q->rear++;
  q->items[q->rear] = item;
}

Tree* dequeue (Queue *q) {
    if (q->front == q->rear) {
        printf ("Queue Underflow\n");
        exit (EXIT_FAILURE);
    }
    q->front++;
    return q->items[q->front];
}
int is_empty (Queue *q) {
    return q->front == q->rear;
}
