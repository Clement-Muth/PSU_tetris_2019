##
## EPITECH PROJECT, 2020
## PSU_tetris_2019 [WSL: Debian]
## File description:
## Makefile
##

## ========================================================================== ##
ERROR_PATH		=	error/
ERROR_SRC		=	error_handling.c

## ========================================================================== ##
INIT_PATH		=	init/
INIT_SRC		=	init.c

## ========================================================================== ##
PROCESS_PATH	=	process/
PROCESS_SRC		=	process.c

## ========================================================================== ##
DISPLAY_PATH	=	display/
DISPLAY_SRC		=	display.c

## ========================================================================== ##
FREE_PATH		=	free/
FREE_SRC		=	free.c

SRC				=	main.c	\
					$(addprefix $(ERROR_PATH), $(ERROR_SRC))	\
					$(addprefix $(INIT_PATH), $(INIT_SRC))	\
					$(addprefix $(PROCESS_PATH), $(PROCESS_SRC))	\
					$(addprefix $(DISPLAY_PATH), $(DISPLAY_SRC))	\
					$(addprefix $(FREE_PATH), $(FREE_SRC))	\

BIN				= 	tetris

CC				= 	gcc

OBJ 			= 	$(SRC:.c=.o)

RM				=	rm

CFLAGS			=	-W -Wall -Werror

LDFLAGS			=	-lm -L../../library -l_string -lopenf -I../../include/

DFLAGS			=	-g -Wfatal-errors -Wpedantic -Wextra \
					-Wnonnull -Wmain -Wmissing-attributes -Wsequence-point -pg

LIBPATH			=	../../library

all:			$(BIN)

debug:			$(OBJ)
				@$(CC) -o $(BIN) $(OBJ) $(LDFLAGS) $(DFLAGS) -DDEBUG

$(BIN):			lib $(OBJ)
				@$(CC) -o $(BIN) $(OBJ) $(LDFLAGS) $(CFLAGS)

lib:
				@$(MAKE) -C ../../library/_string/
				@$(MAKE) -C ../../library/_open/

clean:
				@$(RM) $(OBJ)
				@$(MAKE) -C ../../library/_string/ clean
				@$(MAKE) -C ../../library/_open/ clean

fclean:
				$(RM) ../../generator/$(BIN)
				@$(MAKE) -C ../../library/_string/ fclean
				@$(MAKE) -C ../../library/_open/ fclean

re:				fclean all

.PHONY:			 all, fclean, re, library

## ========================================================================== ##
%.o:	%.c
	@gcc $(LDFLAGS) -g -o $@ -c $<