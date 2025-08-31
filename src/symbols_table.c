#include "../include/symbols_table.h"

TData *table = NULL;
int num = 0;
int numScope = 0;

TData *CreateSymbol(char *name, TOKENS token, int size, int line) {
    TData *newSymbol = (TData *)malloc(sizeof(TData));
    if (!newSymbol) return NULL;
    newSymbol->id = num++;
    newSymbol->varname = name;
    newSymbol->token = token;
    newSymbol->line = line;
    newSymbol->value = 0;
    newSymbol->table = NULL;
    newSymbol->offset = 0;
    newSymbol->next = NULL;
    return newSymbol;
}

TData *getTable() {
    return table;
}

int getScope() {
    return numScope;
}

// Push: install a new scope in the table
void InstallScope() {
    char *name = "SCOPE";
    numScope++;
    TData *scope = CreateSymbol(name, OTHERS, 0, 0);
    if (!scope) {
        printf("Error: could not allocate memory for scope\n");
        exit(1);
    }
    scope->next = table;
    table = scope;
}

TData *LookupInCurrentLevel(char *name) {
    if (!name || !table) return NULL;
    TData *head = table->table;
    while (head) {
        if (strcmp(name, head->varname) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

TData *LookupInTableAux(char *name, TData *symTable) {
    if (!name || !symTable) return NULL;
    TData *head = symTable->table;
    while (head) {
        if (strcmp(name, head->varname) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void InstallInCurrentScope(TData *symbol) {
    if (!symbol || !table) return;
    if (LookupInCurrentLevel(symbol->varname) == NULL) {
        symbol->next = table->table;
        table->table = symbol;
    } else {
        printf("Simbolo existente, linea de error: %d\n", symbol->line);
        exit(1);
    }
}

void PopScope() {
    if (!table) return;
    TData *elim = table;
    table = table->next;
    numScope--;
    free(elim);
}

void InstallParam(TData *param, TData *tablaFunc) {
    if (!param || !tablaFunc) return;
    if (LookupInTableAux(param->varname, tablaFunc) == NULL) {
        param->next = tablaFunc->table;
        tablaFunc->table = param;
    } else {
        printf("Simbolo existente, linea de error: %d\n", param->line);
        exit(1);
    }
}

TData *LookupExternVar(char *name) {
    if (!name) return NULL;
    TData *head = table;
    while (head) {
        TData *aux = LookupInTableAux(name, head);
        if (aux) return aux;
        head = head->next;
    }
    return NULL;
}

void setValue(TData *symbol, int valor) {
    if (symbol) {
        symbol->value = valor;
    } else {
        printf("Error: simbolo es NULL\n");
    }
}

int *typeParam(TData *symTabla) {
    int count = cantArguments(symTabla);
    int *types = (int *)malloc(count * sizeof(int));
    if (!types) return NULL;
    int index = count - 1;
    TData *aux = symTabla ? symTabla->table : NULL;
    while (aux) {
        if (aux->token == PARAMINT || aux->token == PARAMBOOL) {
            types[index--] = aux->token;
        }
        aux = aux->next;
    }
    return types;
}

int cantArguments(TData *symTabla) {
    int cant = 0;
    TData *aux = symTabla ? symTabla->table : NULL;
    while (aux) {
        if (aux->token == PARAMBOOL || aux->token == PARAMINT) {
            cant++;
        }
        aux = aux->next;
    }
    return cant;
}

void prinTable() {
    TData *aux = table;
    printf("TABLA DE SIMBOLOS\n");
    printf("| nam   |    typ   | prof | valor \n");
    while (aux) {
        printf("| %s |", aux->varname);
        printf(" %s |", string[aux->token]);
        printf(" %d |", aux->offset);
        printf(" %d |\n", aux->value);
        if (aux->table) {
            TData *aux1 = aux->table;
            while (aux1) {
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

void addOffset(TData *symbol, int offset) {
    if (symbol) {
        symbol->offset = offset;
    }
}