#define anahtar 12
const byte interruptPin = 2;
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
  pinMode (interruptPin, INPUT_PULLUP); //Set digi pin 11 as pull up button
  pinMode (13, OUTPUT);
  pinMode(led,OUTPUT);
  attachInterrupt(interruptPin, sens, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
anahtardurum = digitalRead(anahtar);

 if(anahtardurum == HIGH){

    son = millis();
  if (son - ilk <= 1000){
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
 button_state = digitalRead(interruptPin);

  delay(25);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  delay(25);

    //delay(50);
  if(button_press_count >= 3){
      digitalWrite(led,HIGH); 
  }
}

 }
else if(anahtardurum == LOW){
  digitalWrite(led,LOW);
  ilk = son;
}
 }
 void sens() {

      button_press_count++;

    } 
