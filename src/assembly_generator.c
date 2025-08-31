#include "../include/assembly_generator.h"
#include "../include/pseudo_assembly.h"
#include <ctype.h>


FILE* file;
int labNum = 0;
int cantParamFunc = -1;
char params[7][20] = {"edi", "esi", "edx", "ecx", "r8d", "r9d"};
int paramExtra = 0;

int positiveMaxOffset = 0;

void createFile() {
    file = fopen("result.s", "w");
    if (file == NULL) {
        printf("Error al crear el archivo result.s\n");
        return;
    }
    fclose(file);
}

void writeArchive(char* string) {
    file = fopen("result.s","a");
    if (file == NULL) {
        printf("Error Escribir archivo");
        return;
    }
    fprintf(file, "%s", string);
    fclose(file);
}

void createWriteASM(PseudoAssembly* instruction) {
    ASM currentTag = instruction->tag;
    switch(currentTag){
        case T_GLOBAL:
            writeVarGlobal(instruction);
            if(instruction->next != NULL && instruction->next->tag != T_GLOBAL){
                char buffer[256];
                sprintf(buffer, ".section .text\n\n ");
                writeArchive(buffer);
            }
            break;
        case T_FUNC:
            writeFunc(instruction);
            cantParamFunc = -1;
            break;
        case T_ASIGN:
            writeAsign(instruction);
            break;
        case T_IFF: case T_WF:
            writeIFF(instruction);
            break;
        case T_LABEL:
            writeLabel(instruction);
            break;
        case T_JUMP:
            writeJump(instruction);
            break;
        case T_LOAD_PARAM:
            int cantParam = 0;
            writeLoadParam(instruction, cantParam);
            return;
            break;
        case T_REQUIRED_PARAM:
            writeLoadParamInFunc(instruction);
            break;
        case T_CALL:
            writeCallFunc(instruction);
            break;
        case T_PLUS: case T_MOD: case T_DIV: case T_PROD: case T_MINUS:
            writeOperation(instruction->op1, instruction->op2, instruction->result, currentTag);
            break;
        case T_NOT: case T_AND: case T_OR:
            writeBooleanOp(instruction->op1, instruction->op2, instruction->result, currentTag);
            break;
        case T_EQUAL: case T_LESS: case T_GREATER:
            writeComparation(instruction->op1, instruction->op2, instruction->result, instruction->tag);
            break;
        case T_RETURN:
            writeReturn(instruction);
            writeEndFunc(instruction);
            break;
    }
    if(instruction->next != NULL)
        createWriteASM(instruction->next);
}

void writeVarGlobal(PseudoAssembly* instruction){
        char buffer[256];
        sprintf(buffer, ".section .data\n\n ");
        writeArchive(buffer);
        sprintf(buffer, ".global %s\n\n ",instruction->result->varname);
        writeArchive(buffer);
        sprintf(buffer, "%s: \n    .long 0\n\n",instruction->result->varname);
        writeArchive(buffer);
}

void writeFunc(PseudoAssembly* instruction) {
    char buffer[256];
    if(strcmp(instruction->result->varname,"main") == 0){
        sprintf(buffer, "\n.global %s\n ",instruction->result->varname);
        writeArchive(buffer);
    }
    sprintf(buffer, "%s:\n    pushq   %%rbp\n    movq    %%rsp, %%rbp\n",instruction->result->varname);
    writeArchive(buffer);
    positiveMaxOffset = instruction->result->offset * -1;
    sprintf(buffer,"    subq $%d, %%rsp \n",positiveMaxOffset);
    writeArchive(buffer);
}

void writeEndFunc(PseudoAssembly* instruction) {
    char buffer[256];
    sprintf(buffer,"    addq $%d, %%rsp \n",positiveMaxOffset);
    writeArchive(buffer);
    // Revierte el rbp de la pila antes a donde estaba antes de ser llamada.
    writeArchive("    popq    %rbp\n");
    // Finaliza la funion y regresa la ejecucion al punto donde fue llamada.
    writeArchive("    ret\n");
}

