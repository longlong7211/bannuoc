void enter_smartconfig()
{
  if (in_smartconfig == false) {
    in_smartconfig = true;
    WiFi.beginSmartConfig();
  }
}
void ktwifiConfig() {
  if (millis() - lastPress > 3000 && digitalRead(PIN_BUTTON) == 1) {
    longpress = true;
  } else if (digitalRead(PIN_BUTTON) == 0) {
    lastPress = millis();
    longpress = false;
  }
  if (longpress) {
    enter_smartconfig();
    Serial.println("Enter smartconfig");
    lastPress = millis();
    longpress = false;
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(300);
    }
  }
  if (WiFi.status() == WL_CONNECTED && in_smartconfig && WiFi.smartConfigDone()) {
    Serial.println("Connected, Exit smartconfig");
    Serial.println("HTTP server started");
  }
  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(D1, HIGH);
  }
}
