#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

int main() {
//  sf::Clock clock;
//  while(clock.GetElapsedTime() < 5.f) {
//    std::cout << clock.GetElapsedTime() << std::endl;
//  }

  sf::Window App(sf::VideoMode(800, 600, 32), "SFML Window");

  bool running = true;

  sf::Event Event;
  while(running) {
    if(App.GetEvent(Event))
      if(Event.Type == sf::Event::Closed)
        running = false;

    App.Display();
  }

  return 0;
}
