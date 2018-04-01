#include <TinyGPS.h>
#include <SoftwareSerial.h>

// GPS
#define OK 1
#define NOTOK 2
#define RST 3

// Инициализируем GPS
SoftwareSerial gpsSerial(10, 11);
TinyGPS gps;

// Переменные для GPS
bool newdata = false;
unsigned long start;
long lat, lon;
unsigned long times, date;

void setup() {
  gpsSerial.begin(9600); // скорость обмена с GPS-приемником

  Serial.begin(9600);//скорость обмена серийным портом
  Serial.println("test gps");
}

void loop() {
  // задержка в секунду между обновлениями координат

  if (millis() - start > 1000)
  {
    newdata = readgps();
    Serial.println(newdata);
    if (newdata)
    {
      start = millis();
      gps.get_position(&lat, &lon);
      gps.get_datetime(&date, &times);
      Serial.print("Lat: "); Serial.print(lat);
      Serial.print(" Long: "); Serial.print(lon);
      Serial.print(" Date: "); Serial.print(date);
      Serial.print(" Time: "); Serial.println(times);
    }
  }
}
bool readgps()
{
  while (gpsSerial.available())
  {
    int b = gpsSerial.read();
    //в TinyGPS есть ошибка: не обрабатываются данные с \r и \n
    if ('\r' != b)
    {
      if (gps.encode(b))
        return true;
    }
  }
  return false;
}
