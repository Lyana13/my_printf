LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJ	= ft_printf.o buff.o specification_handler.o specification_parsers.o  \
	  string_converter.o float_converter.o char_converter.o int_converter.o \
	  int_converter_helper_1.o int_converter_helper_2.o  int_converter_helper_3.o \
	  width_handler.o
NAME = libftprintf.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c 
	gcc -Wall -Wextra -Werror -c  $< -o $@ -I $(LIBFT_DIR) 

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) ./$(NAME)
	ar rc $(NAME) $(OBJ) $(LIBFT)
	ranlib $(NAME)
#	gcc $(OBJ) $(LIBFT) -o $(NAME)

main: $(NAME)
	gcc main.c $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all