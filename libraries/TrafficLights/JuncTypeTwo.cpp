/* 
 * File:   JuncTypeTwo.cpp
 * Author: simon
 * 
 * Created on 15 February 2011, 14:44
 */

#include "JuncTypeTwo.h"


JuncTypeTwo::JuncTypeTwo(Detector* Lns, Detector* Lew, int S) {
    LoopNS = Lns; LoopEW = Lew; Sig = S;

    ChangeToNS();
}

void JuncTypeTwo::Step(){
    if(LoopNS->Demand > LoopEW->Demand)
    {
        if(StageEW){
            ChangeToNS();
        }
    }
    else if(LoopEW->Demand > LoopNS->Demand)
    {
        if(StageNS){
            ChangeToEW();
        }

    }

    if(CurrentStagePeriod > 4500){
        if(StageNS){
            ChangeToEW();
        }
        else if(StageEW){
            ChangeToNS();
        }
    }
    CurrentStagePeriod++;

}

void JuncTypeTwo::ChangeToNS(){
    StageNS = true;
    StageEW = false;
    CurrentStagePeriod = 0;
    Sig = 1;
}

void JuncTypeTwo::ChangeToEW(){
    StageEW = true;
    StageNS = false;
    CurrentStagePeriod = 0;
    Sig = 0;
}





