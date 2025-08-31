#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef SYMBOL_H
#define SYMBOL_H
typedef enum TOKENS {
    VAR,
    EMAIN,
    VARINT,
    VARBOOL,
    CONSINT,
    CONSBOOL,
    PLUS,
    MINUS,
    PROD,
    EDIV,
    EMOD,
    EOR,
    EAND,
    ENOT,
    ASIGN,
    DECLARATION,
    SENTEN,
    EID,
    ERETURN,
    RETINT,
    RETBOL,
    RETVOID,
    EXTINT,
    EXTBOL,
    EXTVOID,
    EIF,
    ETHEN,
    EELSE,
    EWHILE,
    T_GREATER_THAN,
    T_LESS_THAN,
    EEQ,
    EFUNC,
    EFUNCEXTERN,
    EPROGRAM,
    EBLOQ,
    CALL_F,
    ARGS,
    PARAMINT,
    PARAMBOOL,
    OTHERS,
    BLOCK,
    BLOCK_FIN
} TOKENS;

char static string[45][41] = {"VAR","EMAIN","VARINT","VARBOOL","CONSINT","CONSBOOL","SUMA","RESTA","PROD","EDIV","EMOD","EOR","EAND","ENOT","ASIG","DECLARATION","SENTEN","EID","ERETURN","RETINT","RETBOL","RETVOID", "EXTINT",
    "EXTBOL", "EXTVOID","EIF","ETHEN","EELSE","EWHILE","T_GREATER_THAN","T_LESS_THAN","EEQ","EFUNC","EFUNCEXTERN","EPROGRAM","EBLOQ","CALL_F","ARGS", "PARAMINT", "PARAMBOOL","OTHERS","BLOCK","BLOCK_FIN"};

typedef struct TData {
    int id;
    TOKENS token;
    char* varname;     
    struct TData *next;
    int line;
    int value;
    int offset;
    struct TData *table;
} TData;

struct TData *Lookup(char * name);  
void Install(TData *symbol);  
void DeleteList();
void prinTable();
TData* CreateSymbol(char *name, TOKENS token, int size, int line);
void setValue(TData* symbol, int value);
void addOffset(TData* symbol, int offset);
int getScope();

struct TData * getTable();
void InstallInCurrentScope (TData *symbol);

void PopScope();

void InstallParam (TData *param,TData *tablaFunc);
void InstallScope();

struct TData *LookupInCurrentLevel(char * name);
struct TData *LookupInTableAux(char * name, TData *symTable);
struct TData *LookupExternVar(char * name);

int cantArguments(TData* symTabla);
int* typeParam(TData* symTabla);

#endif
