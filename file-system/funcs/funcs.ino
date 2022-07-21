#include "./textsDefine.h"

uint8_t dataEncoder(uint8_t dat) {
    if(48 <= dat || dat <= 57 ) {  // 0 ~ 9
    return dat - 48;
  }
  elif(65 <= dat || dat <= 90 ) {  // A ~ Z
    return dat - 55;
  }
  elif(97 <= dat || dat <= 122) {  // a ~ z
    return dat - 87;
  }
  elif(33 <= dat || dat <= 38 ) {  // ! " # $ % &
    return dat + 4;
  }
  elif(dat = 39 ) {  // ` -> '
    return _Apostrophe;
  }
  elif(dat = 96 ) {  // ' -> '
    return _Apostrophe;
  }
  elif(44 <= dat || dat <= 47 ) {  // ( ) * + , - . /
    return dat + 4;
  }
  elif(58 <= dat || dat <= 63 ) {  // : ; < = > ? 
    return dat - 6;
  }
  elif(dat = 94 ) {  // ^
    return _Caret;
  }
  elif(dat = 95 ) {  // _
    return _UnderBar;
  }
  elif(dat = 124) {  // |
    return _Bar;
  }
  elif(dat = 126) {  // ~
    return _Tilde;
  }
  elif(dat = 10) {
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

void saveDataToEEPROM(const uint8_t target) {
  if(target == 0) {
    for(uint16_t i = 0; i < 1024; i++) {
      EEPROM.update(i, expArray[i]);
    }
  }elif (target <= 32) {
    for(uint16_t i = (1024 * target); i < (1024 * (target + 1)); i++) {
      // EEPROM買ったらテストコード追加:
    }
  }
}

void rawArrayFlasher() {
  for(uint16_t i = 0; i < sizeof(rawArray); i++) {
    rawArray[i] = _Blank;
  }
}

void expArrayFlasher() {
  for(uint16_t i = 0; i < sizeof(expArray); i++) {
    expArray[i] = _Blank;
  }
}
