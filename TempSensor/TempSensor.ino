//Variables
int tempPin = A0; //input the analog pin that the TMP36's Vout is connected to

void setup() {
  pinMode(8, OUTPUT); //buzzer output pin
  Serial.begin(9600); //initiate serial connection with computer
}

void loop() {
   int rawTempVal = analogRead(tempPin); //saving the value received from the TMP36
  float voltage = rawTempVal * 5.0; //converts the sensor value to voltage (for 5V)
  voltage /= 1024.0;
  

  float temperatureC = (voltage-0.5)*100; //voltage to temperature, first convert from 10 mv/degree with 500 mV offset

   
  Serial.println(temperatureC); Serial.println("degrees C");
   
   if(temperatureC>8){ //if temp rises above 8 degrees C
   
     tone(8, 2000, 50); //configuring buzzer to pin 8
     delay(5000);
    }

  else if(temperatureC<2){

      tone(8, 2000, 50); //configuring buzzer to pin 8
      delay(5000);
    }
 
  else{
   noTone(8);
  }
    
}
