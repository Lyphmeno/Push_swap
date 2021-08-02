NAME	=	push_swap

SRCS	=	./lib/ft_calloc.c\
			./lib/ft_atoi.c\
			./lib/ft_itoa.c\
			./lib/ft_lst_add_back.c\
			./lib/ft_lst_add_front.c\
			./lib/ft_lst_length.c\
			./lib/ft_lst_print.c\
			./lib/ft_memset.c\
			./lib/ft_newarray.c\
			./lib/ft_putchar_fd.c\
			./lib/ft_putstr_fd.c\
			./lib/ft_split.c\
			./lib/ft_strlcpy.c\
			./lib/ft_strlen.c\
			./srcs/push_swap.c\

CC		=	gcc

CFLAGS		=	-Werror -Wextra -Wall -fsanitize=address

DEL			=	rm -f

OBJ 		=	$(addsuffix .o, $(basename $(SRCS)))

%.o: %.c
				$(CC) -c -o $@ $< $(CFLAGS)

all:			$(NAME)

$(NAME):$(OBJ)
				${CC} ${CFLAGS} -o ${NAME} ${OBJ}

clean:
				${DEL} ${OBJ}

fclean:			clean
				${DEL} ${NAME}

re:				clean all

.PHONY: 		clean re fclean all