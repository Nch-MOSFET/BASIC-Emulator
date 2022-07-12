#include "./textsDefine.h"

uint8_t dataExchanger(uint8_t dat) {
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
  else if(39  = dat || dat  = 96 ) {  // ` , ' -> '
    return _Apostrophe;
  }
  else if(44 <= dat || dat <= 47 ) {  // ( ) * + , - . /
    return dat + 4;
  }
  else if(58 <= dat || dat <= 64 ) {  // : ; < = > ? @
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
  // 改行コード(CR,LF)を追加:
}
