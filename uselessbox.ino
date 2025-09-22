#include <Servo.h>
#include <FastLED.h>

#define NUM_LEDS 1
#define DATA_PIN 2
CRGB leds[NUM_LEDS];

Servo handServo;

volatile int action = 1;                                                                                  // Use volatile for variables modified in an interrupt service routine
const int frontSwitchPin = 3;
const int handServoPin = 4;


void hitTheSwitch(int speed, int from) {

    // Move servo from 180 to 0, stopping when switch is pressed
    for (int pos = from; pos >= 0; pos -= 1)
    {
      handServo.write(pos);
      delay(speed);
      int switchState = digitalRead(frontSwitchPin);
      Serial.print("Switch state: ");
      Serial.println(switchState);
      if (switchState == LOW)  // Switch pressed (assuming active LOW)
      {
        // Stop movement when switch is pressed
        Serial.println("Switch pressed! Stopping movement.");
        break;
      }
    }
    
}

void detectSwitch()
{
    hitTheSwitch(20, 180);    // speed: 20, from pos: 180
    
    int currentPos = handServo.read();
    Serial.print("Current position: ");
    Serial.println(currentPos);

    Serial.print("BOX started with the switch pointing UP --> restart it with the switch down... ");
}


void setup()
{
  Serial.begin(9600);
  Serial.println("Useless Box v1.1 --> https://github.com/KunstGraveren/uselessbox");
  // 1.0 | init release
  // 1.1 | no end position, reusing interupt switch pin to find the switch

  pinMode(frontSwitchPin, INPUT_PULLUP);                                                                  // Use internal pull-up resistor for the switch

  handServo.attach(handServoPin);
  handServo.write(180);                                                                                   // Set initial position for the hand servo

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);                                                // Assuming WS2812B with GRB ordering
  leds[0] = CRGB::Blue;                                                                                   // Set initial LED color to blue
  FastLED.show();

  attachInterrupt(digitalPinToInterrupt(frontSwitchPin), handleSwitchInterrupt, FALLING);                 // Attach interrupt to the switch pin, ISR will be called when the switch goes from HIGH to LOW (falling edge)

  int switchState = digitalRead(frontSwitchPin);
  Serial.print("Switch state: ");
  Serial.println(switchState);
  // WHEN YELLOW cable is on top
  // LOW (0)  = pointing down, switch is been click off by the servo arm
  // HIGH (1) = pointing up, switch is been manual click by a human.

  if (switchState == HIGH)  // Switch pressed
  {
    detectSwitch();
  }
}


void closeTheBox( int speed ){

  // Move servo back from current position to 180
  int currentPos = handServo.read();
  Serial.print("Moving back to 180 from position: ");
  Serial.println(currentPos);
  
  for (int pos = currentPos; pos <= 180; pos += 1)
  {
    handServo.write(pos);
    delay(speed);
    
    int switchState = digitalRead(frontSwitchPin);
    Serial.print("Switch state: ");
    Serial.println(switchState);
  }
  
}


void loop()
{
  if (action != 0)
  {
    leds[0] = CRGB::Red;                                                                                // Set LED to red while an action is playing
    FastLED.show();

    int switchState = digitalRead(frontSwitchPin);
    if (switchState == HIGH)  // Switch pressed
    {
  
            if (action == 1)
            {
                Serial.println("Action 1: ");
              
                hitTheSwitch(20, 180);    // speed: 20, from pos: 180
                
                closeTheBox(20);          // closing speed: 20

            }
            else if (action == 2)
            {

                Serial.println("Action 2: ");
                delay(2000);
        
                handServo.write(170);                                                                               // Box opens partially
        
                delay(2000);
                        
                hitTheSwitch(40, 170);    // speed: 40, from pos: 170

                delay(500);

                closeTheBox(40);          // closing speed: 40
              
            }
            else if (action == 3)
            {
              
                Serial.println("Action 3: ");
                delay(2000);
        
                 for (int i = 0; i <  5; i++)
                 {
                   for (int j = 180; j >= 165; j--){
                     handServo.write(j);
                     delay(10); // bounce
                   }
                   delay(200);
                 }
        
                hitTheSwitch(30, 165);    // speed: 30, from pos: 165
                delay(400);
                handServo.write(180);     // instance close the box
                    
            }

            else if (action == 4)
            {
              
                Serial.println("Action 4: ");
                delay(2000);
                hitTheSwitch(20, 180);    // speed: 30, from pos: 165
                delay(2000);
                handServo.write(180);     // instance close the box
                
            }

            else if (action == 5)
            {
              
                Serial.println("Action 5: ");
                delay(2000);

                hitTheSwitch(4, 180);    // speed: 4, from pos: 180
        
                delay(2000);
        
                for (int i  = 0; i < 7; i++)
                {
                  handServo.write(75);
                  delay(100);
                  handServo.write(40);
                  delay(100);
                }
                delay(500);
                handServo.write(180);   // instance close the box
                
            }
      
            else if (action == 6)
            { 
  
                Serial.println("Action 6:");
                delay(2000);
                hitTheSwitch(50, 180);    // speed: 50, from pos: 180
                delay(2000);
                handServo.write(180);     // instance close the box
                
            }

            else if (action == 7)
            {
              
              Serial.println("Action 7:");
              delay(2000);
      
              for (int i = 180; i  >= 60; i--)
              {
                handServo.write(i);
                delay(40);
              }
              
              for (int i = 0; i < 3; i++)
              {
                handServo.write(60);
                delay(200);
                handServo.write(40);
                delay(800);
              }
        
              hitTheSwitch(20, 40);    // speed: 20, from pos: 40
              delay(2000);
              handServo.write(180);    // instance close the box
              
            }
 
    }

    action = 0;                                   // Reset action to 0 after completion
    leds[0] = CRGB::Blue;                         // Set LED back to blue after action is done
    FastLED.show();
  }

  delay(10);                                        // Small delay to prevent the loop from running too fast when action is 0
}

void handleSwitchInterrupt() {
   action++;
   if (action > 7) {
     action = 1;
   }
}
