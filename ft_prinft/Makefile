NAME = libftprintf.a
LIBFT = libft
SRCS =	ft_printf.c ft_printf_utils.c ft_printf_p.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I .

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C ${LIBFT}
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean: 
	make fclean -C ${LIBFT}
	rm -f ${OBJS}

fclean:	clean
	rm -f libft/libft.a
	rm -f $(NAME)

re: fclean all