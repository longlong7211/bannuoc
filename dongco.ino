void dongco() {
  if (CAMstatus) {
    digitalWrite(pinbomCAM, HIGH);
    delay(timeStart);
    digitalWrite(pinbomCAM, LOW);
    CAMstatus = 0;
    Serial.println("Rót nước cam xong");
    server.send(200, "text/html", "camOK");
  }

  if (PEPSIstatus) {
    digitalWrite(pinbomPEPSI, HIGH);
    delay(timeStart);
    digitalWrite(pinbomPEPSI, LOW);
    PEPSIstatus = 0;
    Serial.println("rót nước pepsi xong");
    server.send(200, "text/html", "pepsiOK");
  }
  if (LOCstatus) {
    digitalWrite(pinbomLOC, HIGH);
    delay(timeStart);
    digitalWrite(pinbomLOC, LOW);
    LOCstatus = 0;
    Serial.println("rót nước sting xong");
    server.send(200, "text/html", "StingOK");
  }
}
