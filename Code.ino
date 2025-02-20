#include <EEPROM.h>
#include <SoftwareSerial.h>
int counter;
int address;
SoftwareSerial A9G(2, 3);  // RX and TX

void setup() {
  // put your setup code here, to run once:
  address = 32;
  counter = EEPROM.read(address);
  A9G.begin(9600);
  Serial.begin(9600);

  Serial.println("Initializing...");
  A9G.println("AT");
  delay(1000);
  checkSerialResponse();
  A9G.println("AT+CGATT=1");
  delay(1000);
  checkSerialResponse();
  A9G.println("AT+CGDCONT=1,\"IP\",\"mtnirancell\"");
  delay(1000);
  checkSerialResponse();
  A9G.println("AT+CGACT=1,1");
  delay(1000);
  checkSerialResponse();
  A9G.println("AT+HTTPINIT");
  delay(1000);
  checkSerialResponse();
  A9G.println("AT+HTTPPARA=\"CID\",1");
  delay(1000);
  checkSerialResponse();
  A9G.println("AT+HTTPPARA=\"URL\",\"https://www.ee.sharif.ir/\"");
  delay(1000);
  checkSerialResponse();
  A9G.println("AT+HTTPACTION=0");
  delay(1000);
  checkSerialResponse();
  A9G.println("AT+HTTPREAD");
  delay(1000);
  checkSerialResponse();
  A9G.println("AT+HTTPTERM");
  delay(1000);
  checkSerialResponse();

  /*
  Serial.println("Initializing...");
  mySerial.listen();
  mySerial.println("AT+CMGF=1");
  mySerial.println("AT+CMGS=\"09902532131\"");
  mySerial.write(13);
  mySerial.print(counter);
  Serial.println(counter);
  mySerial.write(0x1A);
  Serial.println();
  Serial.println("Initializing...");
  Serial.println(mySerial.println("AT+CGATT=1"));
  Serial.println(mySerial.println("AT+CGDCONT=1,\"IP\",\"mtnirancell\""));
  Serial.println(mySerial.println("AT+CGACT=1,1")); 
  Serial.println(mySerial.println("AT+HTTPINIT"));
  Serial.println(mySerial.println("AT+HTTPPARA=\"CID\",1"));
  Serial.println(mySerial.println("AT+HTTPPARA=\"URL\",\"https://www.ee.sharif.ir/\""));
  Serial.println(mySerial.println("AT+HTTPACTION=0"));
  Serial.println(mySerial.println("AT+HTTPREAD"));
  Serial.println(mySerial.println("AT+HTTPTERM"));
  Serial.println("End of Task...");
  */
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  digitalWrite(12, 1);
  digitalWrite(13, 1);
  digitalWrite(19, 1);
}

int numberDisplay[8];
int array[8];

void loop() {

  if (digitalRead(15) == 0) {
    EEPROM.update(address, 0);
    counter = 0;
  }
  if (digitalRead(14) == 0) {
    counter++;
    EEPROM.update(address, counter);
    
    Serial.println("Initializing...");
    A9G.println("AT");
    delay(1000);
    checkSerialResponse();
    A9G.println("AT+CGATT=1");
    delay(1000);
    checkSerialResponse();
    A9G.println("AT+CGDCONT=1,\"IP\",\"mtnirancell\"");
    delay(1000);
    checkSerialResponse();
    A9G.println("AT+CGACT=1,1");
    delay(1000);
    checkSerialResponse();
    A9G.println("AT+HTTPINIT");
    delay(1000);
    checkSerialResponse();
    A9G.println("AT+HTTPPARA=\"CID\",1");
    delay(1000);
    checkSerialResponse();
    A9G.println("AT+HTTPPARA=\"URL\",\"https://www.ee.sharif.ir/\"");
    delay(1000);
    checkSerialResponse();
    A9G.println("AT+HTTPACTION=0");
    delay(1000);
    checkSerialResponse();
    A9G.println("AT+HTTPREAD");
    delay(1000);
    checkSerialResponse();
    A9G.println("AT+HTTPTERM");
    delay(1000);
    checkSerialResponse();

    while (!digitalRead(14)) {
      digitalWrite(12, 1);
      digitalWrite(13, 1);
      digitalWrite(19, 1);
      numberFinder(counter % 10);
      display(array);
      digitalWrite(12, 0);
      delay(5);

      digitalWrite(12, 1);
      digitalWrite(13, 1);
      digitalWrite(19, 1);
      numberFinder((counter / 10) % 10);
      display(array);
      digitalWrite(13, 0);
      delay(5);

      digitalWrite(12, 1);
      digitalWrite(13, 1);
      digitalWrite(19, 1);
      numberFinder(counter / 100);
      display(array);
      digitalWrite(19, 0);
      delay(5);
    }
  }
  digitalWrite(12, 1);
  digitalWrite(13, 1);
  digitalWrite(19, 1);
  numberFinder(counter % 10);
  display(array);
  digitalWrite(12, 0);
  delay(5);

  digitalWrite(12, 1);
  digitalWrite(13, 1);
  digitalWrite(19, 1);
  numberFinder((counter / 10) % 10);
  display(array);
  digitalWrite(13, 0);
  delay(5);

  digitalWrite(12, 1);
  digitalWrite(13, 1);
  digitalWrite(19, 1);
  numberFinder(counter / 100);
  display(array);
  digitalWrite(19, 0);
  delay(5);
}


