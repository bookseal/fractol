NAME=fractol
//CFLAGS=-Wall -Wextra -Werror 
CFLAGS = -g

SRC= main.c draw_sets.c util_math.c util_mlx.c
OBJ=$(SRC:%.c=%.o)
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -L./mlx -lmlx -I./mlx -framework OpenGL -framework AppKit -o $(NAME)

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all