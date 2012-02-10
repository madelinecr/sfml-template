#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

void setClear() {
  glClearDepth(1.f);
  glClearColor(0.f, 0.f, 0.f, 0.f);
}

void drawCube(sf::Clock Clock) {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.f, 0.f, -200.f);
  glRotatef(Clock.GetElapsedTime() * 50, 1.f, 0.f, 0.f);
  glRotatef(Clock.GetElapsedTime() * 30, 0.f, 1.f, 0.f);
  glRotatef(Clock.GetElapsedTime() * 90, 0.f, 0.f, 1.f);

  glBegin(GL_QUADS);

    glVertex3f(-50.f, -50.f, -50.f);
    glVertex3f(-50.f,  50.f, -50.f);
    glVertex3f( 50.f,  50.f, -50.f);
    glVertex3f( 50.f, -50.f, -50.f);

    glVertex3f(-50.f, -50.f, 50.f);
    glVertex3f(-50.f,  50.f, 50.f);
    glVertex3f( 50.f,  50.f, 50.f);
    glVertex3f( 50.f, -50.f, 50.f);

    glVertex3f(-50.f, -50.f, -50.f);
    glVertex3f(-50.f,  50.f, -50.f);
    glVertex3f(-50.f,  50.f,  50.f);
    glVertex3f(-50.f, -50.f,  50.f);

    glVertex3f(50.f, -50.f, -50.f);
    glVertex3f(50.f,  50.f, -50.f);
    glVertex3f(50.f,  50.f,  50.f);
    glVertex3f(50.f, -50.f,  50.f);

    glVertex3f(-50.f, -50.f,  50.f);
    glVertex3f(-50.f, -50.f, -50.f);
    glVertex3f( 50.f, -50.f, -50.f);
    glVertex3f( 50.f, -50.f,  50.f);

    glVertex3f(-50.f, 50.f,  50.f);
    glVertex3f(-50.f, 50.f, -50.f);
    glVertex3f( 50.f, 50.f, -50.f);
    glVertex3f( 50.f, 50.f,  50.f);

  glEnd();
}

int main() {
  sf::Clock Clock;

  sf::Window App(sf::VideoMode(800, 600, 32), "SFML Window");

  glEnable(GL_DEPTH_TEST);
  glDepthMask(GL_TRUE);

  // Setup a perspective projection
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(90.f, 1.f, 1.f, 500.f);

  sf::Event Event;
  while(App.IsOpened()) {
    if(App.GetEvent(Event))
      if(Event.Type == sf::Event::Closed)
        App.Close();

    setClear();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawCube(Clock);
    App.Display();
  }

  return 0;
}
