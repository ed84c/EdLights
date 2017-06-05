/*
  Lighting.h - Library for the lights
  Created by E. Hunt
*/
#ifndef Lighting_h
#define Lighting_h

#include "Arduino.h"

class Light
{
  public:
    Light();
    boolean status;
    int pin;
    void setStatus();
};

class Lights
{
  public:
    Lights(int nLights);
    Light light[13];
    void refresh();
    void output();
    void fadeOut();
    void fadeIn();
    int duration;
    int durationMin = 60*2;  //Minimum duration of a status of the lights
    int durationMax = 60*30; //Maximum..
    
  private:
    int _nLights; //Number of lights to operate
};  


#endif