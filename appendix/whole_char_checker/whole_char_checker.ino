#define BaudRate 115200

void setup() {
  Serial.begin(BaudRate);

  Serial.println("Start...");

  Serial.println("number,data,isAlpha,isAlphaNumeric,isAscii,isControl,isDigit,isGraph,isHexadecimalDigit,isLowerCase,isUpperCase,isPrintable,isPunct,isSpace,isWhitespace");

  for (uint16_t i = 0; i < 256; i++) {
    Serial.print(i);                       Serial.print(",");
    Serial.write(i);                       Serial.print(",");
    Serial.print(isAlpha(i));              Serial.print(",");
    Serial.print(isAlphaNumeric(i));       Serial.print(",");
    Serial.print(isAscii(i));              Serial.print(",");
    Serial.print(isControl(i));            Serial.print(",");
    Serial.print(isDigit(i));              Serial.print(",");
    Serial.print(isGraph(i));              Serial.print(",");
    Serial.print(isHexadecimalDigit(i));   Serial.print(",");
    Serial.print(isLowerCase(i));          Serial.print(",");
    Serial.print(isUpperCase(i));          Serial.print(",");
    Serial.print(isPrintable(i));          Serial.print(",");
    Serial.print(isPunct(i));              Serial.print(",");
    Serial.print(isSpace(i));              Serial.print(",");
    Serial.print(isWhitespace(i));         Serial.println();
  }
}

void loop() {
}
