# Digital Calculator Using LPC2148

## Project Overview

A digital calculator implemented using the **LPC2148 ARM7 microcontroller**, a **4×4 matrix keypad**, and a **16×2 LCD display**. The system allows users to enter numbers and perform basic arithmetic operations through the keypad, with results displayed in real time on the LCD.

## Features

- Addition (+)
- Subtraction (-)
- Multiplication (*)
- Division (/)
- Keypad-based numerical input
- Real-time LCD output
- Embedded C programming
- ARM7-based microcontroller implementation

## Hardware Requirements

- LPC2148 ARM7 Development Board
- 4×4 Matrix Keypad
- 16×2 LCD Display
- Connecting Wires
- Power Supply
- USB-to-UART or compatible programming/debugging interface, as required by the development board

## Software Requirements

- Keil µVision IDE
- Embedded C
- LPC2148 device support and startup files
- Flash Magic (for programming the microcontroller, if using ISP)

## Working Principle

1. The LPC2148 initializes the LCD and configures the keypad GPIO pins.
2. The user enters numerical values using the 4×4 matrix keypad.
3. The user selects an arithmetic operation.
4. The microcontroller processes the input and performs the selected calculation.
5. The result is displayed on the 16×2 LCD.
6. The user can perform additional calculations using the keypad.

## Supported Operations

| Operation | Symbol |
|---|---|
| Addition | `+` |
| Subtraction | `-` |
| Multiplication | `*` |
| Division | `/` |

## Project Structure

```text
LPC2148-Digital-Calculator/
├── main.c          # Main program and calculation logic
├── README.md       # Project documentation
└── calculator.uvproj  # Keil project file (if included)
```

*Note: Update the file names in this structure to match the files actually uploaded to your repository.*

## How to Run

1. Clone or download this repository.
2. Open the Keil µVision project.
3. Verify the LPC2148 target configuration and GPIO pin connections.
4. Compile the Embedded C program.
5. Flash the generated HEX file to the LPC2148.
6. Connect the keypad and LCD according to the code's pin configuration.
7. Power on the board and start calculating.

## Applications

- Embedded systems learning
- ARM7 microcontroller programming
- GPIO interfacing
- Keypad and LCD interfacing
- Basic arithmetic processing

## Future Improvements

- Support for multi-digit expressions
- Operator precedence and brackets
- Error handling for division by zero
- Clear and backspace functionality
- Improved input validation

## Author

**Krunal Wade**

Electronics and Telecommunication Engineering

## License

This project is available for educational and learning purposes. Add a specific open-source license if you intend to define reuse and distribution permissions.
