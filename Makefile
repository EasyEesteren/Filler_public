NAME = ./wvan-ees.filler

SRC = main.c get_next_line.c extras.c filler.c place.c heat_map.c \
ft_freeintgrid.c set_score.c check_position.c fill_grid.c \
calc_score.c

INCL = filler.h

LIB = -L ./LIBFT/ -lft

all: $(NAME)

$(NAME): 
	@ make -C LIBFT/
	@ echo COMPILING FILLER
	@ gcc -o $(NAME) $(SRC) -I $(INCL) $(LIB) -Wall -Wextra -Werror

clean:
	@ echo CLEANING FILLER
	@ make -C ./LIBFT/ clean

fclean: clean
	@ echo FCLEANING FILLER
	@ make -C ./LIBFT/ fclean
	@ rm $(NAME)

re: fclean all
