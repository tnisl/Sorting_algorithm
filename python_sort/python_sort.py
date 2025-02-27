# Test 0: 65 ms
# Test 1: 62 ms
# Test 2: 62 ms
# Test 3: 64 ms
# Test 4: 67 ms
# Test 5: 67 ms
# Test 6: 61 ms
# Test 7: 59 ms
# Test 8: 63 ms
# Test 9: 61 ms

import numpy as np
import time

for test in range(10):
    PATH = ""
    t = str(test)
    t = t + ".inp"
    PATH = PATH + t

    with open(PATH) as file:
        x = file.read()
        x = x.split(" ")
        x.remove(x[0])
        x.insert(0, "0")        
        if x[len(x)-1] == "":
            x.pop()

        for i in range(len(x)):
            x[i] = float(x[i])

        arr = np.array(x)
        start = time.perf_counter()
        
        arr = np.sort(x)

        end = time.perf_counter()

        print(f"Test {test}: {(end-start)*1000:.0f} ms\0")
        