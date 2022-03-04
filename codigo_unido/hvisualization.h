int h = DHT.humidity;

Serial.print("Humidity = "); //nos imprima el indice UV
Serial.println(h);
if (10 <= h && h < 40) {
  pixels.setPixelColor(6, pixels.Color(0, 0, 255));
  digitalWrite(motorPin, LOW);
  strip.show();
  pixels.show();


}
else if (40 <= h && h < 50) {
  pixels.setPixelColor(6, pixels.Color(0, 0, 255));
  pixels.setPixelColor(7, pixels.Color(0, 0, 255));
  digitalWrite(motorPin, LOW);
  strip.show();
  pixels.show();

}
else if (50 <= h && h < 60) {
  pixels.setPixelColor(6, pixels.Color(0, 0, 255));
  pixels.setPixelColor(7, pixels.Color(0, 0, 255));
  pixels.setPixelColor(8, pixels.Color(0, 0, 255));
  digitalWrite(motorPin, LOW);
  strip.show();
  pixels.show();
}
else if (60 <= h) {
  pixels.setPixelColor(6, pixels.Color(250, 0, 0));
  pixels.setPixelColor(7, pixels.Color(250, 0, 0));
  pixels.setPixelColor(8, pixels.Color(250, 0, 0));
  for (int i = 0; i < 12; i++) {
    strip.setPixelColor(i, pixels.Color(255, 0, 0));
  }
  digitalWrite(motorPin, HIGH);
  strip.show();
  pixels.show();

  delay(500);
  pixels.setPixelColor(6, pixels.Color(0, 0, 0));
  pixels.setPixelColor(7, pixels.Color(0, 0, 0));
  pixels.setPixelColor(8, pixels.Color(0, 0, 0));
  for (int i = 0; i < 12; i++) {
    strip.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  digitalWrite(motorPin, LOW);
  strip.show();
  pixels.show();
  delay(500);
  //delay(DELAYVAL); // Pause before next pass through loop
