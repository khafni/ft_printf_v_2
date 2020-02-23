.PHONY: clean all re fclean
NAME = libftprintf.a
SRCS =  data_gathering_abstraction/data_gathering_p_1.c\
data_gathering_abstraction/data_gathering_p_2.c\
data_analysis/analyser.c\
data_analysis/d_analyser.c\
data_analysis/x_analyser.c\
data_analysis/c_per_analyser.c\
data_analysis/s_analyser.c\
data_printing/data_printing_p_1.c\
data_printing/data_printing_p_2.c\
ft_printf.c\
utills/first_five.c\
utills/second_five.c\
utills/third_five.c\
utills/fourth_five.c\
utills/dec_to_hex.c\
utills/hex_to_dec.c\

OBJS = data_gathering_p_1.o\
data_gathering_p_2.o\
analyser.o\
d_analyser.o\
x_analyser.o\
c_per_analyser.o\
s_analyser.o\
data_printing_p_1.o\
data_printing_p_2.o\
ft_printf.o\
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
