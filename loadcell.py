import RPi.GPIO as GPIO               
from hx711 import HX711               
 
GPIO.setmode(GPIO.BCM)                
hx = HX711(dout_pin=27, pd_sck_pin=17)
hx.zero()

input("Place the  Known Weight : ")

reading=hx.get_data_mean(readings=100)

knownVal=input("enter the known weight ")
value=float(knownVal)

ratio=reading/value

hx.set_scale_ratio(ratio)

while True:
  weight=hx.get_weight_mean()
  print(weight)

  