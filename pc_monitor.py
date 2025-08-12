import psutil
import serial
import time

SERIAL_PORT = 'COM4'  # Change to your ESP8266 COM port
BAUD_RATE = 9600

try:
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE)
except Exception as e:
    print(f"Cannot open serial port {SERIAL_PORT}: {e}")
    exit(1)

while True:
    cpu_usage = psutil.cpu_percent(interval=1)
    message = f"LOAD:{cpu_usage:.1f}\n"
    try:
        ser.write(message.encode())
        print(f"Sent: {message.strip()}")
    except Exception as e:
        print(f"Error writing to serial: {e}")
        break
