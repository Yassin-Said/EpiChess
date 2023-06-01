##
## EPITECH PROJECT, 2023
## NanoTekSpice
## File description:
## NanoTekSpice Makefile
##

SRC = $(wildcard ./src/*.cpp) \
			main.cpp

OBJ =  $(SRC:.cpp=.o)

IFLAGS = -I./include

CXXFLAGS += -std=c++20 -fpic -Wall -Wextra -Werror

NAME = EpiChess

CC = g++
CXX = g++

all: $(ANME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(CXXFLAGS) $(IFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf vgcore.*
	rm -rf lib
	rm -rf $(OBJ)

re: 	fclean all
