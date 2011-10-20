/* 
 * File:   SignalBox.h
 * Author: simon
 *
 * Created on 06 February 2011, 13:55
 */

#ifndef SIGNALBOX_H
#define	SIGNALBOX_H

class SignalBox {
public:

    SignalBox(int r, int a, int g);
    void Set();
    void Step();
    void toRed();
    void toGreen();
    
private:
    int RedPin,
       AmberPin,
       GreenPin;
    bool SwitchingRed,
        SwitchingGreen,
        AtRed,
        AtGreen;
    int Transition;
    void Red();
    void Amber();
    void Green();

};

#endif	/* SIGNALBOX_H */

