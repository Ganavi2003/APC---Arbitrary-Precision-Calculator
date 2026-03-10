#include "main.h"
#include <string.h>
#include <ctype.h>
#include<stdlib.h>

Status subtraction(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **result_head, Dlist **result_tail)
{
    Dlist *tail1_tam = *tail1;
    Dlist *tail2_tam = *tail2;
    *result_head = NULL;
    *result_tail = NULL;
    int borrow = 0;
    int value;
    while (tail1_tam != NULL || tail2_tam != NULL)
    {
        int val1,val2;
        if(tail1_tam == NULL)
            val1 = 0;
        else
            val1 = tail1_tam->data;

        if(tail2_tam == NULL)

            val2 = 0;
        else
            val2 = tail2_tam->data;
        
        val1 = val1 - borrow; 
        if (val1 < val2) 
        { 
            val1 = val1 + 10; 
            borrow = 1; 
        } else 
        borrow = 0; 
        
        int value = val1 - val2;
        Dlist *new_result = malloc(sizeof(Dlist));
        new_result->prev = NULL;
        new_result->next = NULL;
        new_result->data = value;
    
        if(*result_head == NULL)
        {
            *result_head = new_result;
            *result_tail = new_result;
        }else
        {
            (*result_head)->prev = new_result;
            new_result->next = *result_head;
            (*result_head) = new_result;
        }
        if (tail1_tam != NULL) 
            tail1_tam = tail1_tam->prev; 
        if (tail2_tam != NULL) 
            tail2_tam = tail2_tam->prev;
    }
    while (*result_head && (*result_head)->data == 0 && (*result_head)->next != NULL)
    {
        Dlist *temp = *result_head;
        *result_head = (*result_head)->next;
        (*result_head)->prev = NULL;
        free(temp);
    }
    return SUCCESS;
}
