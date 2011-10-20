/* 
 * File:   JuncTypeTwo.h
 * Author: simon
 *
 * Created on 15 February 2011, 14:44
 */

#ifndef JUNCTYPETWO_H
#define	JUNCTYPETWO_H

#include "Detector.h"
#include "SignalBox.h"

class JuncTypeTwo {
public:
    Detector * LoopNS;
    Detector * LoopEW;
    int Sig;


    JuncTypeTwo(Detector* Lns, Detector* Lew, int S);
    void Step();

private:
    bool StageNS;
    bool StageEW;
    int CurrentStagePeriod;
    void ChangeToNS();
    void ChangeToEW();

};

#endif	/* JUNCTYPETWO_H */

