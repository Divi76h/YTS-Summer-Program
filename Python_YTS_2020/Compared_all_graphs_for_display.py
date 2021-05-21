import matplotlib.pyplot as plt
import biosignalsnotebooks as bsnb
import numpy as np
import csv
import scipy as sp
from scipy import signal

x = []
y = []

csvfile = open('EMG_sample_3.csv', "r")
plots = csv.reader(csvfile, delimiter=",")

for row in plots:
    x.append(int(row[0]))
    y.append(int(row[1]))

resolution = 12
vcc = 3300
gain = 1920
sr = 1000

signal_mv = (((np.array(y) / 2**resolution) - 0.5) * vcc) / gain
time = bsnb.generate_time(signal_mv)

pre_pro_signal = signal_mv - np.average(signal_mv)

high = 20/(1000/2)
low = 450/(1000/2)
b, a = sp.signal.butter(4, [high, low], btype="bandpass")
emg_filtered = sp.signal.filtfilt(b, a, pre_pro_signal)

emg_rectified = abs(np.array(emg_filtered))

i = 0
window_size = 25
moving_averages = []

for j in range(window_size - 1):
    emg_rectified = [0] + emg_rectified
while i < len(emg_rectified) - window_size + 1:
    this_window = emg_rectified[i:i + window_size]
    window_average = sum(this_window) / window_size
    moving_averages.append(window_average)
    i += 1

rectified_time = time[0: -(window_size - 1)]

avg_pre_pro_signal = np.average(moving_averages)

binary_val = []

for k in range(len(moving_averages)):
    if moving_averages[k] >= avg_pre_pro_signal:
        binary_val.append(1)
    else:
        binary_val.append(0)

plt.plot(time[0:1000], pre_pro_signal[0:1000], label="raw emg data (centered at 0)")
plt.plot(time[0:1000], emg_rectified[0:1000], label="taking absolute value")
plt.plot(rectified_time[0:1000], moving_averages[0:1000], label="implementing running average")
plt.plot(rectified_time[0:1000], binary_val[0:1000], label="converting into binary data")
plt.xlabel("Time (sec)")
plt.ylabel("EMG (A.U.)")
plt.legend()
#plt.plot(rectified_time[0:200], moving_averages[0:200])
plt.show()

