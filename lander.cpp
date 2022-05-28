/***********************************************************************
 * Source File:
 *    Lander: represent a lunar lander
 * Author:
 *    Michael LeFevre, David Raya
 * Summary:
 *    Runs the calculations for the lander and draws it on the screen.
 ************************************************************************/

#include "uiDraw.h" // For gout
#include "angle.h"
#include "acceleration.h"
#include "velocity.h"
#include "math.h"
#include "lander.h"
#include "physics.h"
#define GRAVITY -1.625
#define MAIN_THRUSTER_FUEL 10.0
#define SIDE_THRUSTER_FUEL 0.1


/******************************************************************************
* DRAW
* Draws the lander on the screen based on the position and the angle.
******************************************************************************/
void Lander::draw(ogstream& gout)
{
   gout.drawLander(position, angle.getRadians());

   if (active)
   {
      if (fuel < MAIN_THRUSTER_FUEL)
         mainThrustOn = false;

      if (fuel < SIDE_THRUSTER_FUEL)
      {
         leftThrustOn = false;
         rightThrustOn = false;
      }

      gout.drawLanderFlames(position, angle.getRadians(), mainThrustOn, leftThrustOn, rightThrustOn);
   }

}

/******************************************************************************
* ADVANCE BY
* Moves the simulation by a specified amount of time.
******************************************************************************/
void Lander::advanceBy(double time)
{
   if (!active)
      return;


   calculateAcceleration();
   calculateVelocity(time);
   calulatePosition(time);

   if (mainThrustOn && fuel >= MAIN_THRUSTER_FUEL)
   {
      fuel -= MAIN_THRUSTER_FUEL;
   }

   if (rightThrustOn && fuel >= SIDE_THRUSTER_FUEL)
   {
      rotateLeft();
      fuel -= SIDE_THRUSTER_FUEL;
   }

   if (leftThrustOn && fuel >= SIDE_THRUSTER_FUEL)
   {
      rotateRight();
      fuel -= SIDE_THRUSTER_FUEL;
   }
}

/******************************************************************************
* KILL
* Simluates the lander crashing.
******************************************************************************/
void Lander::kill()
{
   active = false;
   angle.setDegrees(180);
   velocity.setDx(0);
   velocity.setDy(0);
}

/******************************************************************************
* CALCULATE ACCELRATION
* Calcualtes the lander's acceleration.
******************************************************************************/
void Lander::calculateAcceleration()
{

   double ddxThrust = 0.0;
   double ddyThrust = 0.0;

   if (mainThrustOn && fuel >= MAIN_THRUSTER_FUEL)
   {
      ddxThrust = -computeHorizontalComponent(angle.getRadians(),totalThrust);
      ddyThrust = computeVerticalComponent(angle.getRadians(),totalThrust);
   }

   double ddx = computeAcceleration(ddxThrust,weight);
   double ddy = computeAcceleration(ddyThrust,weight) + GRAVITY;

   Acceleration acceleration(ddx, ddy);
   accel = acceleration;

}

/******************************************************************************
* LAND
* Simulates the lander landing.
*****************************************************************************/
void Lander::land()
{
   active = false;
   angle.setDegrees(0.0);
}

