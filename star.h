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
   Star();

   Star(Point point, int phase) : position(point), phase(phase) {}

   void draw(ogstream& gout)
   {
      gout.drawStar(position, phase);
   }

   // Advances star forward by 1 frame 
   void advance()
   {
      phase++;
   }

private:
   Point position;
   int phase;
};
