#include <Arduino.h>
#include <MakAlc_Alarma.h>
// Asociación Maker Alicante
void cambiaEstadoLed();

MakAlc_Alarma Alarma1;
MakAlc_Alarma Alarma2;

#define PINLED1 DD4           // Conectar un led al pin 4
#define PINLED2 LED_BUILTIN   // Led integrado en placa

#define TIEMPO1 1000          // 1 segundo
#define TIEMPO2 1500          // 1,5 segundos

#define REPETICIONES1 10

void setup() {
  // Definimos los pin de los leds como salida.
  pinMode(PINLED1, OUTPUT);
  pinMode(PINLED2, OUTPUT);

  // La alarma 1 solo se activará 10 veces.
  // La alarma 2 no se detiene.
  Alarma1.Define(TIEMPO1, REPETICIONES1);

  Alarma2.Define(TIEMPO2,*cambiaEstadoLed,-1);

  // Activamos las alarmas.
  Alarma1.Start();
  Alarma2.Start();
}

void loop() {
  // Para la alarma 1 comprobamos si se ha cumplido el plazo y si se ha cumplido
  // lanzamos el código asociado.
  if(Alarma1.Comprueba()){
    // Cambiamos el estado del led.
    digitalWrite(PINLED1, !digitalRead(PINLED1));
  }

  // Cuando se cumpla el plazo la función será llamada de forma automática.
  Alarma2.Comprueba();

}

// Cambia el estado del led. Lo enciende si está apagado y lo apaga si está encendiddo.
void cambiaEstadoLed()
{
  digitalWrite(PINLED2, !digitalRead(PINLED2));
}