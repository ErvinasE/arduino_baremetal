import serial
import time

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
time.sleep(2)  

ser.reset_input_buffer()
ser.reset_output_buffer() 

print(ser.readline().decode().strip())

while True:
    data = input("Sent: ")
    if data == "quit":
        break
    ser.write((data + '\n').encode())
    time.sleep(0.1) # need to wait a little bit

    response = ser.readline().decode().strip()
    print(f"Response: {response}")

ser.close()
