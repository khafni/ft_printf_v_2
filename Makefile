.PHONY: clean all re fclean
NAME = libftprintf.a
SRCS =  data_gathering_abstraction/data_gathering.c\
data_intrepretation/intrepretor.h\
data_intrepretation/d_analyser.c\
data_reading/data_read.c\
utills/first_five.c\
utills/second_five.c\
utills/third_five.c
OBJS = data_gathering.o\
d_analyser.o\
data_read.o\
first_five.o\
second_five.o\
third_five.o
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
