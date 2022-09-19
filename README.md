# Blinking_LED_Control
First Project in Egypt FWD Advanced Embedded Systems Track on the ARM module
## Description
Created a function in the App layer that takes as an input from the user a specific ON time and OFF time in seconds, lights a LED for the given ON time, and dim it for the given OFF time. Didn't use predefined delay functions, only timer driver functions were used. This function implements implicitly the PWM module using Timer Overflow.
## Target Board
Tiva™ TM4C123GH6PM Microcontroller
## Work Done
- Created a COTS folder for the whole project including a folder for each layer in the layered architectureto include MCAL, HAL, APPLICATION.
- Created the GPIO driver from scratch
- Created the Timer driver from scratch.
- Created a Timer Overflow ISR that performs the required functionality.
- Passing the ISR as a callback function from App Layer to Timer driver in MCAL layer.
- Created the Interrupt control driver from scratch.
