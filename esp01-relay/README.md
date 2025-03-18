# ESP-01 Relay Control Project

## 📌 Project Description
This project aims to control devices remotely using an **ESP-01 WiFi module**, a **3.7V LiPo battery, Boost Converter (3.7V → 5V), and Relay circuit**. 
The ESP-01 module is programmed using **Arduino Uno** and operates independently on its circuit.

## 🛠 Components Used
- **ESP-01 WiFi Module**
- **Arduino Uno** (For programming the ESP-01)
- **3.7V LiPo Battery** (Main power source)
- **Boost Converter (3.7V → 5V)** (To increase the power level)
- **5V Relay Module** (To switch devices on/off)
- **Optocoupler (EL817C-G)** (To isolate the ESP-01 signal)
- **BC548B Transistor** (To drive the relay)
- **1N4007 Diode** (To prevent reverse current)
- **Capacitors and Resistors** (For power stabilization and signal adjustments)

## 📜 Circuit Explanation
1. **Arduino Uno is used to program the ESP-01.**
2. **The ESP-01 module** controls the relay circuit through its GPIO pin.
3. **The 3.7V LiPo battery** is boosted to **5V** via the boost converter circuit and powers both the ESP-01 and the relay.
4. **The optocoupler (EL817C-G)** converts the ESP-01’s 3.3V logic level to 5V and triggers the transistor.
5. **The BC548B transistor** is used to drive the relay.
6. **The relay output** controls connected devices by switching them on or off.

   ![sh](https://github.com/user-attachments/assets/8c5af2f6-5f89-4531-bc5d-f4a03e32427b)
   
   ![2d](https://github.com/user-attachments/assets/c7ef7e51-4846-4824-ad03-b69e3eb7d9a5)


## 🔧 Programming the ESP-01 with Arduino
Follow these steps to program the ESP-01:

1. **Set up the Arduino Uno as an ESP-01 programmer:**
   - Upload a blank sketch to the Arduino to enter programmer mode.
   - Connect the Arduino to the ESP-01 as follows:
     - **Arduino 3.3V** → **ESP-01 VCC and CH_PD**
     - **Arduino GND** → **ESP-01 GND**
     - **Arduino RX (Pin 0)** → **ESP-01 TX**  
     - **Arduino TX (Pin 1)** → **ESP-01 RX**   
     - **GPIO0 → GND** (To enter programming mode)
     - **If this connection does not work, try RX-RX and TX-TX instead.**
     

       ![images](https://github.com/user-attachments/assets/7c7fccfe-4f15-405d-8f39-8ba75f85b202)

2. **Configure the following settings in Arduino IDE:**
   - Board: `Generic ESP8266 Module`
   - Flash Mode: `DOUT`
   - Baud Rate: `115200`
3. **Upload the code to ESP-01.**
4. **After uploading, disconnect GPIO0 and restart the ESP-01.**

## 🔋 Power Management
- **Both ESP-01 and the relay operate at 5V**, but **ESP-01's logic level is 3.3V**.
- Therefore, **an optocoupler is used for signal isolation**.
- **The Boost Converter** increases the **3.7V → 5V** to power the entire circuit.

## 🔗 Additional Resources
- **EasyEDA Circuit Schematic:** (Add the schematic image here)
- **ESP-01 Programming Guide:** [Add Link]
- **Relay Control with Arduino:** [Add Link]

## 📌 Conclusion
With this project, **you can remotely control a relay using an ESP-01 module and build an energy-efficient smart system**. For better power efficiency, **MT3608** or a similar high-efficiency boost converter can be used. Consider using a MOSFET instead of a relay as well. 🚀

