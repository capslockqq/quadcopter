import random
import time
while True:
    f = open('data.txt', 'a')
    f.write(str(random.randint(1,101)))
    f.write("\n")
    time.sleep(0.01)
    
