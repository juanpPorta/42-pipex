CC		= gcc -g
NAME	= pipex
MINILIB	= ./libft/libft.a
HEADER	= .
OBJS	= $(SRCS:.c=.o)
SRCS	=  pipex.c pipex_utils.c

all:	$(NAME)


$(NAME):	$(OBJS)
	@make -C ./libft
	$(CC) $(OBJS) $(MINILIB) -o $(NAME)

.c.o:
			$(CC) -I $(HEADER) -c $< -o $(<:.c=.o)

clean:
	rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME) *.o
			@make fclean -C ./libft

re:			fclean all
