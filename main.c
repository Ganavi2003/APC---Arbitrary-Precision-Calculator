#include<stdio.h>
#include "main.h"
#include <string.h>
#include<stdlib.h>

int compare_result;
int main(int argc , char *argv[])
{
    Arguments ArgInfo;
    int ret = read_and_validate(argc,argv,&ArgInfo);
    if(ret == SUCCESS)
    {
        printf("----------------------------------------------------------------\n");
        printf("\033[1;32m                      VALIDATION DONE                           \033[0m\n");
        printf("----------------------------------------------------------------\n");
    }
    else{
        printf("\033[1;31mInvalid Arguments passed\033[0m\n");
        return 1;
    }

    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *result_head = NULL, *result_tail = NULL;

    int ret1 = convert_string_to_list(&head1 , &tail1 ,ArgInfo.operand1);
    if(ret1 == FAILURE)
    {
        printf("\033[1;31mconversion not done\033[0m\n");
        return 1;
    }
    else{
        
        printf("conversion from string to linked list of operand1 is done...\n");
        print_list(head1);
    }

    int ret2 = convert_string_to_list(&head2 , &tail2 ,ArgInfo.operand2);
    if(ret2 == FAILURE)
    {
        printf("\033[1;31mconversion not done\033[0m\n");
        return 1;
    }
    else{
        printf("conversion from string to linked list of operand2 is done...\n");
        print_list(head2);
    }

    int return_sign = check_sign(ArgInfo.operand1,ArgInfo.operand2,ArgInfo.operat,&head1,&tail1,&head2,&tail2);

    char c = argv[2][0];
    switch(c)
    {
        case '+':
        int retur = addition(&head1,&tail1,&head2,&tail2,&result_head,&result_tail);
        if(retur == SUCCESS)
        {
            printf("----------------------------------------------------------------\n");
            printf("\033[96m                      ADDITION DONE...                           \033[0m\n");
            printf("----------------------------------------------------------------\n");
            if(return_sign == -1)
            {
                result_head->data = result_head->data * -1;
            }
            printf("\033[35mRESUL5 --> \033[0m");
            print_result(result_head);
        }
        else        
        {
            printf("\033[1;31mcant do addition\033[0m\n");
            return 0;
        }
        break;

        case '-':
        {
            compare_result = compare(head1, tail1, head2, tail2);

            if(compare_result == 3)
            {
                printf("----------------------------------------------------------------\n");
                printf("\033[96m                 SUBTRACTION DONE...                           \033[0m\n");
                printf("----------------------------------------------------------------\n");
                Dlist *new = malloc(sizeof(Dlist));
                new->data = 0;
                new->prev = NULL;
                new->next = NULL;
                result_head = new;
                printf("\033[35mRESUL5 --> \033[0m");
                print_result(result_head);
                break;
            }
            if(compare_result == 1)   
            {
                Dlist *tmp_head = head1;
                Dlist *tmp_tail = tail1;

                head1 = head2;
                tail1 = tail2;
                head2 = tmp_head;
                tail2 = tmp_tail;
            }

            int retur1 = subtraction(&head1,&tail1,&head2,&tail2,&result_head,&result_tail);

            if(retur1 == SUCCESS)
            {
                printf("----------------------------------------------------------------\n");
                printf("\033[96m                   SUBTRACTION DONE...                          \033[0m\n");
                printf("----------------------------------------------------------------\n");
                if(return_sign == -1)
                {
                    result_head->data = result_head->data * -1;
                }
                printf("\033[35mRESUL5 --> \033[0m");
                print_result(result_head);
            }
            else
            {
                printf("\033[1;31mcant do subtraction\033[0m\n");
                return 0;
            }
        }
        break;

        case '*':
        int retur2 = multiplication(&head1,&tail1,&head2,&tail2,&result_head,&result_tail);
        if(retur2 == SUCCESS)  
        {
            printf("----------------------------------------------------------------\n");
            printf("\033[96m                    MULTIPLICATION DONE...                           \033[0m\n");
            printf("----------------------------------------------------------------\n");
            if(return_sign == -1)
            {
                result_head->data = result_head->data * -1;
            }
            printf("\033[35mRESUL5 --> \033[0m");
            print_result(result_head);
        }
        else
        {
            printf("\033[1;31mcant do subtraction\033[0m\n");
            return 0;
        }
        break;

        case '/':
        if (head2->data == 0 && head2->next == NULL)
        {
            printf("\033[1;31mError: Division by zero\033[0m\n");
            return 0;
        }

        compare_result = compare(head1, tail1, head2, tail2);

        if(compare_result == 3)
        {
            printf("\033[1;34mEntered operand1 and operand2 are equal for division\033[0m\n");
            Dlist *new = malloc(sizeof(Dlist));
            new->data = 1;
            new->prev = NULL;
            new->next = NULL;
            result_head = new;
            printf("\033[35mRESUL5 --> \033[0m");
            print_result(result_head);
        }
        else if (compare_result == 1)
        {
            printf("\033[1;34mEntered operand1 is smaller than operand2 for division\033[0m\n");
            Dlist *new = malloc(sizeof(Dlist));
            new->data = 0;
            new->prev = NULL;
            new->next = NULL;
            result_head = new;
            result_tail = new;
            printf("\033[35mRESUL5 --> \033[0m");
            print_result(result_head);
        }
        else
        {
            int retur2 = division(&head1,&tail1,&head2,&tail2,&result_head,&result_tail);
            if(retur2 == SUCCESS)
            {
                printf("----------------------------------------------------------------\n");
                printf("\033[96m                        DIVISION DONE...                           \033[0m\n");
                printf("----------------------------------------------------------------\n");
                if(return_sign == -1)
                {
                    result_head->data = result_head->data * -1;
                }
                printf("\033[35mRESUL5 --> \033[0m");
                print_result(result_head);
            }
            else
            {
                printf("\033[1;31mcant do Division\033[0m\n");
                return 0;
            }
        }
        break;
        default:
        printf("\033[1;31mInvalid operator\033[0m\n");
    }  
}
