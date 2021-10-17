#include <SoftwareSerial.h>
// *** SPFD5408 change -- Begin
#include <SPFD5408_Adafruit_GFX.h> // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include <SPFD5408_TouchScreen.h>

#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_RS A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

#define YP A1
#define XM A2
#define YM 8   
#define XP 9


#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_RS, LCD_WR, LCD_RD, LCD_RESET);
TouchScreen tf(XP, LCD_RS, LCD_CS, YM, 300);

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

int menu = 1;
int views = 0;


// pins

int vibrate_1 = 44;
int vibrate_2 = 45;
int vibrate_3 = 46;


int Value_1 = 0;
int Value_2 = 0;
int Value_3 = 0;
int Value_4 = 0;
int Value_5 = 0;
int Value_6 = 0;
int Value_7 = 0;
int Value_8 = 0;


int Button_1_plus = 30;
int Button_2_plus = 31;

int Button_1_n = 32;
int Button_2_n = 33;

int Button_inf = 34;

int Button_menu1 = 35;
int Button_menu0 = 36;

String txt0 = "";
char cha0;

String txt1 = "";
char cha1;

String txt2 = "";
char cha2;

String txt3 = "";
char cha3;

int b = -1;
String txt = "";

//*********** TEC
boolean termos1 = false;
boolean termos2 = false;
boolean termos3 = false;
boolean termos4 = false;
boolean termos5 = false;

int sec1 = 25;
int sec2 = 25;
int sec3 = 25;
int sec4 = 25;
int sec5 = 25;

int lm1 = 0;
int lm2 = 0;
int lm3 = 0;
int lm4 = 0;
int lm5 = 0;


void ser() {
  Serial.println(txt);
    Serial1.println(txt);
  txt0 = "";
  txt = "";
  txt1 = "";
}
void ser1() {
  Serial.println(txt);
  Serial1.println(txt);
  txt0 = "";
  txt = "";
  txt1 = "";
}
void ser2() {
  Serial.println(txt2);
  txt2 = "";
}
void ser3() {
  Serial.println(txt3);
  txt3 = "";
}
void sev(){
   txt0 = "";
  txt = "";
  txt1 = "";
}

void setup(void) {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial1.println("HELLO...");
    Serial.println("HELLO...");

  Serial2.begin(2400);
  Serial3.begin(9600);

  //tft.reset();
  tft.begin(0x9341); // SDFP540
  tft.fillScreen(WHITE);
  tft.setRotation(3);
  list();
  delay(2000);

  pinMode(vibrate_1, OUTPUT);
  pinMode(vibrate_2, OUTPUT);
  pinMode(vibrate_3, OUTPUT);

  pinMode(Button_1_plus, INPUT);
  pinMode(Button_2_plus, INPUT);


  pinMode(Button_1_n, INPUT);
  pinMode(Button_2_n, INPUT);

  pinMode(Button_inf, INPUT);
  pinMode(Button_menu1, INPUT);
  pinMode(Button_menu0, INPUT);


  Serial2.print("Value_1 = ");
  Serial2.println(0);
  Serial2.print("Value_2 = ");
  Serial2.println(0);
  Serial2.print("Value_3 = ");
  Serial2.println(0);
  Serial2.print("Value_4 = ");
  Serial2.println(0);
  Serial2.print("Value_5 = ");
  Serial2.println(0);



}


