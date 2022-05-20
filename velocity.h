/***********************************************************************
 * Header File:
 *    Velocity : Represents a velcity
 * Author:
 *    Michael LeFevre, David Raya
 * Summary:
 *    Where the ground is located and where the landing pad is located
 ************************************************************************/

#pragma once
#include "physics.cpp"
#include "acceleration.h"
/******************************************************************************
* Velocity
* Represents a velocity
******************************************************************************/
class Velocity
{
private:
   double dx;
   double dy;

public:
   Velocity(): dx(0.0), dy(0.0) {}
   Velocity(double dx, double dy): dy(dx), dy(dy) {}

   double getDx()
   {
      return dx;
   }

   double getDy()
   {
      return dy;
   }
   
   double setDx(double dx)
   {
      this->dx = dx;
   }
   
   double setDy(double dy)
   {
      this->dy = dy;
   }

   double getSpeed()
   {
      return computeTotalComponent(dx, dy);
   }
   
   void add(Acceleration accel, double time)
   {
      dx = computeVelocity(dx, accel.getDDX(), time);
      dy = computeVelocity(dy, accel.getDDY(), time);
   }



};
