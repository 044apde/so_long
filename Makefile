all : 
	cc -lmlx -framework OpenGl -framework AppKit -lmlx *.c

clean:
	rm -rf a.out