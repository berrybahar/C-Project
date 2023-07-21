#include "assembler.h"

/*don't forget to free the memory after you use (free_list(int_list);)*/

List* create_list() 
{
    List* new_list = (List*)malloc(sizeof(List));
    new_list->size = 0;
    new_list->head = NULL;
    return new_list;
}
 
void add_to_list(List* list, char* name, short number)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->name = name;
    new_node->number = number;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void remove_from_list(List* list) 
{
    Node* node_to_remove = list->head;
    if (list->size == 0) {
        return ;
    }
    list->head = node_to_remove->next;
    free(node_to_remove);
    list->size--;
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