CC= gcc
NAME=push_swap
FLAGS= -Wall -Wextra -Werror
SRCS=push_swap.c\
	push.c swap.c\
	revers_rotate.c\
	rotate.c\
	sort_small.c\
	utiles.c\
	create_stacks.c\
	push_to_b.c\
	push_to_a.c\
	push_big_number.c\
	args_handle.c

OBJS=$(SRCS:.c=.o)
INCL= push_swap.h

GREY=$'\x1b[30m
GREEN=$'\x1b[32m
YELLOW=$'\x1b[33m
BLUE=$'\x1b[34m
PURPLE=$'\x1b[35m
CYAN=$'\x1b[36m
WHITE=$'\x1b[37m

all:$(NAME)
%.o: %.c $(INCL)
	$(CC) $(FLAGS) $< $(INCL) -c

$(NAME):$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf *.o

fclean:clean
	rm -rf *.a
	rm -rf push_swap

.PHONY: all gnl utils bonus clean fclean re

