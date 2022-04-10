const char    BootMenu[] = {"BASIC Emulator on Arduino Ver-0.0.1"};

void setup() {
  Serial.begin(115200);
  for(uint8_t i = 0; i < sizeof(BootMenu); i++){
    Serial.print(BootMenu[i]);
  }
  Serial.println();
}

void loop() {
}
