NAME = philo

SRCS = ./main.c \
		src/init.c src/utils.c src/gettime.c \
		src/threads.c  src/routine.c src/input.c \
		src/check.c src/actions.c src/list.c 

# SRC_B = 

RM = rm -f

INCS	= -I ./includes/

CC = cc

FLAGS = -g -Wall -Wextra -Werror #-fsanitize=thread
# -static-libsan

OBJS = $(SRCS:.c=.o)

$(NAME):	$(OBJS)
		@${CC} $(FLAGS) $(SRCS) -o $(NAME)
		
$(BONUS_NAME) : $(OBJ_B)
		@${CC} $(FLAGS) $(SRC_B) -o checker

all: $(NAME)

clean:
		@$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all


.PHONY : all clean fclean
