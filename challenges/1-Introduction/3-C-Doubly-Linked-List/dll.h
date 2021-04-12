#ifndef DLL_H
#define DLL_H

#include <stdbool.h>

typedef struct Node
{
    char* string;
    int len;

    struct Node* prev;
    struct Node* next;
} Node;

typedef struct DLL
{
    Node* head;
    Node* tail;
} DLL;


DLL* DLL_create();
void DLL_destroy();
DLL* DLL_insert(char* string, int len, DLL* list);
bool DLL_find(char* toFind, DLL* list);
DLL* DLL_delete(char* toDelete, int len, DLL* list);

#endif
