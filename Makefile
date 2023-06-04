# 컴파일러 설정
CC = cc

# 컴파일 및 링크 옵션
CFLAGS = 
LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

# 라이브러리 및 실행 파일 이름
LIBRARY = mlx/libmlx.a
EXECUTABLE = so_long

# 기본 타겟 (all) 설정
all: $(EXECUTABLE)

# 실행 파일 생성 타겟
$(EXECUTABLE): $(LIBRARY) so_long.c so_long_utils.c
	$(CC) $(CFLAGS) -o $@ so_long.c so_long_utils.c $(LIBRARY) $(LDFLAGS)

# 라이브러리 파일 생성 타겟
$(LIBRARY):
	$(MAKE) -C mlx

# 메이크 파일을 실행하여 생성된 파일 및 라이브러리 삭제
clean:
	rm -f $(EXECUTABLE)

# 실행 파일 및 라이브러리 모두 삭제
fclean: clean
	$(MAKE) -C mlx clean
	rm -f $(LIBRARY)

# 전체 빌드 과정 삭제
re: fclean all

.PHONY: all clean fclean re