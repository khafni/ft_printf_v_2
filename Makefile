.PHONY: clean all re fclean
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS =  /data_gathering_abstraction/data_gathering.c\
/data_intrepretation/intrepretor.c
data_read.c
OBJS = $(SRCS:.c=.o)
all:$(NAME)
$(NAME):
	clang $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
