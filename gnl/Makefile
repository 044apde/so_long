CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libgnl.a

SRC_FILES = get_next_line.c get_next_line_utils.c
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(AR) rcs $@ $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all