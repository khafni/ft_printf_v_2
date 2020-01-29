.PHONY: clean all re fclean
NAME = ft_printf.a
SRCS =  data_gathering_abstraction/data_gathering.c\
data_intrepretation/intrepretor.c\
data_reading/data_read.c
OBJS = data_gathering.o\
intrepretor.o\
data_read.o
all:$(NAME)
$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
