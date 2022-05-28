//
//  star.cpp
//  Lab03
//
//  Created by Michael LeFevre on 5/20/22.
//

#include "star.h"
#include "point.h"
/******************************************************************************
 * STAR DEFAULT CONSTRUCTOR
 ******************************************************************************/
Star::Star()
{
   phase = random(0, 255);
   int x = random(0, (int) Point::screenHeight.getX());
   int y = random(225, (int) Point::screenHeight.getY());
   position = Point(x, y);
}

