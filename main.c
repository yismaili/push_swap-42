#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_push *start = NULL;

	if (argc < 2)
		ft_die("check");
	argc = 1;
	while (argv[argc])
	{
		ft_lstnew(&start, ft_atoi(argv[argc]));
		argc++;
	}

    printf("\n Linked list before calling swapNodes() \n ");
    printList(start);

    ft_swapnodes(&start, 1, 2);
// ft_sa(&start);

    printf("\n Linked list after  calling swapNodes() \n ");
    printList(start);

    return 0;
}