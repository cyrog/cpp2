NAME 		= RPN
SRCS 		= main.cpp RPN.cpp
OBJS 		= ${SRCS:.cpp=.o}
CCXX		= @c++
RM			= @rm -rf
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

.cpp.o :
	$(CCXX) -c $(CXXFLAGS) -o $@ $<

all: $(NAME)

$(NAME):	$(OBJS)
	$(CCXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@printf "\e[36m\tCompilation \t[ ✓ ]\n\e[39m"

clean:
	$(RM) $(OBJS)
	@printf "\e[31m\tClean \t\t[ ✓ ]\n\e[39m"

fclean: clean
	$(RM) $(NAME)
	@printf "\e[35;5;161m\tBinary Clean \t[ ✓ ]\n\e[39m"

re: fclean all

.PHONY: all clean fclean re