void loop(void) {



  if (digitalRead(Button_inf) == 1)
  {
    if (menu <= 4)
    {


      if (views == 0) {
        tft.fillScreen(WHITE);
        inf_menu();
        views = 1;
      }
      else
      {
        tft.fillScreen(WHITE);
        list();
        views = 0;
      }
    }
    if (menu >= 5)
    {
      if (views == 0) {
        tft.fillScreen(WHITE);
        inf_tec();
        views = 1;
      }
      else
      {
        tft.fillScreen(WHITE);
        tec();
        views = 0;
      }
    }
  }

  if (digitalRead(Button_menu1) == 1) {
    if (menu >= 7) {
      menu = 7;
    }
    else {
      menu += 1;
    }
    tft.fillScreen(WHITE);
    if (menu <= 4)
    {
      list();
    }
    if (menu >= 5)
    {
      tec();
    }
  }
  if (digitalRead(Button_menu0) == 1) {
    if (menu <= 1) {
      menu = 1;
    }
    else {
      menu -= 1;
    }
    tft.fillScreen(WHITE);
    if (menu <= 4)
    {
      list();
    }
    if (menu >= 5)
    {
      tec();
    }
  }



  //----------------- pins
  if (digitalRead(Button_1_plus) == 1)
  {
    if (menu == 1)
    {
      if (Value_1 >= 238) {
        Value_1 = 238;
      }
      else
      {
        Value_1 += 17;
      }
      analogWrite(vibrate_1, Value_1);
    }
    if (menu == 2)
    {
      if (Value_3 >= 238) {
        Value_3 = 238;
      }
      else
      {
        Value_3 += 17;
      }
      analogWrite(vibrate_3, Value_3);

    }
    if (menu == 3)
    {
      if (Value_5 >= 238) {
        Value_5 = 238;
      }
      else
      {
        Value_5 += 17;
      }
      Serial2.print("Value_2 = ");
      Serial2.println(Value_5);
    }
    if (menu == 4)
    {
      if (Value_7 >= 238) {
        Value_7 = 238;
      }
      else
      {
        Value_7 += 17;
      }
      Serial2.print("Value_4 = ");
      Serial2.println(Value_7);
    }
    if (menu == 5)
    {
      if (sec1 >= 70) {
        sec1 = 70;
      }
      else
      {
        sec1 += 1;
      }
      Serial3.print("sec1 = ");
      Serial3.println(sec1);
    }
    if (menu == 6)
    {
      if (sec3 >= 70) {
        sec3 = 70;
      }
      else
      {
        sec3 += 1;
      }
      Serial3.print("sec3 = ");
      Serial3.println(sec3);
    }
    if (menu == 7)
    {
      if (sec5 >= 70) {
        sec5 = 70;
      }
      else
      {
        sec5 += 1;
      }
      Serial3.print("sec5 = ");
      Serial3.println(sec5);
    }



    tft.fillScreen(WHITE);
    if (menu <= 4)
    {
      list();
    }
    if (menu >= 5)
    {
      tec();
    }
  }
  if (digitalRead(Button_2_plus) == 1)
  {
    if (menu == 1)
    {
      if (Value_2 >= 238) {
        Value_2 = 238;
      }
      else
      {
        Value_2 += 17;
      }
      analogWrite(vibrate_2, Value_2);
    }
    if (menu == 2)
    {
      if (Value_4 >= 238) {
        Value_4 = 238;
      }
      else
      {
        Value_4 += 17;
      }
      Serial2.print("Value_1 = ");
      Serial2.println(Value_4);
    }
    if (menu == 3)
    {
      if (Value_6 >= 238) {
        Value_6 = 238;
      }
      else
      {
        Value_6 += 17;
      }
      Serial2.print("Value_3 = ");
      Serial2.println(Value_6);
    }
    if (menu == 4)
    {
      if (Value_8 >= 238) {
        Value_8 = 238;
      }
      else
      {
        Value_8 += 17;
      }
      Serial2.print("Value_5 = ");
      Serial2.println(Value_8);
    }
    if (menu == 5)
    {
      if (sec2 >= 70) {
        sec2 = 70;
      }
      else
      {
        sec2 += 1;
      }
      Serial3.print("sec2 = ");
      Serial3.println(sec2);
    }
    if (menu == 6)
    {
      if (sec4 >= 70) {
        sec4 = 70;
      }
      else
      {
        sec4 += 1;
      }
      Serial3.print("sec4 = ");
      Serial3.println(sec4);
    }

    tft.fillScreen(WHITE);
    if (menu <= 4)
    {
      list();
    }
    if (menu >= 5)
    {
      tec();
    }

  }
  if (digitalRead(Button_1_n) == 1)
  {
    if (menu == 1)
    {
      if (Value_1 <= 0) {
        Value_1 = 0;
      }
      else
      {
        Value_1 -= 17;
      }
      analogWrite(vibrate_1, Value_1);
    }
    if (menu == 2)
    {
      if (Value_3 <= 0) {
        Value_3 = 0;
      }
      else
      {
        Value_3 -= 17;
      }
      analogWrite(vibrate_3, Value_3);
    }
    if (menu == 3)
    {
      if (Value_5 <= 0) {
        Value_5 = 0;
      }
      else
      {
        Value_5 -= 17;
      }
      Serial2.print("Value_2 = ");
      Serial2.println(Value_5);
    }
    if (menu == 4)
    {
      if (Value_7 <= 0) {
        Value_7 = 0;
      }
      else
      {
        Value_7 -= 17;
      }
      Serial2.print("Value_4 = ");
      Serial2.println(Value_7);
    }
    if (menu == 5)
    {
      if (sec1 <= -10) {
        sec1 = -10;
      }
      else
      {
        sec1 -= 1;
      }
      Serial3.print("sec1 = ");
      Serial3.println(sec1);
    }
    if (menu == 6)
    {
      if (sec3 <= -10) {
        sec3 = -10;
      }
      else
      {
        sec3 -= 1;
      }
      Serial3.print("sec3 = ");
      Serial3.println(sec3);
    }
    if (menu == 7)
    {
      if (sec5 <= -10) {
        sec5 = -10;
      }
      else
      {
        sec5 -= 1;
      }
      Serial3.print("sec5 = ");
      Serial3.println(sec5);
    }

    tft.fillScreen(WHITE);
    if (menu <= 4)
    {
      list();
    }
    if (menu >= 5)
    {
      tec();
    }
  }
  if (digitalRead(Button_2_n) == 1)
  {
    if (menu == 1)
    {
      if (Value_2 <= 0) {
        Value_2 = 0;
      }
      else
      {
        Value_2 -= 17;
      }
      analogWrite(vibrate_2, Value_2);
    }
    if (menu == 2)
    {
      if (Value_4 <= 0) {
        Value_4 = 0;
      }
      else
      {
        Value_4 -= 17;
      }
      Serial2.print("Value_1 = ");
      Serial2.println(Value_4);
    }
    if (menu == 3)
    {
      if (Value_6 <= 0) {
        Value_6 = 0;
      }
      else
      {
        Value_6 -= 17;
      }
      Serial2.print("Value_3 = ");
      Serial2.println(Value_6);
    }
    if (menu == 4)
    {
      if (Value_8 <= 0) {
        Value_8 = 0;
      }
      else
      {
        Value_8 -= 17;
      }
      Serial2.print("Value_5 = ");
      Serial2.println(Value_8);
    }
    if (menu == 5)
    {
      if (sec2 <= -10) {
        sec2 = -10;
      }
      else
      {
        sec2 -= 1;
      }
      Serial3.print("sec2 = ");
      Serial3.println(sec2);
    }
    if (menu == 6)
    {
      if (sec4 <= -10) {
        sec4 = -10;
      }
      else
      {
        sec4 -= 1;
      }
      Serial3.print("sec4 = ");
      Serial3.println(sec4);
    }
    tft.fillScreen(WHITE);
    if (menu <= 4)
    {
      list();
    }
    if (menu >= 5)
    {
      tec();
    }
  }






  //---------------------Serial------------------
  while (Serial.available() > 0)
  {
    cha0 = Serial.read();
    b = cha0;
    txt0 += cha0;
    delay(5);
  }
  while (Serial1.available() > 0)
  {
    cha1 = Serial1.read();
    b = cha1;
    txt1 += cha1;
   Serial.print(txt1);
    delay(5);
  }
  while (Serial3.available() > 0)
  {
    cha3 = Serial3.read();
    txt3 += cha3;
    delay(5);
  }
  if (b > 1)
  {
    if (txt0.length() > 1)
    {
      txt = txt0;
    }
    if (txt1.length() > 1)
    {
      txt = txt1;
    }
  }



  if (txt.indexOf("vibrate 1 +") != -1)
  {
    ser();
    if (Value_1 >= 238) {
      Value_1 = 238;
    }
    else
    {
      Value_1 += 17;
    }
    analogWrite(vibrate_1, Value_1);
    tft.fillScreen(WHITE);
    list();
  }
  if (txt.indexOf("vibrate 2 +") != -1)
  {
    ser();
    if (Value_2 >= 238) {
      Value_2 = 238;
    }
    else
    {
      Value_2 += 17;
    }
    analogWrite(vibrate_2, Value_2);
    tft.fillScreen(WHITE);
    list();
  }
  if (txt.indexOf("vibrate 3 +") != -1)
  {
    ser();
    if (Value_3 >= 238) {
      Value_3 = 238;
    }
    else
    {
      Value_3 += 17;
    }
    analogWrite(vibrate_3, Value_3);
    tft.fillScreen(WHITE);
    list();
  }
  if (txt.indexOf("vibrate 4 +") != -1)
  {
    ser();
    if (Value_4 >= 238) {
      Value_4 = 238;
    }
    else
    {
      Value_4 += 17;
    }
    Serial2.print("Value_1 = ");
    Serial2.println(Value_4);
    tft.fillScreen(WHITE);
    list();
  }
  if (txt.indexOf("vibrate 5 +") != -1)
  {
    ser();
    if (Value_5 >= 238) {
      Value_5 = 238;
    }
    else
    {
      Value_5 += 17;
    }
    Serial2.print("Value_2 = ");
    Serial2.println(Value_5);
    tft.fillScreen(WHITE);
    list();
  }
  if (txt.indexOf("vibrate 6 +") != -1)
  {
    ser();
    if (Value_6 >= 238) {
      Value_6 = 238;
    }
    else
    {
      Value_6 += 17;
    }
    Serial2.print("Value_3 = ");
    Serial2.println(Value_6);
    tft.fillScreen(WHITE);
    list();
  }
  if (txt.indexOf("vibrate 7 +") != -1)
  {
    ser();
    if (Value_7 >= 238) {
      Value_7 = 238;
    }
    else
    {
      Value_7 += 17;
    }
    Serial2.print("Value_4 = ");
    Serial2.println(Value_7);
    tft.fillScreen(WHITE);
    list();
  }
  if (txt.indexOf("vibrate 8 +") != -1)
  {
    ser();
    if (Value_8 >= 238) {
      Value_8 = 238;
    }
    else
    {
      Value_8 += 17;
    }
    Serial2.print("Value_5 = ");
    Serial2.println(Value_8);
    tft.fillScreen(WHITE);
    list();
  }
  if (txt.indexOf("vibrate 1 -") != -1)
  {
    ser();
    if (Value_1 <= 0) {
      Value_1 = 0;
    }
    else
    {
      Value_1 -= 17;
    }
    analogWrite(vibrate_1, Value_1);
    tft.fillScreen(WHITE);
    list();
  }
  if (txt.indexOf("vibrate 2 -") != -1)
  {
    ser();
    if (Value_2 <= 0) {
      Value_2 = 0;
    }
    else
    {
      Value_2 -= 17;
    }
    analogWrite(vibrate_2, Value_2);
    tft.fillScreen(WHITE);
    list();
  }
  if (txt.indexOf("vibrate 3 -") != -1)
  {
    ser();
    if (Value_3 <= 0) {
      Value_3 = 0;
    }
    else
    {
      Value_3 -= 17;
    }
    analogWrite(vibrate_3, Value_3);
    tft.fillScreen(WHITE);
    list();
  }
  if (txt.indexOf("vibrate 4 -") != -1)
  {
    ser();
    if (Value_4 <= 0) {
      Value_4 = 0;
    }
    else
    {
      Value_4 -= 17;
    }
    Serial2.print("Value_1 = ");
    Serial2.println(Value_4);
    tft.fillScreen(WHITE);
    list();
  }
  if (txt.indexOf("vibrate 5 -") != -1)
  {
    ser();
    if (Value_5 <= 0) {
      Value_5 = 0;
    }
    else
    {
      Value_5 -= 17;
    }
    Serial2.print("Value_2 = ");
    Serial2.println(Value_5);
    tft.fillScreen(WHITE);
    list();
  }
  if (txt.indexOf("vibrate 6 -") != -1)
  {
    ser();
    if (Value_6 <= 0) {
      Value_6 = 0;
    }
    else
    {
      Value_6 -= 17;
    }
    Serial2.print("Value_3 = ");
    Serial2.println(Value_6);
    tft.fillScreen(WHITE);
    list();
  }
  if (txt.indexOf("vibrate 7 -") != -1)
  {
    ser();
    if (Value_7 <= 0) {
      Value_7 = 0;
    }
    else
    {
      Value_7 -= 17;
    }
    Serial2.print("Value_4 = ");
    Serial2.println(Value_7);
    tft.fillScreen(WHITE);
    list();
  }
  if (txt.indexOf("vibrate 8 -") != -1)
  {
    ser();
    if (Value_8 <= 0) {
      Value_8 = 0;
    }
    else
    {
      Value_8 -= 17;
    }
    Serial2.print("Value_5 = ");
    Serial2.println(Value_8);
    tft.fillScreen(WHITE);
    list();
  }
  if (txt.indexOf("menu +") != -1)
  {
    ser();
    if (menu >= 7) {
      menu = 7;
    }
    else {
      menu += 1;
    }
    tft.fillScreen(WHITE);
    if (menu <= 4)
    {
      list();
    }
    if (menu >= 5)
    {
      tec();
    }
    Serial.println("menu " + String(menu));
        Serial1.println("menu " + String(menu));
  }

  if (txt.indexOf("menu -") != -1)
  {
    ser();
    if (menu <= 1) {
      menu = 1;
    }
    else {
      menu -= 1;
    }
    tft.fillScreen(WHITE);
    if (menu <= 4)
    {
      list();
    }
    if (menu >= 5)
    {
      tec();
    }
    Serial.println("menu " + String(menu));
        Serial1.println("menu " + String(menu));
  }


  if (txt.indexOf("inf") != -1)
  {
    ser();
    if (menu <= 4)
    {
      if (views == 0) {
        tft.fillScreen(WHITE);
        inf_menu();
        views = 1;
      }
      else
      {
        tft.fillScreen(WHITE);
        list();
        views = 0;
      }
    }
    if (menu >= 5)
    {
      if (views == 0) {
        tft.fillScreen(WHITE);
        inf_tec();
        views = 1;
      }
      else
      {
        tft.fillScreen(WHITE);
        tec();
        views = 0;
      }
    }

  }


  /******************************************  LM _35 *************************/
  if (txt3.indexOf("t1 = ") != -1)
  {
    txt3.replace("t1 = ", "");
    lm1 = txt3.toInt();
    ser3();
  }
  if (txt3.indexOf("t2 = ") != -1)
  {
    txt3.replace("t2 = ", "");
    lm2 = txt3.toInt();
    ser3();
  }
  if (txt3.indexOf("t3 = ") != -1)
  {
    txt3.replace("t3 = ", "");
    lm3 = txt3.toInt();
    ser3();
  }
  if (txt3.indexOf("t4 = ") != -1)
  {
    txt3.replace("t4 = ", "");
    lm4 = txt3.toInt();
    ser3();
  }
  if (txt3.indexOf("t5 = ") != -1)
  {
    txt3.replace("t5 = ", "");
    lm5 = txt3.toInt();
    ser3();
  }





  /*************************    TEC SERIAL    **********************/
  if (txt.indexOf("sec1 +") != -1)
  {
    sev();
    if (sec1 >= 70) {
      sec1 = 70;
    }
    else
    {
      sec1 += 1;
    }
    Serial3.print("sec1 = ");
    Serial3.println(sec1);
    Serial.print("sec1 = ");
    Serial.println(sec1);
Serial1.print("sec1 = ");
    Serial1.println(sec1);
    
    tft.fillScreen(WHITE);
    tec();
  }
  if (txt.indexOf("sec2 +") != -1)
  {
    sev();
    if (sec2 >= 70) {
      sec2 = 70;
    }
    else
    {
      sec2 += 1;
    }
    Serial3.print("sec2 = ");
    Serial3.println(sec2);
    Serial.print("sec2 = ");
    Serial.println(sec2);
    Serial1.print("sec2 = ");
    Serial1.println(sec2);
    
    tft.fillScreen(WHITE);
    tec();
  }
  if (txt.indexOf("sec3 +") != -1)
  {
    sev();
    if (sec3 >= 70) {
      sec3 = 70;
    }
    else
    {
      sec3 += 1;
    }
    Serial3.print("sec3 = ");
    Serial3.println(sec3);
    Serial.print("sec3 = ");
    Serial.println(sec3);
    Serial1.print("sec3 = ");
    Serial1.println(sec3);
    tft.fillScreen(WHITE);
    tec();
  }
  if (txt.indexOf("sec4 +") != -1)
  {
    sev();
    if (sec4 >= 70) {
      sec4 = 70;
    }
    else
    {
      sec4 += 1;
    }
    Serial3.print("sec4 = ");
    Serial3.println(sec4);
    Serial.print("sec4 = ");
    Serial.println(sec4);
    Serial1.print("sec4 = ");
    Serial1.println(sec4);
    tft.fillScreen(WHITE);
    tec();
  }
  if (txt.indexOf("sec5 +") != -1)
  {
    sev();
    if (sec5 >= 70) {
      sec5 = 70;
    }
    else
    {
      sec5 += 1;
    }
    Serial3.print("sec5 = ");
    Serial3.println(sec5);
    Serial.print("sec5 = ");
    Serial.println(sec5);
    Serial1.print("sec5 = ");
    Serial1.println(sec5);
    tft.fillScreen(WHITE);
    tec();
  }
  if (txt.indexOf("sec1 -") != -1)
  {
    sev();
    if (sec1 <= -10) {
      sec1 = -10;
    }
    else
    {
      sec1 -= 1;
    }
    Serial3.print("sec1 = ");
    Serial3.println(sec1);
    Serial.print("sec1 = ");
    Serial.println(sec1);
    Serial1.print("sec1 = ");
    Serial1.println(sec1);
    tft.fillScreen(WHITE);
    tec();
  }
  if (txt.indexOf("sec2 -") != -1)
  {
    sev();
    if (sec2 <= -10) {
      sec2 = -10;
    }
    else
    {
      sec2 -= 1;
    }
    Serial3.print("sec2 = ");
    Serial3.println(sec2);
    Serial.print("sec2 = ");
    Serial.println(sec2);
    Serial1.print("sec2 = ");
    Serial1.println(sec2);
    tft.fillScreen(WHITE);
    tec();
  }
  if (txt.indexOf("sec3 -") != -1)
  {
    sev();
    if (sec3 <= -10) {
      sec3 = -10;
    }
    else
    {
      sec3 -= 1;
    }
    Serial3.print("sec3 = ");
    Serial3.println(sec3);
    Serial.print("sec3 = ");
    Serial.println(sec3);
    Serial1.print("sec3 = ");
    Serial1.println(sec3);
    tft.fillScreen(WHITE);
    tec();
  }
  if (txt.indexOf("sec4 -") != -1)
  {
    sev();
    if (sec4 <= -10) {
      sec4 = -10;
    }
    else
    {
      sec4 -= 1;
    }
    Serial3.print("sec4 = ");
    Serial3.println(sec4);
    Serial.print("sec4 = ");
    Serial.println(sec4);
    Serial1.print("sec4 = ");
    Serial1.println(sec4);
    tft.fillScreen(WHITE);
    tec();
  }
  if (txt.indexOf("sec5 -") != -1)
  {
    sev();
    if (sec5 <= -10) {
      sec5 = -10;
    }
    else
    {
      sec5 -= 1;
    }
    Serial3.print("sec5 = ");
    Serial3.println(sec5);
    Serial.print("sec5 = ");
    Serial.println(sec5);
    Serial1.print("sec5 = ");
    Serial1.println(sec5);
    tft.fillScreen(WHITE);
    tec();
  }





  


}



