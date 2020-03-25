##
## EPITECH PROJECT, 2020
## CPE_dante_2019
## File description:
## Makefile
##

SUCCESS				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[32m $1\x1b[0m"
WARNING				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[33m $1\x1b[0m"
ERROR				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[31m $1\x1b[0m"
DONE				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[34m $1\x1b[0m"

LIB 				= lib_string.a

SRC 				= atoi.c	\
					  memalloc.c	\
					  putchar.c	\
					  putstr.c	\
					  strcmp.c	\
					  strlen.c	\


CFLAGS 				= -Wall -I./include

AR 					= @ar rc

LIB_OBJ 			= $(SRC:.c=.o)

directory 			= ../../include/library/_string

all:				| $(directory) $(LIB)
					@cp -rf include/ $(directory)
					@$(call SUCCESS, "[ OK ] include has benn correctly copied into ../../include/library/_string/")
					@$(call DONE, "[ DONE 100% ]")

$(directory):
					mkdir -p $@

$(LIB):			$(LIB_OBJ)
					@$(AR) $(LIB) $(LIB_OBJ)
					@$(call SUCCESS, "[ OK ] Libmy library successfully compiled.")
					@mv $(LIB) ../
					@$(call SUCCESS, "[ OK ] _string.a has been correctly moved into ../")

clean_lib:
					@$(RM) $(LIB)
					@$(RM) ../$(LIB)

clean:
					@$(RM) $(LIB_OBJ)
					@$(call SUCCESS, "[ OK ] *.o are removed in libmy")

fclean: 			clean
					@$(RM) ../$(LIB)
					@$(RM) $(LIB)
					@$(RM) -rf $(directory)
					@$(call SUCCESS, "[ OK ] Libmy library fully cleaned.")

re: 				fclean all

.PHONY				: all clean fclean re