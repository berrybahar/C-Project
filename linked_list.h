#define ADD_TO_LIST 0
#define IS_THERE_MACRO 1
typedef struct node 
{
    char* name;
    void* data;
    struct node* next;
} Node;
 
typedef struct list 
{
    int size;
    Node* head;
} List;

List* create_list();
int add_to_list(List* list, char* name, void* data);
void* remove_from_list(List* list);
void free_list(List* list);
int is_node_in_list(List* list, Node *temp, char *name, int type);