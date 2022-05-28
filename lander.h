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
#include "angle.h"
#include "acceleration.h"
#include "velocity.h"
#include "math.h"
#define GRAVITY -1.625

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
      angle = Angle();
      weight = 15103.0;
      totalThrust = 45000.0;
      alive = true;
      fuel = 5000;
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

   void draw(ogstream& gout);

   void advanceBy(double time);

   double getAltitude()
   {
      return position.getY();
   }

   double getFuel()
   {
      return fuel;
   }

   Point getPosition()
   {
      return position;
   }
   
   void kill();
   
   void land();

   double getTotalSpeed()
   {
      return velocity.getSpeed();
   }
   
   float getAngle()
   {
      return angle.getDegrees();
   }

   Point position;



private:
   bool mainThrustOn = false;
   bool rightThrustOn = false;
   bool leftThrustOn = false;
   Angle angle;
   double fuel = 3000;
   Velocity velocity;
   Acceleration accel;
   double weight;
   double totalThrust;
   bool alive;
   

   void calculateAcceleration();
   
   void calculateVelocity(double time)
   {
      velocity.add(accel, time);
   }
   
   void calulatePosition(double time)
   {
      position.add(accel, velocity, time);
   }

   void rotateLeft()
   {
      angle.add(-0.1);
   }
   
   void rotateRight()
   {
      angle.add(0.1);
   }

   
};
