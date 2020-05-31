# PART 0 ~ Preparations
This guide should be completed before we start the online course.

---
# 1. Checking your Kit

By now you should have gotten your workshop kit. The first thing to do is make sure you have everything.

Open up the kit and identify the following components:

* LilyPad ATTINY85 development board
* Neopixel Flora RGB LED
* Light Sensor
* 2x 10k𝛀 resistors
* 1x 220𝛀 resistor
* Alligator Clips
* Conductive thread (steel)
* Conductive thread (copper)
* Sewing needles
* Fabric
* other things...

(NOTE: Finish this list)
(NOTE: Provide an image with items labled)

---
# 2. Installing Necessary Software

You will need to download and install the Arduino IDE to create and upload programs to your microcontroller board. Please do this before we start the workshop, and contact us if you have any problems so we can iron those out beforehand and save time.

The installation process has multiple steps and is different depending on your operating system. We assume you are either using a recent version of Windows (8.1 or 10) or an Apple computer with a recent version of OSX. If you're using a flavor of Linux then please contact us.

---
## Windows Pre-installation Steps

***Windows*** users need to first follow these steps before following the more general installation instructions for Mac and Windows below.

Windows users will need to first download and install the DigiStump drivers, which allow your computer to recognize the development board when you plug it in.

If the following instructions aren't completely clear, there is a [video tutorial on YouTube](https://www.youtube.com/watch?v=wq3CuJQLRaw) that might help you with the process.

1. Follow [this download link](https://github.com/digistump/DigistumpArduino/releases/download/1.6.7/Digistump.Drivers.zip) - the link will download a file named `Digistump.Drivers.zip` to your computer.

2. Unzip the contents of the file to your hard drive. It should appear as a folder named `Digistump.Drivers`. Dig into that folder until you find two programs named `DPinst.exe` and `DPinst64.exe` ... these are the driver installation programs. The first one is for 32-bit systems and the second one is for 64-bit systems.

<fig>
<img src="./digistump_win_01.png"><br>
<figcaption>The two installer applications</figcaption>
</fig><br>

3. Run the installer appropriate to your system. Answer `Install/Yes` to any pop-up dialogs.

<img src="./digistump_win_02.png"><br>

<img src="./digistump_win_03.png"><br>

4. Click the `Finish` button once the installation procedure is done.

5. Plug your LilyPad board into your computer using a USB micro data cable. Once you've plugged it in you should see the little red power light on the board turn on.

(NOTE: Have a photo of the board here?)

6. Now check to see that Windows recognizes your board. Open up `Device Manager` (you can search for it in the menu bar if you don't know where it is).

  Once you have Device Manager open, scroll down and find an entry named `libusb-win32 devices`. Open up the dropdown triangle and you should see inside a usb device named `Digispark Bootloader`.

<fig>
<img src="./digistump_win_05.png"><br>
<figcaption>You should see the Digispark Bootloader in Device Manager</figcaption>
</fig><br>

  If you don't have the Digispark Bootloader in Device Manager, make sure your LilyPad is plugged in correctly to your computer. The red power light on the board should be on. You can also try a different USB port on your computer, restarting your computer, or reinstalling the Digistump drivers. If none of that works contact us and let us know.


<img src="./digistump_win_06.png"><br>


---

## Mac Instructions and Windows Next Steps

The remaining steps for Windows users are identical to the installation instructions for Mac users. Windows users must install the Digistump drivers before following these steps.

1. Download the Arduino IDE from [the Arduino website](https://www.arduino.cc/en/Main/Software). You want to download the IDE, not use the web interface!
2. Install the file you downloaded.

  ***Windows Users*** if you are asked to install drivers, answer Yes to all.

3. Once the installation is finished, run the Arduino IDE. A window should open that looks something like this:

<fig>
<img src="./ARDUINO_IDE.png">
<figcaption>The Arduino IDE</figcaption>
</fig><br>

4. Go to `File->Preferences` to open the program preferences window. Near the bottom of the window you should see a field labeled 'Additional Boards Manager URLs', type in the url `http://digistump.com/package_digistump_index.json` and click `OK`.

<fig>
<img src="./ARDUINO_PREFS.png">
<figcaption>Add the digistump board manager url to your Arduino Preferences</figcaption>
</fig><br>


5. Now go to `Tools->Board` and select `Board Manager` at the top of the boards menu to open up the Board Manager window.

6. Select "Contributed" from the drop-down list of filters and find the package named `Digistump AVR Boards`. This package contains the technical description of your LilyPad board so that the Arduino IDE will know how to program it. Click the install button to download and install this add-on. Wait for the installation to finish.

<fig>
<img src="./DIGISTUMP_BOARDS_ARDUINO.png">
<figcaption>The Digistump AVR Boards package, after installation</figcaption>
</fig><br>


7. When the installation is complete, close the Boards Manager window. Again go to `Tools->Board` and look through the available development boards. If you scroll down you should see a board named `Digispark  (Default - 16.5mhz)`. Select that one.

You're now ready to program your ATTINY85!

---
# 3. Testing that your Installation Works

Now we will test that your installation works and that you can successfully upload a program to the ATTINY85.

We'll use one of the basic examples that makes the LED on the board blink. First, make sure that your board is ***not connected*** to your computer. The process to program these boards is very specific and starts with the USB cable ***unplugged***.

1. First, open the `Start` example found at `File->Examples->Digispark_Examples->Start`

2. Check that you have the correct board selected. Under `Tools->Boards` make sure you have selected `Digispark  (Default - 16.5mhz)`

<fig>
<img src="./START_ARDUINO.png">
<figcaption>The 'Start' example</figcaption>
</fig><br>


3. Click the ***Arrow*** Button in the upper left to UPLOAD

4. After a moment, you should see some red text in the lower console reading `Running Digispark Uploader... Plug in device now... (will timeout in 60 seconds)`

<fig>
<img src="./digistump_win_06.png">
<figcaption>You should see this next in the console after clicking the upload button</figcaption>
</fig><br>

5. The IDE is now waiting for you to plug in your board. Plug it in.

6. After a moment the sketch will be uploaded to your board, the little LED should be blinking slowly. If you have problems see the troubleshooting note below.

(NOTE: Add images of what success looks like)

## Troubleshooting

The upload process on these boards can be rather fiddly. Sometimes the board isn't detected after plugging it in, sometimes the upload fails inexplicably.

In most cases, the solution is to repeat the process:
1. Unplug the USB cable
2. Click on the Upload (Arrow) button again
3. Wait for the console message `Plug in device now...` and then plug in the USB cable.

If this keeps happening try using a different USB port on your computer.

Programming errors can also be caused by connecting circuits to certain pins of the LilyPad board. But since we haven't built any circuits yet this should not be the cause of programming problems.
