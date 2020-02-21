.PHONY: clean all re fclean
NAME = libftprintf.a
SRCS =  data_gathering_abstraction/data_gathering.c\
data_intrepretation/intereptor.c\
data_intrepretation/d_analyser.c\
data_intrepretation/x_analyser.c\
data_intrepretation/c_per_interpret.c\
data_intrepretation/s_analyser.c\
data_reading/data_read.c\
utills/first_five.c\
utills/second_five.c\
utills/third_five.c\
utills/fourth_five.c\
utills/dec_to_hex.c\
utills/hex_to_dec.c\

OBJS = data_gathering.o\
intereptor.o\
d_analyser.o\
x_analyser.o\
c_per_interpret.o\
s_analyser.o\
data_read.o\
first_five.o\
second_five.o\
third_five.o\
fourth_five.o\
dec_to_hex.o\
hex_to_dec.o
all:$(NAME)
$(NAME):
	clang -Wall -Wextra -Werror -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
