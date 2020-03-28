##
## EPITECH PROJECT, 2020
## CPE_dante_2019
## File description:
## Makefile
##

SUCCESS				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[32m $1\x1b[0m"
WARNING				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[33m $1\x1b[0m"
ATT				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[31m $1\x1b[0m"
DONE				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[34m $1\x1b[0m"

LIB 				= lib_open.a

SRC 				= openf_readf.c	\

CFLAGS 				= -Wall -I./include

LDFLAGS				= -L../../ -l_string

AR 					= @ar rc

LIB_OBJ 			= $(SRC:.c=.o)

directory 			= ../../include/library/_open

all:				| $(directory) $(LIB)
					@cp -rf include/ $(directory)
					@$(call SUCCESS, "[ OK ] include has benn correctly copied into ../../include/library/_open/")
					@$(call DONE, "[ DONE 100% ]")

$(directory):
					@mkdir -p $@
					@$(call WARNING, "[ /!\ ] Creating folder called _open into ../../include/library/_open/")

$(LIB):			$(LIB_OBJ)
					@$(AR) $(LIB) $(LIB_OBJ)
					@$(call SUCCESS, "[ OK ] lib_open.a library successfully compiled.")
					@mv $(LIB) ../
					@$(call SUCCESS, "[ OK ] _open.a has been correctly moved into ../")

clean_lib:
					@$(RM) $(LIB)
					@$(RM) ../$(LIB)

clean:
					@$(RM) $(LIB_OBJ)
					@$(call ATT, "[ OK ] *.o are removed in lib_open.a")

fclean: 			clean
					@$(RM) ../$(LIB)
					@$(RM) $(LIB)
					@$(RM) -rf $(directory)
					@$(call ATT, "[ OK ] lib_open.a library fully cleaned.")

re: 				fclean all

.PHONY				: all clean fclean re

## ========================================================================== ##
%.o:	%.c
	@gcc $(LDFLAGS) $(CFLAGS) -g -o $@ -c $<