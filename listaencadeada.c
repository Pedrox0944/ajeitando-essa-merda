#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int value;
    struct Node *prox;
} node;

typedef struct 
{
    node *start;
    node *end;
    node *assistant;
    int size_list;
} simple_list;

simple_list *create_list()
{
    simple_list *new = malloc(sizeof(simple_list));
    new->start = NULL;
    new->end = NULL;
    new->assistant = NULL;
    new->size_list = 0;
    return new;
}

node *create_node(int value)
{
    node *new = malloc(sizeof(node));
    new->value = value;
    new->prox = NULL;
    return new;
}

void add(simple_list *list, node *node, int pos)
{
    if (list == NULL || node == NULL) return;
  
    if (list->start == NULL) 
    {
        list->start = node;
        list->end = node;
    }
    else if (pos == 0) 
    {
        node->prox = list->start;
        list->start = node;
    }
    else if (pos == list->size_list) 
    {
        list->end->prox = node;
        list->end = node;
    }
    else 
    {
        list->assistant = list->start;
        for (int i = 0; i < pos-1 ; i++) 
        {
            list->assistant = list->assistant->prox;
        }
        node->prox = list->assistant->prox;
        list->assistant = node;
    }
    list->size_list++;
}

int delete(simple_list *list, int pos)
{
    if (list->size_list >= 0 && pos < list->size_list) 
    {
        node *trash = list->start;
        if (list->size_list == 1) 
        {
            trash = list->start;
            list->start = NULL;
            list->end = NULL;
        }
        else if (pos == 0) 
        {
            trash = list->start;
            list->start = list->start->prox;
        }
        else if(pos == list->size_list - 1)
        {
            list->assistant = list->start;
            for (int i = 0; i < pos-1; i++) 
            {
                trash = list->end;
                list->end = list->assistant;
                list->end->prox = NULL;
            }
        }
        else 
        {
            list->assistant = list->start;
            for (int i = 0; i < pos-1; i++) 
            {
                list->assistant = list->assistant->prox;
            }
            trash = list->assistant->prox;
            list->assistant->prox = trash->prox;
        }
        free(trash);
        list->size_list--;
        return trash->value;
    }
    else {
        puts("List empty");
        return -1;
    }
}

void print(simple_list *list)
{
    puts("--- START LIST ---");
    list->assistant = list->start;
    while (list->assistant != NULL) 
    {
        printf("%d\n", list->assistant->value);
        list->assistant = list->assistant->prox;
    }
    puts("--- END LIST ---");
    puts("");
}

int main()
{
    simple_list *list = create_list();
    node *firtsnode = create_node(10);
    node *secodnode = create_node(9);
    node *finalnode = create_node(8);
    add(list, firtsnode, 0);
    add(list, secodnode, 1);
    add(list, finalnode, 2);
    print(list);
    delete(list, 0);
    print(list);

    return 0;
}
