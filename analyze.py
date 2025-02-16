import json

import matplotlib.pyplot as plt

with open('optical.json', 'r') as file:
    numbers = json.load(file)

plt.plot(numbers)
plt.xlabel('Data Point')
plt.ylabel('Hue (0 - 359.99)')
plt.title('VEX Optical Sensor Hue Readings')
plt.show()