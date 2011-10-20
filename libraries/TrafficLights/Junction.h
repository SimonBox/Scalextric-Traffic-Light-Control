/* 
 * File:   Junction.h
 * Author: simon
 *
 * Created on 06 February 2011, 15:27
 */

#ifndef JUNCTION_H
#define	JUNCTION_H

#include "Detector.h"
#include "SignalBox.h"

class Junction {
public:
    Detector * LoopNS;
    Detector * LoopEW;
    SignalBox * SigNS;
    SignalBox * SigEW;
    
    Junction(Detector* Lns, Detector* Lew, SignalBox* Sns, SignalBox * Sew);
    Junction(SignalBox* Sns, SignalBox * Sew);
    void Step();
    void SimpleStep();
    
private:
    bool StageNS;
    bool StageEW;
    int CurrentStagePeriod;
    void ChangeToNS();
    void ChangeToEW();

};

#endif	/* JUNCTION_H */

