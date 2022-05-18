/**********************************************************************
 * GL Demo
 * Just a simple program to demonstrate how to create an Open GL window, 
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "point.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ground.h"
#include "star.h"
#include "lander.h"
#include <array>
using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Simulator
{
public:
   Simulator(const Point& ptUpperRight) :
          angle(0.0),
          ptStar(ptUpperRight.getX() - 20.0, ptUpperRight.getY() - 20.0),
          ptLM(ptUpperRight.getX() / 2.0, ptUpperRight.getY() / 2.0),
          ground(ptUpperRight)
   { 

      
      for (Star &star : stars)
      {
         phase = random(0, 255);
         int x = random(0, 400);
         int y = random(250, 400);
         star = Star(Point(x, y), phase);
      }
   }


   // Draws everything to the screen
   void draw(ogstream& gout)
   {
      for (auto& star : stars)
      {
         star.draw(gout);
      }

      lander.draw(gout);

      ground.draw(gout);

      gout.setPosition(Point(10.0, 385.0));
      gout << "Altitude: " << lander.getAltitude() << " meters" << "\n"
           << "Fuel: " << lander.getFuel() << " lbs" << "\n"
           << "Speed: " << 12.9 << " m/s";


   }
   // Updates the star's phase, and the Lander's position
   void advance()
   {
      for (auto& star : stars)
      {
         star.advance();
      }

      lander.advanceBy();

   }

   // Activates thrusters based on user input.
   void applyInput(bool isUp, bool isDown, bool isRight, bool isLeft)
   {
      lander.toggleMainThruster(isDown);
      lander.toggleLeftThruster(isLeft);
      lander.toggleRightThruster(isRight);
      if (isUp)
         lander.position.addY(-1.0);
   }

   // this is just for test purposes.  Don't make member variables public!
   Point ptLM;           // location of the LM on the screen
   Point ptUpperRight;   // size of the screen
   double angle;         // angle the LM is pointing
   unsigned char phase;  // phase of the star's blinking
   Ground ground;
   Point ptStar;
   array<Star, 50> stars;

private:
   Lander lander;


};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void * p)
{
   ogstream gout;

   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Simulator * pSimulator = (Simulator *)p;

   bool isRight = false;
   bool isLeft = false;
   bool isUp = false;
   bool isDown = false;

   if (pUI->isRight())
      isRight = true;
   if (pUI->isLeft())
      isLeft = true;
   if (pUI->isUp())
      isUp = true;
   if (pUI->isDown())
      isDown = true;

   pSimulator->applyInput(isUp, isDown, isRight, isLeft);
   pSimulator->advance();
   pSimulator->draw(gout);

}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance, 
   _In_opt_ HINSTANCE hPrevInstance, 
   _In_ PWSTR pCmdLine, 
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char ** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Point ptUpperRight(400.0, 400.0);
   Interface ui(0, NULL, 
                "Open GL Demo", 
                 ptUpperRight);

   // Initialize the game class
   Simulator demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);             

   return 0;
}