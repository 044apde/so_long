# set complier
CC = cc

# option for compile and link
CFLAGS = 
LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

# Library and exe file name
LIBRARY = mlx/libmlx.a gnl/libgnl.a libft/libft.a ft_printf/libftprintf.a
EXECUTABLE = so_long

# complie source
SOURCE = so_long.c so_long_utils.c check_map.c parse_map.c queue.c find_path.c image.c key_hooks.c

# header source
HEADER = so_long.h

# target all
all: $(EXECUTABLE)

# 실행 파일 생성 타겟
$(EXECUTABLE): $(LIBRARY) $(SOURCE) $(HEADER)
	$(CC) $(CFLAGS) -o $@ $(SOURCE) $(LIBRARY) $(LDFLAGS)

# 라이브러리 파일 생성 타겟
$(LIBRARY):
	$(MAKE) -C mlx
	$(MAKE) -C gnl
	$(MAKE) -C libft
	$(MAKE) -C ft_printf

# 메이크 파일을 실행하여 생성된 파일 및 라이브러리 삭제
clean:
	rm -f $(EXECUTABLE)

# 실행 파일 및 라이브러리 모두 삭제
fclean: clean
	$(MAKE) -C mlx clean
	$(MAKE) -C gnl clean
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	rm -f $(LIBRARY)

# 전체 빌드 과정 삭제
re: fclean all

.PHONY: all clean fclean re