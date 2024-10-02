#include <SFML/Graphics.hpp> ///opt/homebrew/Cellar/sfml/2.6.1 (g++ main.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system)

int main(){
    sf::RenderWindow window(sf::VideoMode(1400, 800), "Firewall"); //
    while (window.isOpen()) //window loop 
    {
        sf::Event event;
        while (window.pollEvent(event)) //when an event plays
        {
            if (event.type == sf::Event::Closed) //checks if the event is closed
                window.close(); //closes window
        }

        window.clear(); //clears the screen
        window.display(); //updates the window
    }

    return 0;
}