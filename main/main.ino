uint8_t incomingByte = 0;

char Large[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char Small[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Mark1[16] = {' ', '!', '"', '#', '$', '%', '&', ' ', '(', ')', '*', '+', ',', '-', '.', '/'};
char Mark2[ 7] = {':', ';', '<', '=', '>', '?', '`'};
char Mark3[ 6] = {'[', ' ', ']', '^', '_', '`'};
char Mark4[ 4] = {'{', ' ', '}', '~'}

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();

          if(incomingByte >= 0x20 && 0x2F >= incomingByte){
      Serial.print(encorder_Chr(incomingByte));
    }else if(incomingByte >= 0x30 && 0x39 >= incomingByte){
      Serial.print(encorder_Num(incomingByte));
    }else if(incomingByte >= 0x41 && 0x5A >= incomingByte){
      Serial.print(encorder_Chr(incomingByte));
    }else if(incomingByte >= 0x5B && 0x60 >= incomingByte){
      Serial.print(encorder_Chr(incomingByte));
    }else if(incomingByte >= 0x61 && 0x7A >= incomingByte){
      Serial.print(encorder_Chr(incomingByte));
    }else if(incomingByte >= 0x3A && 0x40 >= incomingByte){
      Serial.print(encorder_Chr(incomingByte));
    }else if(incomingByte >= 0x7B && 0x7E >= incomingByte){
      Serial.print(encorder_Chr(incomingByte));
    }else{
      Serial.println();
    }
  }
}
uint8_t encorder_Num(uint8_t dat){
  //0~9の処理:
  if(dat >= 0x30 && 0x39 >= dat){
    return (dat - 0x30);
  }
}
char encorder_Chr(uint8_t dat){
  //A~Zの処理:
  if(dat >= 0x41 && 0x5A >= dat){
    return Large[dat - 0x41];
  }
  //a~zの処理:
  else if(dat >= 0x61 && 0x7A >= dat){
    return Small[dat - 0x61];
  }
  //記号とか:
  else if(dat >= 0x20 && 0x2F >= dat){
    return Mark1[dat - 0x20];
  }
  else if(dat >= 0x3A && 0x40 >= dat){
    return Mark2[dat - 0x3A];
  }
  else if(dat >= 0x5B && 0x60 >= dat){
    return Mark3[dat - 0x5B];
  }
  else if(dat >= 0x7B && 0x7E >= dat){
    return Mark4[dat - 0x7B];
  }
  //例外処理:
  else{
    return dat;
  }
}
