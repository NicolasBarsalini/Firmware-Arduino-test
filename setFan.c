void setFan() {
  #if SET_FAN
    int fanSpeed = 0;

    lcd.setCursor(0, 0);

    lcd.print("Fan");

    lcd.setCursor(0, 1);
    lcd.print("Select: ");

    while(digitalRead(HOME)) {
        if(fanSpeed < 10 && (digitalRead(RIGHT) || digitalRead(LEFT))) {
            lcd.setCursor(8, 1);
            lcd.print(" ");
            lcd.print(fanSpeed);
        } else if(fanSpeed < 100 && (digitalRead(RIGHT) || digitalRead(LEFT))) {
            lcd.setCursor(8, 1);
            lcd.print(fanSpeed);
        }

        if(!digitalRead(RIGHT)) {
            fanSpeed++;
            if(fanSpeed >= MAXIMUM_FAN) {
                fanSpeed = MAXIMUM_FAN;
            }
        }

        if(!digitalRead(LEFT)) {
            fanSpeed--;
            if(fanSpeed <= MINIMUM_FAN) {
                fanSpeed = MINIMUM_FAN;
            }
        }
    }

    fanSeted = fanSpeed;
    
    Serial.print("Fan Seted! [VALUE=");
    Serial.print(fanSeted);
    Serial.println("]");

  #else
    lcd.setCursor(0, 0);
    lcd.print("Not enabled!");
    delay(3000);
  #endif

    lcd.clear();

    delay(500);
}