void writeLoadParamInFunc(PseudoAssembly* instruction) {
    char buffer[256];
    char* por = "%";
    TData* param = instruction->result;
    cantParamFunc +=1;
    if(cantParamFunc > 5) {
        sprintf(buffer, "    movl  %d(%%rbp), %%eax\n", ((cantParamFunc-5) * 16));
        writeArchive(buffer);
        sprintf(buffer, "    movl %%eax, %d(%%rbp)\n", param->offset);
        writeArchive(buffer);
    }else{
        sprintf(buffer, "    movl %s%s, %d(%%rbp)\n", por, params[cantParamFunc], param->offset);
        writeArchive(buffer);
    }
}

void writeLoadParam(PseudoAssembly* instruction, int cantParam) {
    char buffer[256];
    char por[3] = "%";
    TData *result = instruction->result;
    if(cantParam >= 6){
        sprintf(buffer, "    subq $8, %srsp\n",por);
        writeArchive(buffer);
        paramExtra ++;
        if(result->token == CONSBOOL){
            if(strcmp("true",result->varname) == 0){
                sprintf(buffer, "    pushq $1 \n");
	           }else {
                sprintf(buffer, "    pushq $0\n");
	           }
            writeArchive(buffer);
        }else if(result->token == CONSINT) {
            sprintf(buffer, "    pushq $%s\n", result->varname);
            writeArchive(buffer);
        }
        TOKENS tipoActual = result->token;
        bool operArit = (tipoActual == PLUS || tipoActual == EMOD || tipoActual == PROD || tipoActual == EDIV || tipoActual == EMOD);
        bool operBool = (tipoActual == EOR || tipoActual == EAND || tipoActual == ENOT );
        bool operCondi = (tipoActual == T_GREATER_THAN || tipoActual == T_LESS_THAN || tipoActual == EEQ);
        if(result->token == EID || result->token == CALL_F || operArit || operBool || operCondi) {
            if(result->offset == 0) {
                sprintf(buffer, "    pushq %s(%%rip)\n",result->varname);
                writeArchive(buffer);
            }else{
                sprintf(buffer, "    pushq %d(%%rbp)\n",result->offset);
                writeArchive(buffer);
            }
        }
    }else{
        if(result->token == CONSBOOL){
            if(strcmp("true",result->varname) == 0){
                sprintf(buffer, "    movl $1, %s%s\n",por, params[cantParam]);
	           }else {
                sprintf(buffer, "    movl $0, %s%s\n", por, params[cantParam]);
	           }
            writeArchive(buffer);
        }else if(result->token == CONSINT) {
            sprintf(buffer, "    movl $%s, %s%s\n", result->varname, por, params[cantParam]);
            writeArchive(buffer);
        }
        TOKENS tipoActual = result->token;
        bool operArit = (tipoActual == PLUS || tipoActual == EMOD || tipoActual == PROD || tipoActual == EDIV || tipoActual == EMOD);
        bool operBool = (tipoActual == EOR || tipoActual == EAND || tipoActual == ENOT );
        bool operCondi = (tipoActual == T_GREATER_THAN || tipoActual == T_LESS_THAN || tipoActual == EEQ);
        if(result->token == EID || result->token == CALL_F || operArit || operBool || operCondi) {
            if(result->offset == 0) {
                sprintf(buffer, "    movl %s(%%rip), %seax\n",result->varname, por);
                writeArchive(buffer);
            }else{
                sprintf(buffer, "    movl %d(%%rbp), %seax\n",result->offset, por);
                writeArchive(buffer);
            }
            sprintf(buffer, "    movl %%eax, %s%s\n", por, params[cantParam]);
            writeArchive(buffer);
        }

    }
    cantParam += 1;
    if(instruction->next->tag ==  T_LOAD_PARAM) {
        instruction = instruction->next;
        writeLoadParam(instruction, cantParam);
    } else {
        createWriteASM(instruction->next);
    }

}

