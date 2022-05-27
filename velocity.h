/***********************************************************************
 * Header File:
 *    Velocity : Represents a velcity
 * Author:
 *    Michael LeFevre, David Raya
 * Summary:
 *    Where the ground is located and where the landing pad is located
 ************************************************************************/

#pragma once
#include "acceleration.h"
#include "math.h"
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
   Velocity(double dx, double dy): dx(dx), dy(dy) {}

   // Getters
   double getDx() const { return dx; }
   double getDy() const { return dy; }
   
   // Setters
   void setDx(double dx) { this->dx = dx; }
   void setDy(double dy) { this->dy = dy; }

   double getSpeed() const { return sqrt((dx * dx) + (dy * dy));; }
   
   void add(Acceleration accel, double time)
   {
      dx = dx + (accel.getDDX() * time);
      dy = dy + (accel.getDDY() * time);
   }
};
