#include <assert.h>
#include <stddef.h>
#include <string.h>

#include "dll.h"

void test_insert()
{
    DLL* list = DLL_create();

    assert(list->head == NULL);
    DLL_insert("bruh", 4, list);
    assert(list->head != NULL);
    assert(strcmp(list->head->string, "bruh") == 0);

    DLL_destroy(list);
}

void test_create()
{
    DLL* list = DLL_create();

    assert(list->head == NULL);
    assert(list->tail == NULL);

    DLL_destroy(list);
}

void test_find_one_item()
{
    DLL* list = DLL_create();

    DLL_insert("a", 1, list);
    assert(DLL_find("a", list));

    DLL_destroy(list);
}

void test_find_two_items()
{
    DLL* list = DLL_create();

    DLL_insert("a", 1, list);
    DLL_insert("b", 1, list);
    assert(DLL_find("b", list));

    DLL_destroy(list);
}

void test_find_three_items()
{
    DLL* list = DLL_create();

    DLL_insert("a", 1, list);
    DLL_insert("b", 1, list);
    DLL_insert("c", 1, list);
    assert(DLL_find("b", list));

    DLL_destroy(list);
}

void test_find_not_found()
{
    DLL* list = DLL_create();

    DLL_insert("a", 1, list);
    DLL_insert("b", 1, list);
    DLL_insert("c", 1, list);

    assert(!DLL_find("d", list));

    DLL_destroy(list);
}

void test_delete_one_item()
{
    DLL* list = DLL_create();

    DLL_insert("a", 1, list);
    DLL_delete("a", 1, list);

    assert(!DLL_find("a", list));

    DLL_destroy(list);
}

void test_delete_two_items_del_first()
{
    DLL* list = DLL_create();

    DLL_insert("a", 1, list);
    DLL_insert("b", 1, list);

    DLL_delete("a", 1, list);

    assert(!DLL_find("a", list));

    DLL_destroy(list);
}

void test_delete_two_items_del_last()
{
    DLL* list = DLL_create();

    DLL_insert("a", 1, list);
    DLL_insert("b", 1, list);

    DLL_delete("b", 1, list);

    assert(!DLL_find("b", list));

    DLL_destroy(list);
}

void test_delete_three_items_del_middle()
{
    DLL* list = DLL_create();

    DLL_insert("a", 1, list);
    DLL_insert("b", 1, list);
    DLL_insert("c", 1, list);

    DLL_delete("b", 1, list);

    assert(!DLL_find("b", list));

    DLL_destroy(list);
}

int main()
{
    test_create();
    test_insert();
    test_find_one_item();
    test_find_two_items();
    test_find_three_items();
    test_find_not_found();
    test_delete_one_item();
    test_delete_two_items_del_first();
    test_delete_two_items_del_last();
    test_delete_three_items_del_middle();

    return 0;
}
