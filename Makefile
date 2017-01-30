##
## Makefile for Makefile in /home/riamon_v/rendu/CPE/CPE_colle_semaine6
## 
## Made by vincent riamon
## Login   <riamon_v@epitech.net>
## 
## Started on  Tue May 31 18:19:41 2016 vincent riamon
## Last update Mon Jan 30 13:46:21 2017 Riamon Vincent
##

CXX = g++

NAME = nanotekspice

LIBNAME = libnanotekspice.a

RM = rm -rf

SRCS =  src/main.cpp \

CXXFLAGS = -Wall -Wextra -Werror -Iinclude -g

OBJS = $(SRCS:.cpp=.o)

all: $(NAME) $(LIBNAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

$(LIBNAME):
	@ar rc $(LIBNAME) $(OBJS)
	@ranlib $(LIBNAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBNAME)

re: fclean all

.PHONY: all clean fclean re
