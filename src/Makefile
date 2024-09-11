PROJ_NAME=portugol

LIBS=queue.h tokens.h lexico.h sintatico.h
OBJETOS=lexico.o sintatico.o queue.o tokens.o
FONTES=lexico.c queue.c sintatico.c tokens.c

# compilador
CC=gcc

# Flags
CFLAGS= -ggdb -O0 -std=c99 -fstack-protector-all -Werror=implicit-function-declaration
LDFLAGS=-O0

$(PROJ_NAME): $(OBJETOS)
	$(CC) -o $(PROJ_NAME) $(LDFLAGS) $(OBJETOS) $(LIBS)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

entrega: $(LIBS) $(FONTES) Makefile
	zip portugol.zip $(LIBS) $(FONTES) Makefile