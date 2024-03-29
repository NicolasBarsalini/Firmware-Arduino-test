void setTemperature() {
    #if SET_TEMPERATURE
        int temp = 0;

        lcd.setCursor(0, 0);

        lcd.print("Temperature");

        lcd.setCursor(0, 1);
        lcd.print("Select: ");

        while(digitalRead(HOME)) {
            if(temp < 10 && (digitalRead(RIGHT) || digitalRead(LEFT))) {
                lcd.setCursor(8, 1);
                lcd.print(" ");
                lcd.print(temp);
            } else if(temp < 100 && (digitalRead(RIGHT) || digitalRead(LEFT))) {
                lcd.setCursor(8, 1);
                lcd.print(temp);
            }

            if(!digitalRead(RIGHT)) {
                temp++;
                if(temp >= MAXIMUM_TEMP) {
                    temp = MAXIMUM_TEMP;
                }
            }

            if(!digitalRead(LEFT)) {
                temp--;
                if(temp <= MINIMUM_TEMP) {
                    temp = MINIMUM_TEMP;
                }
            }
        }

        temperatureSeted = temp;

        Serial.print("Temperature Seted! [VALUE=");
        Serial.print(temperatureSeted);
        Serial.println("]");
  #else
    lcd.setCursor(0, 0);
    lcd.print("Not enabled!");
    delay(3000);
  #endif

    lcd.clear();

    delay(500);
}