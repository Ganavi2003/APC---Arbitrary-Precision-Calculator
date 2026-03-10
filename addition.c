#include "main.h"
#include <string.h>
#include <ctype.h>
#include<stdlib.h>

Status addition(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **result_head, Dlist **result_tail)
{
    *result_head = NULL;   
    *result_tail = NULL;
    Dlist *tail1_tam = *tail1;
    Dlist *tail2_tam = *tail2;
    int carry = 0;
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

        value = val1 + val2 + carry;
        carry = value / 10;
        Dlist *new_result = malloc(sizeof(Dlist));
        new_result->prev = NULL;
        new_result->next = NULL;
        new_result->data = value % 10;
    
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

    if (carry > 0)
    {
        Dlist *new_result = malloc(sizeof(Dlist));
        new_result->data = carry;
        new_result->prev = NULL;
        new_result->next = NULL;

        (*result_head)->prev = new_result;
        new_result->next = *result_head;
        *result_head = new_result;
    }
    return SUCCESS;
}
