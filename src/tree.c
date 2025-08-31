#include "../include/tree.h"
#include "../include/symbols_table.h"
#include "../include/errors_manager.h"

bool err = false;
TOKENS aux = RETVOID;

TData *auxFunc = NULL;
int offset = -16;
int cantBloq = -1;

bool inBlockIf = false;
int cantReturns = 0;
int cantRetBlock = 0;
int cantWhileIf = 0;

bool errRet = false;

Tree* createTree(TData* symbol, Tree *l, Tree *r) {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->symbol = symbol;
    tree->left = l;
    tree->right = r;
    return tree;
}

void updateNodeTree(Tree* tree, TData* symbol){
    tree->symbol = symbol;
}

void elimArbol(Tree* tree) {
    if(!tree)
        return;
    if (tree->symbol != NULL) {
        free(tree->symbol);
        tree->symbol = NULL;
    }
    if (tree->left != NULL) {
        elimArbol(tree->left);
    }
    if (tree->right != NULL) {
        elimArbol(tree->right);
    }
    free(tree);
    tree = NULL;
}

void showTreeDot(Tree* tree,FILE* file) {
    if(!tree) 
        return;
    if(tree->left && tree->right ) {
        fprintf(file, "\"%d|  %s\" -> \"%d|  %s\", \"%d|  %s\";\n",(tree->symbol)->id,(tree->symbol)->varname,((tree->left)->symbol)->id, ((tree->left)->symbol)->varname,((tree->right)->symbol)->id,((tree->right)->symbol)->varname);
        showTreeDot(tree->left, file);
        showTreeDot(tree->right, file);
    }else {
        if (tree->left) {
            fprintf(file, "\"%d|  %s\" -> \"%d|  %s\" ;\n",(tree->symbol)->id,(tree->symbol)->varname,((tree->left)->symbol)->id, ((tree->left)->symbol)->varname);
            showTreeDot(tree->left, file);
        }
        if (tree->right) {
            fprintf(file, "\"%d|  %s\" -> \"%d|  %s\" ;\n",(tree->symbol)->id,(tree->symbol)->varname,((tree->right)->symbol)->id, ((tree->right)->symbol)->varname);
            showTreeDot(tree->right, file);
        }
    }
}


void createTable(Tree* tree) {
    TOKENS currentToken = (tree->symbol)->token;
    if(currentToken == EPROGRAM){
       InstallScope();
       InstallInCurrentScope(tree->symbol);
    }
    if(currentToken == RETINT || currentToken == RETBOL || currentToken == RETVOID) {
        cantReturns = 0;
        offset = -16;
        cantBloq++;
        auxFunc = tree->symbol;
        InstallInCurrentScope(tree->symbol);
        InstallScope();
    }else if(currentToken == EXTVOID || currentToken == EXTINT || currentToken == EXTBOL){
        auxFunc = tree->symbol;
        InstallInCurrentScope(tree->symbol);
        InstallScope();
    }
    if( currentToken == EIF || currentToken == EWHILE || currentToken == EELSE){
        cantWhileIf++;
        inBlockIf = true;
        cantBloq++;
        InstallScope();
        InstallInCurrentScope(tree->symbol);
    }
    if (currentToken == VARBOOL || currentToken == VARINT){
        if (getScope() != 1) {
            tree->symbol->offset = offset;
            offset += -16;
        }
        InstallInCurrentScope(tree->symbol);
    }
    if(currentToken == PARAMINT || currentToken == PARAMBOOL)  {
        tree->symbol->offset = offset;
        offset += -16;
        InstallInCurrentScope(tree->symbol);
        InstallParam(tree->symbol, auxFunc);
    }
    if (currentToken == EID) {
        TData* symbolStack = LookupExternVar(tree->symbol->varname);
        if (symbolStack != NULL) {
            tree->symbol->offset = symbolStack->offset;
        }
    }
    if(currentToken == BLOCK_FIN) {
        if (cantBloq > 0)
            cantBloq--;
        if (cantBloq == 0 && !inBlockIf) {
            auxFunc->offset = offset;
            offset =  -16;
        }
        if(inBlockIf && cantWhileIf == 1){
            inBlockIf = false;
            cantWhileIf--;
        }else if(inBlockIf && cantWhileIf > 1) {
            cantWhileIf--;
        }else if(errRet && cantReturns != 2){
            printf("\033[31mTe falta un return en la linea \033[0m %d\n",(tree->symbol)->line-1);
            err = true;
        }else if(errRet && cantReturns == 2) {
            errRet = false;
        }
        PopScope();
        cantRetBlock = 0;

    }
    if (tree->right && tree->left) {
        TOKENS currentToken = (tree->symbol)->token;
        bool operArit = (currentToken == PLUS || currentToken == MINUS || currentToken == PROD || currentToken == EDIV || currentToken == EMOD);
        bool operBool = (currentToken == EOR || currentToken == EAND || currentToken == ENOT );
        bool operCondi = (currentToken == T_GREATER_THAN || currentToken == T_LESS_THAN || currentToken == EEQ);
        if (currentToken == ASIGN) {
            errorAsign(tree, &err);
        } else if(operArit || operBool || operCondi) {
              tree->symbol->offset = offset;
              offset += -16;
             errorOperation(tree, currentToken, &err);
        }else if(currentToken == EIF || currentToken == EWHILE) {
            errorCondition(tree, &err);
        }
    }
    if((tree->symbol->token == RETVOID)){
        aux = tree->symbol->token;
        errRet = false;
    }
    if(tree->symbol->token == RETINT || tree->symbol->token == RETBOL || tree->symbol->token == EXTBOL || tree->symbol->token == RETINT){
        aux = tree->symbol->token;
        errRet = true;
    }
    if(tree->symbol->token == CALL_F) {
        TData* exist = LookupExternVar(tree->left->symbol->varname);
        if(exist){
            tree->symbol->offset = offset;
            offset += -16;
            errorCall(tree, &err);
        }else {
           printf("\033[31mLa funcion no existe\033[0m, error en linea:%d\n",tree->left->symbol->line);
           err = true;
        }
    }
    if (tree->left) {
        if(tree->symbol->token == ERETURN && inBlockIf){
            if(cantRetBlock == 0){
                cantReturns +=1;
            }
            cantRetBlock +=1;
            errorReturn(tree, aux, &err);
        }else if(tree->symbol->token == ERETURN && cantReturns == 2){
            errRet = false;
            errorReturn(tree, aux, &err);
        }else if(tree->symbol->token == ERETURN){
            errRet = false;
            errorReturn(tree, aux, &err);
        }
        if(tree->symbol->token == ENOT){
            tree->symbol->offset = offset;
            offset += -16;
            errorNot(tree, &err);
        }
        createTable(tree->left);
    }
    if (tree->right) {
        createTable(tree->right);
    }
}

void retError() {
    if(errRet){
       printf("\033[31mTe falta un return \033[0m\n");
       err = true;
    }
}

bool getError() {
    return err;
}
