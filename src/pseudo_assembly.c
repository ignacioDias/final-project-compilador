#include "../include/pseudo_assembly.h"
#include "../include/assembly_generator.h"
#include <string.h>

//para paramteros que tienen mas de 6
PseudoAssembly* ParamsMayorSeis = NULL;
PseudoAssembly* instructions = NULL;

int labID = 1;
int paramReq  = 0;

void createInstallSequence(ASM tag, TData* op1, TData* op2, TData* result){
    PseudoAssembly* sequense = (PseudoAssembly*)malloc(sizeof(PseudoAssembly));
    sequense->tag = tag;
    sequense->op1 = op1;
    sequense->op2 = op2;
    sequense->result = result;
    sequense->next = instructions;
    instructions = sequense;
}

void operComparate(TOKENS tag,TData* op1, TData* op2, TData* res){
    TData *auxLeft = LookupVar(op1->varname);
    TData *auxRigth = LookupVar(op2->varname);
    switch(tag){
        case  T_GREATER_THAN:
            createInstallSequence(T_GREATER,op1, op2,res);
            break;
        case  T_LESS_THAN:
            createInstallSequence(T_LESS,op1, op2, res);
            break;
        case  EEQ:
            createInstallSequence(T_EQUAL,op1,  op2, res);
            break;
        }
}

void operBoolean(TOKENS tag,TData* op1, TData* op2, TData* res){
    TData *auxLeft = LookupVar(op1->varname);
    TData *auxRigth = LookupVar(op2->varname);
    switch(tag){
        case  EAND:
            createInstallSequence(T_AND,op1,  op2, res);
            break;
        case  EOR:
            createInstallSequence(T_OR,op1, op2, res);
            break;
    }

}

void operAritmetic(TOKENS tag,TData* op1, TData* op2, TData* res){
    TData *auxLeft = LookupVar(op1->varname);
    TData *auxRigth = LookupVar(op2->varname);
    switch(tag){
        case PLUS:
            createInstallSequence(T_PLUS,op1, op2, res);
            break;
        case MINUS:
            createInstallSequence(T_MINUS,op1, op2, res);
            break;
        case PROD:
            createInstallSequence(T_PROD,op1, op2, res);
            break;
        case  EDIV:
            if (auxRigth != NULL && auxLeft != NULL) {
                if(auxRigth->value == 0 && auxRigth->token == CONSINT) {
                    printf("\033[31mNo se puede dividir por 0 \033[0m, linea de error: %d\n", auxLeft->line);
                    exit(1);
                }
            } else if (auxRigth == NULL && auxLeft != NULL) {
                if(op2->value == 0) {
                    printf("\033[31mNo se puede dividir por 0 \033[0m, linea de error: %d\n", auxLeft->line);
                    exit(1);
                }
            } else if(auxRigth != NULL && auxLeft == NULL){
                if(auxRigth->value == 0) {
                    printf("\033[31mNo se puede dividir por 0 \033[0m, linea de error: %d\n",  op1->line);
                    exit(1);
                }
            } else {
                if(op2->value == 0) {
                    printf("\033[31mNo se puede dividir por 0 \033[0m, linea de error: %d\n",  op1->line);
                    exit(1);
                }
            }
            createInstallSequence(T_DIV,op1, op2, res);
            break;
        case EMOD:
            if (auxRigth != NULL && auxLeft != NULL) {
                if(auxRigth->value == 0 && auxRigth->token == CONSINT) {
                    printf("\033[31mNo se puede sacar resto por 0 \033[0m, linea de error: %d\n", auxLeft->line);
                    exit(1);
                }
            } else if (auxRigth == NULL && auxLeft != NULL) {
                if(op2->value == 0) {
                    printf("\033[31mNo se puede sacar resto por 0 \033[0m, linea de error: %d\n", auxLeft->line);
                    exit(1);
                }
            } else if(auxRigth != NULL && auxLeft == NULL){
                if(auxRigth->value == 0) {
                    printf("\033[31mNo se puede sacar resto por 0 \033[0m, linea de error: %d\n",  op1->line);
                    exit(1);
                }
            } else {
                if(op2->value == 0) {
                    printf("\033[31mNo se puede sacar resto por 0 \033[0m, linea de error: %d\n",  op1->line);
                    exit(1);
                }
            }
            createInstallSequence(T_MOD,op1, op2, res);
            break;
        }
}

