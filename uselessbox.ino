#include <Servo.h>
#include <FastLED.h>
#include <avr/wdt.h>  // Include watchdog timer library

#define NUM_LEDS 1
#define DATA_PIN 2

CRGB leds[NUM_LEDS];

Servo handServo;

volatile bool switchInterruptFlag = false;
unsigned long lastInterruptTime = 0;
constexpr unsigned long debounceDelay = 1000;

constexpr int frontSwitchPin = 3;
constexpr int handServoPin = 4;
volatile uint8_t action = 1;
volatile bool servoIsMoving = false;

void startWatchdog() {
  // Enable watchdog timer with 8s timeout
  wdt_enable(WDTO_8S);
}

void stopWatchdog() {
  // Disable watchdog timer
  wdt_disable();
}

void hitTheSwitch(int speed, int from) {
  servoIsMoving = true;
  startWatchdog();
  for (int pos = from; pos >= 0; pos--) {
    handServo.write(pos);
    delay(speed);
    wdt_reset();
    if (digitalRead(frontSwitchPin) == LOW) {
      Serial.println("Switch pressed! Stopping movement.");
      break;
    }
  }
  stopWatchdog();
  servoIsMoving = false;
}

void detectSwitch() {
  servoIsMoving = true;
  startWatchdog();
  hitTheSwitch(20, 180);
  int currentPos = handServo.read();
  Serial.print("Current position: ");
  Serial.println(currentPos);
  Serial.println("BOX started with the switch pointing UP --> restart it with the switch down...");
  stopWatchdog();
  servoIsMoving = false;
}

void closeTheBox(int speed) {
  servoIsMoving = true;
  startWatchdog();
  int currentPos = handServo.read();
  Serial.print("Moving back to 180 from position: ");
  Serial.println(currentPos);
  for (int pos = currentPos; pos <= 180; pos++) {
    handServo.write(pos);
    delay(speed);
    wdt_reset();
  }
  stopWatchdog();
  servoIsMoving = false;
}

void handleSwitchInterrupt() {
  switchInterruptFlag = true;
}

void setup() {
  Serial.begin(9600);
  Serial.println("Useless Box v1.7 --> https://github.com/KunstGraveren/uselessbox");

  // 1.0 | init release
  // 1.1 | no end position, reusing interupt switch pin to find the switch
  // 1.7 | refctor code & added a dogwach for reset on powerfailer

  pinMode(frontSwitchPin, INPUT_PULLUP);
  handServo.attach(handServoPin);
  handServo.write(180);

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  leds[0] = CRGB::Blue;
  FastLED.show();

  attachInterrupt(digitalPinToInterrupt(frontSwitchPin), handleSwitchInterrupt, FALLING);

  Serial.print("Switch state: ");
  Serial.println(digitalRead(frontSwitchPin));

  // Start with watchdog disabled
  stopWatchdog();
}

void performAction1() {
  Serial.println("Action 1:");
  hitTheSwitch(20, 180);
  closeTheBox(20);
}

void performAction2() {
  Serial.println("Action 2:");
  servoIsMoving = true;
  startWatchdog();
  delay(2000); wdt_reset();
  handServo.write(170);
  delay(2000); wdt_reset();
  hitTheSwitch(40, 170);
  delay(500); wdt_reset();
  closeTheBox(40);
  stopWatchdog();
  servoIsMoving = false;
}

void performAction3() {
  Serial.println("Action 3:");
  servoIsMoving = true;
  startWatchdog();
  delay(2000); wdt_reset();
  for (int i = 0; i < 5; i++) {
    for (int pos = 180; pos >= 165; pos--) {
      handServo.write(pos);
      delay(10);
      wdt_reset();
    }
    delay(200); wdt_reset();
  }
  hitTheSwitch(30, 165);
  delay(400); wdt_reset();
  handServo.write(180);
  stopWatchdog();
  servoIsMoving = false;
}

void performAction4() {
  Serial.println("Action 4:");
  servoIsMoving = true;
  startWatchdog();
  delay(2000); wdt_reset();
  hitTheSwitch(20, 180);
  delay(2000); wdt_reset();
  handServo.write(180);
  stopWatchdog();
  servoIsMoving = false;
}

void performAction5() {
  Serial.println("Action 5:");
  servoIsMoving = true;
  startWatchdog();
  delay(2000); wdt_reset();
  hitTheSwitch(8, 180);
  delay(2000); wdt_reset();
  for (int i = 0; i < 7; i++) {
    handServo.write(75);
    delay(100);
    wdt_reset();
    handServo.write(40);
    delay(100);
    wdt_reset();
  }
  delay(500); wdt_reset();
  handServo.write(180);
  stopWatchdog();
  servoIsMoving = false;
}

void performAction6() {
  Serial.println("Action 6:");
  servoIsMoving = true;
  startWatchdog();
  delay(2000); wdt_reset();
  hitTheSwitch(50, 180);
  delay(2000); wdt_reset();
  handServo.write(180);
  stopWatchdog();
  servoIsMoving = false;
}

void performAction7() {
  Serial.println("Action 7:");
  servoIsMoving = true;
  startWatchdog();
  delay(2000); wdt_reset();
  for (int pos = 180; pos >= 60; pos--) {
    handServo.write(pos);
    delay(40);
    wdt_reset();
  }
  for (int i = 0; i < 3; i++) {
    handServo.write(60);
    delay(200);
    wdt_reset();
    handServo.write(40);
    delay(800);
    wdt_reset();
  }
  hitTheSwitch(20, 40);
  delay(2000); wdt_reset();
  handServo.write(180);
  stopWatchdog();
  servoIsMoving = false;
}

void loop() {
  if (switchInterruptFlag) {
    unsigned long currentTime = millis();
    if (currentTime - lastInterruptTime >= debounceDelay) {
      Serial.println("Handle switch press with debounce");
      action = (action % 7) + 1;
      lastInterruptTime = currentTime;
    }
    switchInterruptFlag = false;
  }

  if (action != 0) {
    leds[0] = CRGB::Red;
    FastLED.show();

    if (digitalRead(frontSwitchPin) == HIGH) {
      switch (action) {
        case 1: performAction1(); break;
        case 2: performAction2(); break;
        case 3: performAction3(); break;
        case 4: performAction4(); break;
        case 5: performAction5(); break;
        case 6: performAction6(); break;
        case 7: performAction7(); break;
      }
    }

    leds[0] = CRGB::Blue;
    FastLED.show();
  }

  // When servo isn't moving watchdog is disabled, so no reset needed here
  delay(10);
}
