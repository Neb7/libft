LIB_DIR		= libft/

LIB_FILE	= ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isalnum.c \
			  ft_isascii.c \
			  ft_isprint.c \
			  ft_lstadd_back.c \
			  ft_lstadd_front.c \
			  ft_lstclear.c \
			  ft_lstdelone.c \
			  ft_lstiter.c \
			  ft_lstlast.c \
			  ft_lstmap.c \
			  ft_lstnew.c \
			  ft_lstsize.c \
			  ft_calloc.c \
			  ft_bzero.c \
			  ft_memset.c \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_putchar_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \
			  ft_putstr_fd.c \
			  ft_strchr.c \
			  ft_strncmp.c \
			  ft_strnstr.c \
			  ft_strlcpy.c \
			  ft_strlcat.c \
			  ft_strrchr.c \
			  ft_strdup.c \
			  ft_split.c \
			  ft_striteri.c \
			  ft_strjoin.c \
			  ft_strmapi.c \
			  ft_strtrim.c \
			  ft_substr.c \
			  ft_strlen.c \
			  ft_toupper.c \
			  ft_tolower.c \
			  ft_itoa.c \
			  ft_atoi.c \
			  ft_strchar.c \
			  ft_valabs.c


PF_DIR		= ft_printf/

PF_FILE		= ft_printf.c \
			  ft_printf_utils.c \
			  ft_printf_put.c \
			  ft_itoa_base.c \
			  ft_putnbrstr.c \
			  ft_putnbr_hex.c


GNL_DIR		= get_next_line/

GNL_FILE	= get_next_line.c \
			  get_next_line_utils.c


SRC			+= $(addprefix ${PF_DIR}, ${PF_FILE})
SRC			+= $(addprefix ${LIB_DIR}, ${LIB_FILE})
SRC			+= $(addprefix ${GNL_DIR}, ${GNL_FILE})

SRCS_DIR 	= srcs/
SRCS		= $(addprefix ${SRCS_DIR}, ${SRC})

OBJS_DIR	= objects/
OBJS		= $(addprefix ${OBJS_DIR}, ${SRC:.c=.o})

CC			= cc
INCLUDES	= -I includes
NAME		= libft.a
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror ${INCLUDES}

#Colors
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m
RESET		= \033[0m

all:			${NAME}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c | ${OBJS_DIR}
				@${CC} ${CFLAGS} -c $< -o $@

${NAME}:		${OBJS}
				@ar rcs $@ -o $^
				@echo "${GREEN}'${NAME}' is compiled ! ✅${RESET}"

${OBJS_DIR}:
				@mkdir -p ${OBJS_DIR}
				@mkdir -p ${OBJS_DIR}${LIB_DIR}
				@mkdir -p ${OBJS_DIR}${PF_DIR}
				@mkdir -p ${OBJS_DIR}${GNL_DIR}

bonus:			${NAME}

clean:
				@${RM} ${OBJS}
				@${RM} -r ${OBJS_DIR}${LIB_DIR} ${OBJS_DIR}${PF_DIR} ${OBJS_DIR}${GNL_DIR}
				@${RM} -r ${OBJS_DIR}
				@echo "${RED}'${NAME}' objects are deleted ! 👍${RESET}"

fclean:			clean
				@${RM} ${NAME}
				@echo "${RED}'${NAME}' is deleted ! 👍${RESET}"

re:				fclean all

.PHONY:			all clean fclean re bonus
