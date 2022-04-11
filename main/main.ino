#define COLs 32  //行当たり最大文字数:

const char BootMenu[] = {"BASIC Emulator on Arduino Ver-0.1.1-beta"};

uint8_t workingCOL = 0;

uint8_t Buffer[COLs];

void setup() {
  Serial.begin(115200);
  for (uint8_t i = 0; i < sizeof(BootMenu); i++) {
    Serial.print(BootMenu[i]);
  }
  Serial.println();

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13,  LOW);
}

void loop() {
  if(Serial.available() > 0){
    readSerials();
  }
}

void ReturnTXT(uint8_t datSize) {
  for (uint8_t i = 0; i < datSize; i++) {
    Serial.print(Buffer[i], HEX);
    Serial.print(" ");
  }
}

void runFunc() {
  //LED関数ここから:
  if (Buffer[0] == 0x4C && Buffer[1] == 0x45 && Buffer[2] == 0x44 && Buffer[3] == 0x20 && Buffer[5] == 0x0A) {
    if (Buffer[4] == 0x30) {
      digitalWrite(13,  LOW);
    } else if(Buffer[4] == 0x31){
      digitalWrite(13, HIGH);
    } else {
      Serial.println("Syntax Error...");
    }
  }
  //LED関数ここまで:

  //WAIT関数ここから:
  if (Buffer[0] == 0x57 && Buffer[1] == 0x41 && Buffer[2] == 0x49 && Buffer[3] == 0x54 && Buffer[4] == 0x20){
    //作業中 in here:
  }
  else {
    Serial.println("Syntax Error...");
  }
  //↓のやつ本当ならセーブ後が望ましい:
  for(uint8_t i = 0; i < COLs; i++){
    Buffer[i] = 0;
  }
}

void readSerials() {
  workingCOL = 0;
  while (Serial.available() > 0) {
    delay(4);  //何故かこれを無くすと挙動が崩れる:
    uint8_t dat = Serial.read();
    Buffer[workingCOL] = dat;
    workingCOL++;
  }
  ReturnTXT(workingCOL);
  //Serial.println(workingCOL);
  runFunc();
}
