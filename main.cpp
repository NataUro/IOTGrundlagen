/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "LCD.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms

//#define _A1_Blink   //Blink_Onboard-LED
//#define _A2_Button   //Button_Onboard-LED
//#define sleep ThisThread ::sleep_for
//#define _A4_Terminal
//#define _A5_Schleife        //Aufgabe 1.1
//#define _A6_Auswahl        //Aufgabe 1.2
//#define _A6_Switchcase
//#define _A7_
//#define _i2cDisplay

#ifdef _A1_Blink

int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);

    while (true) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
    }
}
#endif
//
#ifdef _A2_Button
int main()
{
DigitalOut led(LED1);
DigitalIn button(BUTTON1);

    while (1)
    {
        if (button == 0) //Low aktiv
        {
            led = 1;
        }
            else
            {
                led = 0; 
            }
    }       //alternative: led = !button
}
#endif

#ifdef sleep
int main()
{
    DigitalIn button (BUTTON1);
    
    while(1){
        if (button==0){
            printf("Button on \n");
        } else {
            printf("Button off \n");
        }
        sleep(1s);
    }
}
#endif

#ifdef _A4_Terminal
int main(void){
    DigitalOut led(LED1);
    BufferedSerial serial_port(USBTX, USBRX);
    char c;

    while (true) {
        if  (serial_port.readable()) { //Chars recived?
        serial_port.read(&c, 1);    //Read one char to c
        led = !led;                 //Toggle to LED.
        serial_port.write(&c, 1);   //Send one char back to the terminal
        }
    }
}
#endif

#ifdef _A5_Schleife
int main(){
    for (int i=0; i<=1001 ; i++){
    printf("%d Durchgang", i);
    ThisThread ::sleep_for(500ms);
}
}
#endif

#ifdef _A6_Auswahl
int main(){
    char c;
    BufferedSerial serial_port(USBTX, USBRX);

    while (true){
        if (serial_port.readable()) { // Chars recived?
        serial_port.read(&c ,1) ;       // Read one char to c
        if (c == 'a' || c == 'A') {
            serial_port.write("Auswahl A\n", 10);
        }else if (c == 'b' || c == 'B'){
            serial_port.write("Auswahl B\n", 10);
        }else if (c == 'c' || c == 'C'){
            serial_port.write("Auswahl C\n", 10);
        }else if (c == 'd' || c == 'D') {
            serial_port.write("Auswahl D\n", 10);
        }else  {
             printf("Falsche Auswahl");
        }
        }
    }
}
#endif

#ifdef _A6_Switchcase
int main(){
    BufferedSerial serial_port(USBTX, USBRX);

    switch(serial_port.readable()) {

        case 1: 'a';
        serial_port.write("Auswahl A: \n",10);
        break;

        case 2: 'A';
        serial_port.write ("Auswahl A: \n",10);
        break;

        case 3: 'b';
        serial_port.write("Auswahl B: \n",10);
        break;

        case 4: 'B';
        serial_port.write ("Auswahl B: \n",10);
        break;

        case 5: 'c';
        serial_port.write ("Auswahl C: \n",10);
        break;

        case 6: 'C';
        serial_port.write("Auswahl C: \n",10);
        break; 

        case 7: 'd';
        serial_port.write("Auswahl D: \n",10);
        break;

        case 8: 'D';
        serial_port.write ("Auswahl D: \n",10);
        break;

        default: 
        serial_port.write("Falsche Auswahl",10);
    }
}
#endif

#ifdef _A7_Blink

#include "mbed.h"

BufferedSerial serial_port (USBTX, USBRX);

char c;

int main()

