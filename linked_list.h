typedef struct node {
    char *name;
    short *number;
    struct node* next;
} Node;
 
typedef struct list {
    int size;
    Node* head;
} List;

List* create_list();
void add_to_list(List* list, char *name, short*number);
void* remove_from_list(List* list);
void free_list(List* list);