void writeAsign(PseudoAssembly* instruction) {
    TData* op1 = instruction->result;
    TData* op2 = instruction->op2;
    TOKENS typeOp2 = op2->token;
    char buffer[256];
    char* por = "%%";

    if(typeOp2 == CONSINT){
        if(op1->offset == 0) {
            sprintf(buffer, "    movl $%s, %s(%%rip)\n", op2->varname, op1->varname);
        } else{
            sprintf(buffer, "    movl $%s, %d(%%rbp)\n", op2->varname, op1->offset);
        }
    } else if(typeOp2 == CONSBOOL ){
        if(strcmp("true",op2->varname) == 0){
            if(op1->offset == 0)
                sprintf(buffer, "    movl $1, %s(%%rip)\n", op1->varname);
            else
			    sprintf(buffer, "    movl $1, %d(%%rbp)\n", op1->offset);
		}else {
            if(op1->offset == 0)
                sprintf(buffer, "    movl $0, %s(%%rip)\n", op1->varname);
            else
			    sprintf(buffer, "    movl $0, %d(%%rbp)\n", op1->offset);
		}
    }else {
        if(op2->offset == 0)
            sprintf(buffer, "    movl %s(%%rip), %%eax\n\n", op2->varname);
        else
            sprintf(buffer, "    movl %d(%%rbp), %%eax\n\n", op2->offset);

        writeArchive(buffer);
        if(op1->offset == 0)
            sprintf(buffer, "    movl %%eax, %s(%%rip)\n\n", op1->varname);
        else
            sprintf(buffer, "    movl %%eax, %d(%%rbp)\n\n", op1->offset);
    }
    writeArchive(buffer);
}

void writeReturn(PseudoAssembly* instruction) {
    TData* result = instruction->result;
    TOKENS typeResult = result->token;
    char buffer[256];

    if(strcmp(" ",result->varname) == 0){
        return;
    } else {
        if(result->token == CONSBOOL) {
            if(strcmp("true",result->varname) == 0){
                sprintf(buffer, "    movl $1, %%eax\n");
		    }else {
                sprintf(buffer, "    movl $0, %%eax\n");
		    }
            writeArchive(buffer);
        }
        else if(result->token == CONSINT){
            sprintf(buffer, "    movl $%s,  %%eax\n", result->varname);
        }else{
            if(result->offset == 0)
                sprintf(buffer, "    movl %s(%%rip),  %%eax\n", result->varname);
            else
                sprintf(buffer, "    movl %d(%%rbp),  %%eax\n", result->offset);
        }
        writeArchive(buffer);
    }
}


void writeIFF(PseudoAssembly* instruction) {

    TData* op1 = instruction->op1;
    TData* result = instruction->result;
    char buffer[256];
    char* por = "%%";
    if(op1->token == CONSBOOL) {
       if(strcmp("true",op1->varname) == 0){
                sprintf(buffer, "    movl $1, %%eax\n");
                writeArchive(buffer);
                sprintf(buffer, "    cmpl $1, %%eax\n");
		}else {
                sprintf(buffer, "    movl $0,  %%eax\n");
                writeArchive(buffer);
                sprintf(buffer, "    cmpl $1,  %%eax\n");
		}
    }else {
        if(op1->offset == 0)
           sprintf(buffer, "    cmpl  $1,  %s(%%rip)\n", op1->varname);
        else
          sprintf(buffer, "    cmpl  $1,  %d(%%rbp)\n", op1->offset);
    }
    writeArchive(buffer);
    //salto por falso
    char* nameLabel = result->varname;
    sprintf(buffer, "    jne %s\n", nameLabel);
    writeArchive(buffer);
}

void writeLabel(PseudoAssembly* instruction) {
    char buffer[256];
    writeArchive("\n\n");
    char* nameLabel = instruction->result->varname;
    sprintf(buffer, "%s: \n", nameLabel);
    writeArchive(buffer);
}


void writeJump(PseudoAssembly* instruction) {
    char buffer[256];
    char* nameLabel = instruction->result->varname;
    sprintf(buffer, "    jmp %s\n", nameLabel);
    writeArchive(buffer);
}


