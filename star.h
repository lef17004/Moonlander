/***********************************************************************
 * Header File:
 *    Velocity : Represents a velcity
 * Author:
 *    Michael LeFevre, David Raya
 * Summary:
 *    A star with its position and its phase.
 ************************************************************************/


#pragma once

#include "point.h"   // for Point
#include "uiDraw.h"  //

/*********************************************
* Star
* A single star.
*********************************************/
class Star
{
public:
   Star()
   {
      point = Point();
      phase = 100;
   }

   Star(Point point, int phase) : point(point), phase(phase) {}

   void draw(ogstream& gout)
   {
      gout.drawStar(point, phase);
   }

   void advance()
   {
      this->phase++;
   }

private:
   Point point;
   int phase;


};
