/***********************************************************************
 * Header File:
 *    Lander : represents a Lander
 * Author:
 *    Michael LeFevre, David Raya
 * Summary:
 *    A lander's attributes and behaviors 
 ************************************************************************/

#pragma once
#include "uiDraw.h" // For gout

/******************************************************************************
* Lander
* This class represents a Lunar Lander
******************************************************************************/
class Lander
{
public:
   Lander()
   {
      position = Point(20, 300);
   }

   void toggleMainThruster(bool turnOn)
   {
      mainThrustOn = turnOn;
   }

   void toggleLeftThruster(bool turnOn)
   {
      leftThrustOn = turnOn;
   }

   void toggleRightThruster(bool turnOn)
   {
      rightThrustOn = turnOn;
   }

   void draw(ogstream& gout)
   {
      gout.drawLander(position);
      gout.drawLanderFlames(position, angle, mainThrustOn, leftThrustOn, rightThrustOn);
   }

   void advanceBy()
   {
      if (mainThrustOn)
         position.addY(1.0);
      if (rightThrustOn)
         position.addX(1.0);
      if (leftThrustOn)
         position.addX(-1.0);
   }

   double getAltitude()
   {
      return position.getY();
   }

   double getFuel()
   {
      return fuel;
   }



   Point position;



private:
   
   bool mainThrustOn = false;
   bool rightThrustOn = false;
   bool leftThrustOn = false;
   double angle;
   double fuel = 3000;



};