void writeCallFunc(PseudoAssembly* instruction) {
    char buffer[256];
    char* nameLabel = instruction->op1->varname;
    sprintf(buffer, "    call %s\n", nameLabel);
    writeArchive(buffer);
    if(paramExtra > 0) {
        int aux = paramExtra * 16;
        sprintf(buffer, "    addq $%d,  %%rsp\n",aux);
        writeArchive(buffer);
        paramExtra = 0;
    }

    TData* result = instruction->result;
    sprintf(buffer, "    movl %%eax, %d(%%rbp)\n", result->offset);
    writeArchive(buffer);
}



void writeOperation(TData* op1, TData* op2, TData* final, ASM tag){
    file = fopen("result.s","a");
    if (file == NULL) {
        printf("Error Escribir archivo");
        return;
    }
    char aux[100];
    char* por = "%%";
    if (tag == T_PLUS || tag == T_MOD || tag == T_PROD) {
        if(op1->token == CONSINT){
          sprintf(aux, "    movl $%s, %%eax\n", op1->varname);
        }else{
            if(op1->offset == 0)
                sprintf(aux, "    movl %s(%%rip), %%eax\n", op1->varname);
            else
                sprintf(aux, "    movl %d(%%rbp), %%eax\n", op1->offset);
        }
        writeArchive(aux);
        if(op2->token == CONSINT){
            sprintf(aux, "    movl $%s, %%edx\n", op2->varname);
        }else{
            if(op2->offset == 0)
                sprintf(aux, "    movl %s(%%rip), %%edx\n", op2->varname);
            else
                sprintf(aux, "    movl %d(%%rbp), %%edx\n", op2->offset);
        }
        writeArchive(aux);
        if (tag == T_PLUS){
            sprintf(aux, "    addl %%edx, %%eax\n");
            writeArchive(aux);

        }else if (tag == T_MOD){ 
            sprintf(aux, "    subl %%edx, %%eax\n");
            writeArchive(aux);
        }
        else{
            sprintf(aux, "    imull %%edx, %%eax\n");
            writeArchive(aux);
        }
        sprintf(aux, "    movl %%eax, %d(%%rbp)\n", final->offset);
        writeArchive(aux);
    } else if (tag == T_DIV || tag == T_MOD) {
        if(op1->token == CONSINT)
          sprintf(aux, "    movl $%s, %%eax\n", op1->varname);
        else{
            if(op1->offset == 0)
                sprintf(aux, "    movl %s(%%rip), %%eax\n", op1->varname);
            else
              sprintf(aux, "    movl %d(%%rbp), %%eax\n", op1->offset);
        }
        writeArchive(aux);
        if(op2->token == CONSINT){
            sprintf(aux, "    movl $%s,  %%ecx\n", op2->varname);
            writeArchive(aux);
            sprintf(aux, "    cltd\n");
            writeArchive(aux);
            sprintf(aux, "    idivl %%ecx\n");
        }else{
            if(op2->offset == 0){
                sprintf(aux, "    movl %s(%%rip),  %%ecx\n", op2->varname);
                writeArchive(aux);
                sprintf(aux, "    cltd\n");
                writeArchive(aux);
                sprintf(aux, "    idivl %%ecx\n");
            }else{
                sprintf(aux, "    cltd\n");
                writeArchive(aux);
                sprintf(aux, "    idivl %d(%%rbp)\n", op2->offset);
            }
        }
        writeArchive(aux);

        if (tag == T_DIV)
            sprintf(aux, "    movl %%eax, %d(%%rbp)\n",final->offset);
        else
            sprintf(aux, "    movl %%edx, %d(%%rbp)\n",final->offset);
        writeArchive(aux);
    }
}

