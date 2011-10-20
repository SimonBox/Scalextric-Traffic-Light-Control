/* 
 * File:   Detector.cpp
 * Author: simon
 * 
 * Created on 05 February 2011, 18:08
 */

#include "Detector.h"

Detector::Detector(int Anin, int LEDout, int Up, int Low, int Cnt) {
    AnalogInPin = Anin;
    LEDoutPin = LEDout;
    Upper = Up;
    Lower = Low;
    Count = Cnt;
    Reporting = false;
}

void Detector::Set(){
    pinMode(AnalogInPin,INPUT);
    pinMode(LEDoutPin,OUTPUT);
}

void Detector::AddDownstream(Detector * DS){
    Downstream = DS;
}

void Detector::Step(){
    int signal = analogRead(AnalogInPin);
    Buffer.Add(signal);

    if(PauseCount>50){
        if(Buffer.Positive(Upper,Lower,Count)){
            DemandUp();
            LightUp();
            PauseCount = 0;
            DemandCount = 0;
        }
        else{
            LightDown();
        }
    }

    if(Downstream->Demand > DSdemand){
        DemandDown();
        DSdemand = Downstream->Demand;
        DemandCount = 0;
    }
    else if (Downstream->Demand < DSdemand){
        DSdemand = Downstream->Demand;
    }


    if(DemandCount > 2000)
    {
        Demand = 0;
    }
    PauseCount ++;
    DemandCount ++;
}

void Detector::DemandUp(){
    if (Demand <2)
    {
        Demand++;
    }
    PauseCount = 0;
}

void Detector::DemandDown(){
    if(Demand > 0)
    {
        Demand--;
    }
}

void Detector::LightUp(){
    digitalWrite(LEDoutPin, HIGH);
    if(Reporting){
        for(int i =0; i<10;i++){
            Serial.print(Buffer.buffer[i]);
            Serial.print(", ");
        }
        Serial.println(";");
    }

}

void Detector::LightDown(){
    digitalWrite(LEDoutPin, LOW);
}
