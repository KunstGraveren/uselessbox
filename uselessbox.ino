#include <Servo.h>
#include <FastLED.h>

#define NUM_LEDS 1
#define DATA_PIN 2
CRGB leds[NUM_LEDS];

Servo handServo;

volatile int action = 1;                                                                                  // Use volatile for variables modified in an interrupt service routine
const int frontSwitchPin = 3;
const int handServoPin = 4;

void setup()
{
  Serial.begin(9600);

  pinMode(frontSwitchPin, INPUT_PULLUP);                                                                  // Use internal pull-up resistor for the switch

  handServo.attach(handServoPin);
  handServo.write(180);                                                                                   // Set initial position for the hand servo

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);                                                // Assuming WS2812B with GRB ordering
  leds[0] = CRGB::Blue;                                                                                   // Set initial LED color to blue
  FastLED.show();

  attachInterrupt(digitalPinToInterrupt(frontSwitchPin), handleSwitchInterrupt, FALLING);                 // Attach interrupt to the switch pin, ISR will be called when the switch goes from HIGH to LOW (falling edge)
}

void loop()
{
  // The main loop can now focus on executing the actions based on the 'action' variable
  // The switch press will change 'action' via the interrupt

    if (action != 0)                                                                                      // Only execute an action if action is not 0
    {
      leds[0] = CRGB::Red;                                                                                // Set LED to red while an action is playing
      FastLED.show();
    
      // Box opens, hand moves down, hand wiggles, hand goes up, box closes");
      if (action == 1)
      {
        Serial.println("Action 1: ");
        delay(2000);
        for (int i = 180; i >= 35; i--)
        {
          handServo.write(i);
          delay(20);
        }
        delay(1000);
        handServo.write(26);
        delay(200);
        for (int i = 26; i <=180;  i++)
        {
          handServo.write(i);
          delay(20);
        }
      }

      // Box opens partially, waits, box opens fully, hand moves down, waits, hand wiggles, hand goes up, box closes, waits, box opens partially, waits, box closes");
      else if (action == 2)
      {
        Serial.println("Action 2: ");
        delay(2000);

        handServo.write(170);                                                                               // Box opens partially

        delay(2000);

        for (int i = 170; i >=35; i--)
        {
          handServo.write(i);
          delay(40);
        }

        delay(500);

        handServo.write(26);

        delay(200);

        for (int i = 26; i <=180; i++)
        {
          handServo.write(i);
          delay(40);
        }
      }
      
      // Box opens, waits, box jitters multiple times, hand moves down, hand wiggles, hand goes up, box closes, waits, box opens, waits, box closes");
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

        for  (int i = 165; i >= 35; i--)
        {
          handServo.write(i);
          delay(30);
        }
        handServo.write(26);
        delay(400);
        handServo.write(180);
      }

      // Box opens, hand moves down, waits, hand wiggles, box closes");
      else if (action == 4)
      {
        Serial.println("Action 4: ");
        delay(2000);

        for (int i = 180; i >= 35; i--)
        {
          handServo.write(i);
          delay(20);
        }
        delay(2000);
        handServo.write(26);
        delay(200);
        handServo.write(180);
      }

      // Box opens, hand moves down, waits, hand wiggles multiple times, waits, hand goes up, waits, box closes");
      else if (action == 5)
      {
        Serial.println("Action 5: ");
        delay(2000);

        // slow down openning
        for (int i = 180; i >= 26; i--)
        {
          handServo.write(i);
          delay(4);
        }

        delay(2000);

        for (int i  = 0; i < 7; i++)
        {
          handServo.write(75);
          delay(100);
          handServo.write(40);
          delay(100);
        }
        delay(500);
        handServo.write(180);
      }

      // Box opens slowly, waits, hand moves down slowly, waits, hand wiggles, hand goes up, box closes");
      else if (action == 6)
      { 
        Serial.println("Action 6:");
        delay(2000);
        for (int i = 180; i  >= 26; i--)
        {
          handServo.write(i);
          delay(50);
        }
        delay(2000);
        handServo.write(26);
        delay(200);
        handServo.write(180);
      }

      // Box opens, waits, hand moves down to a certain point, hand wiggles multiple times, hand moves down fully, waits, hand goes up, waits, box closes");
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
        handServo.write(26);
        delay(2000);
        handServo.write(180);
      }

      action = 0;                                   // Reset action to 0 after completion
      leds[0] = CRGB::Blue;                         // Set LED back to blue after action is done
      FastLED.show();
    }

  delay(10);                                        // Small delay to prevent the loop from running too fast when action is 0
}

void handleSwitchInterrupt() {
  
   action++;                                        // Increment the action variable when the switch is pressed
   
   if (action > 7) {                                // Wrap around to action 1 after action 7
     action = 1;
   }

}
