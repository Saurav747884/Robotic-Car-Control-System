# Robotic Car Control System

This project allows you to control a robotic car using an ESP8266 microcontroller. The car's movement is powered by an L298N motor driver and servo motors. The system supports remote control via an external mobile app, and incorporates a laser directed at an LDR (Light Dependent Resistor) to open a gate for the car. It also includes the option for real-time data storage and visualization using ThingSpeak IoT.

## Features

- **Motor Control**: Control the robotic car’s movement (forward, backward, left, right, diagonal) using the external mobile app.
- **Speed Control**: Adjust the speed of the motors using PWM (Pulse Width Modulation), enabling smooth acceleration and deceleration.
- **Servo Control**: Control two servo motors to direct a laser aimed at an LDR, used to open a gate for the car.
- **Wireless Communication**: Use Wi-Fi to communicate with the robot through the mobile app, allowing remote control from any device connected to the same network.
- **IoT Integration**: Optionally integrate ThingSpeak IoT for real-time storage and visualization of movement and sensor data.

## Components Used

- **NodeMCU ESP8266**: The microcontroller used to control the robot and communicate over Wi-Fi.
- **L298N Motor Driver**: Used to control the motors of the robotic car for movement (forward, backward, left, right).
- **Servo Motors**: Used to control the direction of the laser.
- **LDR (Light Dependent Resistor)**: Detects the laser’s alignment to open the gate for the car.
- **Relay Module**: (Optional) Can be used to control additional devices, like a water pump or other peripherals.
- **ThingSpeak IoT**: Used for storing and visualizing movement or sensor data (optional integration).

## How It Works

1. **Movement Control**: 
   - The robot's movement is controlled via commands sent from the mobile app, which communicates with the ESP8266 via Wi-Fi.
   - The L298N motor driver receives these commands and adjusts the motors to make the car move forward, backward, left, right, or diagonally.

2. **Speed Control**: 
   - PWM is used to control the speed of the motors, allowing the user to adjust the car’s speed via the mobile app.

3. **Laser and LDR Gate Control**: 
   - Two servo motors control the laser’s direction, aiming it at an LDR.
   - When the laser is directed correctly at the LDR, the gate opens, allowing the car to pass.

4. **Wireless Communication**: 
   - The mobile app sends commands to the ESP8266 over Wi-Fi. The ESP8266 processes these commands and controls the car’s motors and servos accordingly.

5. **IoT Data Integration** (Optional): 
   - ThingSpeak can be used to store and display data from the sensors or movement commands, allowing real-time monitoring via a web interface.

## Setup Instructions

1. **Hardware Connections**:
   - Connect the **L298N motor driver** to the ESP8266 to control the motors.
   - Connect the **servo motors** to the ESP8266 to control the laser.
   - Connect the **LDR** to detect the laser and open the gate.
   - Ensure the ESP8266 is connected to a power source and to your Wi-Fi network for communication with the app.

2. **Software Setup**:
   - Install the **Arduino IDE** and configure it for the ESP8266.
   - Upload the provided code to the ESP8266.
   - Modify the code to set up the correct Wi-Fi credentials for your network.

3. **App Configuration**:
   - Use an existing mobile app to send commands to the ESP8266 over Wi-Fi. The app should send HTTP requests to control the robot’s movement and speed.
   - If ThingSpeak integration is enabled, you can also monitor real-time data from the robot.

## Code Description

- **Motor Control Functions**: Functions like `goAhead()`, `goBack()`, `goLeft()`, and `goRight()` are used to control the robot's movement based on commands received.
- **Servo Control**: Functions like `F1()`, `F2()`, `F3()`, and `F4()` adjust the direction of the servo motors to control the laser.
- **Wi-Fi Setup**: The ESP8266 connects to a Wi-Fi network and acts as a server, handling incoming requests to control the robot.
- **IoT Integration**: The ThingSpeak library is optionally included to store and visualize sensor data in real-time.

## Project Structure

- **Main Code (Arduino Sketch)**: Contains the logic for controlling the robot, including motor and servo control, Wi-Fi setup, and HTTP request handling.
- **App**: An external mobile app is used to send movement commands to the ESP8266. The app communicates over the same Wi-Fi network.

## License

This project is open-source and available under the [MIT License](LICENSE).

## Acknowledgments

- Thanks to the developers of the libraries used in this project: 
  - ESP8266WiFi for Wi-Fi communication.
  - Servo for controlling the servo motors.
  - ThingSpeak for IoT integration.
