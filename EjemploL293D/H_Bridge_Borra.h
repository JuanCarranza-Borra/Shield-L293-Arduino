////////////////////////////////////////////////////
//   Elaborado por: Juan Jose Carranza Garcia     //
//          Fecha: 5 de junio del 2016            //
//               Version 1.0.1                    //
////////////////////////////////////////////////////

volatile int DatoBuffer;
void Mandar74HC595(int bits);

class DC_Motor{
  private: int _Adelante,_Atras,_PWM,_E=1,Vel;
  public:
   void attach(int _a)
   {
    for(int i=2;i<=12;i++) pinMode(i,OUTPUT);
    switch(_a)
    {
      case 1: _Adelante = 2; _Atras=3; _PWM=11; break;
      case 2: _Adelante = 4; _Atras=1; _PWM=3; break;
      case 3: _Adelante = 7; _Atras=5; _PWM=6; break;
      case 4: _Adelante = 0; _Atras=6; _PWM=5; break;
    }
   }
   void Velocidad(int _V);
   void Sentido(int _S);
   void Desactivar(void);
   void Activar(void);
};
void DC_Motor::Desactivar(void)
{
  digitalWrite(_PWM,LOW);
  _E=0;
}
void DC_Motor::Activar(void)
{
  analogWrite(_PWM,Vel);
  _E=1;
}
void DC_Motor::Velocidad(int _V)
{
  Vel = _V;
  if(_E==1) analogWrite(_PWM,Vel);
}
void DC_Motor::Sentido(int _S)
 {
      DatoBuffer =     DatoBuffer&(~(1<<_Adelante))&(~(1<<_Atras));
      if(_S == 1)      DatoBuffer = DatoBuffer|(1<<_Adelante);
      else if(_S == 2) DatoBuffer = DatoBuffer|(1<<_Atras);
      Mandar74HC595(DatoBuffer);
 }

void Mandar74HC595(int bits)
{
int buffer;
  for(buffer  = 0;buffer <= 7;buffer++)
  {
    if(bits&(1<<(7-buffer))) digitalWrite(8,HIGH);
    else digitalWrite(8,LOW);     
    digitalWrite(4,HIGH);
    delayMicroseconds(10);
    digitalWrite(4,LOW);  
    delayMicroseconds(10);
  }
  digitalWrite(12,HIGH);
  delayMicroseconds(1);
  digitalWrite(12,LOW);
}


