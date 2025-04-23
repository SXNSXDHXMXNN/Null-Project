const int analogPins[] ={A0,A1,A2,A3,A4,A5,A6,A7};
const int numAnalogInps = 8;
int Enable = 12;
int i;
int sensorValue;
const int umbral=120;
void setup() {
  Serial.begin(9600);
  pinMode(Enable,LOW);
}
void loop() {
for(int i= 0; i < numAnalogInps;  i++){
int sensorValue = analogRead(analogPins[i]);
if (sensorValue <= umbral){
  sensorValue= 1;
  }
Serial.print ("A");
Serial.print (i);
Serial.print (" : ");
Serial.print (sensorValue);
if ( i< numAnalogInps -1){
  Serial.print (" , ");
}
}
Serial.println();
delay(1000);
}
