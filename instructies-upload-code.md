# How to Upload Code to an Arduino Nano (AVR) Using the Arduino IDE

<!-- ## Windows: Install the CH340 Driver
1. Visit the manufacturer's Chinese info link for the CH340 driver : https://www.infwin.com/resource-usb-to-serial-port-driver-ch340-series/
2. Download the Windows CH340 Driver.
3. Unzip the downloaded file.
4. Run the installer executable from the unzipped folder.
5. Restart your PC
-->

---

## Step 1: Install the Arduino IDE
1. Download the latest version of the Arduino IDE from the official website: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)
2. Follow the installation instructions for your operating system (Windows, macOS, Linux).

## Step 2: Connect Your Arduino Nano
1. Connect the Nano to your computer via the USB.

## Step 3: Open the Arduino IDE
1. Launch the Arduino IDE application.

## Step 4: Select the Correct Board
1. In the menu, go to **Tools > Board > Arduino AVR Boards**.
2. Select **Arduino Nano**.

## Step 5: Select the Correct Processor and Bootloader
1. Still under **Tools**, find the **Processor** menu.
2. Choose **ATmega328P (Old Bootloader)**.

## Step 6: Select the Correct Port
1. Connect your Arduino Nano.
2. Go to **Tools > Port**.
3. Select the port that corresponds to your Nano (e.g., `COM3` on Windows or `/dev/tty.usbserial-XXXX` on macOS/Linux).

## Step 7: Open or Write Your Code
1. Open the existing sketch, go to **File > Open** and select the `.ino` file.

## Step 8: Verify the Code
1. Click on the **Verify** button (checkmark icon) or press **Ctrl + R** (Windows/Linux) or **Cmd + R** (macOS).
2. The IDE will compile your code and check for errors.

## Step 9: Upload the Code
1. Click on the **Upload** button (right arrow icon) or press **Ctrl + U** (Windows/Linux) or **Cmd + U** (macOS).
2. The IDE will compile and then upload the code to the Nano.
3. Watch the status messages at the bottom of the IDE for confirmation.

## Step 10: Confirm Upload
1. Once uploaded, the Nano will run the new program.
2. You can open the **Serial Monitor** (**Tools > Serial Monitor**) to communicate with your Nano if your sketch includes serial communication.
