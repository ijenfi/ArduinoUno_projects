/*
 Authors: Mila Grigoryeva & Ikhlas Jenfi
 File: Lab 11 code
 Description: Morse code transmitter & receiver with 7-segment display
 */
#define LED_A 2
#define LED_B 8
#define LED_C 6
#define LED_D 5
#define LED_E 4
#define LED_F 3
#define LED_G 9

const int led = 7;
const int ldr = A0;
volatile int numberOfDashes = 0;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);

  pinMode(LED_A, OUTPUT);
  pinMode(LED_F, OUTPUT);
  pinMode(LED_E, OUTPUT);
  pinMode(LED_D, OUTPUT);
  pinMode(LED_C, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  digitalWrite(LED_A, HIGH);
  digitalWrite(LED_F, HIGH);
  digitalWrite(LED_E, HIGH);
  digitalWrite(LED_D, HIGH);
  digitalWrite(LED_C, HIGH);
  digitalWrite(LED_G, HIGH);
  digitalWrite(LED_B, HIGH);
}

void loop() {
  // randomly choose which number to transmit
  int number = random(1, 4);
  
  if(number == 1) {
    numberOne();
  }
  else if(number == 2) {
    numberTwo();
  }
  else if(number == 3) {
    numberThree();
  }
  else {
    numberFour();
  }

  if(numberOfDashes == 4) {
    blink1();
  }
  if(numberOfDashes == 3) {
    blink2();
  }  
  if(numberOfDashes == 2) {
    blink3();
  }
  if(numberOfDashes == 1) {
    blink4();
  }
  numberOfDashes = 0;
  
  delay(5000); 
}

void readLdr() {
  int ldr_value = analogRead(ldr);
  if(ldr_value < 200) {
    numberOfDashes = numberOfDashes + 1;
  }  
}

void morseDot() {
  Serial.println("Dot");
  readLdr();
  digitalWrite(led, HIGH);
  delay(250);
  //readLdr();
  digitalWrite(led, LOW);
  delay(250);
}

void morseDash() {
  Serial.println("Dash");
  //readLdr();
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  readLdr();
  delay(1000);
}

void numberOne() {
  morseDot();
  morseDash();
  morseDash();
  morseDash();
  morseDash();
}

void numberTwo() {
  morseDot();
  morseDot();
  morseDash();
  morseDash();
  morseDash();
}

void numberThree() {
  morseDot();
  morseDot();
  morseDot();
  morseDash();
  morseDash();
}

void numberFour() {
  morseDot();
  morseDot();
  morseDot();
  morseDot();
  morseDash();
}


void blink1(){
        //light 1
        digitalWrite(LED_B, LOW);
        digitalWrite(LED_C, LOW);
        delay(500);
        digitalWrite(LED_B, HIGH);
        digitalWrite(LED_C, HIGH);
        delay(500);
}
void blink2(){
        //light 2
        digitalWrite(LED_A, LOW);
        digitalWrite(LED_B, LOW);
        digitalWrite(LED_G, LOW);
        digitalWrite(LED_E, LOW);
        digitalWrite(LED_D, LOW);
        delay(500);
        digitalWrite(LED_A, HIGH);
        digitalWrite(LED_B, HIGH);
        digitalWrite(LED_G, HIGH);
        digitalWrite(LED_E, HIGH);
        digitalWrite(LED_D, HIGH);
        delay(500);
}
void blink3(){
        //light 3
        digitalWrite(LED_A, LOW);//a
        digitalWrite(LED_B, LOW);//b
        digitalWrite(LED_G, LOW);//g
        digitalWrite(LED_C, LOW);//c
        digitalWrite(LED_D, LOW);//d
        delay(500);
        digitalWrite(LED_A, HIGH);//a
        digitalWrite(LED_B, HIGH);//b
        digitalWrite(LED_G, HIGH);//g
        digitalWrite(LED_C, HIGH);//c
        digitalWrite(LED_D, HIGH);//d
        delay(500);
}
void blink4(){
        //light 4
        digitalWrite(LED_F, LOW);
        digitalWrite(LED_G, LOW);
        digitalWrite(LED_B, LOW);
        digitalWrite(LED_C, LOW);
        delay(500);
        digitalWrite(LED_F, HIGH);
        digitalWrite(LED_G, HIGH);
        digitalWrite(LED_B, HIGH);
        digitalWrite(LED_C, HIGH);
        delay(500);
}
void blink5(){
        // light 5
        digitalWrite(LED_A, LOW);
        digitalWrite(LED_F, LOW);
        digitalWrite(LED_G, LOW);
        digitalWrite(LED_C, LOW);
        digitalWrite(LED_D, LOW);
        delay(500);
        digitalWrite(LED_A, HIGH);
        digitalWrite(LED_F, HIGH);
        digitalWrite(LED_G, HIGH);
        digitalWrite(LED_C, HIGH);
        digitalWrite(LED_D, HIGH);
        delay(500);
}
