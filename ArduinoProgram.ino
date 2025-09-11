#include <Servo.h>
#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

const int relay_BerasKencur = A0;
const int relay_KunirAsem = A1;
const int ldrPin = A3;
const int tombol_BerasKencur = 8;
const int tombol_KunirAsem = 9;
const int led_Coin = 4;
const int led_BerasKencur = 6;
const int led_KunirAsem = 5;
const int servoPin = 11;

const int waitingJamu = 4000;

const int dfTX = 7;
const int dfRX = 2;
SoftwareSerial mySerial(dfRX, dfTX);

Servo myServo;
int currentPos = 90;

void setup() {
  Serial.begin(9600);
  pinMode(relay_BerasKencur, OUTPUT);
  pinMode(relay_KunirAsem, OUTPUT);
  pinMode(ldrPin, INPUT);
  pinMode(tombol_BerasKencur, INPUT_PULLUP);
  pinMode(tombol_KunirAsem, INPUT_PULLUP);
  pinMode(led_Coin, OUTPUT);
  pinMode(led_BerasKencur, OUTPUT);
  pinMode(led_KunirAsem, OUTPUT);


  digitalWrite(relay_BerasKencur, HIGH);
  digitalWrite(relay_KunirAsem, HIGH);
  digitalWrite(led_Coin, LOW);
  digitalWrite(led_BerasKencur, LOW);
  digitalWrite(led_KunirAsem, LOW);

  myServo.attach(servoPin);
  myServo.write(currentPos);

  mySerial.begin(9600);
  mp3_set_serial(mySerial);
  delay(1000);
  mp3_set_volume(100);
}

void loop() {
  Serial.print("Deteksi Coin: ");
  Serial.println(analogRead(ldrPin));

  if (analogRead(ldrPin) >= 900) {

    Serial.println("Koin Terdeteksi");

    mp3_play(15);

    digitalWrite(led_Coin, HIGH);
    delay(100);
    digitalWrite(led_Coin, LOW);

    delay(1000);

    while (true) {
      myServo.write(90);
      if (digitalRead(tombol_BerasKencur) == LOW) {
        mp3_play(12);
        delay(500);
        aksiTombol_BerasKencur();
        mp3_play(20);
        break;
      }
      if (digitalRead(tombol_KunirAsem) == LOW) {
        mp3_play(18);
        delay(500);
        aksiTombol_KunirAsem();
        mp3_play(20);
        break;
      }
    }
  }
}

void aksiTombol_BerasKencur() {
  Serial.println("Tombol Beras Kencur diTekan");
  digitalWrite(led_BerasKencur, HIGH);

  servoSmoothMove(currentPos, 180);
  currentPos = 180;
  delay(1000);

  triggerRelay_BerasKencur();

  servoSmoothMove(currentPos, 90);
  currentPos = 90;
  delay(1000);

  digitalWrite(led_BerasKencur, LOW);
  delay(1000);
}

void aksiTombol_KunirAsem() {
  Serial.println("Tombol Kunir Asem diTekan");
  digitalWrite(led_KunirAsem, HIGH);

  servoSmoothMove(currentPos, 0);
  currentPos = 0;
  delay(1000);

  triggerRelay_KunirAsem();

  servoSmoothMove(currentPos, 90);
  currentPos = 90;
  delay(1000);

  digitalWrite(led_KunirAsem, LOW);
  delay(1000);
}


void servoSmoothMove(int fromPos, int toPos) {
  if (fromPos < toPos) {
    for (int pos = fromPos; pos <= toPos; pos++) {
      Serial.println("Servo Bergerak");
      myServo.write(pos);
      Serial.println(pos);
      delay(15);

    }
  } else {
    for (int pos = fromPos; pos >= toPos; pos--) {
      Serial.println("Servo Bergerak");
      myServo.write(pos);
      Serial.println(pos);
      delay(15);
    }
  }
}


void triggerRelay_BerasKencur() {
  digitalWrite(relay_BerasKencur, LOW);
  Serial.println("Pompa Beras Kencur Nyala");
  delay(100);
  digitalWrite(relay_BerasKencur, HIGH);

  delay(waitingJamu);

  digitalWrite(relay_BerasKencur, LOW);
  Serial.println("Pompa Beras Kencur Mati");
  delay(100);
  digitalWrite(relay_BerasKencur, HIGH);
}

void triggerRelay_KunirAsem() {
  digitalWrite(relay_KunirAsem, LOW);
  Serial.println("Pompa Kunir Asem Nyala");
  delay(100);
  digitalWrite(relay_KunirAsem, HIGH);

  delay(waitingJamu);

  digitalWrite(relay_KunirAsem, LOW);
  Serial.println("Pompa Kunir Asem Mati");
  delay(100);
  digitalWrite(relay_KunirAsem, HIGH);
}
