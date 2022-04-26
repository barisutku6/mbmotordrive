#define button_pin 11
int button_press_count = 0;
int button_state = 0;
int prev_button_state = 0;
int led = 8;
void setup() {
  // put your setup code here, to run once:
delay(100);
  Serial.begin(9600);
  pinMode (button_pin, INPUT_PULLUP); //Set digi pin 11 as pull up button
  pinMode (13, OUTPUT);
   pinMode(led,OUTPUT);
   Serial.println("Button Count:");
}

void loop() {
  // put your main code here, to run repeatedly:

   button_state = digitalRead(button_pin);
     if (button_state != prev_button_state) {
   if (button_state == HIGH) {
      digitalWrite(13, LOW);
    } else { //button press
      digitalWrite(13, HIGH);
      button_press_count++;
      Serial.println(button_press_count); //print the count
    }
   if((button_press_count >= 3) && button_press_count < 12){
      digitalWrite(led,HIGH);
    }
   else if (button_press_count >= 12){
      button_press_count = 0;
      digitalWrite(led,LOW);
   }
    //delay(50);
  }
  prev_button_state = button_state;
}
