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
			  ft_valabs.c \
			  ft_vector.c \
			  ft_isspace.c


GNL_DIR		= get_next_line/

GNL_FILE	= get_next_line.c \
			  get_next_line_utils.c


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
CFLAGS		= -Wall -Wextra -Werror ${INCLUDES} -g

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

#${OBJS_DIR}%.o: ${SRCS_DIR}%.c | ${OBJS_DIR}
#				@${CC} ${CFLAGS} -c $< -o $@
PROGRESS_FILE = .progress_count
TOTAL_FILES = $(words $(OBJS))

define show_progress
	count=$$(cat $(PROGRESS_FILE)); \
	count=$$((count + 1)); \
	echo $$count > $(PROGRESS_FILE); \
	percent=$$(( 100 * $$count / $(TOTAL_FILES) )); \
	bar_len=30; \
	filled=$$(( bar_len * $$count / $(TOTAL_FILES) )); \
	bar=""; \
	for i in $$(seq 1 $$filled); do bar="$$bar#"; done; \
	for i in $$(seq $$((bar_len - filled))); do bar="$$bar-"; done; \
	printf "\r${YELLOW}[%-30s] %3d%% (%d/%d)${RESET}" "$$bar" "$$percent" "$$count" "$(TOTAL_FILES)"; \
	if [ $$count -eq $(TOTAL_FILES) ]; then echo; fi
endef

${OBJS_DIR}%.o: ${SRCS_DIR}%.c | ${OBJS_DIR}
				@${CC} ${CFLAGS} -c $< -o $@
				@if [ ! -f $(PROGRESS_FILE) ]; then echo 0 > $(PROGRESS_FILE); fi
				@$(call show_progress)

${NAME}:		${OBJS}
				@ar rcs $@ -o $^
				@echo "${GREEN}'${NAME}' is compiled ! ✅${RESET}"
				@rm -f $(PROGRESS_FILE)

${OBJS_DIR}:
				@mkdir -p ${OBJS_DIR}
				@mkdir -p ${OBJS_DIR}${LIB_DIR}
				@mkdir -p ${OBJS_DIR}${GNL_DIR}

bonus:			${NAME}

clean:
				@${RM} ${OBJS}
				@${RM} -r ${OBJS_DIR}${LIB_DIR} ${OBJS_DIR}${GNL_DIR}
				@${RM} -r ${OBJS_DIR}
				@${RM} -f $(PROGRESS_FILE)
				@echo "${RED}'${NAME}' objects are deleted ! 👍${RESET}"

fclean:			clean
				@${RM} ${NAME}
				@echo "${RED}'${NAME}' is deleted ! 👍${RESET}"

re:				fclean all

.PHONY:			all clean fclean re bonus
