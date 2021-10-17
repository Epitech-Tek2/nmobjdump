##
## EPITECH PROJECT, 2021
## library [WSL: Debian]
## File description:
## Makefile
##

NAMENM	=	my_nm
NAMEOBJ	=	my_objdump

COMMONDIR	=	sources

OBJDIR	=	$(COMMONDIR)/objdump
NMDIR	=	$(COMMONDIR)/nm

SRCSNM	=	$(NMDIR)/main.c	\
			$(COMMONDIR)/utils.c	\
			$(COMMONDIR)/parser.c	\
			$(COMMONDIR)/ar/ar_file.c	\
			$(COMMONDIR)/ar/getter.c	\
			$(OBJDIR)/write_header.c	\
			$(OBJDIR)/write_section.c	\
			$(NMDIR)/elf_process.c	\
			$(NMDIR)/write_sym.c	\
			$(NMDIR)/sort_sym.c

SRCSOBJ	=	$(OBJDIR)/objdump.c	\
			$(COMMONDIR)/utils.c	\
			$(COMMONDIR)/parser.c	\
			$(COMMONDIR)/ar/ar_file.c	\
			$(COMMONDIR)/ar/getter.c	\
			$(OBJDIR)/write_header.c	\
			$(OBJDIR)/write_section.c	\
			$(OBJDIR)/write.c	\
			$(OBJDIR)/parsing_args.c

CFLAGS	+=	-W -Wall -Wextra -g
CFLAGS	+=	-Iincludes/

LBLIBS	=	-L./bin/ -lutils -L./bin/ -lassert -g
LIB_PATH	=	library

CC	=	gcc

RM	=	rm -f

OBJSNM	=	$(SRCSNM:.c=.o)
OBJSOBJ	=	$(SRCSOBJ:.c=.o)

%.o: %.c
		@$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)

all:	objdump nm

nm:		lib $(NAMENM)

objdump:	lib $(NAMEOBJ)

lib:
		$(MAKE) -C $(LIB_PATH)/utils/
		$(MAKE) -C $(LIB_PATH)/assert/

$(NAMENM):	$(OBJSNM)
		@$(CC) $(OBJSNM) -o $(NAMENM) $(LDFLAGS) $(LBLIBS)

$(NAMEOBJ):	$(OBJSOBJ)
		@$(CC) $(OBJDIR)/main.c $(OBJSOBJ) -o $(NAMEOBJ) $(LDFLAGS) $(LBLIBS)

tests_run: lib
	gcc $(SRCSOBJ) tests/*.c -o unit_tests --coverage -lcriterion -Iincludes/ $(LBLIBS)
	- ./unit_tests

clean:
		@$(RM) $(OBJSNM)
		@$(RM) $(OBJSOBJ)
		@$(RM) *.gcda
		@$(RM) *.gcno
		@$(RM) unit_tests
		$(MAKE) -C $(LIB_PATH)/assert/ clean
		$(MAKE) -C $(LIB_PATH)/utils/ clean

fclean:		clean
		@$(RM) $(NAMENM)
		@$(RM) $(NAMEOBJ)
		$(MAKE) -C $(LIB_PATH)/assert/ fclean
		$(MAKE) -C $(LIB_PATH)/utils/ fclean

re:		fclean all

.PHONY:		all clean fclean re