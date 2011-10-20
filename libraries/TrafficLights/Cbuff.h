/* 
 * File:   Cbuff.h
 * Author: simon
 *
 * Created on 06 February 2011, 11:53
 */

#ifndef CBUFF_H
#define	CBUFF_H
/*Class implements a simple circular buffer for integers*/

class Cbuff {
public:
    int buffer [10];
    int Next;
    int Size;
    Cbuff();
    void Add(int signal);
    bool Positive(int Upper, int Lower, int Count);
private:

};

#endif	/* CBUFF_H */

