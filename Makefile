
NAME	= ft_ip

SRCS	= ft_ip.c	\
		  main.c

LIB		= libft/libft.a

OBJDIR	= bin
OBJS	= $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

all : $(NAME)

$(LIB) :
	make -C libft

$(OBJDIR) :
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o : %.c
	gcc -c -o $@ -Ilibft -I. -Wall -Wextra -Werror $< 

$(NAME) : $(LIB) $(OBJDIR) $(OBJS)
	gcc -o $(NAME) -Wall -Wextra -Werror -lm $(OBJS) $(LIB)

clean : 
	rm -rf $(OBJDIR);

fclean : clean
	rm -rf $(NAME)

re : fclean all
