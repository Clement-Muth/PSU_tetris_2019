##
## EPITECH PROJECT, 2019
## makefile
## File description:
## make files
##

FSRC	:=	src/

FMINOS	:=	$(FSRC)/minos/

FFLAG	:=	$(FSRC)/flags/

FCURSE	:=	$(FSRC)/curse/

SRC	:=	$(FSRC)main.c	\
		$(FFLAG)read_flags.c	\
		$(FFLAG)check_help.c	\
		$(FFLAG)fill_flags.c	\
		$(FFLAG)adapt_flags.c	\
		$(FFLAG)debug_mode.c	\
		$(FCURSE)init_curse.c	\
		$(FCURSE)process_curse.c	\
		$(FMINOS)read_minos.c	\
		$(FMINOS)checker.c	\
		$(FMINOS)count_asterisk.c	\
		$(FMINOS)fill_minos.c	\
		$(FMINOS)format_piece.c	\
		$(FMINOS)get_file.c	\
		$(FMINOS)adapt_minos.c	\
		$(FMINOS)print_minos.c	\
		$(FMINOS)next_tab.c	\

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

$(NAME):	$(OBJ)	make_all
	@$(CC)  $(OBJ) -o $(NAME) $(LDFLAGS)
	@echo -e "$(CLEAR)$(NAME) : $(COLOR)OK$(WHITE)"

%.o:	%.c
	@$(CC) -o $@ -c $< $(CFLAGS)
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
