MY_SOURCES = src/check_map.c src/extract_obstacles.c src/find_bsq.c src/get_map.c src/insert_bsq.c src/main.c src/print_map.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Werror -Wextra

NAME = bsq

$(NAME):	$(MY_OBJECTS)
	cc -o $(NAME) $(MY_OBJECTS)

clean:
	rm -f *.o src/*.o *.out $(NAME)

fclean:
	rm -f src/*.o *.o *.out $(NAME)