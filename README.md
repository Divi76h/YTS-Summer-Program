# YTS-Summer-Program
Developed an EMG sensor using Arduino. Used python to process the EMG data into binary output, which was then used to move a prosthetic limb.


Filtering process of RAW EMG DATA:


This is what the prerecorded EMG data usually looks like (values are in millivolts):

![rawemgdata](https://user-images.githubusercontent.com/51193121/119175752-dc0b2000-ba87-11eb-9007-725f7878e64d.png)
Zoomed in:

![rawemgdatazoom2](https://user-images.githubusercontent.com/51193121/119175821-f218e080-ba87-11eb-95bd-6fdb525286e4.png)

Since this data would be used to power a motor that moves a prosthetic limb, this data needs to be filtered and processed into binary data. The python script filters it in 3 steps.

Step1: Convert into Absolute value (nonnegative value)

  The graph after this process looks like this:

![absvalue](https://user-images.githubusercontent.com/51193121/119176342-9b5fd680-ba88-11eb-911d-98faa50591bf.png)
  Zoomed in:

![absvaluezoom](https://user-images.githubusercontent.com/51193121/119176486-ca764800-ba88-11eb-8f7c-40408ab66583.png)
  Absolute value graph compared with raw data graph:

![absvaluezoomvsraw](https://user-images.githubusercontent.com/51193121/119176500-cd713880-ba88-11eb-8463-7925bc62751c.png)
Step2: Taking running average

  The graph after this process looks like this:
![runningaverage](https://user-images.githubusercontent.com/51193121/119176802-250fa400-ba89-11eb-963c-145aa31479be.png)

  Zoomed in:
![runningaveragezoom](https://user-images.githubusercontent.com/51193121/119176820-2b9e1b80-ba89-11eb-8a21-939e0ed390a7.png)

  Running average graph compared with Absolute value graph:
![runningaveragezoomvsabs](https://user-images.githubusercontent.com/51193121/119176926-46709000-ba89-11eb-928b-9449f3abc3c0.png)
 
Step3: Binary (0 or 1)

  The data after this process looks like this (compared with running average graph):
![runningaveragezoomvsbinary](https://user-images.githubusercontent.com/51193121/119176981-56886f80-ba89-11eb-9b49-0ee40fc7b4ca.png)

All compared (raw, absolute, running average, and binary data graph):
![allcomparison](https://user-images.githubusercontent.com/51193121/119177008-5e481400-ba89-11eb-8569-b8dd8f9d3073.png)
