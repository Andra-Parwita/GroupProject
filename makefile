# Compiler
COMPILER = g++
FLAGS = -std=c++11 -I/opt/homebrew/Cellar/sfml/2.6.1/include
INCLUDE = -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Source files
FILES = main.cpp game.cpp grid.cpp tile.cpp application.cpp fileExplorer.cpp vpn.cpp vscode.cpp antivirus.cpp chrome.cpp gameController.cpp virus.cpp bug.cpp trojan.cpp worm.cpp shooter.cpp logicBomb.cpp iloveyou.cpp
FILEXP = fileExplorer.cpp application.cpp shooter.cpp  fileExplorerMain.cpp
VPN = vpn.cpp application.cpp shooter.cpp vpnMain.cpp
TAFILE = vscode.cpp application.cpp vscodeMain.cpp
TVFILE = virus.cpp virusTest.cpp bug.cpp

#Name
OUT = a.out
VPNOUT = vpnTest.out
FILEXPOUT = filetest.out
TOUT = test.out
VOUT = Vtest.out

# Rules
all: 
	$(COMPILER) $(FLAGS) $(FILES) -o $(OUT) $(INCLUDE)
fileExp: 
	$(COMPILER) $(FLAGS) $(FILEXP) -o $(FILEXPOUT) $(INCLUDE)
vpn:
	$(COMPILER) $(FLAGS) $(VPN) -o $(VPNOUT) $(INCLUDE)
AppTest:
	$(COMPILER) $(FLAGS) $(TAFILE) -o $(TOUT) $(INCLUDE)
VirusTest:
	$(COMPILER) $(FLAGS) $(TVFILE) -o $(VOUT) $(INCLUDE)
clean:
	rm -f $(OUT) $(VPNOUT) $(FILEXPOUT) $(TOUT) $(VOUT)