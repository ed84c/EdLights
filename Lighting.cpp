/*
  Lighting.cpp - Library for the lights
  Created by E Hunt
*/

#include "Arduino.h"
#include "Lighting.h"



Light::Light()
{

}

void Light::setStatus()
{
  status= random(0,1);
}

Lights::Lights(int nLights)
{
  _nLights = nLights;
  
  for(int i=0;i<nLights;i++)
  {
    light[i].pin = i;
    pinMode(i, OUTPUT);
  }
}

void Lights::refresh()
{
  //On refresh, we fade out the lights, pick a new randomised status for the lights
  //and a new randomised wait time for the next refresh and then fade them in
  
  fadeOut();
  
  for(int i=0;i<_nLights;i++)
  {
    light[i].setStatus();
  }
  duration = random(durationMin,durationMax);
  fadeIn();

}

void Lights::fadeOut()
{
 
 // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    for(int j=0;j < _nLights;j++)
    {
      if (light[j].status == 1)
      {
        analogWrite(light[j].pin, fadeValue);
      }
    }
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
}

void Lights::fadeIn()
{
  
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    for(int j=0;j < _nLights;j++)
    {
      if (light[j].status == 1)
      {
        analogWrite(light[j].pin, fadeValue);
      }
    }
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
  
}

