# Define compiler
CC = cc

# Define CFLAGS (compiler flags)
CFLAGS = -Wall -Wextra -Werror

# Source code files
SRCs = ft_conversion.c ft_decimal_to_hexa.c ft_print_address.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_put_unsigned_nbr.c ft_strlen.c 

# Object files (built from source code)
OBJs = ft_conversion.o ft_decimal_to_hexa.o ft_print_address.o ft_printf.o ft_putchar.o ft_putnbr.o ft_putstr.o ft_put_unsigned_nbr.o ft_strlen.o

# Executable name
NAME = libftprintf.a

# Main target (to build the executable)
all: $(NAME)

# How to build the executable
$(NAME): $(OBJs)
	ar rcs $(NAME) $(OBJs)

# Target to clean up object files
clean: 
	rm -f $(OBJs)

# Target to clean up object files & the executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything (clean first, then build)
re: fclean all