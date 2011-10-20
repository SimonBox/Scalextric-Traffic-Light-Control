/* 
 * File:   Detector.h
 * Author: simon
 *
 * Created on 05 February 2011, 18:08
 */

#ifndef DETECTOR_H
#define	DETECTOR_H

#include"WProgram.h"
#include"Cbuff.h"

class Detector {
public:
    //class members
    int Demand;
    bool Reporting;
    Detector(int Anin, int LEDout, int Up, int Low, int Cnt);
    void Set();
    void AddDownstream(Detector * DS);
    void Step();
private:
    int AnalogInPin,
            LEDoutPin;
    int PauseCount,
            DemandCount,
            Upper,
            Lower,
            Count,
            DSdemand;
    Cbuff Buffer;
    Detector * Downstream;
    void DemandUp();
    void DemandDown();
    void LightUp();
    void LightDown();

};

#endif	/* DETECTOR_H */

