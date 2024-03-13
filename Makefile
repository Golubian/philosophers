# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 13:40:15 by gachalif          #+#    #+#              #
#    Updated: 2024/03/06 12:19:34 by gachalif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

SRCS_DIR = srcs
SRCS =\
		$(SRCS_DIR)/main.c \

INCLUDES = -I includes \

OBJS = $(SRCS:.c=.o)

UP		= "\033[1F"
CLR		= "\033[2K"
YELLOW	= "\033[33;1m"
CYAN	= "\033[36;1m"
GREEN	= "\033[32;1m"
DEFAULT	= "\033[0;0m"

define HEADER
Philosophers
\033[0;1m
Generate solution:
        ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
endef
export HEADER

all: $(NAME)
		@		echo $(GREEN)
		@		echo "$$HEADER"
		@		echo $(DEFAULT)

%.o:	%.c
		@ echo $(UP)$(CLR)🔥 $(YELLOW)$@ 
		@ $(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

			 
$(NAME):	$(OBJS)
			@ echo $(UP)$(CLR)🔥 $@ 
			@ $(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
			@ echo $(UP)$(CLR)✅ $(GREEN)$@ built!$(DEFAULT)

debug:	CFLAGS += -g
debug:	clean all
		@	echo $(UP)$(CLR)🐛 $(GREEN)$(NAME) built for debug!$(DEFAULT)

clean:
		@	rm -f $(OBJS)
		@	echo 🧽 $(GREEN)All clean!$(DEFAULT)

fclean: 
		@	rm -f $(OBJS) $(NAME)
		@	echo 🧽 $(GREEN)All f...clean!$(DEFAULT)

re:	
		@	rm -f $(OBJS) $(NAME)
		@	echo 🛠$(YELLOW) REBUILDING
		@	echo 
		@	make all

.PHONY = all clean fclean re debug