void traslate(TOKENS tag, Tree* op1, Tree* op2, Tree* res) {
    TData * op1Symbol = op1->symbol;
    TData * op2Symbol = NULL;
    TData * resSymbol = res->symbol;

    TData *auxRigth = NULL;
    TData *auxLeft = LookupVar(op1->symbol->varname);

    if(op2 != NULL){
        op2Symbol = op2->symbol;
        auxRigth = LookupVar(op2->symbol->varname);
    }

    switch(tag){
        case ASIGN:
            if(auxRigth){
                op1Symbol->value = auxRigth->value;
                resSymbol = op1Symbol;
            }else {
                op1Symbol->value = op2Symbol->value;
                resSymbol = op1Symbol;
            }
            createInstallSequence(T_ASIGN,op1Symbol,op2Symbol,resSymbol);
            break;
        case PLUS: case MINUS: case PROD: case EDIV: case EMOD:
            operAritmetic(tag,op1Symbol,op2Symbol,resSymbol);
            break;
        case  EAND: case  EOR:
            operBoolean(tag,op1Symbol,op2Symbol,resSymbol);
            break;
        case  T_GREATER_THAN: case  T_LESS_THAN: case  EEQ:
            operComparate(tag,op1Symbol,op2Symbol,resSymbol);
            break;
        case EWHILE:
            createInstallSequence(T_WHILE,op1Symbol,op2Symbol,resSymbol);
            break;
        case EIF:
            createInstallSequence(T_IF,op1Symbol,op2Symbol,resSymbol);
            break;
        case ENOT:
            createInstallSequence(T_NOT,op1Symbol,op2Symbol,resSymbol);
            break;
    }
}

TData *LookupVar(char * name){
  PseudoAssembly* head = instructions;
  if(name == NULL) {
    return NULL;
  }
  while(head != NULL) {
    if(strcmp(name, head->result->varname)==0){
      return head->result;
    }
    head = head->next;
  }
  return NULL;
}

void generateThreeDir(Tree* tree) {
    generateCode(tree);
    invertASM(&instructions);
}

void generateVarGlobals(){
    TData * aux = getTable();
    while(aux != NULL) {
        TData * recorrert = aux->table;
        while(recorrert != NULL) {
            if(recorrert->token == VARINT || recorrert->token == VARBOOL ){
                char * name1 = "_";
                createInstallSequence(T_GLOBAL, CreateSymbol(name1,OTHERS,0,0),CreateSymbol(name1,OTHERS,0,0), recorrert);
            }
        recorrert = recorrert->next;
        }
        aux = aux->next;
    }
}

void generateCode(Tree* tree) {
    TOKENS tipoActual = tree->symbol->token;
    switch(tipoActual){
        case ERETURN:
            handleGenerateOpReturn(tree);
            createRetTag(tree->left->symbol);
            break;
        case RETINT: case RETBOL: case RETVOID:
            if (strcmp((tree->symbol)->varname,"main") == 0) {
                handleGenerateMain(tree);
                createSentenThreeDir(T_END_FUN, tree->symbol);
            } else {
                handleGenerateFunc(tree);
                paramReq = 0;
                createSentenThreeDir(T_END_FUN, tree->symbol);
            }
            break;
        case CALL_F:
            has_Operation(tree->right);
            has_Call_Func(tree->right);
            generateLoadParams(tree->right);
            createCall_Func(tree->left->symbol, tree->symbol);
            break;
        case EIF:
            handleGenerateIF(tree);
            break;
        case EWHILE:
            handleGenerateWhile(tree);
            break;
        default:
            if(strcmp((tree->symbol)->varname,"PROGRAM") == 0){
                generateVarGlobals();
            }
            if ((tree->right != NULL && tree->left != NULL)) {
                handleGenerateBinaryOperation(tree);
            }else if (tree->left != NULL) {
                handleUnaryOp(tree);
            }else if (tree->right != NULL) {
                generateCode(tree->right);
            }
            break;
    }
}

