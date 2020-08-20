#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgalazza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 15:09:26 by hgalazza          #+#    #+#              #
#    Updated: 2019/11/04 14:04:10 by hgalazza         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

FILES =		ft_atoi ft_bzero ft_isalnum ft_isalpha \
			ft_isascii ft_isdigit ft_islower ft_isprint \
			ft_isspace ft_isupper ft_itoa ft_lstadd ft_lstdel \
			ft_lstdelone ft_lstiter ft_lstmap ft_lstnew \
			ft_memalloc ft_memccpy ft_memchr ft_memcmp \
			ft_memcpy ft_memdel ft_memmove ft_memset \
			ft_putchar_fd ft_putchar ft_putendl_fd ft_putendl \
			ft_putnbr_fd ft_putnbr ft_putstr_fd ft_putstr ft_strcat \
			ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdel \
			ft_strdup ft_strequ ft_striter ft_striteri ft_strjoin ft_strlcat \
			ft_strlen ft_strmapi ft_strncat ft_strncmp ft_strncpy ft_strnequ ft_strmap \
			ft_strnew ft_strnstr ft_strrchr ft_strsplit ft_strstr \
			ft_strsub ft_strtrim ft_tolower ft_toupper get_next_line \
 			ft_printf digit_work ft_ftoa itoa_base string_ft work_s_c work_specifications work_variable

SRC = $(addsuffix .c, $(FILES))
OBJECTS = $(addsuffix .o, $(FILES))
FLAGS = -Wall -Wextra -Werror -c
HEADER = libft.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(FLAGS) -I $(HEADER) $(SRC)
clean:
	@/bin/rm -f $(OBJECTS)
fclean: clean
	@/bin/rm -f $(NAME)
re: fclean all
