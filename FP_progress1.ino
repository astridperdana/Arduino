int sensorpin =A0;
int sensorvalue = 0;
int ledpin = 11;
int ledBright;
int sensorPin = 1;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
 
   int reading = analogRead(sensorPin);  
 
 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = reading * 50.0;
 voltage /= 1024.0; 
 
 // print out the voltage
 Serial.print(voltage); Serial.println(" volts");
 
 // now print out the temperature
 float temperatureC = ((voltage - 0.5) * 10)-10 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)
Serial.print("Suhu Saat Ini :");Serial.print(temperatureC); Serial.println(" degrees C");
  
  
  
  // put your main code here, to run repeatedly:
sensorvalue = analogRead(sensorpin);
Serial.print("Kecerahan Saat Ini = ");
Serial.println(sensorvalue);

sensorvalue = 1023-sensorvalue;
ledBright = map(sensorvalue, 0, 1024, 0, 255);
analogWrite(ledpin, ledBright);
delay(1000);
}
