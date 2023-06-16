CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBRARY = mlx/libmlx.a gnl/libgnl.a libft/libft.a ft_printf/libftprintf.a
EXECUTABLE = so_long
SOURCE = so_long.c so_long_utils.c check_map.c parse_map.c queue.c find_path.c image.c key_hooks.c render_map.c
HEADER = so_long.h

all: $(EXECUTABLE)

$(EXECUTABLE): $(LIBRARY) $(SOURCE) $(HEADER)
	$(CC) $(CFLAGS) -o $@ $(SOURCE) $(LIBRARY) $(LDFLAGS)

$(LIBRARY):
	$(MAKE) -C mlx
	$(MAKE) -C gnl
	$(MAKE) -C libft
	$(MAKE) -C ft_printf

clean:
	rm -f $(EXECUTABLE)

fclean: clean
	$(MAKE) -C mlx clean
	$(MAKE) -C gnl clean
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	rm -f $(LIBRARY)

re: fclean all

.PHONY: all clean fclean re