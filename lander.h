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

   void draw(ogstream& gout)
   {
      gout.drawLander(position, angle.getRadians());
      
      if (alive)
      {
         if (fuel < 10.0)
            mainThrustOn = false;
         
         if (fuel < 0.1)
         {
            leftThrustOn = false;
            rightThrustOn = false;
         }
         
         gout.drawLanderFlames(position, angle.getRadians(), mainThrustOn, leftThrustOn, rightThrustOn);
      }
         
   }

   void advanceBy(double time)
   {
      
      if (!alive)
         return;
      
      
      calculateAcceleration();
      calculateVelocity(time);
      calulatePosition(time);
      
      if (mainThrustOn && fuel >= 10.0)
      {
         fuel -= 10.0;
      }
      
      if (rightThrustOn && fuel >= 0.1)
      {
         rotateLeft();
         fuel -= 0.1;
      }
         
      if (leftThrustOn && fuel >= 0.1)
      {
         rotateRight();
         fuel -= 0.1;
      }
         
   }

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
   
   void kill()
   {
      alive = false;
      angle.setDegrees(180);
      velocity.setDx(0);
      velocity.setDy(0);
   }
   
   void land()
   {
      alive = false;
   }

   double getTotalSpeed()
   {
      return velocity.getSpeed();
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
   

   void calculateAcceleration()
   {
     
      double ddxThrust = 0.0;
      double ddyThrust = 0.0;
      
      if (mainThrustOn && fuel >= 10.0)
      {
         ddxThrust = -sin(angle.getRadians()) * totalThrust;
         ddyThrust = cos(angle.getRadians()) * totalThrust;
      }
      
      double ddx = ddxThrust / weight;
      double ddy = (ddyThrust / weight) + GRAVITY;
      
      Acceleration acceleration(ddx, ddy);
      accel = acceleration;
      
   }
   
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
      angle.rotate(-0.1);
   }
   
   void rotateRight()
   {
      angle.rotate(0.1);
   }
   
};