void handleGenerateOpReturn(Tree* tree) {
    if (tree->left != NULL)
        generateCode(tree->left);
    if (tree->right != NULL)
        generateCode(tree->right);
}

void handleGenerateMain(Tree* tree){
    createSentenThreeDir(T_FUNC,tree->symbol);
    if (tree->left != NULL)
        generateCode(tree->left);
    if (tree->right != NULL)
        generateCode(tree->right);
    if(tree->symbol->token == RETVOID){
        char * name1 = " ";
        createInstallSequence(T_RETURN, CreateSymbol(name1,OTHERS,0,0),CreateSymbol(name1,OTHERS,0,0), CreateSymbol(name1,OTHERS,0,0));
    }
 }

void has_Operation(Tree* tree){
    if(tree == NULL) return;

    if(tree->left)
        has_Operation(tree->left);
    if(tree->right)
        has_Operation(tree->right);
    TOKENS tipoActual = tree->symbol->token;
    bool operArit = (tipoActual == PLUS || tipoActual == MINUS || tipoActual == PROD || tipoActual == EDIV || tipoActual == EMOD);
    bool operBool = (tipoActual == EOR || tipoActual == EAND || tipoActual == ENOT );
    bool operCondi = (tipoActual == T_GREATER_THAN || tipoActual == T_LESS_THAN || tipoActual == EEQ);
    if(operArit || operBool || operCondi){
        generateCode(tree);
    }
}

void has_Call_Func(Tree* tree) {
    if(tree == NULL) return;

    if(tree->left)
        has_Call_Func(tree->left);

    if(tree->right)
        has_Call_Func(tree->right);

    if (tree->symbol->token == CALL_F) {
        generateLoadParams(tree->right);
        createCall_Func(
            tree->left->symbol, tree->symbol);
    }
}

void generateLoadParams(Tree* tree) {
    if(tree == NULL) return;

    TOKENS tipoActual = tree->symbol->token;

    if (tipoActual != ARGS) {
        createTagLoad(tree->symbol);
    }
    bool notOperArit = (tipoActual != PLUS && tipoActual != MINUS && tipoActual != PROD && tipoActual != EDIV && tipoActual != EMOD);
    bool notOperBool = (tipoActual != EOR && tipoActual != EAND && tipoActual != ENOT );
    bool notOperCondi = (tipoActual != T_GREATER_THAN && tipoActual != T_LESS_THAN && tipoActual != EEQ);
    bool ifNotType = (tipoActual != CALL_F && (notOperArit && notOperBool && notOperCondi));
    if(ifNotType) {
        if(tree->left != NULL){
            generateLoadParams(tree->left);
        }
        if(tree->right != NULL){
            generateLoadParams(tree->right);
        }
    }

}

void createTagLoad(TData* symbol) {
    char * name1 = "_";
    createInstallSequence(T_LOAD_PARAM, CreateSymbol(name1,OTHERS,0,0),CreateSymbol(name1,OTHERS,0,0), symbol);
}

void concatLists(PseudoAssembly *list1, PseudoAssembly *list2) {
    if(!list2) {
        return;
    }
    PseudoAssembly * actual = list2;
    while (actual->next != NULL) {
        actual = actual->next;
    }
    actual->next = list1;
    instructions = list2;
}