void numberFinder(int num) {
  if (num == 0) {
    array[0] = 1;
    array[1] = 1;
    array[2] = 1;
    array[3] = 1;
    array[4] = 1;
    array[5] = 1;
    array[6] = 0;
    array[7] = 0;
  } else if (num == 1) {
    array[0] = 0;
    array[1] = 1;
    array[2] = 1;
    array[3] = 0;
    array[4] = 0;
    array[5] = 0;
    array[6] = 0;
    array[7] = 0;
  } else if (num == 2) {
    array[0] = 1;
    array[1] = 1;
    array[2] = 0;
    array[3] = 1;
    array[4] = 1;
    array[5] = 0;
    array[6] = 1;
    array[7] = 0;
  } else if (num == 3) {
    array[0] = 1;
    array[1] = 1;
    array[2] = 1;
    array[3] = 1;
    array[4] = 0;
    array[5] = 0;
    array[6] = 1;
    array[7] = 0;
  } else if (num == 4) {
    array[0] = 0;
    array[1] = 1;
    array[2] = 1;
    array[3] = 0;
    array[4] = 0;
    array[5] = 1;
    array[6] = 1;
    array[7] = 0;
  } else if (num == 5) {
    array[0] = 1;
    array[1] = 0;
    array[2] = 1;
    array[3] = 1;
    array[4] = 0;
    array[5] = 1;
    array[6] = 1;
    array[7] = 0;
  } else if (num == 6) {
    array[0] = 1;
    array[1] = 0;
    array[2] = 1;
    array[3] = 1;
    array[4] = 1;
    array[5] = 1;
    array[6] = 1;
    array[7] = 0;
  } else if (num == 7) {
    array[0] = 1;
    array[1] = 1;
    array[2] = 1;
    array[3] = 0;
    array[4] = 0;
    array[5] = 0;
    array[6] = 0;
    array[7] = 0;
  } else if (num == 8) {
    array[0] = 1;
    array[1] = 1;
    array[2] = 1;
    array[3] = 1;
    array[4] = 1;
    array[5] = 1;
    array[6] = 1;
    array[7] = 0;
  } else if (num == 9) {
    array[0] = 1;
    array[1] = 1;
    array[2] = 1;
    array[3] = 1;
    array[4] = 0;
    array[5] = 1;
    array[6] = 1;
    array[7] = 0;
  }
}

void display(int numberString[8]) {
  for (int i = 0; i < 8; i++) {
    if (numberString[i] == 1) {
      digitalWrite(i + 4, HIGH);
    } else {
      digitalWrite(i + 4, LOW);
    }
  }
}
/*
void sendATCommand(String command, const int timeout) {
  mySerial.println(command);
  long int time = millis();
  while ((time + timeout) > millis()) {
    while (mySerial.available()) {
      char c = mySerial.read();
      Serial.write(c);
    }
  }
}
*/

void checkSerialResponse(){
  while(A9G.available()){
    Serial.write(A9G.read());
  }
}