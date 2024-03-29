#include <dht.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

// FUNCTIONS ENABLED
#define SET_HUMIDITY 1
#define SET_TEMPERATURE 1
#define SET_FAN 0

//defines
#define BUZZER 19 // Digital pin used by buzzer, to do a "bip"
#define PINDHT22 25 // Analog pin used by DHT11 humidity sensor
#define ONEWIREBUS 13 // Pin OneWire for temperature sensor
#define FAN 14
#define HOME 15
#define LEFT 4
#define RIGHT 27
#define RELAY 5

#define MAXIMUM_TEMP 50
#define MINIMUM_TEMP 0

#define MAXIMUM_HUMIDITY 100
#define MINIMUM_HUMIDITY 0

#define MAXIMUM_FAN 100
#define MINIMUM_FAN 0

dht DHT;
OneWire oneWire(ONEWIREBUS);
DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd(0x27, 16, 2);

float humidityCalculator();
float temperatureCalculator();

void setTemperature();
void setHumidity();
void setFan();

float temperature = 0, humidity = 0, fan = 0;
int temperatureSeted = NULL, humiditySeted = NULL, fanSeted = NULL;

void setup(){
  Serial.begin(9600);
  pinMode(PINDHT22, INPUT);
  pinMode(HOME, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  sensors.begin();

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Estufa MarkZ8");
  lcd.setCursor(2,1);
  lcd.print("version 2.0");
  delay(3000);
  lcd.clear();
} 

void loop() {
    
    if(!digitalRead(HOME)) {
        menu();
    }

    temperature = temperatureCalculator();
    humidity = humidityCalculator();

    lcd.setCursor(0,0);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print("C");

    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(round(humidity));
}

float humidityCalculator(){
  DHT.read22(PINDHT22);
  return DHT.humidity;
}

float temperatureCalculator(){
  sensors.requestTemperatures();
  return sensors.getTempCByIndex(0);
}