void handleGenerateFunc(Tree* tree){
    createSentenThreeDir(T_FUNC,tree->symbol);
    if(tree->left != NULL) {
        requireParams(tree->left);
        invertASM(&ParamsMayorSeis);
        concatLists(instructions,ParamsMayorSeis);
        ParamsMayorSeis = NULL;
    }
    if(tree->right != NULL) {
        generateCode(tree->right);
    }
    if(tree->symbol->token == RETVOID){
        char * name1 = " ";
        createInstallSequence(T_RETURN, CreateSymbol(name1,OTHERS,0,0),CreateSymbol(name1,OTHERS,0,0), CreateSymbol(name1,OTHERS,0,0));
    }
 }


void requireParams(Tree* tree) {
    if(tree->symbol->token == PARAMBOOL || tree->symbol->token == PARAMINT){
        paramReq += 1;
        createCodRequiredParam(tree->symbol);
    }
    if(tree->left)
        requireParams(tree->left);
    if(tree->right)
        requireParams(tree->right);
 }

 void createCall_Func(TData* nameFunc, TData* tempResult){
    char * name1 = "_";
    createInstallSequence(T_CALL, nameFunc,CreateSymbol(name1,OTHERS,0,0), tempResult);
 }

 void createSentenThreeDir(ASM tag , TData* func){
    char * name1 = "_";
    createInstallSequence(tag, CreateSymbol(name1,OTHERS,0,0),CreateSymbol(name1,OTHERS,0,0), func);
 }

void handleGenerateIF(Tree* tree) {
    generateCode(tree->left);
    PseudoAssembly* IFF = createTagForFalse(T_IFF,  tree->left->symbol);
    char* labelIFF = (char*) malloc(10 * sizeof(char));
    strcpy(labelIFF, IFF->result->varname);

    IFF->next = instructions;
    instructions = IFF;

    TOKENS tipoActual = (tree->symbol)->token;
    TData* auxLeft = LookupVar(tree->left->symbol->varname);

    if((strcmp((tree->symbol)->varname,"if_then") == 0)){
        generateCode(tree->right);
        createAndAppendTagLabel(labelIFF);

    } else if((strcmp((tree->symbol)->varname,"if_else") == 0)){
        generateCode((tree->right)->left);  //then
        //create jump
        PseudoAssembly* jump = createJump();
        jump->next = instructions;
        instructions = jump;
        createAndAppendTagLabel(labelIFF);
        generateCode((tree->right)->right->left); //else
        createAndAppendTagLabel(jump->result->varname);
    }
}

void handleGenerateWhile(Tree* tree) {
    PseudoAssembly* jump = createJump();
    createAndAppendTagLabel(jump->result->varname);
    generateCode(tree->left);
    PseudoAssembly* conditionFalse = createTagForFalse(T_WF,  tree->left->symbol);
    conditionFalse->next = instructions;
    instructions = conditionFalse;
    generateCode(tree->right);  
    jump->next = instructions;
    instructions = jump;
    createAndAppendTagLabel(conditionFalse->result->varname);
}

void handleGenerateBinaryOperation(Tree* tree) {
    TOKENS tipoActual = (tree->symbol)->token;
    if (tree->left != NULL) {
        generateCode(tree->left);
    }
    if (tree->right != NULL) {
        generateCode(tree->right);
    }
    bool isAsignBool = tipoActual == ASIGN || tipoActual == EAND || tipoActual == EOR || tipoActual == EEQ || tipoActual == T_GREATER_THAN || tipoActual == T_LESS_THAN;
    bool isAritmet = tipoActual == PLUS || tipoActual == MINUS || tipoActual == PROD || tipoActual == EMOD || tipoActual == EDIV;
    if (isAsignBool || isAritmet) {
        traslate(tipoActual, tree->left, tree->right, tree);
    }
}

void handleUnaryOp(Tree* tree) {
    generateCode(tree->left);
    if ((tree->symbol)->token  == ENOT) {
        traslate((tree->symbol)->token, tree->left,NULL, tree);
    }
}

