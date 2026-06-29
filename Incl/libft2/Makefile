SRcS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
ft_tolower.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_strchr.c get_next_line.c ft_printf.c ft_printf_utils_00.c ft_printf_utils_01.c \
ft_lstnew_bonus.c  ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
ft_lstmap_bonus.c get_next_line.c ft_printf.c ft_printf_utils_00.c ft_printf_utils_01.c \
ft_swap.c ft_strndup.c ft_issign.c free_tab.c ft_putstr.c print_tab.c

OBJS = ${SRcS:.c=.o}

NAME = libft.a

RM = rm -f

IDIR = .

cc = cc -I$(IDIR)

cfLAGS = -Wextra -Wall -Werror -fPIE

all: ${NAME}

${NAME}: ${OBJS}
	ar -crs $@ $^

%.o:%.c
	$(cc) $(cfLAGS) -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.pHONy: all clean fclean re

