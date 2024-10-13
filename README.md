# GroupProject
Group Project for OOP (comp sci)

Description:
A single-level lane-type tower defence game similar to Plants vs Zombies using typical computer applications that defend the computer against viruses. The game will consist of “applications” you can place on the field. The field will consist of  5x20 tiles (subject to change). The goal is to stop the viruses from reaching your side as they cross the field. 

To do:
core:
- App (change VPN into something else)
- App cooldowns after placement (so there is no more spam)
- game over 
Additional:
- Refactor the whole damn code (reduce redundancy, add const)
- Convert Virus Manager into std::vector (from array)
- Spriting 
- Menu (pause)
- Make a damn Makefile
- controlled test cases
- balancing
- showing hp states
- put stuff into folders cause omg it's hard to read and find stuff

Authored by Ida Bagus Andra Parwita and Fardeen Rahman
 - note GitHub Andra-Parwita did not link with the computer used to push, hence different collaborations (check commits in main)

g++ -std=c++11 main.cpp game.cpp grid.cpp tile.cpp application.cpp fileExplorer.cpp vpn.cpp vscode.cpp antivirus.cpp chrome.cpp gameController.cpp  virus.cpp bug.cpp trojan.cpp worm.cpp shooter.cpp logicBomb.cpp iloveyou.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system