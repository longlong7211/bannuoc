void adminlogin() {
  Serial.println("Admin login");
  server.send(200, "text/html", sendHTMLADMIN());
  statusgettime=1;
}
void handle_OnConnect() {
  CAMstatus = 0;
  PEPSIstatus = 0;
  LOCstatus = 0;
  Serial.println("CONNECTED");
  server.send(200, "text/html", SendHTML());
}

void camON() {
  CAMstatus = 1;
  Serial.println("dang rot nuoc cam");
}

void pepsiON() {
  PEPSIstatus = 1;
  Serial.println("Dang rot nuoc pepsi");
}

void locON() {
  LOCstatus = 1;
  Serial.println("Dang rot nuoc sting");
}

void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}
//set time rot nuoc
void settime() {
  if (server.hasArg("TIMEROT") && statusgettime) {
    statusgettime = 0;
    Serial.println("Set thời gian rót nước lưu EEPROM");
    Serial.print("trạng thái của hasArg: ");
    Serial.println(server.hasArg("TIMEROT"));
    Serial.print("thời gian get được: ");
    Serial.println(server.arg("TIMEROT"));
    if (server.hasArg("TIMEROT")) {
      String t;
      t = server.arg("TIMEROT");
      EEPROM.write(100, t[0]);
      Serial.println("thời gian rót");
      Serial.println(t);
      EEPROM.commit();
      Serial.print("giá trị EEPROM: ");
      int er=map(EEPROM.read(100),49,57,1,9);
      Serial.println(er);
      timeStart=er*1000;
      handle_OnConnect();
    }
  }
}
