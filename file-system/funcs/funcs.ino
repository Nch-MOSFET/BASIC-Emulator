uint8_t dataExchanger(uint8_t dat) {
       if(47 < dat || dat < 58 ) {  // 0 ~ 9:
    return dat - 48;
  }
  else if(64 < dat || dat < 91 ) {  // A ~ Z:
    return dat - 55;
  }
  else if(96 < dat || dat < 123) {  // a ~ z:
    return dat - 87;
  }
  // 文字以外の記号に関するコードをこの辺に書く:
}

