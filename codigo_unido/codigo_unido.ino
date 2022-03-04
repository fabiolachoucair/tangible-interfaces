//configuración del sensor miniSD
#include <SPI.h>
#include <SD.h>
#define SSpin 10 //establecemos a que pin esta conectado el CS, puede ser cualquiera
File archivo; //creas un objeto tipo File y lo llamas archivo

//configuración del sensor dht11
#include "dht.h"
dht DHT;
#define DHT11_PIN 4

//configuración del neopixel alargado
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIN        6
#define NUMPIXELS 9
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//configuración del neopixel circular
#define PINS        5
#define NUM_LEDS 12
Adafruit_NeoPixel strip(NUM_LEDS, PINS, NEO_GRB + NEO_KHZ800);

//configuración motor vibración
const int motorPin = 9;//decimos donde tenemos conectado el vibración
#define DELAYVAL 200 // Time (in milliseconds) to pause between pixels


void setup() {

  Serial.begin(9600); //velocidad a la que se visualiza la info en el monitor
  pinMode(4, INPUT);//DHT11
  pinMode(motorPin, OUTPUT); //decimos que el motor es de salida
  pixels.begin();// INITIALIZE NeoPixel strip object (REQUIRED)
  strip.begin();
  strip.show();

  //UV
  int radiacion = analogRead(A0); //el sensor esta conectado al pin analógico 0, leemos el valor.
  float voltage = radiacion * (5.0 / 1023.0); //convertimos el valor leido a voltage (de 0 a 1023 a de 0 a 5v)

  Serial.print("UV Index = "); //nos imprima el indice UV
  Serial.println(voltage / .1); //operación para pasar el voltage a indice de UV (de 1-2 bajo, de 3-5 moderado, de 6-7 alto, de 8 a 10 muy alto y de 11 para arriba muy muy muy alto)
  float nivelUv = voltage / .1;

  //SD
  Serial.println("Inicializando tarjeta...");
  if (!SD.begin(SSpin)) {
    Serial.println("fallo en inicializacion!");
    return;
  }

  Serial.println("inicializacion correcta");
  archivo = SD.open("prueba.txt", FILE_WRITE);
  if (archivo) {
    for (int i = 1; i < 30; i++) {
      int TEMPERATURA = DHT.temperature;
      int HUMEDAD = DHT.humidity;
      int INDICEUV = nivelUv;
      archivo.println("-------------------------------------------------------------");
      archivo.println(i);
      archivo.print("TEMPERATURA : ");
      archivo.println(TEMPERATURA);
      archivo.print("HUMEDAD : ");
      archivo.println(HUMEDAD);
      archivo.print("INDICEUV : ");
      archivo.println(INDICEUV);
      archivo.println("-------------------------------------------------------------");
      delay(1000);
      archivo.close();
      Serial.println("escritura correcta");
    }

  }
}

void loop() {
  for (int i = 0; i <= 12; i++) {
    strip.setPixelColor(i, strip.Color(255, 255, 255));
  } //declarar que el neopixel circular se encienda siempre en blanco a no ser que llegue al 4o nivel de alguno de los sensores

  //Temperatura

#include "tvisualization.h"

  //Uv
#include "uvvisualization.h"

  // Humedad
#include "hvisualization.h"
}
}
