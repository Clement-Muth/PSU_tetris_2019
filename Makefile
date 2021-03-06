##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make files
##

FSRC	:=	src/

FMINOS	:=	$(FSRC)minos/

FFLAG	:=	$(FSRC)flags/

FCURSE	:=	$(FSRC)curse/

SRC	:=	$(FSRC)main.c	\
		$(FFLAG)read_flags.c	\
		$(FFLAG)check_help.c	\
		$(FFLAG)fill_flags.c	\
		$(FFLAG)adapt_flags.c	\
		$(FFLAG)debug_mode.c	\
		$(FCURSE)init/init_curse.c	\
		$(FCURSE)process/process_curse.c	\
		$(FCURSE)get/utilities_curse.c	\
		$(FCURSE)display/display_game.c	\
		$(FCURSE)process/process_display.c	\
		$(FCURSE)process/process_next_minos.c	\
		$(FCURSE)process/process_collisions.c	\
		$(FCURSE)init/create_map.c	\
		$(FCURSE)check/checker.c	\
		$(FCURSE)display/print_timer.c	\
		$(FCURSE)get/get_inputs.c	\
		$(FMINOS)read_minos.c	\
		$(FMINOS)count_asterisk.c	\
		$(FMINOS)fill_minos.c	\
		$(FMINOS)format_piece.c	\
		$(FMINOS)get_file.c	\
		$(FMINOS)adapt_minos.c	\
		$(FMINOS)print_minos.c	\
		$(FMINOS)next_tab.c	\
		$(FMINOS)rotate_minos.c	\
		$(FMINOS)free_minos.c	\
		$(FMINOS)checker.c	\

NAME	:=	tetris

OBJ	:=	$(SRC:.c=.o)

_MAKEFILES	:=	linked	\
				regex	\
				my	\
				_open	\
				_string	\

LIBS	:=	$(addprefix -l, $(_MAKEFILES))

LDFLAGS +=	-L./lib $(LIBS) -lncurses

CFLAGS	+=	-Wall

COLOR	:=	\033[01;38;5;31m

WHITE	:=	\033[0;0m

CLEAR	:=	\033[2K

all:	$(NAME)

$(NAME):	make_all $(OBJ)
	@$(CC)  $(OBJ) -o $(NAME) $(LDFLAGS)
	@echo -e "$(CLEAR)$(NAME) : $(COLOR)OK$(WHITE)"

%.o:	%.c
	@$(CC) -o $@ -c $< -g -Iinclude/ $(CFLAGS)
	@echo -ne "$(CLEAR)Compiled $< : $(COLOR)OK$(WHITE)\r"

clean:	make_clean
	@find ./$(FSRC) -name "*.o" -delete
	@rm -f vgcore*
	@echo -e "'.o' Deletion : \033[01;38;5;220mDONE$(WHITE)"

fclean: clean	make_fclean
	@rm -f $(NAME)
	@echo -e "'$(NAME)' deletion : \033[01;38;5;222mDONE$(WHITE)"

re:	fclean	all

de:	make_all
	@$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) -g
	@echo "Valgrind Output :"
	@valgrind --leak-check=full ./$(NAME)

go:	all
	@./$(NAME)

make_all:
	@for makefile in $(_MAKEFILES); do	\
	$(MAKE) --no-print-directory -C lib/$$makefile;	\
	done

make_clean:
	@for makefile in $(_MAKEFILES); do	\
	$(MAKE) --no-print-directory -C lib/$$makefile clean;	\
	done

make_fclean:
	@for makefile in $(_MAKEFILES); do	\
	$(MAKE) --no-print-directory -C lib/$$makefile fclean;	\
	done

.PHONY:	$(NAME) clean fclean re go de
