#include "Cbuff.h";
#include "Detector.h";
#include "Junction.h";
#include "SignalBox.h";


Detector D0 = Detector(A1,A2,500,50,2);
Detector D1 = Detector(A5,A6,500,50,2);
Detector D2 = Detector(A9,A10,500,20,2);
Detector D3 = Detector(A13,14,500,20,2);
SignalBox SWns = SignalBox(2,40,3);
SignalBox SWew = SignalBox(4,40,5);
SignalBox SEns = SignalBox(6,40,7);
SignalBox SEew = SignalBox(13,40,A5);
Junction J1 = Junction(&D0,&D3,&SWns,&SWew);





void setup() {
  //POWERPINS
  pinMode(A0, OUTPUT);
  digitalWrite(A0, HIGH);
  pinMode(A3, OUTPUT);
  digitalWrite(A3, LOW); 
 //
  pinMode(A4, OUTPUT);
  digitalWrite(A4, HIGH);
  pinMode(A7, OUTPUT);
  digitalWrite(A7, LOW);  
  //
  pinMode(A8, OUTPUT);
  digitalWrite(A8, HIGH);
  pinMode(A11, OUTPUT);
  digitalWrite(A11, LOW); 
  //
  pinMode(A12, OUTPUT);
  digitalWrite(A12, HIGH);
  pinMode(A15, OUTPUT);
  digitalWrite(A15, LOW); 
  
  pinMode(A13, INPUT);
  pinMode(A14, OUTPUT);
  
  //100 put your setup code here, to run once:
  D0.Set();
  D1.Set();
  D2.Set();
  D3.Set();
  D0.AddDownstream(&D1);
  D1.AddDownstream(&D2);
  D2.AddDownstream(&D3);
  D3.AddDownstream(&D0);
  SWns.Set();
  SWew.Set();
  SEns.Set();
  SEew.Set();
  //D1.Reporting = true;
  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  D0.Step();
  D1.Step();
  D2.Step();
  D3.Step();
  SWns.Step();
  SWew.Step();
  SEns.Step();
  SEew.Step();
  
  
  J1.Step();
  /*if(dc==100)
  {
  Serial.print("[");
  Serial.print(D0.Demand);
  Serial.print(", ");
  Serial.print(D1.Demand);
  Serial.print(", ");
  Serial.print(D2.Demand);
  Serial.print(", ");
  Serial.print(D3.Demand);
  Serial.print(", ");
  Serial.print(D4.Demand);
  Serial.println("];");
  dc = 0;
  }
  else{
    dc++;
  }*/
  delay(1);
}
