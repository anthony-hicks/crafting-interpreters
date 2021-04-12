/*
    TODO: Insert, Find, Delete
    TODO: Unit tests
*/
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "dll.h"

DLL* DLL_create()
{
    DLL* list = malloc(sizeof(DLL));

    list->head = list->tail = NULL;

    return list;
}

void DLL_destroy(DLL* list)
{
    free(list);
}

DLL* DLL_insert(char* string, int len, DLL* list)
{
    // TODO: Make a Node_create() function?
    Node* n = malloc(sizeof(Node));
    n->string = malloc(sizeof(char) * len);
    strncpy(n->string, string, len);

    if (list->head == NULL)
    {
        list->head = n;
        list->tail = n;
        n->prev = NULL;
        n->next = NULL;
    }
    else
    {
        list->tail->next = n;

        n->prev = list->tail;
        n->next = NULL;

        list->tail = n;
    }
    return list;
}

bool DLL_find(char* toFind, DLL* list)
{
    // TODO
    Node* iter = list->head;

    while (iter != NULL)
    {
        if (strcmp(iter->string, toFind) == 0)
        {
            return true;
        }
        iter = iter->next;
    }
    return false;
}

DLL* DLL_delete(char* toDelete, int len, DLL* list)
{
    // TODO
    return list;
}
