/***********************************************************************
 * Header File:
 *    Velocity : Represents a velcity
 * Author:
 *    Michael LeFevre, David Raya
 * Summary:
 *    Where the ground is located and where the landing pad is located
 ************************************************************************/

#pragma once

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

   double getDx()
   {
      return dx;
   }

   double getDy()
   {
      return dy;
   }

   void addDx(double amount)
   {

   }

   void addDy(double amount)
   {

   }

   double getSpeed()
   {

   }

   double getTotalVelocity()
   {

   }

   double setDx(double dx)
   {

   }

   double setDy(double dy)
   {

   }
};
