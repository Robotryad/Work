#include <DallasTemperature.h>
#include <OneWire.h>

//TEMP
#define tempbodyPin 4
#define powerTempPin 6

int temp;

OneWire oneWire(tempPin);
DallasTemperature sensorTemp(&oneWire);

void setup() {
  Serial.begin(9600);//скорость обмена серийным портом
  pinMode (tempPin, INPUT);//измерение температуры тела - в серийный порт
  pinMode (powerTempPin, OUTPUT);//вывод температуры тела
}

void loop() {
  sensorTemp.begin();
  digitalWrite(powerTempPin, HIGH);
  sensorTemp.requestTemperatures();
  delay(500);
  sensorTemp.requestTemperatures();
  int temp = round(float(sensorTemp.getTempCByIndex(0)));
  digitalWrite(powerTempPin, LOW);
  Serial.print("temp= "); Serial.println(temp);
}
