# Automatic Grass Cutter

The Automatic Grass Cutter is an Arduino-based project designed to automate grass cutting using DC motors and an ultrasonic sensor for obstacle detection. The system ensures safe operation by stopping the motors if an obstacle is detected within a specified distance.

## Project Overview

This project uses:
- **DC Motors** to drive the cutting mechanism.
- **Ultrasonic Sensor** to detect obstacles and ensure safe operation.
- **Arduino** as the central controller to manage motor operations and sensor readings.

The grass cutter moves forward until an obstacle is detected. If an object is within a set distance threshold, the motors stop to prevent collisions or damage.

## Tech Specifications

- **Microcontroller**: Arduino Uno
- **Motors**: 
  - Motor A
    - Speed Control: PWM on pin 9
    - Direction Control: Pins 8 and 7
  - Motor B
    - Speed Control: PWM on pin 3
    - Direction Control: Pins 5 and 4
- **Ultrasonic Sensor**:
  - Trigger Pin: Pin 11
  - Echo Pin: Pin 10
  - Range: Configured for a threshold of 20 cm
- **Power Supply**: External power source for motors and Arduino
- **Communication**: Serial communication for debugging (9600 baud rate)

## Requirements

### Hardware

- Arduino Uno (or compatible microcontroller)
- Ultrasonic Sensor (HC-SR04 or equivalent)
- L298N Motor Driver (or equivalent motor driver module)
- 2 DC Motors with wheels
- Power supply for motors and Arduino (e.g., 12V battery)
- Connecting wires and breadboard

### Software

- Arduino IDE (latest version recommended)

## How It Works

1. The ultrasonic sensor measures the distance to objects in front of the grass cutter.
2. If the measured distance is greater than the threshold (20 cm), the motors are activated to move the cutter forward.
3. If an object is detected within 20 cm, the motors are stopped to prevent collisions.
4. Serial output provides real-time distance measurements and status updates for debugging.


