#include "uiDraw.h" // For gout
#include "angle.h"
#include "acceleration.h"
#include "velocity.h"
#include "math.h"
#include "lander.h"
#define GRAVITY -1.625

void Lander::draw(ogstream& gout)
{
   gout.drawLander(position, angle.getRadians());

   if (alive)
   {
      if (fuel < 10.0)
         mainThrustOn = false;

      if (fuel < 0.1)
      {
         leftThrustOn = false;
         rightThrustOn = false;
      }

      gout.drawLanderFlames(position, angle.getRadians(), mainThrustOn, leftThrustOn, rightThrustOn);
   }

}

void Lander::advanceBy(double time)
{
   if (!alive)
      return;


   calculateAcceleration();
   calculateVelocity(time);
   calulatePosition(time);

   if (mainThrustOn && fuel >= 10.0)
   {
      fuel -= 10.0;
   }

   if (rightThrustOn && fuel >= 0.1)
   {
      rotateLeft();
      fuel -= 0.1;
   }

   if (leftThrustOn && fuel >= 0.1)
   {
      rotateRight();
      fuel -= 0.1;
   }
}

void Lander::kill()
{
   alive = false;
   angle.setDegrees(180);
   velocity.setDx(0);
   velocity.setDy(0);
}

void Lander::calculateAcceleration()
{

   double ddxThrust = 0.0;
   double ddyThrust = 0.0;

   if (mainThrustOn && fuel >= 10.0)
   {
      ddxThrust = -sin(angle.getRadians()) * totalThrust;
      ddyThrust = cos(angle.getRadians()) * totalThrust;
   }

   double ddx = ddxThrust / weight;
   double ddy = (ddyThrust / weight) + GRAVITY;

   Acceleration acceleration(ddx, ddy);
   accel = acceleration;

}

void Lander::land()
{
   alive = false;
   angle.setDegrees(0.0);
}

