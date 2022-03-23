NAME = ft_containers_complexinette

SRCS = main.cpp get_random_array.cpp

OBJS = $(SRCS:.cpp=.o)

LIB = lib_complexinette/libcomplexinette.a

INCLUDES += . lib_complexinette

INCLUDES_FLAG = $(foreach dir, $(INCLUDES), -I $(dir))

CC = clang++

CXXFLAGS = -g3 -O0 -std=c++20

.cpp.o :
		$(CC) $(CXXFLAGS) $(INCLUDES_FLAG) -c $< -o ${<:.cpp=.o}

all : $(NAME)

$(LIB):
		@make -C lib_complexinette

$(NAME): $(OBJS) $(LIB)
		$(CC) $(CXXFLAGS) $(INCLUDES_FLAG) -o $(NAME) $(OBJS) $(LIB) -lpthread

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re make_lib