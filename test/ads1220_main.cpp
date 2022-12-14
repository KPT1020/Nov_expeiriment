#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_ADS1X15.h>
// // //////////////////////////////////////////////////////////////////////////////////////////
// // //
// // //    Demo code for the ADS1220 24-bit ADC breakout board
// // //
// // //    Author: Ashwin Whitchurch
// // //    Copyright (c) 2018 ProtoCentral
// // //
// // //    This example gives differential voltage across the AN0 and AN1 pins in mVolts
// // //
// // //    Arduino connections:
// // //
// // //  |ADS1220 pin label| Pin Function         |Arduino Connection|
// // //  |-----------------|:--------------------:|-----------------:|
// // //  | DRDY            | Data ready Output pin|  D02             |
// // //  | MISO            | Slave Out            |  D12             |
// // //  | MOSI            | Slave In             |  D11             |
// // //  | SCLK            | Serial Clock         |  D13             |
// // //  | CS              | Chip Select          |  D7              |
// // //  | DVDD            | Digital VDD          |  +5V             |
// // //  | DGND            | Digital Gnd          |  Gnd             |
// // //  | AN0-AN3         | Analog Input         |  Analog Input    |
// // //  | AVDD            | Analog VDD           |  -               |
// // //  | AGND            | Analog Gnd           |  -               |
// // //
// // //    This software is licensed under the MIT License(http://opensource.org/licenses/MIT).
// // //
// // //   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// // //   NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// // //   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// // //   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// // //   SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// // //
// // //   For information on how to use, visit https://github.com/Protocentral/Protocentral_ADS1220
// // //
// // /////////////////////////////////////////////////////////////////////////////////////////

// // #include "Protocentral_ADS1220.h"
// // #include <SPI.h>

// // #define PGA 1                 // Programmable Gain = 1
// // #define VREF 2.048            // Internal reference of 2.048V
// // #define VFSR VREF/PGA
// // #define FSR (((long int)1<<23)-1)

// // #define ADS1220_CS_PIN    7
// // #define ADS1220_DRDY_PIN  2

// // Protocentral_ADS1220 pc_ads1220;
// // int32_t adc_data;
// // volatile bool drdyIntrFlag = false;

// // void drdyInterruptHndlr(){
// //   drdyIntrFlag = true;
// // }


// // void enableInterruptPin(){

// //   attachInterrupt(digitalPinToInterrupt(ADS1220_DRDY_PIN), drdyInterruptHndlr, FALLING);
// // }

// // void setup()
// // {
// //     Serial.begin(57600);

// //     pc_ads1220.begin(ADS1220_CS_PIN,ADS1220_DRDY_PIN);

// //     pc_ads1220.set_data_rate(DR_330SPS);
// //     pc_ads1220.set_pga_gain(PGA_GAIN_32);
// //     pc_ads1220.select_mux_channels(MUX_AIN0_AIN1);  //Configure for differential measurement between AIN0 and AIN1

// //     pc_ads1220.Start_Conv();  //Start continuous conversion mode

// //     enableInterruptPin();
// // }

// // void loop()
// // {
// //     if(drdyIntrFlag){
// //         drdyIntrFlag = false;

// //         adc_data=pc_ads1220.Read_Data_Samples();
// //         float Vout = (float)((adc_data*VFSR*1000)/FSR);     //In  mV

// //         delay(300);

// //         Serial.print("Vout in mV : ");
// //         Serial.print(Vout);
// //         Serial.print("  32bit HEX : ");
// //         Serial.println(adc_data,HEX);
// //     }
// // }//////////////////////////////////////////////////////////////////////////////////////////
// // //
// // //    Demo code for the ADS1220 24-bit ADC breakout board
// // //
// // //    Author: Ashwin Whitchurch
// // //    Copyright (c) 2018 ProtoCentral
// // //
// // //    This example gives differential voltage across the AN0 and AN1 pins in mVolts
// // //
// // //    Arduino connections:
// // //
// // //  |ADS1220 pin label| Pin Function         |Arduino Connection|
// // //  |-----------------|:--------------------:|-----------------:|
// // //  | DRDY            | Data ready Output pin|  D02             |
// // //  | MISO            | Slave Out            |  D12             |
// // //  | MOSI            | Slave In             |  D11             |
// // //  | SCLK            | Serial Clock         |  D13             |
// // //  | CS              | Chip Select          |  D7              |
// // //  | DVDD            | Digital VDD          |  +5V             |
// // //  | DGND            | Digital Gnd          |  Gnd             |
// // //  | AN0-AN3         | Analog Input         |  Analog Input    |
// // //  | AVDD            | Analog VDD           |  -               |
// // //  | AGND            | Analog Gnd           |  -               |
// // //
// // //    This software is licensed under the MIT License(http://opensource.org/licenses/MIT).
// // //
// // //   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// // //   NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// // //   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// // //   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// // //   SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// // //
// // //   For information on how to use, visit https://github.com/Protocentral/Protocentral_ADS1220
// // //
// // /////////////////////////////////////////////////////////////////////////////////////////

