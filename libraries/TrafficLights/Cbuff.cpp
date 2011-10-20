/* 
 * File:   Cbuff.cpp
 * Author: simon
 * 
 * Created on 06 February 2011, 11:53
 */

#include "Cbuff.h"

Cbuff::Cbuff(){
    Next=0;
    Size = 10;
    for(int i; i<10;i++){
        buffer[i]=0;
    }
}

void Cbuff::Add(int signal){
    buffer[Next] = signal;
    Next = (Next+1) % Size;
}

bool Cbuff::Positive(int Upper, int Lower, int Count){
    int Ucount = 0;
    int Lcount = 0;

    for(int i =0; i<Size; i++){
        if(buffer[i]>=Upper){
            Ucount++;
        }
        if(buffer[i]<=Lower){
            Lcount++;
        }
    }

    bool Temp=(Ucount>=Count && Lcount >=Count);
    return(Temp);
}



