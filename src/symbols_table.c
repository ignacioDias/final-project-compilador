#include "../include/symbols_table.h"
TData *table = NULL;

int num = 0;
int numScope = 0;

struct TData * CreateSymbol(char *name, TOKENS token, int size, int line){
    TData *newSymbol = (TData *)malloc(sizeof(TData));
    newSymbol->id=num++;
    newSymbol->varname = name;
    newSymbol->token = token;
    newSymbol->line = line;
    newSymbol->value = 0;
    newSymbol->table = NULL;
    newSymbol->offset = 0;
    return newSymbol;
}

struct TData * getTable(){
    return table;
}

int getScope() {
  return numScope;
}

//push - instalo en la tabla el scope
void InstallScope(){
  char aux[10];
  char *name = "SCOPE";
  numScope++;
  sprintf(aux,"Scope %d",numScope);
  TData *scope = CreateSymbol(name,OTHERS, 0, 0);

  scope->next =  table;
  table = scope;
}

TData *LookupInCurrentLevel(char * name){
  TData *head = table->table;
  if(name == NULL) {
    return NULL;
  }
  while(head != NULL) {
    if(strcmp(name, head->varname)==0){
      return head;
    }
    head = head->next;
  }
  return NULL;
}

TData *LookupInTableAux(char * name, TData *symTable){
  TData *head = symTable->table;
  if(name == NULL) {
    return NULL;
  }
  while(head != NULL) {
    if(strcmp(name, head->varname)==0){
      return head;
    }
    head = head->next;
  }
  return NULL;
}

void InstallInCurrentScope (TData *symbol){
  TData *head = table;
  if(LookupInCurrentLevel(symbol->varname) == NULL) {
    symbol->next =  head->table;
    head->table = symbol;
  } else {
    printf("Simbolo existente, linea de error: %d", symbol->line);
    exit(1);
  }
}

void PopScope(){
  TData* elim = table;
  table = table -> next;
  numScope--;
  free(elim);
}

void InstallParam (TData *param,TData *tablaFunc){
  TData *head = tablaFunc;
  if(LookupInTableAux(param->varname,head) == NULL) {
    param->next =  head->table;
    head->table = param;
  } else {
    printf("Simbolo existente, linea de error: %d", param->line);
    exit(1);
  }
}

TData *LookupExternVar(char * name) {
  TData *head = table;
  if(LookupInTableAux(name,head) == NULL){
    while(head != NULL) {
      TData *aux = LookupInTableAux(name, head);
      if(aux){
        return aux;
      }
      head = head->next;
    }
  }
}

void setValue(TData* symbol, int valor){
    if(symbol != NULL) {
      symbol->value = valor;
    } else {
        printf("Error: simbolo es NULL\n");
    }
}

int* typeParam(TData* symTabla){
  int index = cantArguments(symTabla);
  int* types = (int*) malloc(index * sizeof(int));
  index -= 1;
  TData *aux = symTabla->table;
  while(aux != NULL) {
    if (aux->token == PARAMINT || aux->token == PARAMBOOL) {
      types[index] = aux->token;
      index -= 1;
    }
    aux = aux->next;
  }
  return types;
}

int cantArguments(TData* symTabla){
  int cant = 0;
  TData *aux = symTabla->table;
  while(aux != NULL) {
    if (aux->token == PARAMBOOL || aux->token == PARAMINT) {
      cant += 1;
    }
    aux = aux->next;
  }
  return cant;
}

void prinTable(){
    TData *aux = table;
    printf("TABLA DE SIMBOLOS\n");
    printf("| nam   |    typ   | prof | valor \n");
    while(aux != NULL) {
        //printf("Func\n");
        printf("| %s |", aux->varname);
        printf(" %s |", string[aux->token]);
        printf(" %d |", aux->offset);
        printf(" %d |\n", aux->value);
        if(aux->table != NULL) {
            TData *aux1 = aux->table;
            while(aux1 != NULL) {
              printf("| %s |", aux1->varname);
              printf(" %s |", string[aux1->token]);
              printf(" %d |", aux1->offset);
              printf(" %d |\n", aux1->value);
              aux1 = aux1->next;
            }
        }
        aux = aux->next;
    }
}

void addOffset(TData* symbol, int offset) {
  symbol->offset = offset;
}