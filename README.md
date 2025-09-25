# ECPROBE
A simple EC Probe using a 555 timer, some resistors, capacitors and an Arduino Uno.

 EC Probe (Electrical Conductivity & TDS Sensor)

This project measures **electrical conductivity (EC)** and estimates **total dissolved solids (TDS)** in liquids using an Arduino-compatible microcontroller.  
It also includes **temperature compensation** and **serial user feedback** for real-time monitoring.  

Built with **PlatformIO** for reproducibility and modular design.  

---

## Project Structure

├── include/ # Header files (.h)
├── src/ # Source files (.cpp)
│ ├── main.cpp # Entry point
│ ├── conductanceRead.cpp
│ ├── tempRead.cpp
│ └── userFeedback.cpp
├── lib/ # custom libraries
├── test/ # Unit tests
├── platformio.ini # PlatformIO build configuration
├── README.md # Project documentation
└── LICENSE # CC0-1.0 License

---

## Features

- **Conductivity measurement** using probe input.  
- **Temperature sensor support** for compensation.  
- **User feedback** via serial monitor (with ANSI escape codes for clean UI).  
- **Modular design** for easy extension (`conductanceRead`, `tempRead`, `userFeedback`).  

---

## Hardware Requirements

- Arduino-compatible microcontroller (e.g., Uno, Nano, ESP32).  
- EC probe (2-pin or 3-pin, analog input).  
- Temperature sensor (e.g., DS18B20, NTC thermistor).    
- Breadboard, jumper wires, USB cable.
- Develop your own probe architecture.

---

## Software Setup

1. Install [VS Code](https://code.visualstudio.com/) + [PlatformIO IDE](https://platformio.org/).  
2. Clone this repo:
   
   ```bash
   git clone https://github.com/antonykasera/ECPROBE.git
   cd ECPROBE
   ```
4.  Open the project in VS Code → PlatformIO should auto-detect platformio.ini.
5.  Build & upload:
   
   ```bash
   pio run --target upload
   ```
5.  Open serial monitor:
   
    ```bash
    pio device monitor
    ```
    

