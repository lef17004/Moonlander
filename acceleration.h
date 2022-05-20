#pragma once

class Acceleration {
private:
   float ddx;
   float ddy;

public:
   Acceleration()
   {
      ddx = 0;
      ddy = 0;
   }

   Acceleration(float ddx, float ddy) : ddx(ddx), ddy(ddy) {}


   float getDDX() 
   {
      return ddx;
   }

   float getDDY() 
   {
      return ddy;
   }

   void setDDY(float ddy)
   {
      this->ddy = ddy;
   }

   void setDDX(float ddx)
   {
      this->ddx = ddx;
   }
   
};