// // #include "Protocentral_ADS1220.h"
// // #include <SPI.h>

// // #define PGA 1                 // Programmable Gain = 1
// // #define VREF 2.048            // Internal reference of 2.048V
// // #define VFSR VREF/PGA
// // #define FSR (((long int)1<<23)-1)

// // #define ADS1220_CS_PIN    7
// // #define ADS1220_DRDY_PIN  2

// // Protocentral_ADS1220 pc_ads1220;
// // int32_t adc_data;
// // volatile bool drdyIntrFlag = false;

// // void drdyInterruptHndlr(){
// //   drdyIntrFlag = true;
// // }


// // void enableInterruptPin(){

// //   attachInterrupt(digitalPinToInterrupt(ADS1220_DRDY_PIN), drdyInterruptHndlr, FALLING);
// // }

// // void setup()
// // {
// //     Serial.begin(57600);

// //     pc_ads1220.begin(ADS1220_CS_PIN,ADS1220_DRDY_PIN);

// //     pc_ads1220.set_data_rate(DR_330SPS);
// //     pc_ads1220.set_pga_gain(PGA_GAIN_32);
// //     pc_ads1220.select_mux_channels(MUX_AIN0_AIN1);  //Configure for differential measurement between AIN0 and AIN1

// //     pc_ads1220.Start_Conv();  //Start continuous conversion mode

// //     enableInterruptPin();
// // }

// // void loop()
// // {
// //     if(drdyIntrFlag){
// //         drdyIntrFlag = false;

// //         adc_data=pc_ads1220.Read_Data_Samples();
// //         float Vout = (float)((adc_data*VFSR*1000)/FSR);     //In  mV

// //         delay(300);

// //         Serial.print("Vout in mV : ");
// //         Serial.print(Vout);
// //         Serial.print("  32bit HEX : ");
// //         Serial.println(adc_data,HEX);
// //     }
// // }//////////////////////////////////////////////////////////////////////////////////////////
// //
// //    Demo code for the ADS1220 24-bit ADC breakout board
// //
// //    Author: Ashwin Whitchurch
// //    Copyright (c) 2018 ProtoCentral
// //
// //    This example gives differential voltage across the AN0 and AN1 pins in mVolts
// //
// //    Arduino connections:
// //
// //  |ADS1220 pin label| Pin Function         |Arduino Connection|
// //  |-----------------|:--------------------:|-----------------:|
// //  | DRDY            | Data ready Output pin|  D02             |
// //  | MISO            | Slave Out            |  D12             |
// //  | MOSI            | Slave In             |  D11             |
// //  | SCLK            | Serial Clock         |  D13             |
// //  | CS              | Chip Select          |  D7              |
// //  | DVDD            | Digital VDD          |  +5V             |
// //  | DGND            | Digital Gnd          |  Gnd             |
// //  | AN0-AN3         | Analog Input         |  Analog Input    |
// //  | AVDD            | Analog VDD           |  -               |
// //  | AGND            | Analog Gnd           |  -               |
// //
// //    This software is licensed under the MIT License(http://opensource.org/licenses/MIT).
// //
// //   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// //   NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// //   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// //   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// //   SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// //
// //   For information on how to use, visit https://github.com/Protocentral/Protocentral_ADS1220
// //
// /////////////////////////////////////////////////////////////////////////////////////////

// #include "Protocentral_ADS1220.h"
// #include <SPI.h>

// #define PGA 1                 // Programmable Gain = 1
// #define VREF 2.048            // Internal reference of 2.048V
// #define VFSR VREF/PGA
// #define FSR (((long int)1<<23)-1)

// #define ADS1220_CS_PIN    13
// #define ADS1220_DRDY_PIN  16

// Protocentral_ADS1220 pc_ads1220;
// int32_t adc_data;
// volatile bool drdyIntrFlag = false;

// void drdyInterruptHndlr(){
//   drdyIntrFlag = true;
// }


// void enableInterruptPin(){

//   attachInterrupt(digitalPinToInterrupt(ADS1220_DRDY_PIN), drdyInterruptHndlr, FALLING);
// }

// void setup()
// {
//     Serial.begin(115200);
//     // SPI.begin();

