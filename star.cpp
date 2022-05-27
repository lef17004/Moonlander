//
//  star.cpp
//  Lab03
//
//  Created by Michael LeFevre on 5/20/22.
//

#include "star.h"
/******************************************************************************
 * STAR DEFAULT CONSTRUCTOR
 ******************************************************************************/
Star::Star()
{
   // TODO: Use stacic variable in point rather than hardcoding values. 
   phase = random(0, 255);
   int x = random(0, 400);
   int y = random(225, 400);
   position = Point(x, y);
}

