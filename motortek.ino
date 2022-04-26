#define buttonumuz 12
int motor2pin1 = 4;
int motor2pin2 = 5;
unsigned long ilk = 0;
unsigned long son;
int buttondurum = 0;

void setup() {
  // put your setup code here, to run once:
 delay(100);
  Serial.begin(9600);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
    pinMode(buttonumuz, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
buttondurum = digitalRead(buttonumuz);
 if(buttondurum == HIGH){
    son = millis();
  if (son - ilk <= 155000){
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(100);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(100);
}
 }
else if(buttondurum == LOW){
  
  ilk = son;
}
 }
