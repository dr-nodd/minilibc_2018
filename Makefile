##
## EPITECH PROJECT, 2018
## Minilibc
## File description:
## Makefile
##


NAME		=	libasm.so

DIR		=	src

SRCS		=	$(DIR)/strchr.asm		\
			$(DIR)/strlen.asm			\
			$(DIR)/memset.asm			\
			$(DIR)/memcpy.asm			\
			$(DIR)/strcmp.asm			\
			$(DIR)/strncmp.asm			\
			$(DIR)/rindex.asm			\
			$(DIR)/strstr.asm			\
			$(DIR)/strpbrk.asm			\
			$(DIR)/strcspn.asm			\
			$(DIR)/strcasecmp.asm		\
			$(DIR)/memmov.asm			\


ASMFLAGS	=	-f elf64

LDFLAGS		=	-shared

ASM		=	nasm

LD		=	gcc

RM		=	rm -f

OBJS		=	$(SRCS:.asm=.o)

NAME_TESTS	=	units

DIR_TESTS	=	tests

SRC_TESTS	=	$(DIR_TESTS)/tests_strlen.c		\
				$(DIR_TESTS)/tests_rindex.c		\
				$(DIR_TESTS)/tests_strcmp.c		\
				$(DIR_TESTS)/tests_strncmp.c	\
				$(DIR_TESTS)/tests_strchr.c		\
				$(DIR_TESTS)/tests_strpbrk.c	\
				$(DIR_TESTS)/tests_strcspn.c	\
				$(DIR_TESTS)/tests_strstr.c		\
				$(DIR_TESTS)/tests_strcasecmp.c	\
				$(DIR_TESTS)/tests_mem.c		\

%.o: %.asm
		@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $< | tr ' ' '.'
		@$(ASM) -o $@ $< $(ASMFLAGS)

all:		$(NAME)

$(NAME):	$(OBJS)
		@$(LD) $(LDFLAGS) -o $(NAME) $(OBJS) -nostdlib
		@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(NAME) | tr ' ' '.'

clean:
		@$(RM) $(OBJS)
		@$(RM) *.gcno
		@$(RM) *.gcda
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(OBJS) | tr ' ' '.'

fclean:		clean
		@$(RM) $(NAME)
		@$(RM) $(NAME_TESTS)
		@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(NAME) | tr ' ' '.'

re:		fclean all

test_run:	all
		gcc $(SRC_TESTS) -fno-builtin -ldl -Wall -Wextra --coverage -lcriterion -lgcov -o $(NAME_TESTS)
		./units

.PHONY:		all clean fclean re test_run