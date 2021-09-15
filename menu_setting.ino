void setting_menu()//Поведение энкодора в зависимости от меню в котором сейчас находимся
{
    switch (menu) {
                  case 0:
                      menu_0();
                  break;
                    
                  case 1:
                      menu_1();
                  //   oled.clear(enc.counter, 0, enc.counter+100, 15); 
                    break;
                  case 2:
                      menu_2();
                    break;
                 case 3:
                      menu_3();
                    break;
                 case 4:
                      menu_4();
                    break;
              }
}



//Отображаем картинку в зависимости от выбранного меню
void select_menu()
{
   if(flag_slaid==0) return; //Если флаг опущен, выходим (что бы не перерисовывать изображения)
   
   switch (menu) {
     case 0://Отображаем температуру после загрузки 
      oled.clear();
      display_temp();//Отображаем температуру (что бы не ждать секунду пока она отобразится таймером) убираем мигания при переходе 
      oled.drawBitmap(0, 16, grad,50,50);
     // oled.clear();//Иконка ламочки(регулировка яркости дальнего в пол накала)
      
      if (PTF) //Если включен, отображаем что включен)) возвращаем желтую метку
         {
            displayName("ПТФ");
         }
          
      break;


    case 1:
      oled.clear();//Иконка ламочки(регулировка яркости дальнего в пол накала)
      oled.drawBitmap(40, 15, lampa,50,50);
      oled.rect(0,0,svet_yarkost, 15);
      
      break;

      
    case 2:
      oled.clear();//Включение\Отключение насоса
      oled.drawBitmap(40, 15, nasos,50,50);
        if (nasos_power) //Если включен, отображаем что включен)) возвращаем желтую метку
          oled.rect(0,0,128 , 15);
      break;

      
    case 3:
       
       oled.clear();
       oled.drawBitmap(40, 16, yarkost,50,50);
        if (auto_svet) //Если включен, отображаем что включен)) возвращаем желтую метку
          {
           // oled.rect(0,0,128 , 15);
            displayName("АВТО");
          }

       
           
       
     break;

      
   case 4:
      
     oled.clear();
     
     oled.drawBitmap(0, 16, yarkost,50,50);
     oled.setCursorXY(0,0); // курсор в (пиксель X, пиксель Y)
      oled.setScale(2);
       oled.print("Автоматика"); 
      //oled.print("Освещенность");  
       
      break;

      
   case 5:
       Serial.println("Perv4");
       
       oled.clear();
      break;
  }
  
  flag_slaid=0; //Выставляем флаг, что бы до перехода на другое меню не попадать в функуцию

}














/*----------Функции сервисные---------------------------------------------------------------------*/
//Пищать когда надо)
void beeping(int count)
{
   for(int i=0;i<count;i++)
  {
    digitalWrite(BEEP,1);
    delay(50);
    digitalWrite(BEEP,0);
    delay(10);
  }
}

//Получаем температуру
double getTemp() {
  double t;    
  t = log(((10240000/analogRead(A7)) - 10000));
  t = 1 / (0.001129148 + (0.000234125 * t) + (0.0000000876741 * t * t * t));
  t = t - 273.15;    // Конвертируем Кельвины в Цельсии
  return t;
}

//Получение освещения с датчика
int getLighting()
 {
   return map(analogRead(A0),0,700,100,0);
 }


void displayName(String st)
{ 

           //oled.rect(0,0,42 , 15);
           oled.setCursorXY(0,0); // курсор в (пиксель X, пиксель Y)
           oled.setScale(2);
           oled.print(st);
           //oled.rect(57+st.length()*5,0,128 , 15);
          
}
 