unsigned long testFillScreen() {
  unsigned long start = micros();

  tft.fillScreen(BLACK);
  tft.fillScreen(RED);
  tft.fillScreen(GREEN);
  tft.fillScreen(BLUE);
  tft.fillScreen(BLACK);
}


unsigned long list() {

  //tft.fillScreen(WHITE);
  views = 0;


  tft.drawFastHLine(0, 150, 320, RED);
  tft.drawFastHLine(0, 50, 320, BLUE);

  tft.drawFastVLine(0, 0, 300, BLACK);
  tft.drawFastVLine(190, 0, 300, BLACK);
  tft.drawFastVLine(50, 0, 300, BLACK);

  tft.setTextColor(BLACK);
  tft.setCursor(20, 20);
  tft.print(menu);
  tft.setCursor(100, 10);
  tft.print("Point");
  tft.setCursor(240, 10);
  tft.print("Value");

  int i = menu * 2;

  tft.setCursor(100, 90);
  tft.print("Vibrate ");
  tft.print(i - 1);
  tft.setCursor(100, 190);
  tft.print("Vibrate ");
  tft.print(i);

  int show_1 = 1;
  int show_2 = 1;

  if (menu == 1)
  {
    show_1 = Value_1;
    show_2 = Value_2;
  }
  if (menu == 2)
  {
    show_1 = Value_3;
    show_2 = Value_4;
  }
  if (menu == 3)
  {
    show_1 = Value_5;
    show_2 = Value_6;
  }
  if (menu == 4)
  {
    show_1 = Value_7;
    show_2 = Value_8;
  }

  tft.setCursor(250, 90);
  tft.print(show_1 / 17);
  tft.setCursor(250, 190);
  tft.print(show_2 / 17);

}


