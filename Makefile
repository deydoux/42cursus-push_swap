NAME				=	push_swap
BONUS_NAME			=	checker
UTILS_NAME			=	push_swap_utils.a

SUB_SOURCES_DIR		=	push_swap
BONUS_SOURCES_DIR	=	checker
UTILS_SOURCES_DIR	=	utils

SOURCES				=	compute_moves.c	\
						create_chunks.c	\
						greater_elem.c	\
						index_stack.c	\
						push_swap.c		\
						sort_stack.c

BONUS_SOURCES		=	checker.c

UTILS_SOURCES		=	free_stacks.c			\
						init_stacks.c			\
						is_sorted_stack.c		\
						parse_args.c			\
						push_stack.c			\
						reverse_rotate_stacks.c	\
						rotate_stacks.c			\
						swap_stacks.c

LIBFT_DIR			=	libft
SOURCES_DIR			=	sources
INCLUDE_DIR			=	include
OBJECTS_DIR			=	.objects

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -MMD -I $(INCLUDE_DIR)
AR					=	ar
ARFLAGS				=	-c -r -s
RM					=	rm -rf
MKDIR				=	mkdir -p

LIBFT				=	$(LIBFT_DIR)/libft.a
OBJECTS				=	$(addprefix $(OBJECTS_DIR)/$(SUB_SOURCES_DIR)/,$(SOURCES:.c=.o))
BONUS_OBJECTS		=	$(addprefix $(OBJECTS_DIR)/$(BONUS_SOURCES_DIR)/,$(BONUS_SOURCES:.c=.o))
UTILS_OBJECTS		=	$(addprefix $(OBJECTS_DIR)/$(UTILS_SOURCES_DIR)/,$(UTILS_SOURCES:.c=.o))
DEPENDENCIES		=	$(OBJECTS:.o=.d) $(BONUS_OBJECTS:.o=.d) $(UTILS_OBJECTS:.o=.d)

all					:	$(NAME) bonus

bonus				:	$(BONUS_NAME)

-include 				$(DEPENDENCIES)

$(OBJECTS_DIR)/%.o	:	$(SOURCES_DIR)/%.c
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -o $@ -c	$<

$(UTILS_NAME)		:	$(UTILS_OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

$(LIBFT_DIR)		:
	$(MAKE) --no-print-directory -C	$@

$(LIBFT)			:	$(LIBFT_DIR)

$(NAME)				:	$(OBJECTS) $(UTILS_NAME) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS_NAME)		:	$(BONUS_OBJECTS) $(UTILS_NAME) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

clean				:
	$(MAKE) --no-print-directory -C	$(LIBFT_DIR) $@
	$(RM) $(OBJECTS_DIR)

fclean				:
	$(MAKE) --no-print-directory -C	$(LIBFT_DIR) $@
	$(RM) $(OBJECTS_DIR) $(NAME) $(BONUS_NAME) $(UTILS_NAME)

re					:	fclean all

.PHONY				:	all bonus clean fclean re $(LIBFT_DIR)
