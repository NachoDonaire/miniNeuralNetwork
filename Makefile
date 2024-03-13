SRCSDIR = ./src/

SRC =	Creature \
	Input	\
	OutNeuron	\
	Neuron	\
	Network	\
	utils	\
	main

SRCS = $(addprefix $(SRCSDIR), $(SRC))

SRCF = $(addsuffix .cpp, $(SRCS))

NAME = miniNeuralNetwork

CC = c++

CPPFLAGS =  -I ./inc 

LIBS = -l SDL2 -L /usr/lib/x86_64-linux-gnu/ -lm -ldl -lglfw -pthread -lSDL2_ttf

OBJ 	= $(addsuffix .o,$(SRCS))

#ifeq ($(shell uname), Linux)
#	LIBS = $(DMLX)$(NMLX) -ldl -lglfw -pthread -lm
#else ifeq ($(findstring Darwin, $(shell uname)), Darwin)
#	LIBS = $(DMLX)$(NMLX) ./MLX42/libglfw3.a -framework Cocoa -framework OpenGL -framework IOKit
#else
#	$( info **** S.O no ha sido reconocido ****)
#endif




all 	:	$(NAME)

#$(OBJ)	:	$(SRCF)
#	$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

$(NAME)	:	$(OBJ)
			#@make -C $(MLXDIR)
			$(CC) $(CPPFLAGS) $(SRCF) -o $(NAME) $(LIBS)

clean:
	#@make clean -C $(MLXDIR)
	rm -rf $(OBJ)
fclean:
	#@make clean -C $(MLXDIR)
	rm -rf $(OBJ) $(NAME)


