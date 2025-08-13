# cpu-usage-monitor
Micro-scheme that displays CPU usage

<img width="640" height="640" alt="image" src="https://github.com/user-attachments/assets/98f59215-a2a1-48c7-b85b-3e6232963a58" />

HOW DOES IT WORK?

The system works by running a Python script on your PC that uses `psutil` to read the CPU usage and sends it over a USB serial connection to the ESP8266. The ESP8266, connected to an SSD1306 OLED via I²C, receives the value, then updates the display to show the current CPU percentage in real time, repeating the process continuously.




ITEMS NEDEED:


 - Esp8266
 - Ssd1306
 - 4 female-female wires
 - Micro-usb **DATA** cable



 
WIRING:
 - GND - GND
 - VCC - 3.3V
 - SCL - D1 
 - SDA - D2

APPS USED:
 - Cmd
 - Arduino Ide
 - Text Editor (Notepad, VScode...)

INSTALLATION:
check the [installation-steps](https://github.com/bullsxit/cpu-usage-monitor/blob/main/installation-steps)


