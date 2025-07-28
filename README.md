# Smart Cradle – IoT Based Baby Monitoring System

## 🌟 Overview
An IoT-based smart cradle that helps working parents monitor their babies in real time. It features auto-swing on cry detection, moisture detection, lullaby playback, and live video streaming.

## 💡 Features
- Cry detection and automatic cradle swinging
- Moisture (wetness) detection with notifications
- Live video streaming using ESP32-CAM
- Remote lullaby playback
- Blynk IoT app integration for notifications and control

## 🔧 Technologies Used
- NodeMCU (ESP8266)
- ESP32-CAM
- LM393 Sound Sensor
- Rain Sensor (Moisture)
- Stepper Motor + A4988 Driver
- DFPlayer Mini + Mini Speaker
- Blynk IoT Platform
- Arduino IDE, C++

## 🚀 Getting Started
1. Flash `esp8266_cradle.ino` to NodeMCU
2. Flash `esp32_cam_stream.ino` to ESP32-CAM
3. Set up Blynk app with appropriate token
4. Connect the components as per the diagram
5. Power on the system and monitor via Blynk

## 🛠️ Future Work
- Emotion detection using facial recognition
- Climbing detection using ML
- Integration with mobile apps

