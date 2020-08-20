# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcathery <mcathery@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 21:37:50 by mcathery          #+#    #+#              #
#    Updated: 2020/08/19 12:30:59 by hgalazza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOLD = $(shell echo "\033[1m")
BOLD_END = $(shell echo "\033[21m")
RED = $(shell echo "\033[31m")
GREEN = $(shell echo "\033[32m")
YELLOW = $(shell echo "\033[33m")
BLUE = $(shell echo "\033[34m")
MAGENTA = $(shell echo "\033[35m")
EOC = $(shell echo "\033[0m")

FLAGS = -Wall -Wextra -Werror
LIBFT = libft/
O_PATH = ./src/obj/
LIB = -L $(LIBFT) -lft
LBM = $(LIBFT)libft.a
NAME = lem-in
SRCS_PATH = src/
INCLUDES_PATH = incl/
INCLUDES = -I incl/ -I libft/
FILES = ants.c \
		clear.c \
		find_capacity.c \
		form_path.c \
		ft_lists.c \
		paths.c \
		queue.c \
		sort_paths.c \
		v_add_functions.c \
		v_add_link.c \
		v_create_rooms.c \
		v_lem_in.c \
		v_rooms.c

SRCS = $(addprefix $(SRCS_PATH), $(FILES))
OBJS = $(addprefix $(O_PATH),$(subst .c,.o,$(FILES)))
CHECK_O = .o_path_exists

all: $(NAME)

$(NAME): $(LBM) $(OBJS)
	@/bin/echo $(YELLOW)[$(MAGENTA)$(BOLD)Creating $(BLUE)$(NAME) $(EOC)$(YELLOW)...]$(EOC)
	@gcc $(FLAGS) -o $(NAME) $(INCLUDES) $(OBJS) $(LIB)
	@/bin/echo "$(YELLOW)[$(BOLD)$(BLUE)$(NAME) $(MAGENTA)Created!$(EOC)$(YELLOW)]$(EOC)"

$(O_PATH)%.o: $(SRCS_PATH)%.c | $(CHECK_O)
	@/bin/echo -n $(YELLOW)[$(GREEN)$(BOLD)Compiling $(BLUE)$(notdir $@) $(EOC)$(YELLOW)...]- -$(EOC)
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(YELLOW)[$(BOLD)$(GREEN)Done!$(EOC)$(YELLOW)]$(EOC)"

$(CHECK_O):
	@mkdir $(O_PATH)
	@touch $(CHECK_O)

$(LBM):
	@make -C $(LIBFT)

clean:
	@/bin/echo "$(YELLOW)[$(RED)$(BOLD)Cleaning $(EOC)$(YELLOW)...]$(EOC)"
	@/bin/rm -f $(OBJS)
	@make -C $(LIBFT) clean &> /dev/null
	@rm -rf $(CHECK_O)
	@rm -rf $(O_PATH)
	@/bin/echo "$(YELLOW)[$(RED)$(BOLD)All .o Removed!$(EOC)$(YELLOW)]$(EOC)"

fclean: clean
	@make -C $(LIBFT) fclean &> /dev/null
	@/bin/rm -f $(NAME)
	@/bin/echo "$(YELLOW)[$(BOLD)$(BLUE)$(NAME) $(RED)Removed!$(EOC)$(YELLOW)]$(EOC)"

re: fclean all

.PHONY = all clean fclean re