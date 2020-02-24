#include <LiquidCrystal.h>
int playerScore = 0;
int dealerScore = 0;

int playerCard; // The card that the player draws from the deck
int dealerCard; // The card that the dealer draws from the deck

int playerSum = 0;
int dealerSum = 0;

int playerSwitch = 2; // The switch for determining if the player stands or continues the game

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(playerSwitch, INPUT);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  int playerStand = digitalRead(playerSwitch);
    
  int playerDeck[]={1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10};
  int dealerDeck[] = {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10};
  const int deckSize = sizeof playerDeck / sizeof playerDeck[0];

  for (int i=0; i < deckSize; i++) {
   int number1 = random(0, deckSize);  // Integer from 0 to questionCount-1
   int temp = playerDeck[number1];
   playerDeck[number1] =  playerDeck[i];
   playerDeck[i] = card1;

   int number2 = random(0, deckSize);  // Integer from 0 to questionCount-1
   int temp2 = dealerDeck[number2];
   dealerDeck[number2] =  dealerDeck[i];
   dealerDeck[i] = card2;
    
  
   playerCard = card1;
   dealerCard = card2;
   lcd.print("player: ");
   lcd.print(playerSum);
   lcd.setCursor(0, 1);
   lcd.print("dealer: ");
   lcd.print(dealerSum);
   delay(1000);
   lcd.clear();
   playerSum = playerSum + playerCard;
   dealerSum = dealerSum + dealerCard;
   delay(1000);
   lcd.print("To take a stand");
   lcd.setCursor(0, 1);
   lcd.print("use the switch");
   delay(1000);
   if (playerStand == LOW) {
    lcd.clear();
    if (playerSum > 21 && (dealerSum > 17 && dealerSum < 21)) {
      lcd.print("Game over");
      break;
      }
    if (playerSum == 21) {
      lcd.print("Player wins!");
      }
    }
   if (playerStand == HIGH) {
    while(true){
      lcd.clear();
      if (playerSum > dealerSum && playerSum < 21){
      lcd.print("game over");
      lcd.setCursor(0, 1);
      lcd.print("the player won");
      delay(1000);
      }
      if (dealerSum > playerSum && dealerSum < 21) {
        lcd.print("game over");
        lcd.setCursor(0, 1);
        lcd.print("the dealer won");
        delay(1000);
        }
     }
    }
 }
}
