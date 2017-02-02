##
## Makefile :D
##
## Made by David Zeng
## Login   <zeng_d@epitech.net>
##
## Started on  Mon Oct 12 13:31:18 2015 David Zeng
## Last update Thu Feb  2 11:34:29 2017 Riamon Vincent
##

NAME:=		../libnanotekspice.a
SRCDIR:=	src/
COMPDIR:=	components/
GATESDIR:=	gates/

INCLUDE:=	include/ \
		include/components \
		include/gates

SRC:=		$(COMPDIR)Input.cpp \
		$(COMPDIR)Output.cpp \
		$(COMPDIR)True.cpp \
		$(COMPDIR)False.cpp \
		$(COMPDIR)Clock.cpp \
		$(GATESDIR)AND-4081.cpp \
		$(GATESDIR)OR-4071.cpp \
		$(GATESDIR)XOR-4030.cpp \
		$(GATESDIR)NOR-4001.cpp \
		$(GATESDIR)NAND-4011.cpp \
		$(GATESDIR)INVERSE-4069.cpp \

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
	@ar rc $(NAME) $(OBJS)
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
