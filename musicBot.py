import RPi.GPIO as GPIO
import time
import os
import sys


GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(14, GPIO.IN, pull_up_down=GPIO.PUD_UP)

count = 0

try:
    while True:
        button_state = GPIO.input(14)
        if button_state == False:
          if count == 0:
            print('Starting intro music')
            os.system("omxplayer intro.mp3 -o alsa")
            count+=1
            time.sleep(1)
          elif count == 1:
            print('Starting ending music')
            os.system("omxplayer gagaending.mp3 -o alsa")
            time.sleep(1)
            count+=1
except:
    GPIO.cleanup()

