#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#define NAME 51
#define LASTNAME 51

typedef struct
{
    char name[NAME];
    char lastName[LASTNAME];
    int clienteId;
    int isEmpty;
}Cliente;

Cliente* cliente_new();
void cliente_delete();
Cliente* cliente_newConParametros(char* name,char* lastName,int clienteId,int isEmpty);

int cliente_setName(Cliente* this,char* name);
int cliente_getName(Cliente* this,char* name);

int cliente_setLastName(Cliente* this,char* lastName);
int cliente_getLastName(Cliente* this,char* lastName);

int cliente_setClienteId(Cliente* this,int clienteId);
int cliente_getClienteId(Cliente* this,int* clienteId);

int cliente_setIsEmpty(Cliente* this,int isEmpty);
int cliente_getIsEmpty(Cliente* this,int* isEmpty);

#endif // CLIENTE_H_INCLUDED
