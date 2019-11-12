#include <LiquidCrystal.h>
#include <Keypad.h>
const byte filas = 4;
const byte Colunas = 4;
char tecla[filas][Colunas] = {
  {'1','2','3','A'},
  {'4','5','6','+'},
  {'7','8','9','-'},
  {'*','0','=','/'}
};
byte pinFilas[filas] = {7, 6, 5, 4};
byte pinColunas[Colunas] = {3, 2, A5, A4};

Keypad keypad = Keypad( makeKeymap(tecla), pinFilas, pinColunas, filas, Colunas );
LiquidCrystal lcd(8,9,10,11,12,13); //RS,E,D4,D5,D6,D7
String lerString1,lerString2;
byte conta=0;
char a;
long dado1,dado2,rpt1;
double dado3,dado4,rpt2;
void setup(){
  lcd.begin(16,2);
}

void loop(){
  char key = keypad.getKey();
  if (key=='0'||key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'){
    
      if(conta==0){
        lcd.print(key);
        lerString1+=key;
        dado1=lerString1.toInt();
      }
      
      else if(conta==1){
        lcd.print(key);
        lerString2+=key;
        dado2=lerString2.toInt();
      }
   
  }

  if(key=='A'){

      lerString2="";
      lerString1="";
      dado1=0;
      dado2=0;
      dado3=0;
      dado4=0;
      conta=0;
      rpt1=0;
      rpt2=0;
      lcd.clear();
  }
  else if(key=='='&&a=='+'){
    conta++;
    lcd.setCursor(0,2);
    rpt1=dado1+dado2;
    lcd.print("R = ");
    lcd.print(rpt1);
  }

  else if(key=='='&&a=='-'){
    conta++;
    lcd.setCursor(0,2);
    rpt1=dado1-dado2;
    lcd.print("R = ");
    lcd.print(rpt1);
  }
  else if(key=='='&&a=='*'){
    conta++;
    lcd.setCursor(0,2);
    rpt1=dado1*dado2;
    lcd.print("R = ");
    lcd.print(rpt1);
  }
  else if(key=='='&&a=='/'){
    conta++;
    lcd.setCursor(0,2);
    dado3=dado1;
    dado4=dado2;
    lcd.print("R = ");
    rpt2=(dado3/dado4);
    lcd.print(rpt2);
  }

  
  else if((key=='+'||key=='-'||key=='*'||key=='/')&&(conta==0)){
    conta++;
    a=key;
    lcd.print(a);
  }
}
