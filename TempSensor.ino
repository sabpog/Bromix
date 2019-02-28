//Variables
int tempPin = 0; //input the analog pin that the TMP36's Vout is connected to
int buzzerPin = 1; //buzzer pins Vout is connected here 

float sinVal;
int toneVal; 


void setup() {
  pinMode(8, OUTPUT); //buzzer output pin
  Serial.begin(9600); //initiate serial connection with computer
}


void loop() {
  int rawVal = analogRead(tempPin); //saving the value received from the TMP36
  float voltage = rawVal * 5.0; //converts the sensor value to voltage (for 5V)
  voltage /= 1024.0;

  Serial.print(voltage); Serial.println("volts"); //printing out the voltage for visualization, can be removed later

  float temperatureC = (voltage-0.5)*100; //voltage to temperature, first convert from 10 mv/degree with 500 mV offset

  Serial.print(temperatureC); Serial.println("degrees C");

  if(temperatureC>8){ //if temp rises above 8 degrees C
    for(int x=0; x<180; x++){ 
      sinVal=(sin(x*(3.1412/180))); //convert sin function from degrees to radians
      toneVal = 2000+(int(sinVal*1000)); //generating a sound frequency

      tone(8, toneVal); //configuring buzzer to pin 8
      delay(2);
    }

  }
 if(temperatureC<2){
    for(int x=0; x<180; x++){ 
      sinVal=(sin(x*(3.1412/180))); //convert sin function from degrees to radians
      toneVal = 2000+(int(sinVal*1000)); //generating a sound frequency

      tone(8, toneVal); //configuring buzzer to pin 8
      delay(2);
    }
  }
  else{
    noTone(8);
  }
    
}
