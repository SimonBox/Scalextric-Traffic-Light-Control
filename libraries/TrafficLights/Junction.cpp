/* 
 * File:   Junction.cpp
 * Author: simon
 * 
 * Created on 06 February 2011, 15:27
 */

#include "Junction.h"

Junction::Junction(Detector* Lns, Detector* Lew, SignalBox* Sns, SignalBox * Sew) {
    LoopNS = Lns; LoopEW = Lew; SigNS = Sns; SigEW = Sew;

    ChangeToNS();
}

Junction::Junction(SignalBox* Sns, SignalBox * Sew) {
    SigNS = Sns; SigEW = Sew;

    ChangeToNS();
}



void Junction::Step(){
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

    if(CurrentStagePeriod > 2000){
        if(StageNS){
            ChangeToEW();
        }
        else if(StageEW){
            ChangeToNS();
        }
    }
    CurrentStagePeriod++;
    
}

void Junction::SimpleStep(){
    if(CurrentStagePeriod > 2000){
        if(StageNS){
            ChangeToEW();
        }
        else if(StageEW){
            ChangeToNS();
        }
    }
    CurrentStagePeriod++;

}

void Junction::ChangeToNS(){
    StageNS = true;
    StageEW = false;
    CurrentStagePeriod = 0;
    SigNS->toGreen();
    SigEW->toRed();
}

void Junction::ChangeToEW(){
    StageEW = true;
    StageNS = false;
    CurrentStagePeriod = 0;
    SigNS->toRed();
    SigEW->toGreen();
}



