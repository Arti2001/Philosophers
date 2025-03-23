NAME	= philo
SRCDIR  = src
INCDIR  = include
CC		= gcc
CFLAGS	= -Wextra -Werror -Wall -pthread -I$(INCDIR)
RM  	= rm -rf

SRC		= main.c pars_utils.c inits.c print.c simulation.c exit_utils.c
OBJ		= $(addprefix $(SRCDIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SRCDIR)/*.o a.out

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re