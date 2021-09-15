// дефайн перед подключением либы - использовать microWire (лёгкая либа для I2C)
//#define USE_MICRO_WIRE
//Отключаем дисплей oled.setPower(false);
#include <GyverOLED.h>
#include "menu_icon.h"
#include <EncButton.h>

#define OUT_MENU 5000
#define UPDATE_TEMP 1000
#define COUNT_MENU 5
#define BEEP 4
#define YARKOST 10


int menu=0;
boolean PTF=0;
boolean isPTF=0;
boolean flag_slaid=1;
boolean nasos_power=0;//включение или выключение насоса
boolean auto_svet=0;//Включение автоматического управления фарами по датчику света
boolean dalni_svet=1;//Включение дальнего света (переключатель подрулевой)
int auto_svetn_on=0;
uint32_t myTimer1;//Таймер работает когда включено 0 меню(показ температуры)
uint32_t myTimer2;//Таймер (если нету действий выходить в 0 меню)
uint32_t myTimer3;//Таймер3 При включении помпы отображать анимацию
uint32_t myTimer4;//Таймер3 При включении помпы отображать анимацию

int svet_yarkost=0;
int yark_dipsl=255;

GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;
EncButton<EB_TICK, 2, 3, 7> enc;  // энкодер с кнопкой <A, B, KEY>


void setup() {
  /*init pin*/
   pinMode(BEEP,OUTPUT);
  /*init pin*/

  /*init serial*/
  Serial.begin(9600);

  /*OLED*/
  oled.init();  // инициализация
  oled.clear();   // очистить дисплей (или буфер)
  oled.home();            // курсор в 0,0
  oled.setCursorXY(30, 0); // курсор в (пиксель X, пиксель Y)

  //logo
  oled.drawBitmap(0, 0, bitmap_128x64,128,64);
  delay(500);
  oled.clear();
  beeping(10);
 /*OLED*/

 /*encoder*/
   enc.counter = 0;      // изменение счётчика
 /*encoder*/
 
     

}


void loop() {
  enc.tick();
  out_menu_0();//Проверка(если нет действий выход на 0 меню)
  
  
  setting_menu();//Проверка в каком меню находимся
  

  if (enc.isClick()) //Нажатие на энкодер
  {
     menu++; //Переод на следующие меню
     //Serial.println(menu);
     if (menu >= COUNT_MENU) 
      menu=0;//если все меню прошли начинаем с 0 меню
      flag_slaid=1;//Опускаем флаг, для входа в меню 
      myTimer2 = millis();//Сброс таймера (действие) 
  }

  if (enc.isHolded()) 
    {
     // enc.counter = 0;      // изменение счётчика
     // oled.clear(); Сделать включение противотуманок
      if (PTF == 1 & menu==0) //Если на 0 меню, то можно управлять ПТФ, в других меню нельзя 
      {
         PTF=0;
         oled.clear(0,0,128, 15); 
         beeping(1);
         
      } else if (menu==0)
      {
          PTF=1;
          displayName("ПТФ");//Отображаем желтую полоску сверху(что бы информировать что включены ПТФ) 
          
          beeping(2); 
      }
       
      Serial.println(PTF);
     }

   select_menu();
   car_pompa();

   
}
