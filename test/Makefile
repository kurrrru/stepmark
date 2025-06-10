NAME	= test.out
SRCS	= main.cpp ../stepmark.cpp
OBJS	= $(SRCS:.cpp=.o)
CXX		= g++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

.DEFAULT_GOAL := all

all: $(NAME)

run: $(NAME)
	./$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re
