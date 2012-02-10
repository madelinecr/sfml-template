#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

void setClear() {
  glClearDepth(1.f);
  glClearColor(0.f, 0.f, 0.f, 0.f);
}

int main() {
//  sf::Clock clock;
//  while(clock.GetElapsedTime() < 5.f) {
//    std::cout << clock.GetElapsedTime() << std::endl;
//  }

  sf::Window App(sf::VideoMode(800, 600, 32), "SFML Window");

  sf::Event Event;
  while(App.IsOpened()) {
    if(App.GetEvent(Event))
      if(Event.Type == sf::Event::Closed)
        App.Close();

    setClear();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    App.Display();
  }

  return 0;
}
