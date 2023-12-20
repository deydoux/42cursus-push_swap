NAME				=	push_swap

LIBFT_DIR			=	libft
SOURCES_DIR			=	sources
INCLUDE_DIR			=	include
OBJECTS_DIR			=	.objects

SOURCES				=	free_stacks.c	\
						init_stacks.c	\
						parse_args.c	\
						push_swap.c

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -MMD -I $(INCLUDE_DIR)
RM					=	rm -rf
MKDIR				=	mkdir -p

LIBFT				=	$(LIBFT_DIR)/libft.a
OBJECTS				=	$(addprefix $(OBJECTS_DIR)/,$(SOURCES:.c=.o))
DEPENDENCIES		=	$(addprefix $(OBJECTS_DIR)/,$(SOURCES:.c=.d))

all					:	$(NAME)

-include 				$(DEPENDENCIES)

$(LIBFT)			:
	$(MAKE) -C $(@D) $(@F)

$(OBJECTS_DIR)/%.o	:	$(SOURCES_DIR)/%.c
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -o $@ -c	$<

$(NAME)				:	$(OBJECTS) $(LIBFT)
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -o $@ $^

clean				:
	$(MAKE) -C $(LIBFT_DIR) $@
	$(RM) $(OBJECTS_DIR)

fclean				:	clean
	$(MAKE) -C $(LIBFT_DIR) $@
	$(RM) $(NAME)

re					:	fclean all

.PHONY				:	all clean fclean re
