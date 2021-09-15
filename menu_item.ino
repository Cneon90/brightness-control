void menu_0()
{//Меню отображения температуры
   car_temp(); //вкладка my_timer (обновляется каждую сукенду) 

   if (enc.isLeft()) 
     {
      
       yark_dipsl=yark_dipsl-10;
       if (yark_dipsl <=0) yark_dipsl = 0;
        Serial.println(yark_dipsl);
        beeping(1); 
        oled.setContrast(yark_dipsl);  
     }
     
   if (enc.isRight()) { 
   
     yark_dipsl=yark_dipsl+10;
       if (yark_dipsl >= 255) yark_dipsl = 255;
         Serial.println(yark_dipsl);
         beeping(1); 
         oled.setContrast(yark_dipsl); 
   }
 
  
}


//Меню настройки яркости фар
void menu_1()
{
 
   if (enc.isLeft()) 
     {
      myTimer2 = millis();//Сброс таймера (Если не сбросить значит действий нет, и надо выйти в 0 меню)

      
      oled.clear(enc.counter, 0, enc.counter+1, 15); 
      if(enc.counter <= 0) 
       enc.counter = 0;

       svet_yarkost=enc.counter;
       //Serial.print("yarkost"); 
       //Serial.println(svet_yarkost);
     }
     
   if (enc.isRight()) { 
    myTimer2 = millis(); //Сброс таймера
    oled.rect(0,0,enc.counter, 15);  

      if(enc.counter >= 128) 
       enc.counter = 128;

       svet_yarkost=enc.counter;
        Serial.print("yarkost"); 
       Serial.println(svet_yarkost);
   }
   
}


//menu включения насоса(помпы) 
void menu_2()
{
  
   if (enc.isLeft()) 
     {
      myTimer2 = millis();//Сброс таймера
      nasos_power=0;
      oled.clear(0,0,128, 15); 
      beeping(1);
     }
     
   if (enc.isRight()) { 
      myTimer2 = millis();//Сброс таймера
      nasos_power = 1;
      oled.rect(0,0,128, 15); 
      beeping(2); 
   }
}

void menu_3()
{
  if (enc.isLeft()) 
    {
      myTimer2 = millis();//Сброс таймера
      auto_svet=0;
      oled.clear(0,0,128, 15); 
      beeping(1);
     }
     
   if (enc.isRight()) { 
      myTimer2 = millis();//Сброс таймера
      auto_svet = 1;
      //oled.rect(0,0,128, 15); 
      beeping(2); 
      displayName("АВТО");
   }
}

void menu_4()
{
   if (enc.isLeft()) 
    {
      myTimer2 = millis();//Сброс таймера
      auto_svetn_on--;
      if(auto_svetn_on <10)
       oled.clear(80,40,124,64);
       if(auto_svetn_on <=0) auto_svetn_on = 0;
      oled.setCursorXY(90,40); // курсор в (пиксель X, пиксель Y)
      oled.setScale(3);
      oled.print(auto_svetn_on); 
     }
     
   if (enc.isRight()) { 
      auto_svetn_on++;
      myTimer2 = millis();//Сброс таймера
      if(auto_svetn_on >=100) auto_svetn_on = 99;
      if(auto_svetn_on <10)
        oled.clear(80,40,90,64);
       
      oled.setCursorXY(90,40); // курсор в (пиксель X, пиксель Y)
      oled.setScale(3);
      oled.print(auto_svetn_on); 
    
   }
  

}
