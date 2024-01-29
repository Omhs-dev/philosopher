NAME = philo
BONUS_NAME = checker

SRCS = ./main.c \
		src/init.c src/utils.c src/gettime.c \
		src/threads.c  src/routine.c

# SRC_B = 

RM = rm -f

INCS	= -I ./includes/

CC = cc

FLAGS = -g -Wall -Wextra -Werror #-fsanitize=address -static-libsan

OBJS = $(SRCS:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

$(NAME):	$(OBJS)
		@${CC} $(FLAGS) $(SRCS) -o $(NAME)
		
$(BONUS_NAME) : $(OBJ_B)
		@${CC} $(FLAGS) $(SRC_B) -o checker

all: $(NAME)

bonus: $(BONUS_NAME)

clean:
		@$(RM) $(OBJS) $(OBJ_B)

fclean: clean
		$(RM) $(NAME) $(BONUS_NAME)

re: fclean all


.PHONY : all clean fclean re bonus
