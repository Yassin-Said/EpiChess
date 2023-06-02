##
## EPITECH PROJECT, 2023
## NanoTekSpice
## File description:
## NanoTekSpice Makefile
##

SRC = $(wildcard ./src/*.cpp ./src/pieces/*.cpp) \
			main.cpp

OBJ =  $(SRC:.cpp=.o)

IFLAGS = -I./include

CXXFLAGS += -std=c++20 -fpic -Wall -Wextra -Werror $(IFLAGS)

NAME = EpiChess

CC = g++
CXX = g++

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf vgcore.*
	rm -rf lib
	rm -rf $(OBJ)

re: 	fclean all
