#include "main.h"
#include <string.h>
#include <ctype.h>
#include<stdlib.h>

Status division(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **result_head, Dlist **result_tail)
{
    Dlist *temp1_head = NULL,*temp1_tail = NULL;
    Dlist *new = malloc(sizeof(Dlist));
    new->data = 0;
    new->prev = NULL;
    new->next = NULL;
    temp1_head = new;
    temp1_tail = new;

    Dlist *temp2_head = NULL,*temp2_tail = NULL;
    Dlist *new1 = malloc(sizeof(Dlist));
    new1->data = 1;
    new1->prev = NULL;
    new1->next = NULL;
    temp2_head = new1;
    temp2_tail = new1;

    Dlist *temp3_head = NULL,*temp3_tail = NULL;
    
    int compare_result = compare(*head1, *tail1, *head2, *tail2);
    while (compare_result == 2 || compare_result == 3)
    {
        Dlist *new_head = NULL, *new_tail = NULL;

        addition(&temp1_head,&temp1_tail,
             &temp2_head,&temp2_tail,
             &new_head,&new_tail);

        dl_delete_list(&temp1_head, &temp1_tail);

        temp1_head = new_head;
        temp1_tail = new_tail;

        subtraction(head1,tail1,head2,tail2,&temp3_head,&temp3_tail);
        
        Dlist *old_head = *head1;
        Dlist *old_tail = *tail1;

        *head1 = temp3_head; 
        *tail1 = temp3_tail;  

        dl_delete_list(&old_head, &old_tail);

        temp3_head = NULL; 
        temp3_tail = NULL;

        compare_result = compare(*head1, *tail1, *head2, *tail2);
    }
    *result_head = temp1_head; 
    *result_tail = temp1_tail;
    return SUCCESS;
}
