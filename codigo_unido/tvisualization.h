//los valores de T van de -3 grados a + 55 (cuando saltaría la alarma)
  int d = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  delay(2000);

  int t = DHT.temperature;
  //int t = 80; //para provar el codigo de emergencia quitando las // y comentando la de arriba
if (t >= -3 && t <= 27) {
    pixels.setPixelColor(0, pixels.Color(0, 150, 0));
    strip.show();
    pixels.show();

  }
  if (t > 27 && t <= 40) {
    pixels.setPixelColor(0, pixels.Color(0, 150, 0));
    pixels.setPixelColor(1, pixels.Color(0, 150, 0));
    strip.show();
    pixels.show();
  }
  if (t > 40 && t <= 55) {
    pixels.setPixelColor(0, pixels.Color(0, 150, 0));
    pixels.setPixelColor(1, pixels.Color(0, 150, 0));
    pixels.setPixelColor(2, pixels.Color(0, 150, 0));
    strip.show();
    pixels.show();
  }
  if (t > 55) {
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.setPixelColor(1, pixels.Color(255, 0, 0));
    pixels.setPixelColor(2, pixels.Color(255, 0, 0));
    for (int i = 0; i < 12; i++) {
      strip.setPixelColor(i, pixels.Color(255, 0, 0));
    }
    digitalWrite(motorPin, HIGH);
    strip.show();
    pixels.show();
    delay(1000);
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    for (int i = 0; i < 12; i++) {
      strip.setPixelColor(i, pixels.Color(0, 0, 0));
    }
    digitalWrite(motorPin, LOW);
    delay(100);
    pixels.show();   // Send the updated pixel colors to the hardware.
    strip.show();
  }
