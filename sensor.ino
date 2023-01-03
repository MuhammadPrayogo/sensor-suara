#define BLYNK_TEMPLATE_ID "TMPLmx9UTkLH"
#define BLYNK_DEVICE_NAME "sensor suara"
#define BLYNK_AUTH_TOKEN "iwO7mfEt7tP1a6mh8-0O4UrahITs99VM"

#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>


// Kode Auth
char auth[]= BLYNK_AUTH_TOKEN;
char ssid[] = "OPPPOA53"; //Nama Wifi
char pass[] = "12345678"; //Password

int Led = D5;
int OutSuara = D4;
int Buzzer = D6;
int val, kondisi;

WidgetLCD lcd(V1);

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(Led, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(OutSuara, INPUT);
  kondisi = 0; //Kondisi Lampu Awal Nyala
}

void Bunyi1(){
  digitalWrite(Buzzer, HIGH);
  delay(1000);
  digitalWrite(Buzzer, LOW);
}

void Bunyi2(){
  digitalWrite(Buzzer, HIGH);
  delay(500);
  digitalWrite(Buzzer, LOW);
  delay(500);
  digitalWrite(Buzzer, HIGH);
  delay(500);
  digitalWrite(Buzzer, LOW);
}

void loop() {
  Blynk.run();
  
  val = digitalRead(OutSuara);
  if((val == HIGH)&&(kondisi == 0)){
    kondisi = 1;
    Bunyi2();
    digitalWrite(Led, HIGH);
    Serial.println("Lampu Menyala");
    lcd.print(0, 0, "STATUS LAMPU");
    lcd.print(0, 1, "Lampu Hidup");
  }else if ((val == HIGH)&&(kondisi == 1)){
    kondisi = 0;
    Bunyi1();
    digitalWrite(Led, LOW);
    Serial.println("Lampu Mati");
    lcd.print(0, 0, "STATUS LAMPU");
    lcd.print(0, 1, "Lampu Padam");
  }else{
    
  }
 }   
