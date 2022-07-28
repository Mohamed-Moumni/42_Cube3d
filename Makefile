
SRCS  = src/cube3d.c src/error.c src/cube3d_utiles/get_next_line.c \
src/cube3d_utiles/get_next_line_utils.c src/cube3d_utiles/ft_putstr.c \
		src/cube3d_utiles/ft_lstnew.c src/cube3d_utiles/ft_lstsize.c \
		src/cube3d_utiles/ft_lstadd_back.c src/cube3d_utiles/ft_lstlast.c \
		src/cube3d_utiles/ft_split.c src/cube3d_utiles/ft_strlcpy.c src/cube3d_utiles/ft_strlen.c
OBJ = $(SRCS:.c=.o)

NAME= cube3d

HEADERS = includes/cube3d.h includes/structs.h

CC = cc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all