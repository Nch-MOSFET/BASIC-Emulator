#define ROWs 32  //最大行数;
#define COLs 32  //行当たり最大文字数:

const char    BootMenu[] = {"BASIC Emulator on Arduino Ver-0.0.1-Beta"};

      uint8_t workingROW = 0;
      uint8_t workingCOL = 0;

      uint8_t BASIC[ROWs][COLs];
      uint8_t Buffer     [COLs];

      uint8_t counter;

void setup() {
  Serial.begin(115200);
  for(uint8_t i = 0; i < sizeof(BootMenu); i++){
    Serial.print(BootMenu[i]);
  }
  Serial.println();

  pinMode(13, OUTPUT);
}

void loop() {
  Serials();
}

void ReturnTXT(uint8_t datSize){
  for(uint8_t i = 0; i < datSize; i++){
    Serial.write(Buffer[i]);
  }
}

void Serials(){
  workingCOL = 0;
  while(Serial.available() > 0) {
    uint8_t dat = Serial.read();
    Buffer[workingCOL] = dat;
    workingCOL++;
  }
  ReturnTXT(workingCOL);
}
