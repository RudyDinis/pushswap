NAME = push_swap
LIBFT = libft

SRCS =	main.c pile.c utils.c utils2.c operations/sa.c operations/sb.c \
		operations/ss.c operations/pb.c operations/pa.c operations/ra.c \
		operations/rb.c operations/rr.c operations/rra.c operations/rrb.c \
		operations/rrr.c ft_split.c resolve.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I .

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
clean: 
	rm -f ${OBJS}

fclean:	clean
	rm -f $(NAME)

re: fclean all