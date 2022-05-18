/***********************************************************************
 * Header File:
 *    Angle: Represents an Angle
 * Author:
 *    Michael LeFevre, David Raya
 * Summary:
 *    An angle
 ************************************************************************/

#pragma once
#include <iostream>
#include <math.h>
using namespace std;
#define PI 3.14159


/******************************************************************************
 * ANGLE
 * This class represents an angle.
 ******************************************************************************/
class Angle
{
public:

   void setDegrees(double degrees)
   {
      double radians = convertToRadinas(degrees);
      angleRadians = normalize(radians);
   }

   void setRadians(double radians)
   {
      angleRadians = normalize(radians);
   }

   float getDegrees()
   {
      return convertToDegrees(getRadians());
   }

   float getRadians()
   {
      return angleRadians;
   }

private:

   double angleRadians;

   double convertToDegrees(double radians)
   {
      return (180.0 * radians) / PI;
   }

   double convertToRadinas(double degrees)
   {
      return (degrees * 2.0 * PI) / 360.0;
   }

   // Wraps a value around the range [0, 2PI)
   double normalize(double value)
   {
      double normalizedRadianValue = value - (2.0 * PI * floor(value / (2.0 * PI)));

      return normalizedRadianValue;
   }

};