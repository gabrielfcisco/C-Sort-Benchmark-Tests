# # Name of the project
# PROJ_NAME=projeto2
 
# # .c files
# C_SOURCE=$(wildcard ./src/*.c)
 
# # .h files
# H_SOURCE=$(wildcard ./include/*.h)
 
# # Object files
# OBJ=$(subst .c,.o,$(subst source,objects,$(C_SOURCE)))
 
# # Compiler and linker
# CC=gcc
 
# # Flags for compiler
# CC_FLAGS=-c         \
# 		 -W         \
# 		 -Wall      \
# 		 -ansi      \
# 		 -pedantic
 
# # Command used at clean target
# RM = rm -rf
 
# #
# # Compilation and linking
# #
# all: objFolder $(PROJ_NAME)
 
# $(PROJ_NAME): $(OBJ)
# 	@ echo 'Building binary using GCC linker: $@'
# 	$(CC) $< -o $@
# 	@ echo 'Finished building binary: $@'
# 	@ echo ' '
 
# ./objects/%.o: ./source/%.c ./source/%.h
# 	@ echo 'Building target using GCC compiler: $<'
# 	$(CC) $< $(CC_FLAGS) -o $@
# 	@ echo ' '
 
# ./objects/main.o: ./main.c $(H_SOURCE)
# 	@ echo 'Building target using GCC compiler: $<'
# 	$(CC) $< $(CC_FLAGS) -o $@
# 	@ echo ' '
 
# objFolder:
# 	@ mkdir -p objects
 
# clean:
# 	@ $(RM) ./objects/*.o $(PROJ_NAME) *~
# 	@ rmdir objects
 
# .PHONY: all clean

CC = gcc
CFLAGS = -I./include
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Lista de arquivos de origem
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Gera os nomes dos arquivos objetos
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Nome do executável
TARGET = $(BIN_DIR)/PROJETO2

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CC) -o $@ $^

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean