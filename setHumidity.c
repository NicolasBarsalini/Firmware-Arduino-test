void setHumidity() {
  #if SET_HUMIDITY
    int hum = 0;

    lcd.setCursor(0, 0);

    lcd.print("Humidity");

    lcd.setCursor(0, 1);
    lcd.print("Select: ");

    while(digitalRead(HOME)) {
        if(hum < 10 && (digitalRead(RIGHT) || digitalRead(LEFT))) {
            lcd.setCursor(8, 1);
            lcd.print(" ");
            lcd.print(hum);
        } else if(hum < 100 && (digitalRead(RIGHT) || digitalRead(LEFT))) {
            lcd.setCursor(8, 1);
            lcd.print(hum);
        }

        if(!digitalRead(RIGHT)) {
            hum++;
            if(hum >= MAXIMUM_HUMIDITY) {
                hum = MAXIMUM_HUMIDITY;
            }
        }

        if(!digitalRead(LEFT)) {
            hum--;
            if(hum <= MINIMUM_HUMIDITY) {
                hum = MINIMUM_HUMIDITY;
            }
        }
    }

    humiditySeted = hum;
    
    Serial.print("Humidity Seted! [VALUE=");
    Serial.print(humiditySeted);
    Serial.println("]");

  #else
    lcd.setCursor(0, 0);
    lcd.print("Not enabled!");
    delay(3000);
  #endif

    lcd.clear();

    delay(500);
}