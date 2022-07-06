#include "./textsDefine.h"

uint8_t dataExchanger(uint8_t dat) {
       if(48 <= dat || dat <= 57 ) {  // 0 ~ 9:
    return dat - 48;
  }
  else if(65 <= dat || dat <= 90 ) {  // A ~ Z:
    return dat - 55;
  }
  else if(97 <= dat || dat <= 122) {  // a ~ z:
    return dat - 87;
  }
  // 文字以外の記号に関するコードをこの辺に書く:
}

