/*
Authors: Mila Grigoryeva & Ikhlas Jenfi
File: Lab 9
Description: Washing machine Arduino
*/

#define SWITCH1 10
#define SWITCH2 11
#define SWITCH3 12

#define RELAY 13

#define MOTOR1 3
#define MOTOR2 5

#define LED 9

#define LED_A 2
#define LED_B 8
#define LED_C 6
#define LED_D A4
#define LED_E 4
#define LED_F A5
#define LED_G 7

#define INTERVAL3000 3000

unsigned long time_1 = 0;

void setup() {
  pinMode(SWITCH1, INPUT);
  pinMode(SWITCH2, INPUT);  
  pinMode(SWITCH3, INPUT);
  pinMode(MOTOR1, OUTPUT);
  pinMode(MOTOR2, OUTPUT);
  pinMode(LED, OUTPUT);

 pinMode(LED_A, OUTPUT);
 pinMode(LED_F, OUTPUT);
 pinMode(LED_E, OUTPUT);
 pinMode(LED_D, OUTPUT);
 pinMode(LED_C, OUTPUT);
 pinMode(LED_G, OUTPUT);
 pinMode(LED_B, OUTPUT);
 digitalWrite(LED_B, HIGH);
 digitalWrite(LED_A, HIGH);
 digitalWrite(LED_F, HIGH);
 digitalWrite(LED_E, HIGH);
 digitalWrite(LED_D, HIGH);
 digitalWrite(LED_C, HIGH);
 digitalWrite(LED_G, HIGH);
       
 Serial.begin(9600);

}

void loop() {
  boolean switchOne = digitalRead(SWITCH1);
  boolean switchTwo = digitalRead(SWITCH2);
  boolean switchThree = digitalRead(SWITCH3);
    if(switchOne == 1) {
    Serial.println("Machine is ON");
    Serial.println("\n");
    digitalWrite(RELAY, LOW);
    Serial.println("2. Washing machine is washing 9s\n");
    analogWrite(MOTOR1, 200);
    delay(9000);
    analogWrite(MOTOR1, 0);
    Serial.println("3. Dirty water is pumped out of the machine for 3s\n");
    analogWrite(MOTOR2, 200);
    delay(3000);
    switchThree = 1;
    switchTwo = 0;
    analogWrite(MOTOR2, 0);
    Serial.println("4. Washing machine takes water for 3s\n");
    digitalWrite(RELAY, HIGH);
    delay(3000);
    switchTwo = 1;
    Serial.println("5. Washing machine is rinsing for 5s\n");
    analogWrite(MOTOR1, 200);
    delay(5000);
    analogWrite(MOTOR1, 0);
    Serial.println("6. Rinsing water is pumped out of the machine for 3s\n");
    analogWrite(MOTOR2, 200);
    delay(3000);
    switchTwo = 0;
    analogWrite(MOTOR2, 0);
    Serial.println("7. Water machine is centrifuging for 5s\n");
    analogWrite(MOTOR1, 200);
    delay(5000);
    analogWrite(MOTOR1, 0);
    Serial.println("8. LED is blinking when the washing program is finished");
    blinkLED();     
  }
  
  if(switchOne == 0) {
    Serial.println("Machine iS OFF");
    Serial.println("\n");
  }
}

void blinkLED(){
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);    
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}

void blink0(){
        //light 0
        digitalWrite(LED_A, LOW);
        digitalWrite(LED_B, LOW);
        digitalWrite(LED_C, LOW);
        digitalWrite(LED_D, LOW);
        digitalWrite(LED_E, LOW);
        digitalWrite(LED_F, LOW);
        delay(500);
        digitalWrite(LED_A, HIGH);
        digitalWrite(LED_B, HIGH);
        digitalWrite(LED_C, HIGH);
        digitalWrite(LED_D, HIGH);
        digitalWrite(LED_E, HIGH);
        digitalWrite(LED_F, HIGH);
        delay(500);
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
void blink6(){
        //light 6
        digitalWrite(LED_A, LOW);
        digitalWrite(LED_F, LOW);
        digitalWrite(LED_E, LOW);
        digitalWrite(LED_D, LOW);
        digitalWrite(LED_C, LOW);
        digitalWrite(LED_G, LOW);
        delay(500);
        digitalWrite(LED_A, HIGH);
        digitalWrite(LED_F, HIGH);
        digitalWrite(LED_E, HIGH);
        digitalWrite(LED_D, HIGH);
        digitalWrite(LED_C, HIGH);
        digitalWrite(LED_G, HIGH);
        delay(500);
}
void blink7(){
        //light 7
        digitalWrite(LED_A, LOW);
        digitalWrite(LED_B, LOW);
        digitalWrite(LED_C, LOW);
        delay(500);
        digitalWrite(LED_A, HIGH);
        digitalWrite(LED_B, HIGH);
        digitalWrite(LED_C, HIGH);
        delay(500);
}
void blink8(){
        //light 8
        digitalWrite(LED_A, LOW);
        digitalWrite(LED_B, LOW);
        digitalWrite(LED_C, LOW);
        digitalWrite(LED_D, LOW);
        digitalWrite(LED_E, LOW);
        digitalWrite(LED_F, LOW);
        digitalWrite(LED_G, LOW);
        delay(500);
        digitalWrite(LED_A, HIGH);
        digitalWrite(LED_B, HIGH);
        digitalWrite(LED_C, HIGH);
        digitalWrite(LED_D, HIGH);
        digitalWrite(LED_E, HIGH);
        digitalWrite(LED_F, HIGH);
        digitalWrite(LED_G, HIGH);
        delay(500);
}
void blink9(){
        //light 9
        digitalWrite(LED_A, LOW);
        digitalWrite(LED_B, LOW);
        digitalWrite(LED_C, LOW);
        digitalWrite(LED_G, LOW);
        digitalWrite(LED_F, LOW);
        delay(500);
        digitalWrite(LED_A, HIGH);
        digitalWrite(LED_B, HIGH);
        digitalWrite(LED_C, HIGH);
        digitalWrite(LED_G, HIGH);
        digitalWrite(LED_F, HIGH);
        delay(500);
}
