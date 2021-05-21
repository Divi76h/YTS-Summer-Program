import serial
import matplotlib.pyplot as plt
import numpy as np
import csv

S = serial.Serial("COM3", 115200)

time = []
val = []
n = 1000

resolution = 12
vcc = 3300
gain = 1920
sr = 1000

emg_rectified = []

window_size = 20
moving_averages = []
emg_final = []

avg_pre_pro_signal = 0.07
avg_pre_pro_signal = float(avg_pre_pro_signal)

binary_val = []

for i in range(n):
    try:
        raw = S.readline()
        tmp = (raw.split(b","))
        time.append(int(tmp[0])/1000)
        val.append(int(tmp[1]))

        signal_mv = (((int(tmp[1]) / 2 ** resolution) - 0.5) * vcc) / gain

        emg_rectified.append(abs(signal_mv))

        moving_averages = sum(emg_rectified[i+1-window_size:])/window_size
        emg_final.append(moving_averages)

        if moving_averages >= avg_pre_pro_signal:
            binary_val.append(1)

        else:
            binary_val.append(0)

        S.write((str(binary_val[-1]) + "\n").encode("UTF-8"))
        print("sent", binary_val[-1])

        x1 = time[-200:]
        y1 = emg_final[-200:]
        y2 = binary_val[-200:]

        if i % 20 == 0:
            plt.plot(x1, y1)
            plt.plot(x1, y2)
            plt.pause(0.01)
            plt.cla()

    except:
        print("[-] ERROR")

f = open("DATABASE_FOR_EMG.csv", "w")

for i in range(n):
    f.write(str(time[i]) + "," + str(val[i]) + "\n")

f.close()
S.close()
