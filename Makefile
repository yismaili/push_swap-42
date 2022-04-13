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
	free.c\
	push_big_number.c\
	utils_tow.c\
	args_handle.c
BONUSRC =  push.c\
		swap.c\
		revers_rotate.c\
		rotate.c\
		sort_small.c\
		utiles.c\
		create_stacks.c\
		push_to_b.c\
		push_to_a.c\
		push_big_number.c\
		args_handle.c\
		checker.c\
		utils_tow.c\
		free.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c

CHECKER = checker

OBJS=$(SRCS:.c=.o)
BONUS_OBJ = $(BONUSRC:.c=.o)
INCL= push_swap.h
INCLB= checker.h

BGreen=\033[1;32m
BYellow=\033[1;33m
BBlue=\033[1;34m
BPurple=\033[1;38;5;205m
BRed=\033[1;31m

all:$(NAME)


		@echo "$(BRed)"
		@echo "██████╗░██╗░░░██╗░██████╗██╗░░██╗  ░██████╗░██╗░░░░░░░██╗░█████╗░██████╗░"
		@echo "██╔══██╗██║░░░██║██╔════╝██║░░██║  ██╔════╝░██║░░██╗░░██║██╔══██╗██╔══██╗"
		@echo "██████╔╝██║░░░██║╚█████╗░███████║  ╚█████╗░░╚██╗████╗██╔╝███████║██████╔╝"
		@echo "██╔═══╝░██║░░░██║░╚═══██╗██╔══██║  ░╚═══██╗░░████╔═████║░██╔══██║██╔═══╝░"
		@echo "██║░░░░░╚██████╔╝██████╔╝██║░░██║  ██████╔╝░░╚██╔╝░╚██╔╝░██║░░██║██║░░░░░ BY younes ismaili"
		@echo "╚═╝░░░░░░╚═════╝░╚═════╝░╚═╝░░╚═╝  ╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝░░╚═╝╚═╝░░░░░"

%.o: %.c $(INCL)
	@echo "$(BPurple) Compile $(BYellow) $^ $(BGreen)to $@"
	$(CC) $(FLAGS) $< $(INCL) -c

$(NAME):$(OBJS)
	@echo "$(BYellow) Make $(BGreen) $@"
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@echo "$(BBlue) Clean"
	rm -rf *.o

fclean:clean
	@echo "$(BGreen) Fclean"
	rm -rf *.a
	rm -rf push_swap
re : fclean all

bonus : $(CHECKER)

$(CHECKER) : $(BONUS_OBJ)
	@cd make
	@cd make bonus
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(CHECKER)

.PHONY: all gnl utils bonus clean fclean re

