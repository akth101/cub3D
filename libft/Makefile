
CC = cc

NAME = libft.a

HEADER = libft.h

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_memset.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
       ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c ft_atoi.c \
       ft_strncmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
       ft_strrchr.c ft_substr.c ft_strnstr.c ft_calloc.c ft_strdup.c \
       ft_strjoin.c ft_itoa.c ft_strtrim.c ft_split.c ft_bzero.c ft_memcpy.c \
       ft_memmove.c ft_memchr.c ft_memcmp.c ft_strmapi.c ft_striteri.c \
       ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
       get_next_line_bonus.c get_next_line_utils_bonus.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
        ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
        ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(BONUS:.c=.o)

ifdef BONUSFLAG
	ALLOBJS = $(OBJS) $(OBJS_BONUS)
else
	ALLOBJS = $(OBJS)
endif

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER) -I get_next_line_bonus.h

$(NAME) : $(ALLOBJS)
	ar -rcs $@ $(ALLOBJS)

bonus :
	make BONUSFLAG=1

clean :
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all bonus fclean clean re
