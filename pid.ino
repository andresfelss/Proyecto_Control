#include <math.h>

//Valores fijos del circuito
float rAux = 100000.0;
float vcc = 5.0;
float beta = 3950.0;
float temp0 = 297.15;
float r0 = 100000.0;
float error = 0.0;
float e1 = 0.0;
int U = 0;

//Variables usadas en el cálculo
float vm = 0.0;
float rntc = 0.0;
float temperaturaK = 0.0;
float tempC = 0.0;
float ref = 0.0;
float Kp = 0.0;
float Ki = 0.0;

//PID::PIDParameters<double> parameters(4.0, 0.2, 1);
//PID::PIDController<double> pidController(parameters);

void setup(){
  //pidController.Input = 25;
  //pidController.Setpoint = 100;
  //pidController.TurnOn();
  ref = 85;
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  Kp = 120;
  Ki = 1;

}
void loop() {

  //Bloque de cálculo
    vm = (vcc/1024)*(analogRead(1));                    //Calcular tensión en la entrada
    rntc = rAux / ((vcc/vm)-1);                         //Calcular la resistencia de la NTC
    temperaturaK = beta/(log(rntc/r0) + (beta/temp0));
    tempC = temperaturaK - 273.15;  //Calcular la temperatira en Kelvin

    error = ref - tempC;
    U = constrain((Kp*error + Ki*e1 ),0,255);
    analogWrite(9,U);
    Serial.println(tempC);
    e1 = error;


    delay(100);
}
