/*---------------------------------------------------------------------------------------------

  Open Sound Control (OSC) library for the ESP8266/ESP32

  Example for receiving open sound control (OSC) messages on the ESP8266/ESP32
  Send integers '0' or '1' to the address "/led" to turn on/off the built-in LED of the esp8266.

  This example code is in the public domain.

--------------------------------------------------------------------------------------------- */
#ifdef ESP8266
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#endif
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCBundle.h>
#include <OSCData.h>

char ssid[] = "HUAWEI_311_FA98";          // your network SSID (name)
char pass[] = "RAADH00RLAM";                    // your network password

// A UDP instance to let us send and receive packets over UDP
WiFiUDP Udp;
const IPAddress outIp(192,168,8,101);        // remote IP (not needed for receive)
const unsigned int outPort = 57120;          // remote port (not needed for receive)
const unsigned int localPort = 8888;        // local port to listen for UDP packets (here's where we send the packets)


OSCErrorCode error;
unsigned int ledState = LOW;              // LOW means led is *on*

#ifndef BUILTIN_LED
#ifdef LED_BUILTIN
#define BUILTIN_LED LED_BUILTIN
#else
#define BUILTIN_LED 12
#endif
#endif

int stimulator1a = 15;
int stimulator1b = 2;
int stimulator2a = 4;
int stimulator2b = 16;
int stimulator3a = 17;
int stimulator3b = 5;
int stimulator4a = 18;
int stimulator4b = 19;
int buttonPin = 13; // Pin donde está conectado el botón
const int T_HIGH = 40;
const int T_LOW = 40;
const int SAFE_TIME = 10;

void setup() {

  pinMode(stimulator1a, OUTPUT);
  pinMode(stimulator1b, OUTPUT);
  pinMode(stimulator2a, OUTPUT);
  pinMode(stimulator2b, OUTPUT);
  pinMode(stimulator3a, OUTPUT);
  pinMode(stimulator3b, OUTPUT);
  pinMode(stimulator4a, OUTPUT);
  pinMode(stimulator4b, OUTPUT);
  //pinMode(led, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Configurar el pin del botón como entrada con resistencia interna de pull-up
    
  digitalWrite(stimulator1a, LOW);
  digitalWrite(stimulator1b, LOW);
  digitalWrite(stimulator2a, LOW);
  digitalWrite(stimulator2b, LOW);
  digitalWrite(stimulator3a, LOW);
  digitalWrite(stimulator3b, LOW);
  digitalWrite(stimulator4a, LOW);
  digitalWrite(stimulator4b, LOW);
  //digitalWrite(led, LOW);

  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED, ledState);    // turn *on* led

  Serial.begin(115200);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Starting UDP");
  Udp.begin(localPort);
  Serial.print("Local port: ");
#ifdef ESP32
  Serial.println(localPort);
#else
  Serial.println(Udp.localPort());
#endif

}


// void led(OSCMessage &msg) {
//   ledState = msg.getInt(0);
//   digitalWrite(BUILTIN_LED, ledState);
//   Serial.print("/move: ");
//   Serial.println(ledState);
// }

void loop() {
  OSCMessage msg;
  int size = Udp.parsePacket();

  if (size > 0) {
    while (size--) {
      msg.fill(Udp.read());
    }
    if (!msg.hasError()) {
      msg.dispatch("/msg", blnk);
    } else {
      error = msg.getError();
      Serial.print("error: ");
      Serial.println(error);
    }
  }
}

void blnk(OSCMessage &msg) {
  int sel = msg.getInt(0);
    switch (sel) {
        case 1:
            for (int i = 0; i < 5; i++) {
                digitalWrite(stimulator1a, LOW);
                digitalWrite(stimulator1b, LOW);
                delay(SAFE_TIME);
                digitalWrite(stimulator1a, HIGH);
                digitalWrite(stimulator1b, LOW);
                delay(T_HIGH);
                digitalWrite(stimulator1a, LOW);
                digitalWrite(stimulator1b, LOW);
                delay(SAFE_TIME);
                digitalWrite(stimulator1a, LOW);
                digitalWrite(stimulator1b, HIGH);
                delay(T_LOW);
            }
            break;
        case 2:
            for (int i = 0; i < 5; i++) {
                digitalWrite(stimulator1a, LOW);
                digitalWrite(stimulator1b, LOW);
                delay(SAFE_TIME);
                digitalWrite(stimulator1a, HIGH);
                digitalWrite(stimulator1b, LOW);
                delay(T_HIGH);
                digitalWrite(stimulator1a, LOW);
                digitalWrite(stimulator1b, LOW);
                delay(SAFE_TIME);
                digitalWrite(stimulator1a, LOW);
                digitalWrite(stimulator1b, HIGH);
                delay(T_LOW);
            }
            break;
        case 3:
            for (int i = 0; i < 5; i++) {
                digitalWrite(stimulator1a, LOW);
                digitalWrite(stimulator1b, LOW);
                delay(SAFE_TIME);
                digitalWrite(stimulator1a, HIGH);
                digitalWrite(stimulator1b, LOW);
                delay(T_HIGH);
                digitalWrite(stimulator1a, LOW);
                digitalWrite(stimulator1b, LOW);
                delay(SAFE_TIME);
                digitalWrite(stimulator1a, LOW);
                digitalWrite(stimulator1b, HIGH);
                delay(T_LOW);
            }
            break;
        case 4:
            for (int i = 0; i < 5; i++) {
                digitalWrite(stimulator1a, LOW);
                digitalWrite(stimulator1b, LOW);
                delay(SAFE_TIME);
                digitalWrite(stimulator1a, HIGH);
                digitalWrite(stimulator1b, LOW);
                delay(T_HIGH);
                digitalWrite(stimulator1a, LOW);
                digitalWrite(stimulator1b, LOW);
                delay(SAFE_TIME);
                digitalWrite(stimulator1a, LOW);
                digitalWrite(stimulator1b, HIGH);
                delay(T_LOW);
            }
            break;
        default:
            digitalWrite(stimulator1a, LOW);
            digitalWrite(stimulator1b, LOW);
            digitalWrite(stimulator2a, LOW);
            digitalWrite(stimulator2b, LOW);
            digitalWrite(stimulator3a, LOW);
            digitalWrite(stimulator3b, LOW);
            digitalWrite(stimulator4a, LOW);
            digitalWrite(stimulator4b, LOW);
            break;
    }
    digitalWrite(stimulator1a, LOW);
    digitalWrite(stimulator1b, LOW);
    digitalWrite(stimulator2a, LOW);
    digitalWrite(stimulator2b, LOW);
    digitalWrite(stimulator3a, LOW);
    digitalWrite(stimulator3b, LOW);
    digitalWrite(stimulator4a, LOW);
    digitalWrite(stimulator4b, LOW);
}