{

    while(true)

    {

    if(serial_port.readable())

    {

        serial_port.read(&c, 1);

        switch (c)

        {

            case 'a':

            {

                serial_port.write("Auswahl A:", 10); break;

            }

            case 'A':

            {

                serial_port.write("Auswahl A:", 10); break;

            }

            case 'b':

            {

                serial_port.write("Auswahl B:", 10); break;

            }

            case 'B':

            {

                serial_port.write("Auswahl B:", 10); break;

            }

            case 'c':

            {

                serial_port.write("Auswahl C:", 10); break;

            }

            case 'C':

            {

                serial_port.write("Auswahl C:", 10); break;

            }

            case 'd':

            {

                serial_port.write("Auswahl D:", 10); break;

            }

            case 'D':

            {

                serial_port.write("Auswahl D:", 10); break;

            }

            default:

            {

                  serial_port.write("Falsche Antwort", 15); break;

            }

           

        }

    }

 

    }

}

#endif

 

#ifdef _A8_Frequenz

#include "mbed.h"

 

int main()

{

   DigitalOut leda(PC_0);

   DigitalOut ledb(PC_1);

   DigitalOut ledc(PC_2);

   DigitalOut ledd(PC_3);

   DigitalOut lede(PC_4);

   DigitalOut ledf(PC_5);

   DigitalOut ledg(PC_6);

   DigitalOut ledDP(PC_7);

 

   DigitalOut seg0(PC_9);

   DigitalOut seg1(PC_10);

   DigitalOut seg2(PC_11);

   DigitalOut seg3(PC_12);

   seg0.write(0);

   seg1.write(1);

   seg2.write(1);

   seg3.write(1);

   DigitalIn button(BUTTON1);

 

while(true)

{ if(button == true){

   leda=1; //eins wird angezeigt

   ledb=0;

   ledc=0;

   ledd=1;

   lede=1;

   ledf=1;

   ledg=1;

   ledDP=0;

}

else if(button==false)

{

   leda=0; //null wird angezeigt

   ledb=0;

   ledc=0;

   ledd=0;

   lede=0;

   ledf=0;

   ledg=1;

   ledDP=1;

}

}                    

}

#endif

 

#ifdef _A9_Zähler

#include "mbed.h"

 

int main()

{

   DigitalOut leda(PC_0);

   DigitalOut ledb(PC_1);

   DigitalOut ledc(PC_2);

   DigitalOut ledd(PC_3);

   DigitalOut lede(PC_4);

   DigitalOut ledf(PC_5);

   DigitalOut ledg(PC_6);

   DigitalOut ledDP(PC_7);

 

   DigitalOut seg0(PC_9);

   DigitalOut seg1(PC_10);

   DigitalOut seg2(PC_11);

   DigitalOut seg3(PC_12);

   seg0.write(0);

   seg1.write(1);

   seg2.write(1);

   seg3.write(1);

   DigitalIn button(BUTTON1);

   while (true)

   {

   leda=0; //null wird angezeigt

   ledb=0;

   ledc=0;

   ledd=0;

   lede=0;

   ledf=0;

   ledg=1;

   ledDP=1;

 ThisThread::sleep_for(500ms);

   leda=1; //eins wird angezeigt

   ledb=0;

   ledc=0;

   ledd=1;

   lede=1;

   ledf=1;

   ledg=1;

   ledDP=0;

 ThisThread::sleep_for(500ms);

   leda=0; //zwei wird angezeigt

   ledb=0;

   ledc=1;

   ledd=0;

   lede=0;

   ledf=1;

   ledg=0;

   ledDP=1;

 ThisThread::sleep_for(500ms);

   leda=0; //3 wird angezeigt

   ledb=0;

   ledc=0;

   ledd=0;

   lede=1;

   ledf=1;

   ledg=0;

   ledDP=1;

 ThisThread::sleep_for(500ms);

   leda=1; //4 wird angezeigt

   ledb=0;

   ledc=0;

   ledd=1;

   lede=1;

   ledf=0;

   ledg=0;

   ledDP=1;

 ThisThread::sleep_for(500ms);

   leda=0; //5 wird angezeigt

   ledb=1;

   ledc=0;

   ledd=0;

   lede=1;

   ledf=0;

   ledg=0;

   ledDP=0;

 ThisThread::sleep_for(500ms);

   leda=0; //6 wird angezeigt

   ledb=1;

   ledc=0;

   ledd=0;

   lede=0;

   ledf=0;

   ledg=0;

   ledDP=0;

 ThisThread::sleep_for(500ms);

   leda=0; //7 wird angezeigt

   ledb=0;

   ledc=0;

   ledd=1;

   lede=1;

   ledf=1;

   ledg=1;

   ledDP=0;

 ThisThread::sleep_for(500ms);

   leda=0; //8 wird angezeigt

   ledb=0;

   ledc=0;

   ledd=0;

   lede=0;

   ledf=0;

   ledg=0;

   ledDP=0;

 ThisThread::sleep_for(500ms);

   leda=0; //9 wird angezeigt

   ledb=0;

   ledc=0;

   ledd=0;

   lede=1;

   ledf=0;

   ledg=0;

   ledDP=0;

 ThisThread::sleep_for(500ms);

}

}

