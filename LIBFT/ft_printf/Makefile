
NAME = libftprintf.a

HEADER = ft_printf.h

OBJ = ft_printf.o flags.o width.o precision.o specifier.o length.o conversions.o strings_chars.o \
floats.o long_floats.o specifier_f.o pointer_conv.o floaters.o no_specifier.o  \
conversion_2.o width_2.o precision_2.o specifier_2.o flags_2.o floats_2.o long_floats_2.o

SRCS = ft_printf.c flags.c width.c precision.c specifier.c length.c conversions.c strings_chars.c \
floats.c long_floats.c specifier_f.c pointer_conv.c floaters.c no_specifier.c \
conversion_2.c width_2.c precision_2.c specifier_2.c flags_2.c floats_2.c long_floats_2.c

all: $(NAME)

$(NAME):
	@cp ../libft.a $(NAME)
	@gcc -c $(SRCS) -I $(HEADER) -Wall -Wextra -Werror
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