unsigned long inf_menu() {

  //tft.fillScreen(BLACK);
  views = 1;

  tft.drawFastHLine(0, 120, 320, RED);
  tft.drawFastVLine(80, 0, 300, BLACK);
  tft.drawFastVLine(160, 0, 300, BLACK);
  tft.drawFastVLine(235, 0, 300, BLACK);


  tft.setTextSize(1);
  tft.setCursor(10, 30);
  tft.setTextColor(BLACK);
  tft.print("Vibrate ");
  tft.print(1);
  tft.print(" :");

  tft.setCursor(95, 30);
  tft.print("Vibrate ");
  tft.print(2);
  tft.print(" :");

  tft.setCursor(170, 30);
  tft.print("Vibrate ");
  tft.print(3);
  tft.print(" :");

  tft.setCursor(238, 30);
  tft.print("Vibrate ");
  tft.print(4);
  tft.print(" :");

  tft.setCursor(10, 150);
  tft.print("Vibrate ");
  tft.print(5);
  tft.print(" :");

  tft.setCursor(95, 150);
  tft.print("Vibrate ");
  tft.print(6);
  tft.print(" :");

  tft.setCursor(170, 150);
  tft.print("Vibrate ");
  tft.print(7);
  tft.print(" :");

  tft.setCursor(238, 150);
  tft.print("Vibrate ");
  tft.print(8);
  tft.print(" :");

  tft.setTextSize(1);
  tft.setTextColor(RED);
  tft.setCursor(30, 90);
  tft.print(Value_1 / 17);
  tft.setCursor(115, 90);
  tft.print(Value_2 / 17);
  tft.setCursor(190, 90);
  tft.print(Value_3 / 17);
  tft.setCursor(265, 90);
  tft.print(Value_4 / 17);
  tft.setCursor(30, 200);
  tft.print(Value_5 / 17);
  tft.setCursor(115, 200);
  tft.print(Value_6 / 17);
  tft.setCursor(190, 200);
  tft.print(Value_7 / 17);
  tft.setCursor(265, 200);
  tft.print(Value_8 / 17);

}



