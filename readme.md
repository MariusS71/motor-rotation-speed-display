# Motor Rotation Speed Display

## Project Overview
This project involves controlling a DC motor with an encoder and displaying its rotation speed (in RPM) on two 7-segment displays. The motor's speed is controlled using a potentiometer, while the encoder generates pulses based on the motor's rotation, which are used to calculate the speed. An Arduino platform processes the encoder's pulses and displays the calculated RPM on two 7-segment displays via a CD4511 BCD decoder.

### Components Used:
- **DC Motor with Encoder**: The motor's speed is controlled via a potentiometer, and the encoder sends pulse signals to indicate motor rotation.
- **Arduino Board**: The microcontroller reads encoder pulses and calculates the RPM.
- **7-Segment Display**: Two common cathode 7-segment displays are used to show the RPM.
- **CD4511 BCD Decoder**: A BCD to 7-segment display decoder is used to drive the two 7-segment displays, saving both components and pins.
- **NPN Transistor**: Used for controlling the motor speed.
- **Potentiometer**: Adjusts the motor's speed.
- **Power Supply**: The motor operates at 10V, while the Arduino is powered by a standard USB connection.

## How It Works:
1. **Motor Control**: The motor's speed is adjusted using a potentiometer, which controls an NPN transistor to regulate the motor's power.
2. **Encoder & Interrupts**: The motor's encoder generates pulses corresponding to the rotation. The Arduino uses interrupts to capture these pulses, measuring the time between them to calculate the motor's rotation speed (RPM).
3. **RPM Calculation**: The Arduino uses the time between pulses (via `micros()`) to determine the motor's speed. An experimental constant is used to convert the time interval to RPM.
4. **BCD to 7-Segment Display**: The RPM value is displayed on two 7-segment displays using a CD4511 BCD decoder, which converts the binary representation of the number into signals that drive the display.
5. **Optimization**: The system uses a single decoder for both displays to save components and reduce pin usage on the Arduino.

### Tinkercad Circuit:
You can view and simulate the circuit on Tinkercad:  
[**View Circuit on Tinkercad**](https://www.tinkercad.com/things/lar8heKt4m4)

### Code Explanation:
The Arduino code reads encoder pulses through an interrupt service routine (ISR). When a pulse is detected, the program calculates the time between pulses to estimate the motor's rotation speed. The `micros()` function is used to measure time with high precision.

To convert the RPM to a 4-bit binary format suitable for the BCD decoder, the RPM value is shifted right and processed using the `AND` operation to extract the required bits.

The 7-segment displays are alternated between the two digits rapidly, so that both digits can be displayed at the same time, without flicker, by multiplexing.

### Features:
- **Motor Speed Control**: Adjust motor speed via the potentiometer.
- **RPM Display**: Accurate display of the motor's RPM on two 7-segment displays.
- **Interrupt Handling**: Efficiently handles encoder pulses using interrupts to minimize processing delays.
- **BCD to 7-Segment Conversion**: Uses a CD4511 BCD decoder to control two 7-segment displays with minimal hardware.

## Circuit Diagram:
A visual representation of the circuit can be found in the Tinkercad link above, which shows the complete wiring, including the motor, encoder, potentiometer, transistor, BCD decoder, and 7-segment displays.
