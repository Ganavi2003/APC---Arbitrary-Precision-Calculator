#include "main.h"
#include <string.h>
#include <ctype.h>
#include<stdlib.h>

Status multiplication(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **result_head, Dlist **result_tail)
{
    Dlist *tail2_tam = *tail2;
    Dlist *tem1_head = NULL,*tem1_tail = NULL;
    Dlist *tem2_head = NULL,*tem2_tail = NULL;
    int count = 0;
    while(tail2_tam != NULL)
    {
        tem1_head = NULL;
        tem1_tail = NULL;

        int val1, val2, carry1 = 0;
        val2 = tail2_tam->data;

        Dlist *tail1_tam = *tail1;
        while (tail1_tam != NULL)
        {
            val1 = tail1_tam->data;
            int value;
            value = val1 * val2 + carry1;
            carry1 = value / 10;
            Dlist *new = malloc(sizeof(Dlist));
            new->prev = NULL;
            new->next = NULL;
            new->data = value % 10;

            if(tem1_head == NULL)
            {
                tem1_head = new;
                tem1_tail = new;
            }else
            {
                tem1_head->prev = new;
                new->next = tem1_head;
                tem1_head = new;
            }
            tail1_tam = tail1_tam->prev; 
        }
        if (carry1 > 0) 
        { 
            Dlist *new = malloc(sizeof(Dlist)); 
            new->data = carry1;
            new->prev = NULL; 
            new->next = tem1_head; 
            tem1_head->prev = new; 
            tem1_head = new; 
        }

        for (int i = 0; i < count; i++) 
        { 
            Dlist *new = malloc(sizeof(Dlist)); 
            new->data = 0; 
            new->prev = tem1_tail; 
            new->next = NULL; 
            tem1_tail->next = new; 
            tem1_tail = new; 
        }
        if (*result_head == NULL) 
        {
            *result_head = tem1_head;
            *result_tail = tem1_tail;
        }
        else
        {
            tem2_head = NULL;
            tem2_tail = NULL;
            addition(result_head,result_tail,&tem1_head,&tem1_tail,&tem2_head,&tem2_tail);
            dl_delete_list(&tem1_head, &tem1_tail);
            *result_head = tem2_head; 
            *result_tail = tem2_tail;
        }
        tail2_tam = tail2_tam->prev;
        count++;
    }
    return SUCCESS;
}