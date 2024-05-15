# Define compiler
CC = cc


# YOU NOW NEED TO ADD THE LAST FILE YOU HAVE ADDED FT_FREE.

# Define CFLAGS (compiler flags)
CFLAGS = -Wall -Wextra -Werror

# Source code files
SRCs = pipex.c
Libft = libft/libft.a

# Executable name
NAME = pipex

# Main target (to build the executable)
all: $(NAME)

# How to build the executable
$(NAME): $(SRCs)
	make -C libft
	$(CC) $(CFLAGS) $(SRCs) $(Libft) -o $(NAME)

# Target to clean up object files
clean:
	rm -f $(NAME)
	make clean -C libft

# Target to clean up object files & the executable
fclean: clean
	rm -f $(NAME)
	make fclean -C libft

# Rebuild everything (clean first, then build)
re: fclean all