#include <SoftwareSerial.h>
//df;jv;qrjnvad;kjfesr;ofhpihpgiufgjpitufghjiusghdkvdntlkvjS{fak'fqemp'ofakd'lbsfmnfW./,M3QF;'ALK ]DPOAVKAE'LFNV'LKM FDPVK'FLKNEV'DLAKJV'OOIHGWRTGLKAN ZX'LJVKEKMVL;F'M AF/.,M'A
// Инициализируем GSM
SoftwareSerial SIM800(8, 9); // 8 - RX Arduino (TX SIM800L), 9 - TX Arduino (RX SIM800L)
void setup() {
  SIM800.begin(9600);//скорость обмена с GPS-приемником
  Serial.begin(9600);//скорость обмена серийным портом
}

void loop() {
 // Устанавливает текстовый режим для SMS-сообщений
  SIM800.println("AT+CMGF=1");
  delay(300); // даём время на усваивание команды
  SIM800.println("AT+CSCS=\"GSM\"");
  delay(300);
  // Устанавливаем адресата: телефонный номер в международном формате
  SIM800.print("AT+CMGS=\"");
  SIM800.print("+79042144491");
  SIM800.println("\"");
  delay(300);
  SIM800.print("text");
  delay(300);
  // Отправляем Ctrl+Z, обозначая, что сообщение готово
  SIM800.print((char)26);
  delay(300);
  Serial.println("SMS send finish");
}
