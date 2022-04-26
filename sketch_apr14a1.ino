#define button_pin 11
#define buttonumuz 12

// variables will change:
int button_press_count = 0;
int button_state = 0;
int prev_button_state = 0;
int motor2pin1 = 4;
int motor2pin2 = 5;
int led = 8;
unsigned long ilk = 0;
unsigned long son;
int buttondurum = 0;



void setup() {
// put your setup code here, to run once:
  delay(100);
  Serial.begin(9600);
  pinMode (button_pin, INPUT_PULLUP); //Set digi pin 11 as pull up button
  pinMode (13, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(buttonumuz, INPUT);

  Serial.println("Button Count:");
}

void loop() {
  // put your main code here, to run repeatedly:
  buttondurum = digitalRead(buttonumuz);
  button_state = digitalRead(button_pin);
  
  //for (int i = 0; i <= 125; i++) {
  if(buttondurum == HIGH){
    son = millis();
  if (son - ilk <= 3000){
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(100);

  //digitalWrite(motor1pin1, LOW);
  //digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(100);
  if (button_state != prev_button_state) {
   if (button_state == HIGH) {
      digitalWrite(13, LOW);
    } else { //button press
      digitalWrite(13, HIGH);
      button_press_count++;
      Serial.println(button_press_count); //print the count
    }
   if(button_press_count >= 3){
      digitalWrite(led,HIGH);
    }

    //delay(50);
  }
  prev_button_state = button_state;
  }
  //}
  
  
  /*if (button_state != prev_button_state) {
    if (button_state == HIGH) {
      digitalWrite(13, LOW);
    } else { //button press
      digitalWrite(13, HIGH);
      button_press_count++;
      Serial.println(button_press_count); //print the count
    }
    if(button_press_count >= 10){
      digitalWrite(led,HIGH);
    }
    delay(50);
  }
  prev_button_state = button_state;*/
  //}
}
else if(buttondurum == LOW){
  
  ilk = son;
  button_press_count = 0;
  if(button_press_count < 3){
    digitalWrite(led,LOW);
  }
}

/*else {
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  button_press_count = 0;
}*/
}
