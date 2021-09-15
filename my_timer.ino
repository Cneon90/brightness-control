//Меню 0 (показывает температуру (обновляется каждую секунду)
void display_temp()
{//Отображаем температуру
      oled.home();            // курсор в 0,0
      oled.setCursorXY(60, 16); // курсор в (пиксель X, пиксель Y)
      oled.setScale(3);
      oled.print(getTemp());
      /*-------------*/
      int pos_Svet=map(getLighting(),0,100,60,128);
      if (pos_Svet <=60) pos_Svet=60; 
      oled.clear(pos_Svet,40,128, 60); 
      oled.rect(60,40,pos_Svet, 60);
      //oled.setCursorXY(60, 40); // курсор в (пиксель X, пиксель Y)
      //oled.setScale(3);
      //oled.print(getLighting());
}
/*----------------------------------------------------------------------*/


void car_temp()
{//переодический опрашиваем и отображаем температуру(если находимся в меню 0)
  if (millis() - myTimer1 >= UPDATE_TEMP) {   // ищем разницу (1000 мс)
    myTimer1 = millis();              // сброс таймера
    display_temp();
  }
}



bool flag_nasos;


void car_pompa()
{//Анимация при включеной помпе
   if(menu == 4)
    {
      if (millis() - myTimer4 >= 100) {   // ищем разницу (1000 мс)
                 myTimer4 = millis();  
               //  myTimer2 = millis();//Сброс таймера      
                 oled.setCursorXY(90,16); // курсор в (пиксель X, пиксель Y)
                 oled.setScale(3);
                 int svet= getLighting();
                 if(svet <= 0) svet=0; //Ограничим нижний диапозон(а то уходит в минус)  
                
                 if(svet < 10) 
                 {//Убираем лишний символ когда значение меньше 10
                   //oled.clear(100,16,128,32);
                    oled.setCursorXY(90,16);
                    oled.print(" ");     
                 }
                 oled.print(svet); 
      }
    }

  
   if(menu !=0) return;//Если на главном экране

   
   if(auto_svet==1)
                         {
                          oled.drawBitmap(80, 0,  A_16x16,16,16);
                          //oled.setCursorXY(60,0); // курсор в (пиксель X, пиксель Y)
                          //oled.setScale(2);
                          //oled.print("A");
                            
                         }

     if(dalni_svet==1)
                         {
                          oled.drawBitmap(60, 0,  dal_16x16,16,16);
                          //oled.setCursorXY(60,0); // курсор в (пиксель X, пиксель Y)
                          //oled.setScale(2);
                          //oled.print("A");
                            
                         }
    
                           
  if(nasos_power==0) return;//Если помпа включена*/
 
    
           if (millis() - myTimer3 >= 300) {   // ищем разницу (1000 мс)
                 myTimer3 = millis();              // сброс таймера
                   
                   
                   /*Если помпа включена*/
                   if(flag_nasos==1)
                         {
                            oled.drawBitmap(128-16-1, 0,  nasos_1_16x16,16,16);
                            flag_nasos=0;
                         }
                    else 
                        {
                          oled.drawBitmap(128-16-1, 0,  nasos_2_16x16,16,16);
                          flag_nasos=1;  
                        }
                    /*Если помпа включена*/

                   
                   
                    
                        



  
  }

    
}


void out_menu_0()
{//Делаем выход в меню если нету действия(для проверки действия необходимо на события энкодера сбрасывать счетчик) 
  if (millis() - myTimer2 >= OUT_MENU) {   // ищем разницу (500 мс)
  {
    myTimer2 = millis();              // сброс таймера
    if(menu != 0) {
      menu=0; //Если больше * сек, то выход в 0 меню (показ температуры)  
      flag_slaid=1;
    }
    
  }
 }  
}
