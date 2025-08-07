#include "../include/pseudo_assembly.h"
#include "../include/assembly_generator.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define DIRECTORY "outputs"

int globalContext = 0; 
AssemblyList* globalVariables; 
AssemblyList* linesOfCode;

void intialize() {
    globalVariables = NULL;
    linesOfCode = NULL;
}

void identifyGlobal(AssemblyList *pseudoProgram) { 
    if(!pseudoProgram || !pseudoProgram->info)
        return;
    
    switch((pseudoProgram->info)->op) {
        case ASIGN:
            if(!globalContext) {
                insertGlobal(pseudoProgram->info);
            }
            break;
        case FUN_DECL:
            if(!globalContext) {
                insertGlobal(pseudoProgram->info);
            }
            globalContext++;
            break;
        case END_FUNC:
            globalContext--;
            break;
        default:
            break;
    }
}

void insertGlobal(Triple *triple) {
    AssemblyList *newNode = malloc(sizeof(AssemblyList));
    newNode->info = triple;
    newNode->next = globalVariables;
    globalVariables = newNode;
}

void insertCode(Triple *triple) {
    AssemblyList *newNode = malloc(sizeof(AssemblyList));
    newNode->info = triple;
    newNode->next = linesOfCode;
    linesOfCode = newNode;
}

void writeHeader(FILE *f) {
    fprintf(f, "section .data\n");
    AssemblyList *g = globalVariables;
    while(g) {
        if(g->info->temporary) {
            fprintf(f, "%s dq 0\n", g->info->temporary->name);
        }
        g = g->next;
    }
    fprintf(f, "\nsection .text\n");
    fprintf(f, "global _start\n\n");
}

void translateTripleToAssembly(Triple *triple, FILE *f) {
    switch(triple->op) {
        case ASIGN:
            if (triple->firstOperand && triple->temporary) {
                fprintf(f, "    mov rax, [%s]\n", triple->firstOperand->name);
                fprintf(f, "    mov [%s], rax\n", triple->temporary->name);
            }
            break;
        case SUMA:
            fprintf(f, "    mov rax, [%s]\n", triple->firstOperand->name);
            fprintf(f, "    add rax, [%s]\n", triple->secondOperand->name);
            fprintf(f, "    mov [%s], rax\n", triple->temporary->name);
            break;
        case MENOS:
            fprintf(f, "    mov rax, [%s]\n", triple->firstOperand->name);
            fprintf(f, "    sub rax, [%s]\n", triple->secondOperand->name);
            fprintf(f, "    mov [%s], rax\n", triple->temporary->name);
            break;
        case MULT:
            fprintf(f, "    mov rax, [%s]\n", triple->firstOperand->name);
            fprintf(f, "    imul rax, [%s]\n", triple->secondOperand->name);
            fprintf(f, "    mov [%s], rax\n", triple->temporary->name);
            break;
        case DIV:
            fprintf(f, "    mov rax, [%s]\n", triple->firstOperand->name);
            fprintf(f, "    cqo\n");
            fprintf(f, "    idiv qword [%s]\n", triple->secondOperand->name);
            fprintf(f, "    mov [%s], rax\n", triple->temporary->name);
            break;
        case FUN_DECL:
            fprintf(f, "%s:\n", triple->temporary->name);
            break;
        case END_FUNC:
            fprintf(f, "    ret\n\n");
            break;
        default:
            // Otros casos no implementados aún
            break;
    }
}

void generateAssemblyFile(AssemblyList *program, const char *filename) {
    char path[256];
    snprintf(path, sizeof(path), "%s/%s.s", DIRECTORY, filename);
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("Error opening file");
        return;
    }

    writeHeader(f);

    AssemblyList *node = program;
    while (node) {
        identifyGlobal(node);
        insertCode(node->info);
        node = node->next;
    }

    node = linesOfCode;
    while (node) {
        translateTripleToAssembly(node->info, f);
        node = node->next;
    }

    fclose(f);
}