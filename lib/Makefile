##
## Makefile :D
##
## Made by David Zeng
## Login   <zeng_d@epitech.net>
##
## Started on  Mon Oct 12 13:31:18 2015 David Zeng
## Last update Fri Feb  3 18:28:21 2017 Riamon Vincent
##

NAME:=		../libnanotekspice.a
SRCDIR:=	src/

INCLUDE:=	include/ \
		include/components \
		include/gates \

SRC:=		components/Input.cpp \
		components/Output.cpp \
		components/True.cpp \
		components/False.cpp \
		components/Clock.cpp \
		gates/AND-4081.cpp \
		gates/OR-4071.cpp \
		gates/XOR-4030.cpp \
		gates/NOR-4001.cpp \
		gates/NAND-4011.cpp \
		gates/INVERSE-4069.cpp \
		gates/FlipFlop-4013.cpp \
		gates/counter-4040.cpp \
		gates/decoder-4514.cpp \
		gates/adder-4008.cpp \
		gates/register-4094.cpp \
		gates/Jdecade-4017.cpp \
		gates/rand-4801.cpp \
		gates/rdonly-2716.cpp \
		Component.cpp \
		Exception.cpp \

CXX:=		g++
CXXFLAGS:=	-W -Wall -Wextra -g -std=c++14
SRC:=		$(addprefix $(SRCDIR), $(SRC))
OBJ:=		$(SRC:.cpp=.o)
RM:=		rm -f

DEFAULT:=	"\033[00;0m"
GREEN:=		"\033[0;32;1m"
RED:=		"\033[0;31;1m"
CYAN:=		"\033[0;36;1m"

all: $(NAME)

$(NAME): $(OBJ)
	echo -e $(GREEN)"[LIB]"$(CYAN) $(NAME)$(DEFAULT)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	for file in $(SRC); do fgrep -niH -e TODO -e FIXME $$file --color=auto; done; true

clean:
	echo -e $(CYAN)"Cleaning $(NAME) tmp files..." $(DEFAULT)
	$(RM) $(OBJ)

fclean:	clean
	echo -e $(CYAN)"Cleaning $(NAME) executable..." $(DEFAULT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: all $(NAME) clean fclean re

.cpp.o:
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(foreach dir, $(INCLUDE), -I$(dir)) && \
		echo -e $(GREEN)"[OK]"$(DEFAULT) $< || \
		echo -e $(RED)"[KO]"$(DEFAULT) $<
