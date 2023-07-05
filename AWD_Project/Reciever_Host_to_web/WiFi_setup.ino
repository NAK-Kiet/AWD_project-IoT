void wifisetupInit(){
    WiFi.mode(WIFI_STA);
  //WiFi.begin(ssid, password);
  WiFiManager wm;
  wm.resetSettings();
  bool res;
  res = wm.autoConnect("AWD Demo","12345678");
  
  if(!res){
    Serial.println("Fail To connect");
  }
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}