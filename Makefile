
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJ	= ft_printf.o buff.o specification_handler.o specification_parsers.o  \
	  string_converter.o char_converter.o int_converter.o \
	  int_converter_helper_1.o int_converter_helper_2.o width_handler.o
NAME = printf

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c 
	gcc -c  $< -o $@ -I $(LIBFT_DIR) 

$(NAME): $(OBJ) $(LIBFT)
	gcc $(OBJ) $(LIBFT) -o $(NAME)
#	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
