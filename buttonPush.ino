int onOffState = LOW; // Variable to hold current button state
int numberButtonPushes = 0;

void setup () {
  Serial.begin(9600);
  pinMode(2, INPUT);          // Set pin #2 to accept input
}

void loop () {
  int buttonValue = digitalRead(2);    // Set buttonValue to digital output of pin 2
  
  // If button is pushed    
  if (buttonValue == HIGH) {   
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
    delay(30);
  }
  
  // If button isn't pushed
  if (buttonValue == LOW) {
    //numberButtonPushes++; commented out because as long as button is low will keep incrementing
  }
  
  //onOffState = buttonValue;
  //wait(
}