void writeBooleanOp(TData* op1, TData* op2, TData* final, ASM tag){
    char aux[100];
    if(op1->token == CONSBOOL){
        if(strcmp("true",op1->varname) == 0){
            sprintf(aux, "    movl $1, %%eax\n");
            writeArchive(aux);
	    	sprintf(aux, "    cmpl $0, %%eax\n");
	    }else {
            sprintf(aux, "    movl $0, %%eax\n");
            writeArchive(aux);
		    sprintf(aux, "    cmpl $0, %%eax\n");
	    }
    }else{
        if(op1->offset == 0)
            sprintf(aux, "    cmpl $0, %s(%%rip)\n", op1->varname);
        else
            sprintf(aux, "    cmpl $0, %d(%%rbp)\n", op1->offset);
    }
    writeArchive(aux);
    if (tag == T_AND || tag == T_OR){
        if (tag == T_AND)
            sprintf(aux, "    je .LA%d \n", labNum+1);
        else
            sprintf(aux, "    jne .LO%d \n", labNum+1);

        writeArchive(aux);
        if(op2->token == CONSBOOL){
            if(strcmp("true",op2->varname) == 0){
		    	sprintf(aux, "    movl $1, %%eax\n");
                writeArchive(aux);
		    	sprintf(aux, "    cmpl $0, %%eax\n");
		    }else {
			    sprintf(aux, "    movl $0, %%eax\n");
                writeArchive(aux);
			    sprintf(aux, "    cmpl $0, %%eax\n");
		    }
        }else{
            if(op2->offset == 0)
                sprintf(aux, "    cmpl $0, %s(%%rip)\n", op2->varname);
            else
                sprintf(aux, "    cmpl $0, %d(%%rbp)\n", op2->offset);
        }
        writeArchive(aux);
        if (tag == T_AND){
            labNum++;
            sprintf(aux, "    je .LA%d \n", labNum);
        }else{
            labNum++;
            sprintf(aux, "    je .LO%d \n", labNum+1);
        }
        writeArchive(aux);
        if (tag == T_OR) {
            sprintf(aux, ".LO%d: \n", labNum);
            writeArchive(aux);
        }
        sprintf(aux, "    movl $1, %%eax\n");
        writeArchive(aux);
        if (tag == T_AND) {
            labNum++;
            sprintf(aux, "    jmp .LA%d \n", labNum);
            writeArchive(aux);
            labNum --;
            sprintf(aux, ".LA%d: \n", labNum);
        } else {
            labNum++;
            sprintf(aux, "    jmp .LO%d \n", labNum+1);
            writeArchive(aux);
            sprintf(aux, ".LO%d: \n", labNum);
        }
        writeArchive(aux);
        sprintf(aux, "    movl $0, %%eax\n");
        writeArchive(aux);
        labNum++;
        if (tag == T_AND) {
            sprintf(aux, ".LA%d: \n", labNum);
        } else {
            sprintf(aux, ".LO%d: \n", labNum);
        }
        writeArchive(aux);
    } else {
        sprintf(aux, "    sete  %%al\n");
        writeArchive(aux);
        sprintf(aux, "    movzbl  %%al, %%eax\n");
        writeArchive(aux);
    }
    sprintf(aux, "    movl %%eax, %d(%%rbp)\n",final->offset);
    writeArchive(aux);
}

void writeComparation(TData* op1, TData* op2, TData* final, ASM tag){
    char aux[30];
    if( op1->token == CONSINT){
        sprintf(aux, "    movl $%s , %%eax \n", op1->varname);
    }else{
        if(op1->offset == 0)
          sprintf(aux, "    movl %s(%%rip) , %%eax\n ", op1->varname);
        else
           sprintf(aux, "    movl %d(%%rbp) , %%eax\n ", op1->offset);
    }
    writeArchive(aux);
    if(op2->token == CONSINT){
        sprintf(aux, "   cmpl  $%s , %%eax \n", op2->varname);
    }else{
        if(op2->offset == 0)
            sprintf(aux, "   cmpl %s(%%rip) , %%eax\n", op2->varname);
        else
            sprintf(aux, "   cmpl %d(%%rbp) , %%eax\n", op2->offset);
    }
    writeArchive(aux);
    if(tag == T_ASIGN){
        sprintf(aux, "    sete %%al\n");
        writeArchive(aux);
    }
    if(tag == T_GREATER){
        sprintf(aux, "    setg %%al\n");
        writeArchive(aux);
    }
    if(tag == T_LESS){
        sprintf(aux, "    setl %%al\n");
        writeArchive(aux);
    }
    sprintf(aux, "    movzbl %%al, %%eax\n");
    writeArchive(aux);
    sprintf(aux, "    movl  %%eax, %d(%%rbp)\n", final->offset);
    writeArchive(aux);
}
