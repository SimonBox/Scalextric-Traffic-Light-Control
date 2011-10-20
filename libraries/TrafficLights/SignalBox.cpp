/* 
 * File:   SignalBox.cpp
 * Author: simon
 * 
 * Created on 06 February 2011, 13:55
 */

#include"WProgram.h"
#include "SignalBox.h"

SignalBox::SignalBox(int r, int a, int g) {
    RedPin = r;
    AmberPin = a;
    GreenPin = g;
    Red();
    SwitchingRed = SwitchingGreen = false;
    Transition = 0;

}

void SignalBox::Set(){
    pinMode(RedPin,OUTPUT);
    pinMode(AmberPin,OUTPUT);
    pinMode(GreenPin,OUTPUT);
}

void SignalBox::Step(){
    int AmberTime = 100;
    if (SwitchingGreen)
    {
        Transition++;
        if(Transition > 0 && Transition < AmberTime){
            Amber();
        }        
        else if (Transition >= AmberTime){
            Green();
            SwitchingGreen = false;
            Transition = 0;
        }
    }
    else if (SwitchingRed)
    {
        Transition++;
        if(Transition > 0 && Transition < AmberTime){
            Amber();
        }        
        else if (Transition >= AmberTime){
            Red();
            SwitchingRed = false;
            Transition = 0;
        }
    }
    else{}

    
}

void SignalBox::toRed(){
    if(AtGreen || SwitchingGreen){
        Transition = 0;
        SwitchingRed = true;
        SwitchingGreen = false;
    }

}

void SignalBox::toGreen(){
    if(AtRed || SwitchingRed){
        Transition = 0;
        SwitchingGreen = true;
        SwitchingRed = false;
    }
}

void SignalBox::Red(){
    digitalWrite(RedPin,HIGH);
    digitalWrite(AmberPin,LOW);
    digitalWrite(GreenPin,LOW);
    AtRed = true;
    AtGreen = false;
}

void SignalBox::Amber(){
    digitalWrite(RedPin,LOW);
    digitalWrite(AmberPin,HIGH);
    digitalWrite(GreenPin,LOW);
    AtRed = false;
    AtGreen = false;
}

void SignalBox::Green(){
    digitalWrite(RedPin,LOW);
    digitalWrite(AmberPin,LOW);
    digitalWrite(GreenPin,HIGH);
    AtGreen = true;
    AtRed = false;
}

