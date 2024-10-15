# Compiler
COMPILER = g++
FLAGS = -std=c++11 -I/opt/homebrew/Cellar/sfml/2.6.1/include
INCLUDE = -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Source files
FILES = main.cpp game.cpp grid.cpp tile.cpp application.cpp fileExplorer.cpp vpn.cpp vscode.cpp antivirus.cpp chrome.cpp gameController.cpp virus.cpp bug.cpp trojan.cpp worm.cpp shooter.cpp logicBomb.cpp iloveyou.cpp

#Name
OUT = a.out

# Rules
all: 
	$(COMPILER) $(FLAGS) $(FILES) -o $(OUT) $(INCLUDE)

clean:
	rm -f $(OUT)