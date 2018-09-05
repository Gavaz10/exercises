#include <stdio.h>

struct node
{
    int data;
    struct node* next;
};

struct linked_list
{
    struct node* head;
    int size;
};

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void print_list(struct linked_list* list)
{
    struct node* cur = ((*list).head);
    for(int i=0;i<(*list).size;i++)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void insert_node(struct linked_list* list, int element)
{
    struct node* cur = ((*list).head);
    if((*list).size == 0)
    {
        (*list).head = malloc(sizeof((*list).head));
        (*list).head->data = element;
    }
    else
    {
        for(int i=1;i<(*list).size;i++)
        {
            cur = cur->next;
        }
        cur->next = malloc(sizeof(cur->next));
        cur->next->data = element;
    }
    (*list).size++;
}

void delete_node(struct linked_list* list, struct node* node)
{
    struct node* cur = ((*list).head);
    if(cur == node)
    {
        (*list).head = cur->next;
        (*list).size--;
        return;
    }
    struct node* prev = ((*list).head);
    cur = cur->next;

    for(int i=1;i<(*list).size;i++)
    {
        if(cur == node)
        {

            prev->next = cur->next;
            (*list).size--;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

int main()
{
    struct linked_list list;
    list.size = 0;
    insert_node(&list, 5);
    insert_node(&list, 1);
    insert_node(&list, 123);
    insert_node(&list, 321);
    insert_node(&list, 777);
    insert_node(&list, 666);
    insert_node(&list, 555);
    delete_node(&list, (list.head->next->next));//delete 3rd
    print_list(&list);
}
