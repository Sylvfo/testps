NAME			= push_swap
SRCS			= 	main.c	utils.c	chained_lists.c	swap.c utils_plus.c\
					push.c	rotate.c	reverse_rotate.c	check.c\
					get_numbers.c	len_two_three.c	cost_analysis.c\
					target.c	play_partition.c	notes.c stack_b_to_a.c prints.c\
					len_four_to_six.c	count_rotations.c write_partition.c\

OBJ_DIR 		= obj
FLAGS			= -Wall -Werror -Wextra -g
CC				= gcc
RM				= rm -f

OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

PRINTF_DIR		= librairies/printf
PRINTF			= ./${PRINTF_DIR}/libftprintf.a
LIBFT_DIR		= librairies/libft
LIBFT 			= ./${LIBFT_DIR}/libft.a

all: $(NAME)

$(NAME): ${OBJ}
		make -C ${PRINTF_DIR}
		make -C ${LIBFT_DIR}
		${CC} ${FLAGS} -o $@ $^ ${PRINTF} ${LIBFT} ${MINILIBX}

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(OBJ_DIR)
		${CC} ${FLAGS} -c $< -o $@

clean:
			rm -rf $(OBJ_DIR)
			make clean -C ${PRINTF_DIR}
			make clean -C ${LIBFT_DIR}
			$(RM) $(OBJ)

fclean:		clean
			make fclean -C ${PRINTF_DIR}
			make fclean -C ${LIBFT_DIR}
			$(RM) $(NAME)
 
re:			fclean	all

.PHONY:		all re clean fclean