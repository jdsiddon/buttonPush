int onOffState = LOW; // Variable to hold current button state
int numberButtonPushes = 0;
int lastButtonState = LOW; // The previous reading from the input pin
int buttonState;

// Debounce variables
long lastDebounceTime = 0;
long debounceDelay = 50; 


void setup () {
  Serial.begin(9600);
  pinMode(2, INPUT);          // Set pin #2 to accept input
}

void loop () {
  int reading = digitalRead(2);    // Set buttonValue to digital output of pin 2
  
  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        numberButtonPushes++;  
    
        // If numberButtonPushes divided by 2 has a remainder not equal to 0 and onOffState is equal to LOW.
        if(numberButtonPushes % 2 != 0 && onOffState == LOW) {     
          Serial.println(" On");
          onOffState = HIGH;
        }
    
        // If the number of button pushes divided by two has a remainder equal to 1 and noOffState is equal to LOW. 
        if (numberButtonPushes % 2 == 0 && onOffState == HIGH) {    
          Serial.println(" Off");
          onOffState = LOW;  
        }
      }
    }
  }
  
  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading; 
}
