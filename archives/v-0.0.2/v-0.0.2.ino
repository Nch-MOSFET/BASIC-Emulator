#define COLs 32  //行当たり最大文字数:

const char    BootMenu[] = {"BASIC Emulator on Arduino Ver-0.0.2"};

      uint8_t workingCOL = 0;

      uint8_t Buffer[COLs];

void setup() {
  Serial.begin(115200);
  for(uint8_t i = 0; i < sizeof(BootMenu); i++){
    Serial.print(BootMenu[i]);
  }
  Serial.println();

  pinMode(13, OUTPUT);
}

void loop() {
  readSerials();
}

void ReturnTXT(uint8_t datSize){
  for(uint8_t i = 0; i < datSize; i++){
    Serial.write(Buffer[i]);
  }
}

void readSerials(){
  workingCOL = 0;
  while(Serial.available() > 0) {
    uint8_t dat = Serial.read();
    Buffer[workingCOL] = dat;
    workingCOL++;
  }
  ReturnTXT(workingCOL);
}
