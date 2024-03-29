void menu() {
    int opt = 0;

    lcd.clear();

    delay(300);

    while(digitalRead(HOME)) {

        if(opt >= 3) {
            opt = 3;
        }

        if(opt <= 0) {
            opt = 0;
        }

        if(!digitalRead(RIGHT)) {
            opt++;
            lcd.clear();
        }

        if(!digitalRead(LEFT)) {
            opt--;
            lcd.clear();
        }

        if(opt >= 2) {
            lcd.setCursor(1, 0);
            lcd.print("Set humidity");

            lcd.setCursor(1, 1);
            lcd.print("Set fan");
        } else {

            lcd.setCursor(1, 0);
            lcd.print("Home");

            lcd.setCursor(1, 1);
            lcd.print("Set temperature");
        }

        Serial.println(opt);

        switch(opt) {
            case 0:
                lcd.setCursor(0, 0);
                lcd.print("<");

                lcd.setCursor(0, 1);
                lcd.print(" ");
                break;

            case 1:
                lcd.setCursor(0, 0);
                lcd.print(" ");

                lcd.setCursor(0, 1);
                lcd.print(">");
                break;

            case 2:
                lcd.setCursor(0, 0);
                lcd.print(">");

                lcd.setCursor(0, 1);
                lcd.print(" ");
                break;

            case 3:
                lcd.setCursor(0, 0);
                lcd.print(" ");

                lcd.setCursor(0, 1);
                lcd.print(">");
                break;
    
        }
    }

    lcd.clear();
    // lcd.setCursor(0,0);
    // lcd.print(opt);
    delay(500);
    // lcd.clear();

    switch(opt) {
      case 0:
        loop();
        break;
      case 1:
        setTemperature();
        break;
      case 2:
        setHumidity();
        break;
      case 3:
        setFan();
        break;
    }
}