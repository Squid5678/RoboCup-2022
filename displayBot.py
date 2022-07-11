from PIL import Image
import time
import os
import sys
import RPi.GPIO as GPIO
import pynput
from pynput.keyboard import Key, Controller
#image = Image.open('Display.jpg')
#image.show()

keyboard = Controller()
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(15, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(18, GPIO.IN, pull_up_down=GPIO.PUD_UP)





    
time.sleep(5)

#sensitive
def sensor1Detect():
    for i in range(3):
        keyboard.press(Key.right)
        keyboard.release(Key.right)
        time.sleep(.13)
    for i in range(3):
        keyboard.press(Key.left)
        keyboard.release(Key.left)
        time.sleep(.13)
#LOUD
def sensor2Detect():
    for i in range(6):
        keyboard.press(Key.right)
        keyboard.release(Key.right)
        time.sleep(.13)
    for i in range(6):
        keyboard.press(Key.left)
        keyboard.release(Key.left)
        time.sleep(.13)
        
        
        

try:
    while True:
        
        sensor1 = GPIO.input(18)
        sensor2 = GPIO.input(15)
        
        
        if sensor2 == False:
            sensor2Detect()
            
        elif sensor1 == False:
            sensor1Detect()
        
except:
    GPIO.cleanup()
