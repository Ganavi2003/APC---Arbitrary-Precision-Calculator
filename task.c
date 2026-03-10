#include<stdio.h>
#include "main.h"
#include <string.h>
#include <ctype.h>
#include<stdlib.h>
Status read_and_validate(int argc ,char *argv[],Arguments *ArgInfo)
{
    if(argc < 4)
    {
        printf("Number aruments passed not enough to prform operations!!!\n");
        return FAILURE;
    }

    //operand1 validation
    if(argv[1] == NULL)
    {
        printf("You have not passed any argument!!!\n");
        return FAILURE;
    }
    ArgInfo->operand1 = argv[1];
    
    int start1;
    if(ArgInfo->operand1[0] == '+' || ArgInfo->operand1[0] == '-' )
    {
        start1 = 1;
    }
    else
        start1 = 0;
    
    for(int i = start1; ArgInfo->operand1[i] != '\0' ; i++ )
    {
        if(isdigit(ArgInfo->operand1[i]) == 0)
        {
            printf("You have not passed digits as operand1!!!\n");
            return FAILURE;
        }
    }
    
    //operator validation
    if(argv[2] == NULL)
    {
        printf("You have not passed operator as argument!!!\n");
        return FAILURE;
    }
    if(strcmp(argv[2], "+") != 0 && strcmp(argv[2], "-") != 0 && strcmp(argv[2], "*") != 0 && strcmp(argv[2], "/") != 0)
    {
        printf("You have not passed valid operator to perform operation!!!\n");
        return FAILURE; 
    }
    ArgInfo->operat = argv[2];

     //operand2 validation
    if(argv[3] == NULL)
    {
        printf("You have not passed operand2 as argument!!!\n");
        return FAILURE;
    }
    ArgInfo->operand2 = argv[3];

    int start2;
    if(ArgInfo->operand2[0] == '+' || ArgInfo->operand2[0] == '-' )
    {
        start2 = 1;
    }
    else
        start2 = 0;
    
    for(int i = start2; ArgInfo->operand2[i] != '\0' ; i++ )
    {
        if(isdigit( ArgInfo->operand2[i]) == 0)
        {
            printf("You have not passed digits as operand2!!!\n");
            return FAILURE;
        }
    }
    return SUCCESS;
}

int check_sign(char *op1,char *op2,char *operat,Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
    int compare_result = compare(*head1, *tail1, *head2, *tail2);
    if((op1[0] == '+' || (op1[0] >= '0' && op1[0] <= '9')) && (op2[0] == '+' || (op2[0] >= '0' && op2[0] <= '9')))
    {
        if(operat[0] == '-' && compare_result == 1)
        {
            return -1;
        }
        return 1;
    }
    else if(op1[0] == '-'&&  op2[0] == '-' )
    {
        if(operat[0] == '+')
            return -1;
        else if(operat[0] == '-' && compare_result == 2)
            return -1;
        else
            return 1;
    }
    else if(op1[0] == '-' && (op2[0] == '+' || (op2[0] >= '0' && op2[0] <= '9')))
    {
        if(operat[0] == '+'){
            operat[0] = '-';
            if(compare_result == 1)
            return 1;
            else
            return -1;
        }
        else if(operat[0] == '-')
        {
            operat[0] = '+';
            return -1;
        }
        else
            return -1;
    }
    else if((op1[0] == '+' || (op1[0] >= '0' && op1[0] <= '9')) && op2[0] == '-')
    {
        if(operat[0] == '-')
        {
            operat[0] = '+';
            return 1;
        }
        else if(operat[0] == '+')
        {
            operat[0] = '-';
            if(compare_result == 2)
            return 1;
            else
            return -1;
        }
        else
        return -1;
    }
}

Status convert_string_to_list(Dlist **head, Dlist **tail,char *operand)
{
    int start;
    if(operand[0] == '+' || operand[0] == '-' )
        start = 1;
    else
        start = 0;
    
    for (int i = start; i < strlen(operand) ; i++)
    {
        Dlist *new = malloc(sizeof(Dlist));
        new->prev = NULL;
        new->next = NULL;
        new->data = operand[i] - '0';

        if(*head == NULL)
        {
            *head = new;
            *tail = new;
        }
        else
        {
            (*tail)->next = new;
            new->prev = *tail;
            *tail = new;
        }
    }

    return SUCCESS;
}

int compare(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2)
{
    int len1 = 0, len2 = 0;
    Dlist *temp1 = head1, *temp2 = head2;

    while (temp1)
    {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        len2++;
        temp2 = temp2->next;
    }

    if (len1 < len2)
        return 1;   // operand1 smaller

    if (len1 > len2)
        return 2;   // operand1 larger

    temp1 = head1;
    temp2 = head2;
    while (temp1 && temp2)
    {
        if (temp1->data < temp2->data)
            return 1;   // smaller
        if (temp1->data > temp2->data)
            return 2;   // larger
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return 3;   // equal
}

void print_result(Dlist *head)
{
	if (head == NULL)
	    printf("INFO : List is empty\n");
	else
	{
	    while (head)		
	    {
		    printf("%d", head -> data);
		    head = head -> next;
	    }
    	printf("\n");
    }
}

void print_list(Dlist *head)
{
	if (head == NULL)
	    printf("INFO : List is empty\n");
	else
	{
	    printf("\033[1;35mHead -> \033[0m ");
	    while (head)		
	    {
		    printf("%d <-", head -> data);
		    head = head -> next;
		    if (head)
		        printf("> ");
	    }
    	printf(" \033[1;35mTail\033[0m\n");
    }
}

int dl_delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
    {
        return FAILURE;
    }
    else
    {
        while((*head)->next != NULL)
        {
            (*head) = (*head)->next;
            free((*head)->prev);
            (*head)->prev = NULL;
        }
        free(*head);
        *head = *tail = NULL;
    }
}