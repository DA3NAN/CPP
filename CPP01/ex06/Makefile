# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aait-mal <aait-mal@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 12:18:49 by aait-mal          #+#    #+#              #
#    Updated: 2023/10/24 16:29:11 by aait-mal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = HarlFilter
SRC = $(wildcard *.cpp)
HEADER = $(wildcard *.hpp *.h)

OBJ = $(SRC:.cpp=.o)
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
