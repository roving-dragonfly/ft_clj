NAME= ft_clj
CC= gcc
FLAGS= -Wall -Wextra -g3 -fsanitize=address
SRC=	srcs/main.c \
	srcs/read.c \
	srcs/ast/ft_put_parser.c \
	srcs/ast/tokenization/ft_new_token_queue.c \
	srcs/ast/tokenization/ft_peek_token.c \
	srcs/ast/tokenization/ft_pop_token.c \
	srcs/ast/tokenization/ft_print_token_queue.c \
        srcs/ast/tokenization/ft_push_token.c \
	srcs/ast/tokenization/ft_empty_queue.c \
	srcs/ast/tokenization/ft_tokenize.c \
	srcs/ast/generation/ft_get_parser.c \
	srcs/ast/generation/ft_get_parser_chars.c \
	srcs/ast/generation/ft_get_parser_logicals.c \
	srcs/ast/generation/ft_get_parser_misc.c \
	srcs/ast/generation/ft_get_parser_strings.c \
	srcs/ast/evaluation/ft_eval_parser.c \
	srcs/ast/evaluation/ft_eval_parser_and.c \
	srcs/ast/evaluation/ft_eval_parser_multiply.c \
	srcs/ast/evaluation/ft_eval_parser_not.c \
	srcs/ast/evaluation/ft_eval_parser_or.c \
	srcs/ast/evaluation/ft_eval_parser_plus.c \
	srcs/ast/evaluation/ft_eval_parser_ref.c \
	srcs/ast/evaluation/ft_eval_parser_onechar.c \
	srcs/ast/evaluation/ft_eval_parser_str.c \
	srcs/ast/evaluation/ft_eval_parser_str_any.c \
	srcs/ast/evaluation/ft_eval_parser_undefined.c \
	srcs/ast/grammar/ft_sexp_parser.c

OBJ= $(SRC:.c=.o)
HDR_PATHS= ./includes ./libft/includes
HDR_FLAGS= $(addprefix -I, $(HDR_PATHS))
HDR_PATH= ./includes ./libft/includes

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $^ -L./libft -lft -lreadline $(FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $< $(HDR_FLAGS) $(FLAGS) -o $@ -c

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
