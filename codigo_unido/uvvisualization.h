
int radiacion = analogRead(A5); //el sensor esta conectado al pin analógico 0, leemos el valor.
float voltage = radiacion * (5.0 / 1023.0); //convertimos el valor leido a voltage (de 0 a 1023 a de 0 a 5v)

Serial.print("UV Index = "); //nos imprima el indice UV
Serial.println(voltage / .1); //operación para pasar el voltage a indice de UV (de 1-2 bajo, de 3-5 moderado, de 6-7 alto, de 8 a 10 muy alto y de 11 para arriba muy muy muy alto)
float nivelUv = voltage / .1;

//int nivelUv = 30; //para provar el codigo de emergencia quitando las // y comentando la de arriba

if (nivelUv <= 2) {

  pixels.setPixelColor(3, pixels.Color(150, 0, 200));
  strip.show();
  pixels.show();

} if (nivelUv > 2  && nivelUv <= 5) {
  pixels.setPixelColor(3, pixels.Color(150, 0, 200));
  pixels.setPixelColor(4, pixels.Color(150, 0, 200));
  strip.show();
  pixels.show();
} if (nivelUv > 5 && nivelUv <= 7) {
  pixels.setPixelColor(3, pixels.Color(150, 0, 200));
  pixels.setPixelColor(4, pixels.Color(150, 0, 200));
  pixels.setPixelColor(5, pixels.Color(150, 0, 200));
  strip.show();
  pixels.show();
} if (nivelUv > 7) {
  pixels.setPixelColor(3, pixels.Color(250, 0, 0));
  pixels.setPixelColor(4, pixels.Color(250, 0, 0));
  pixels.setPixelColor(5, pixels.Color(250, 0, 0));
  for (int i = 0; i < 12; i++) {
    strip.setPixelColor(i, pixels.Color(255, 0, 0));
  }
  digitalWrite(motorPin, HIGH);
  strip.show();
  pixels.show();

  delay(500);
  pixels.setPixelColor(3, pixels.Color(0, 0, 0));
  pixels.setPixelColor(4, pixels.Color(0, 0, 0));
  pixels.setPixelColor(5, pixels.Color(0, 0, 0));
  for (int i = 0; i < 12; i++) {
    strip.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  digitalWrite(motorPin, LOW);
  strip.show();
  pixels.show();
  delay(500);
  pixels.show();   // Send the updated pixel colors to the hardware.
  strip.show();
  //delay(DELAYVAL); // Pause before next pass through loop
}