void invertASM(PseudoAssembly ** list) {
    PseudoAssembly* prev = NULL;
    PseudoAssembly* current = *list;
    PseudoAssembly* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *list = prev;
}
void deleteInstructions() {
    PseudoAssembly* current = instructions;
    PseudoAssembly* next = NULL;

    while (current != NULL) {
        next = current->next;
        if (current->tag == T_IFF) {
            free(current->op2);
            free(current->result);
        } else if (current->tag == T_JUMP || current->tag == T_LABEL) {
            free(current->op1);
            free(current->op2);
            free(current->result);
        }
        free(current);
        current = next;
    }
}

void printAsembler() {
    PseudoAssembly* current = instructions;
    printf("\nInstructions\n");
    while (current != NULL) {
        if (current->op1 && current->op2) {
            printf("%s %s %s %s\n", tagName[current->tag], current->op1->varname, current->op2->varname, current->result->varname);
        }else if (!current->op1 && current->op2){
            printf("%s   %s %s\n", tagName[current->tag], current->op2->varname, current->result->varname);
        }else if (current->op1 && !current->op2){
            printf("%s %s   %s\n", tagName[current->tag], current->op1->varname, current->result->varname);
        }else{
            printf("%s     %s\n", tagName[current->tag], current->result->varname);
        }
        current = current->next;
    }
}

PseudoAssembly* createTagForFalse(ASM tag, TData* condition) {
    PseudoAssembly* sequense = (PseudoAssembly*)malloc(sizeof(PseudoAssembly));
    sequense->tag = tag;
    sequense->op1 = condition;
    char * name1 = "_";
    sequense->op2 =  CreateSymbol(name1,OTHERS,0,0);
    char* name = generateNameLabel();
    sequense->result = CreateSymbol(name,OTHERS,0,0);
    return sequense;
}

PseudoAssembly* createJump() {
    PseudoAssembly* jump = (PseudoAssembly*)malloc(sizeof(PseudoAssembly));
    jump->tag = T_JUMP;
    char * name1 = "_";
    jump->op1 = CreateSymbol(name1,OTHERS,0,0);
    jump->op2 =  CreateSymbol(name1,OTHERS,0,0);
    char* name = generateNameLabel();
    jump->result = CreateSymbol(name,OTHERS,0,0);
    return jump;
}

char* generateNameLabel() {
    char* nameLabel = (char*) malloc(10 * sizeof(char));
    sprintf(nameLabel, "L%d", labID);
    labID++;
    return nameLabel;
}

void createAndAppendTagLabel(char* nameLabel) {
    char * name1 = "_";
    createInstallSequence(T_LABEL,CreateSymbol(name1,OTHERS,0,0),CreateSymbol(name1,OTHERS,0,0),CreateSymbol(nameLabel,OTHERS,0,0));
}

void createRetTag(TData* func){
    char * name1 = " ";
    createInstallSequence(T_RETURN,CreateSymbol(name1,OTHERS,0,0),CreateSymbol(name1,OTHERS,0,0),func);
}

void createCodRequiredParam(TData* param){
    if( paramReq > 6) {
        PseudoAssembly* sequense = (PseudoAssembly*)malloc(sizeof(PseudoAssembly));
        sequense->tag = T_REQUIRED_PARAM;
        char * name1 = " ";
        sequense->op1 = CreateSymbol(name1,OTHERS,0,0);
        sequense->op2 =  CreateSymbol(name1,OTHERS,0,0);
        sequense->result = param;
        sequense->next = ParamsMayorSeis;
        ParamsMayorSeis = sequense;
    }else {
        char * name1 = " ";
        createInstallSequence(T_REQUIRED_PARAM,CreateSymbol(name1,OTHERS,0,0), CreateSymbol(name1,OTHERS,0,0), param);
    }
}

void generateAssembler() {
    createFile();
    createWriteASM(instructions);
}