//     pc_ads1220.begin(ADS1220_CS_PIN,ADS1220_DRDY_PIN);

//     pc_ads1220.set_data_rate(DR_330SPS);
//     pc_ads1220.set_pga_gain(PGA_GAIN_32);
//     pc_ads1220.select_mux_channels(MUX_AIN0_AIN1);  //Configure for differential measurement between AIN0 and AIN1

//     pc_ads1220.Start_Conv();  //Start continuous conversion mode

//     enableInterruptPin();
// }

// void loop()
// {

//         drdyIntrFlag = false;

//         adc_data=pc_ads1220.Read_Data_Samples();
//         float Vout = (float)((adc_data*VFSR*1000)/FSR);     //In  mV

//         delay(300);

//         Serial.print("Vout in mV : ");
//         Serial.print(Vout);
//         Serial.print("  32bit HEX : ");
//         Serial.println(adc_data,HEX);
// }

//////////////////////////////////////////////////////////////////////////////////////////
//
//    Demo code for the ADS1220 24-bit ADC breakout board
//
//    Author: Ashwin Whitchurch
//    Copyright (c) 2018 ProtoCentral
//
//    This example sequentially reads all 4 channels in continuous conversion mode
//
//    Arduino connections:
//
//  |ADS1220 pin label| Pin Function         |Arduino Connection|
//  |-----------------|:--------------------:|-----------------:|
//  | DRDY            | Data ready Output pin|  D2              |
//  | MISO            | Slave Out            |  D12             |
//  | MOSI            | Slave In             |  D11             |
//  | SCLK            | Serial Clock         |  D13             |
//  | CS              | Chip Select          |  D7              |
//  | DVDD            | Digital VDD          |  +5V             |
//  | DGND            | Digital Gnd          |  Gnd             |
//  | AN0-AN3         | Analog Input         |  Analog Input    |
//  | AVDD            | Analog VDD           |  -               |
//  | AGND            | Analog Gnd           |  -               |
//
//    This software is licensed under the MIT License(http://opensource.org/licenses/MIT).
//
//   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
//   NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
//   SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//   For information on how to use, visit https://github.com/Protocentral/Protocentral_ADS1220
//
/////////////////////////////////////////////////////////////////////////////////////////

#include "Protocentral_ADS1220.h"
#include <SPI.h>

#define PGA          1                 // Programmable Gain = 1
#define VREF         2.048            // Internal reference of 2.048V
#define VFSR         VREF/PGA
#define FULL_SCALE   (((long int)1<<23)-1)

#define ADS1220_CS_PIN    13
#define ADS1220_DRDY_PIN  16

Protocentral_ADS1220 pc_ads1220;
int32_t adc_data;
volatile bool drdyIntrFlag = false;

void drdyInterruptHndlr(){
  drdyIntrFlag = true;
}

void enableInterruptPin(){

  attachInterrupt(digitalPinToInterrupt(ADS1220_DRDY_PIN), drdyInterruptHndlr, FALLING);
}

void setup()
{
    Serial.begin(115200);

    pc_ads1220.begin(ADS1220_CS_PIN,ADS1220_DRDY_PIN);

    pc_ads1220.set_data_rate(DR_330SPS);
    pc_ads1220.set_pga_gain(PGA_GAIN_32);

    pc_ads1220.set_conv_mode_single_shot(); //Set Single shot mode
    // digitalWrite(ADS1220_DRDY_PIN,HIGH);
}

float convertToMilliV(int32_t i32data)
{
    return (float)((i32data*VFSR*1000)/FULL_SCALE);
}

void loop()
{
    Serial.println(digitalRead(ADS1220_DRDY_PIN));
    adc_data=pc_ads1220.Read_SingleShot_SingleEnded_WaitForData(MUX_SE_CH0);
    Serial.print("\n\nCh1 (mV): ");
    Serial.print(adc_data);
    delay(100);

    adc_data=pc_ads1220.Read_SingleShot_SingleEnded_WaitForData(MUX_SE_CH1);
    Serial.print("\nCh2 (mV): ");
    Serial.print(convertToMilliV(adc_data));
    delay(100);

    adc_data=pc_ads1220.Read_SingleShot_SingleEnded_WaitForData(MUX_SE_CH2);
    Serial.print("\nCh3 (mV): ");
    Serial.print(convertToMilliV(adc_data));
    delay(100);

    adc_data=pc_ads1220.Read_SingleShot_SingleEnded_WaitForData(MUX_SE_CH3);
    Serial.print("\nCh4 (mV): ");
    Serial.print(convertToMilliV(adc_data));
    delay(100);
}