#endif


#ifdef _i2cDisplay
#include "LCD.h"
#define sleep ThisThread::sleep_for
lcd myLCD;

int main()
{
    myLCD.clear();
    myLCD.cursorpos(0);
    myLCD.printf("TGI-J1 %c-)" , ':');
}

#endif
//------------------------------------------

#ifdef Ampelschaltung

unit8_t sevenSeg(const unit8_t num)
{
    unit8_t sevenSeg[16] = {0x3F, 0x6, 0x5B, 0x4F, 0x66, 0x6D, 0x}
} 


void SegEasyCross()
{

    PortOut pc(PortC, 0xFFFF)

    //7SEG
    uint16_t var = 0;
    int i = 0;
    for(i = 15; i >= 0; i--) {
        var = sevenSeg(i);
        pc = var;
        delay_ms(3000);
    }
    pc = 0xFF; // ausschalten

}

int EasyCrossingShield()
{

    lcd mylcd;

    // Ampellichter
    DigitalOut LR1(PB_1);
    DigitalOut LY1(PB_2);
    DigitalOut LG1(PB_3);
    DigitalOut LR2(PB_4);
    DigitalOut LY2(PB_5);
    DigitalOut LG2(PB_6);
    DigitalOut LR3(PB_7);
    DigitalOut LY3(PB_8);
    DigitalOut LG3(PB_9);
    DigitalOut LR4(PB_10);
    DigitalOut LY4(PB_11);
    DigitalOut LG4(PB_12);

    //DigitalOut RP(PB_13);
    //DigitalOut GP(PB_14);


    for(int i=0; i<10; i++) {

        RP = 0;
        GP = 0.3f;
        LR1 = 1;
        sleep_for(500ms);
        LY1 = 1;
        sleep_for(250ms);
        LG1 = 1;
        LR1 = 0;
        LY1 = 0;
        sleep_for(500ms);
        LG1 = 0;
        LR1 = 0;
        LY1 = 0;

        RP = 0.5f;
        GP = 0;

        LR2 = 1;
        sleep_for(500ms);
        LY2 = 1;
        sleep_for(250ms);
        LG2 = 1;
        LR2 = 0;
        LY2 = 0;
        sleep_for(500ms);
        LG2 = 0;

        RP = 0;
        GP = 1;

        LR3 = 1;
        sleep_for(500ms);
        LY3 = 1;
        sleep_for(250ms);
        LG3 = 1;
        LR3 = 0;
        LY3 = 0;
        sleep_for(500ms);
        LG3 = 0;

        RP = 1;
        GP = 0;

        LR4 = 1;
        sleep_for(500ms);
        LY4 = 1;
        sleep_for(250ms);
        LG4 = 1;
        LR4 = 0;
        LY4 = 0;
        sleep_for(500ms);
        LG4 = 0;

        RP = 0;
        GP = 1;
        sleep_for(500ms);

    }

   

    return 1;
}

int main()
{

    // ISR Anbinden an Button RE
    InterruptIn button(PB_0);

    button.rise(&fussgaenger);  // attach the address of the flip function to the rising edge
	
	while (true) {
    EasyCrossingShield();
    }
}

#endif
//---------------------------------------------------------