unsigned long tec() {

  //tft.fillScreen(WHITE);
  views = 0;


  tft.drawFastHLine(0, 150, 320, RED);
  tft.drawFastHLine(0, 50, 320, BLUE);

  tft.drawFastVLine(0, 0, 300, BLACK);
  tft.drawFastVLine(190, 0, 300, BLACK);
  tft.drawFastVLine(50, 0, 300, BLACK);

  tft.setTextColor(BLACK);
  tft.setCursor(20, 20);
  tft.print(menu);
  tft.setCursor(100, 10);
  tft.print("Point");
  tft.setCursor(240, 10);
  tft.print("Value");

  int i = menu * 2;

  tft.setCursor(100, 90);
  tft.print("TEC ");
  tft.print(i - 9);
  tft.setCursor(100, 190);
  tft.print("TEC ");
  tft.print(i - 8);

  int show_1 = 0;
  int show_2 = 0;

  if (menu == 5)
  {
    show_1 = sec1;
    show_2 = sec2;
  }
  if (menu == 6)
  {
    show_1 = sec3;
    show_2 = sec4;
  }
  if (menu == 7)
  {
    show_1 = sec5;
  }


  tft.setCursor(250, 90);
  tft.print(show_1);
  tft.setCursor(250, 190);
  tft.print(show_2);

}

