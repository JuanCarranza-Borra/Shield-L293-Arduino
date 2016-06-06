#include "H_Bridge_Borra.h"

DC_Motor IzquierdoDelante,DerechoDelante,IzquierdoAtras,DerechoAtras;  //Define tus motores les puedes poner el nombre que quieras

void setup() {
  IzquierdoDelante.attach(1);     //El motor IzquierdoDelante esta en el canal 1 de tu shield
  IzquierdoDelante.Sentido(0);    //"   "   estara detenido  

  DerechoDelante.attach(2);       //El motor DerechoDelante esta en el canal 2 de tu shield
  DerechoDelante.Sentido(1);      //"   "    Ira Hacia Adelante

  IzquierdoAtras.attach(3);      //El motor IzquierdoAtras esta en el canal 3 de tu shield
  IzquierdoAtras.Sentido(2);     //"   "    Ira Hacia Atras
  
  DerechoAtras.attach(4);         //El motor DerechoAtras esta en el canal 4 de tu shield
  DerechoAtras.Sentido(1);      //"   "    Ira Hacia Adelante
  
  DerechoDelante.Desactivar();    //Desactivaremos el motor DerechoDelante (Por defecto todos los motores estan activados)
                                  // Para Activar el DerechoDelante.Activar();
}

void loop() {
  for(int i=0;i<255;i++)
   {
    IzquierdoDelante.Velocidad(i);   // Dale la velocidad de i a todos los motores (El valor va de 0-255)
    DerechoDelante.Velocidad(i);
    IzquierdoAtras.Velocidad(i);
    DerechoAtras.Velocidad(i);
    delay(10);
   }
    for(int i=255;i>0;i--)
   {
   IzquierdoDelante.Velocidad(i);
    DerechoDelante.Velocidad(i);
    IzquierdoAtras.Velocidad(i);
    DerechoAtras.Velocidad(i);
    delay(10);
   }
}
