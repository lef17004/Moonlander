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
   phase = random(0, 255);
   int x = random(0, 400);
   int y = random(250, 400);
   position = Point(x, y);
}
