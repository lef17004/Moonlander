//
//  physics.h
//  Lab03
//
//  Created by Michael LeFevre on 5/26/22.
//
#pragma once

/******************************************************************************
 * Collection of Physics Equations 
 ******************************************************************************/
float computeDistance(float position, float velocity, float acceleration, float time);
float computeAcceleration(float force, float mass);
float computeVelocity(float velocity, float acceleration, float time);
float computeVerticalComponent(float angle, float totalVelocity);
double computeHorizontalComponent(double a, double total);
double computeTotalComponent(double x, double y);
double radiansFromDegrees(double d);

