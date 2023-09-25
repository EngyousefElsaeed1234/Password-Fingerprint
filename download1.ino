#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#define pb1 10
#define pb2 11
#define pb3 12
#define pb4 13
#define pb5 A0
#define pb6 A1

LiquidCrystal_I2C lcd(39,16,2);
const byte row = 4;
const byte col = 4; 

char Keys[row][col] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[row] = {2, 3, 4, 5};
byte colPins[col] = {6, 7, 8, 9};

Keypad myKey (makeKeymap(Keys),rowPins,colPins,row,col);
char truePass[]={'1','2','3','4'};
char pass[sizeof(truePass)]={0};
byte counter = 0;
byte i = 0;
bool reading;
void reset(){
 lcd.home();
 lcd.clear();
 lcd.print("Enter password : ");
 lcd.setCursor(0,1);
}

void setup() {
  pinMode(10,OUTPUT);
  pinMode(pb1, INPUT_PULLUP);
  pinMode(pb2, INPUT_PULLUP);
  pinMode(pb3, INPUT_PULLUP);
  pinMode(pb4, INPUT_PULLUP);
  pinMode(pb5, INPUT_PULLUP);
  pinMode(pb6, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  reset();
}
void loop() {
  char key = myKey.getKey();
  while(!key)key=myKey.getKey();
  lcd.print("*");
  if(key == 'D'){
    lcd.clear();  
    lcd.home();
    for(i=0;i<sizeof(pass);i++)
    {
     if(truePass[i]!=pass[i])break;
    }
  if((i==sizeof(pass))&&(counter==0)){
  counter=-1;
  lcd.clear();
  lcd.home();
  lcd.print("User authorized");
  delay(2000);
  lcd.setCursor(0, 0);
  lcd.print("Enter ur finger");
  for(byte i = 1;i<=10000;i++){
    if(!digitalRead(pb1)){
    lcd.clear();
    lcd.home();
    lcd.print("The ID is : 1");
    delay(2000);
    reset();
    break;
  }
  else if(!digitalRead(pb2)){
    lcd.clear();
    lcd.home();
    lcd.print("The ID is : 2");
    delay(2000);
    reset();
    break;
  }
  else if(!digitalRead(pb3)){
    lcd.clear();
    lcd.home();
    lcd.print("The ID is : 3");
    delay(2000);
    reset();
    break;
  }
  else if(!digitalRead(pb4)){
    lcd.clear();
    lcd.home();
    lcd.print("The ID is : 4");
    delay(2000);
    reset();
    break;
  }
  else if(!digitalRead(pb5)){
    lcd.clear();
    lcd.home();
    lcd.print("The ID is : 5");
    delay(2000);
    reset();
    break;
  }
  else if(!digitalRead(pb6)){
    lcd.clear();
    lcd.home();
    lcd.print("The ID is : 6");
    delay(2000);
    reset();
    break;
  }
    delay(1);
  }
  }
  else {
  counter=-1;
  lcd.clear();
  lcd.home();
  lcd.print("Wrong password");
  delay(2000);
  reset();
  }
  }
  else
    *(pass+counter)=key;
 counter=(counter>=3)?-1:counter;
 counter++; 
}