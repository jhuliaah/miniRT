# Project Name
NAME        = minirt

# Compiler and Flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -I./inc
LDFLAGS     = -lreadline
INCLUDES    = -Iinc -Ilibft

# Library Paths
LIBFT       = libft/libft.a

# Directories
SRC_DIR     = src
OBJ_DIR     = obj

# Source Files - no final trocar pelos nomes dos arquivos
SRCS 		= $(shell find $(SRC_DIR) -name "*.c")
# Object Files (generated using patsubst)
OBJS        = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(NAME)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ./$(NAME)

# Link the final executable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(LDFLAGS)

# Compile .c files into .o files; ensure directory exists
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


# Build the libft library
$(LIBFT):
	$(MAKE) -C inc/libft

# Clean object files
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C inc/libft clean

# Remove objects and executable
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C inc/libft fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
