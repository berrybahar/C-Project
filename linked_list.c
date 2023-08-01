#include "assembler.h"
 
List* create_list() 
{
    List* new_list = (List*)malloc(sizeof(List));
    new_list->size = 0;
    new_list->head = NULL;
    return new_list;
}

 /*returns true if the node is added*/
int add_to_list(List* list, char* name, void* data) 
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(is_node_in_list(list, new_node, name, ADD_TO_LIST) == FALSE)
    {
        new_node->name = name;
        new_node->data = data;
        new_node->next = list->head;
        list->head = new_node;
        list->size++;
        return TRUE;
    }
    return FALSE;
}
 
void* remove_from_list(List* list) 
{
    Node* node_to_remove;
    void* data;
    if (list->size == 0) {
        return NULL;
    }
    node_to_remove = list->head;
    data = node_to_remove->data;
    list->head = node_to_remove->next;
    free(node_to_remove);
    list->size--;
    return data;
}
 
void free_list(List* list) 
{
    Node* current_node = list->head;
    while (current_node != NULL) {
        Node* next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    free(list);
}

/**
 * 
*/
int is_node_in_list(List* list, Node *temp, char *name, int type)
{
    if (list->size == 0) 
    {
        return FALSE;
    }
    temp = list->head;
    while(temp != NULL)
    {
        if(type == ADD_TO_LIST)
        {
            if(strstr(temp->name, name) != NULL)
            return TRUE;
        }
        else if(type == IS_THERE_MACRO)
        {
            if(strstr(name, temp->name) != NULL)
            return TRUE;
        }
        temp = temp->next;
    }
    
    return FALSE;
}