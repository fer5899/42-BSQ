MY_SOURCES = ft_int_tochart.c rush.c nuevo.c ft_nospace.c dict_to_string.c atoi.c	printer.c checkdict.c ft_strcmp.c list.c list.h

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Werror -Wextra

NAME = rush-02

$(NAME):	$(MY_OBJECTS)
	cc -o $(NAME) $(MY_OBJECTS)

clean:
	rm -f *.o *.out $(NAME)

fclean:
	rm -f *.o *.out $(NAME)