typedef struct _Argument
{
    char *operand1;
    char *operand2;
    char *operat;
}Arguments;

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;

typedef enum
{
    SUCCESS,
    FAILURE
} Status;

Status read_and_validate(int argc,char *argv[],Arguments *ArgInfo);

Status convert_string_to_list(Dlist **head, Dlist **tail,char *operand);

Status addition(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **result_head, Dlist **result_tail);

Status subtraction(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **result_head, Dlist **result_tail);

Status multiplication(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **result_head, Dlist **result_tail);

Status division(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **result_head, Dlist **result_tail);

int compare(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2);

int dl_delete_list(Dlist **head, Dlist **tail);

int check_sign(char *op1,char *op2,char *operat,Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);

void print_result(Dlist *head);

void print_list(Dlist *head);

