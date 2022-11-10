#include <Arduino.h>
#include <Adafruit_ADS1X15.h>
#include "uFire_SHT20.h"

uFire_SHT20 sht20;

String command;


Adafruit_ADS1115 ads;  /* Use this for the 16-bit version */
int16_t adc0, adc1, adc2, adc3;
float volts0, volts1, volts2, volts3;

int VDAC = 0;

// const int freq = 5000;

// const int pump = 32;
// const int sol = 33;
// const int col = 27;


// const int pump_ledChannel = 0;
// const int sol_ledChannel = 1;
// const int col_ledChannel = 2;

// const int resolution = 8;
// const int zone = 5000;
// const int dutyCycle = 255;
// const int gain = 4.096;

// This is required on ESP32 to put the ISR in IRAM. Define as
// empty for other platforms. Be careful - other platforms may have
// other requirements.

void setup(void)
{

  Serial.begin(115200);
  dacWrite(25,200); //heater
  
  Wire.begin();
  sht20.begin();

  
  // esp32 pwm setup

  // pinMode(pump, OUTPUT);
  // pinMode(sol, OUTPUT);
  // pinMode(col, OUTPUT);
  // ledcSetup(pump_ledChannel, freq, resolution);
  // ledcSetup(sol_ledChannel, freq, resolution);
  // ledcSetup(col_ledChannel, freq, resolution);
  // ledcAttachPin(pump, pump_ledChannel);
  // ledcAttachPin(sol, sol_ledChannel);
  // ledcAttachPin(col, col_ledChannel);



  dacWrite(26,VDAC); //offset voltage

    // The ADC input range (or gain) can be changed via the following
  // functions, but be careful never to exceed VDD +0.3V max, or to
  // exceed the upper and lower limits if you adjust the input range!
  // Setting these values incorrectly may destroy your ADC!
  //                                                                ADS1015  ADS1115
  //                                                                -------  -------
  // ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
   ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV

  if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }



}

void increase_offset(int a){
  VDAC = VDAC + a;
  dacWrite(26,VDAC);
}

void decrease_offset(int b){
  VDAC = VDAC - b;
  dacWrite(26,VDAC);
}

void heat_sensor(int c){
  dacWrite(25, c);
}

void signal_gain_one(){
  ads.setGain(GAIN_ONE);
}

void signal_gain_eight(){
  ads.setGain(GAIN_EIGHT);
}

void signal_gain_sixteen(){
  ads.setGain(GAIN_SIXTEEN);
}

// void test_pwm_on(int d){
//   ledcWrite(d, 200);
// }

// void test_pwm_off(int e){
//   ledcWrite(e,0);
// }

void read_data(){
  adc0 = ads.readADC_SingleEnded(0);
  adc1 = ads.readADC_SingleEnded(1);
  adc2 = ads.readADC_SingleEnded(2);
  adc3 = ads.readADC_SingleEnded(3);
  
  Serial.print(sht20.humidity());
  Serial.print(",");
  Serial.print(VDAC);
  Serial.print(",");
  Serial.print(adc0); 
  Serial.print(",");
  Serial.print(adc1);
  Serial.print(","); 
  Serial.print(adc2); 
  Serial.print(",");
  Serial.println(adc3); 


}

void loop(void)
{
  if(Serial.available()){
    command = Serial.readStringUntil('\n');

    if(command.equals("IO")){
      increase_offset(1);
    }
    if(command.equals("IO5")){
      increase_offset(5);
    }
    if(command.equals("DO")){
    decrease_offset(1);
    }
    if(command.equals("DO5")){
      decrease_offset(5);
    }
    if(command.equals("HS255")){
      heat_sensor(255);
    }
    if(command.equals("HS240")){
      heat_sensor(240);
    }
    if(command.equals("HS")){
      heat_sensor(220);
    }
    if(command.equals("NS")){
      heat_sensor(200);
    }
    if(command.equals("OS")){
      heat_sensor(0);
    }    
    if(command.equals("LS")){
      heat_sensor(180);
    }
    if(command.equals("VS")){
      heat_sensor(50);
    }           
    if(command.equals("SG1")){
      signal_gain_one();
    }
    if(command.equals("SG8")){
      signal_gain_eight();
    }    
    if(command.equals("SG16")){
      signal_gain_sixteen();
    }
    // if(command.equals("pump_on")){
    //   test_pwm_on(0);
    // }
    // if(command.equals("pump_off")){
    //   test_pwm_off(0);
    // }
    // if(command.equals("col_on")){
    //   test_pwm_on(2);
    // }
    // if(command.equals("col_off")){
    //   test_pwm_off(2);
    // }
    // if(command.equals("sol_on")){
    //   test_pwm_on(1);
    // }
    // if(command.equals("col_off")){
    //   test_pwm_off(1);
    // }


    // else{
    //   Serial.println("Invalid command");
    // read_data();
    // }
  }

  read_data();
  
  // volts0 = ads.computeVolts(adc0);
  // volts1 = ads.computeVolts(adc1);
  // volts2 = ads.computeVolts(adc2);
  // volts3 = ads.computeVolts(adc3);


  
  // dacWrite(26, Output);
  // Serial.print(Output);
  // Serial.print(",");

  // Serial.print(sht20.temperature());
  // Serial.print(",");
  // Serial.print(sht20.humidity());
  // Serial.print(",");

  // Serial.println("hekki");

}