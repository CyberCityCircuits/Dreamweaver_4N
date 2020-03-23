# DREAMWEAVER 4N

*Hello!*  Welcome to the DREAMWEAVER 4N repo.  The DREAMWEAVER 4N is an Open Source 4 Channel Sequencer or Arpeggiator based on the Arduino architecture.  This is something that I have been working on for several months.  If you have any comments or suggestions, I can be reached on Twitter [@MakeAugusta](https://twitter.com/MakeAugusta).

![DW4N 1.6 Beta](https://github.com/CyberCityCircuits/Dreamweaver_4N/blob/master/Images/1_6_Beta_001.jpg | width=50)

### Features & Specifications:
* **Dimensions:** 62 mm x 100 mm (2.45 x 4 in)  
* **Weight:**  100 grams (~4 oz.)  
* **Knobs:** Six (6)  
    * Four for Setting Note Values
    * Two for Setting Spread and Length
* **LEDs:** Eight RGB WS2812 LEDs (Fully Programmable)
* **Microcontroller:** Atmel ATMEGA328PB-AU
* **Power:** Via USB Micro
* **Audio Output Options:** Piezo-Buzzer & 3.5mm Jack
* **General Input/Outputs:**
	* Two Digital Only Input/Outputs
	* Two Analog/Digital Input/Outputs
* **Buttons:**
    * One for Software Reset
    * Nine are Fully Programmable
* **Programming software:** Arduino IDE
* **Programmer:** On-board CH340G    


## Programming the DREAMWEAVER 4N

### Loading Software onto the DREAMWEAVER 4N
The DREAMWEAVER 4N can use the **Ardiuno IDE** to write software to it.  The Arduino IDE recognizes the DREAMWEAVER 4N as an **Arduino Nano**.  To set the Arduino IDE to load it change your *board type* in the *Tools* menu.
* **Tools**
    * **Board:**
        * Arduino Nano
    * **Processor:**
        * ATmega328P

If you need to download the **Arduino IDE**, use the following link: [https://www.arduino.cc/en/main/software](https://www.arduino.cc/en/main/software)


### Pin Settings
Below is a list of all the pins used in the Dreamweaver 4N
**Pin** | **Description**
:---:|:-----------
 **0** | Serial Data (Reserved)
 **1** | Serial Data (Reserved)
 **2** | Button 9
 **3** | IO 2 (Digital Only)
 **4** | IO 1/Speaker (Digital Only)
 **5** | Button 4
 **6** | Button 5
 **7** | Button 6
 **8** | Button 7
 **9** | RGB Data 
**10** | Button 3
**11** | Button 2
**12** | Button 1
**13** | Button 8
**14** | IO 3 (Analog/Digital)
**15** | IO 4 (Analog/Digital)
**16** | Knob 1 - Value 1
**17** | Knob 2 - Value 2
**18** | Knob 3 - Value 3
**19** | Knob 4 - Value 4
**20** | Knob 6 - Spread
**21** | Knob 5 - Length
