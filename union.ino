#define anahtar 12
#define button_pin 11
int motor2pin1 = 4;
int motor2pin2 = 5;
unsigned long ilk = 0;
unsigned long son;
int anahtardurum = 0;
int button_press_count = 0;
int button_state = 0;
int prev_button_state = 0;
int led = 8;


void setup() {
  // put your setup code here, to run once:
 delay(100);
  Serial.begin(9600);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(anahtar, INPUT);
  pinMode (button_pin, INPUT_PULLUP); //Set digi pin 11 as pull up button
  pinMode (13, OUTPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
anahtardurum = digitalRead(anahtar);
button_state = digitalRead(button_pin);
 if(anahtardurum == HIGH){
    son = millis();
  if (son - ilk <= 1000){
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
 

  delay(25);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
      if (button_state != prev_button_state) {
       if (button_state == HIGH) {
      digitalWrite(13, HIGH);
      button_press_count++;
      Serial.println(button_press_count); 
    } else { 
      digitalWrite(13, LOW);
    }
       if(button_press_count >= 3){
      digitalWrite(led,HIGH);
    }
    
       }
  delay(25);
prev_button_state = button_state;

    //delay(50);
   
}
 }
else if(anahtardurum == LOW){
  digitalWrite(led,LOW);
  ilk = son;
}
 }