unsigned long inf_tec() {

  //tft.fillScreen(BLACK);
  views = 1;

  tft.drawFastHLine(0, 120, 320, RED);
  tft.drawFastVLine(80, 0, 300, BLACK);
  tft.drawFastVLine(160, 0, 300, BLACK);
  tft.drawFastVLine(235, 0, 300, BLACK);


  tft.setTextSize(1);
  tft.setCursor(10, 30);
  tft.setTextColor(BLACK);
  tft.print("TEC ");
  tft.print(1);
  tft.print(" :");


  tft.setCursor(95, 30);
  tft.print("TEC ");
  tft.print(2);
  tft.print(" :");

  tft.setCursor(170, 30);
  tft.print("TEC ");
  tft.print(3);
  tft.print(" :");

  tft.setCursor(238, 30);
  tft.print("TEC ");
  tft.print(4);
  tft.print(" :");

  tft.setCursor(10, 150);
  tft.print("TEC ");
  tft.print(5);
  tft.print(" :");



  tft.setTextSize(1);
  tft.setTextColor(RED);
  tft.setCursor(30, 90);
  tft.println(sec1);
  tft.setCursor(115, 90);
  tft.println(sec2);
  tft.setCursor(190, 90);
  tft.println(sec3);
  tft.setCursor(265, 90);
  tft.println(sec4);
  tft.setCursor(30, 200);
  tft.println(sec5);

}
