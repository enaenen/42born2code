%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework Appkit -o $(NAME)
