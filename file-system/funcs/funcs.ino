#include "./textsDefine.h"

uint8_t decodeArray[64] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 32, 33, 34, 35, 36, 37, 38, 124, 40, 41, 42, 43, 44, 45, 46, 47, 58, 59, 60, 61, 62, 63, 64, 94, 95, 39, 126, 10};

uint8_t rawArray[1365];
uint8_t expArray[1024];

uint8_t expanded[4];    // 展開後のデータ保管用:
uint8_t compressed[3];  // 圧縮後のデータ保管用:

uint8_t dataEncoder(uint8_t dat) {
       if(48 <= dat || dat <= 57 ) {  // 0 ~ 9
    return dat - 48;
  }
  else if(65 <= dat || dat <= 90 ) {  // A ~ Z
    return dat - 55;
  }
  else if(97 <= dat || dat <= 122) {  // a ~ z
    return dat - 87;
  }
  else if(33 <= dat || dat <= 38 ) {  // ! " # $ % &
    return dat + 4;
  }
  else if(dat = 39 ) {  // ` -> '
    return _Apostrophe;
  }
  else if(dat = 96 ) {  // ' -> '
    return _Apostrophe;
  }
  else if(44 <= dat || dat <= 47 ) {  // ( ) * + , - . /
    return dat + 4;
  }
  else if(58 <= dat || dat <= 63 ) {  // : ; < = > ? 
    return dat - 6;
  }
  else if(dat = 94 ) {  // ^
    return _Caret;
  }
  else if(dat = 95 ) {  // _
    return _UnderBar;
  }
  else if(dat = 124) {  // |
    return _Bar;
  }
  else if(dat = 126) {  // ~
    return _Tilde;
  }
  else if(dat = 10) {
    return _Enter;
  }
}

uint8_t dataDecoder(uint8_t seed) {
  return decodeArray[seed];
}

void dataCompresser(uint8_t seed1, uint8_t seed2, uint8_t seed3, uint8_t seed4) {
/*
 * 圧縮前
 * 111111
 *       222222
 *             333333
 *                   444444
 * 圧縮後
 * 11111122
 *         22223333
 *                 33444444
 */

  compressed[0] = 0;
  compressed[1] = 0;
  compressed[2] = 0;
  
  compressed[0] = (seed1 << 2) + (seed2 >> 4);
  compressed[1] = (seed2 << 4) + (seed3 >> 2);
  compressed[2] = (seed3 << 6) +  seed4;
}

void dataExpander(uint8_t seed1, uint8_t seed2, uint8_t seed3) {
/*
 * 展開後
 * 11111111
 *         22222222
 *                 33333333
 * 展開前
 * 111111
 *       112222
 *             222233
 *                   333333
 */

  expanded[0] = 0;
  expanded[1] = 0;
  expanded[2] = 0;
  expanded[3] = 0;

  expanded[0] =   seed1 >> 2;
  expanded[1] = ((seed1 << 4) + (seed2 >> 4)) & 0b00111111;
  expanded[2] = ((seed2 << 2) + (seed3 >> 6)) & 0b00111111;
  expanded[3] =   seed3                       & 0b00111111;
}
