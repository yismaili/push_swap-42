#include "push_swap.h"

void	ft_create_stackb(t_data *data, int argc, char **argv)
{
	int		i;
	t_stack	*nude;
	i = 1;

	nude = (t_stack*)malloc(sizeof(t_stack));
	if (!nude)
		ft_die("error stack\n");
	data->stack_b = nude;
	while (i < argc)
	{
		nude->content = ft_atoi(argv[i]);
		nude->next = NULL;
		if (i + 1 < argc)
		{
			nude->next = (t_stack*)malloc(sizeof(t_stack));
			if (!nude)
				ft_die("error stack\n");
			nude = nude->next;
		}
		i++;
	}
	data->stack_end_b = nude;
}