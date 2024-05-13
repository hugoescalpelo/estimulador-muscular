#include <Arduino.h>

int stimulator1a = 15;
int stimulator1b = 2;
int stimulator2a = 4;
int stimulator2b = 5;
int stimulator3a = 18;
int stimulator3b = 19;
int led = 1;
int buttonPin = 13; // Pin donde está conectado el botón
bool buttonPressed = false; // Estado del botón

const int T_HIGH = 10;
const int T_LOW = 10;
const int SAFE_TIME = 10;

void setup() {
    pinMode(stimulator1a, OUTPUT);
    pinMode(stimulator1b, OUTPUT);
    pinMode(stimulator2a, OUTPUT);
    pinMode(stimulator2b, OUTPUT);
    pinMode(stimulator3a, OUTPUT);
    pinMode(stimulator3b, OUTPUT);
    pinMode(led, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP); // Configurar el pin del botón como entrada con resistencia interna de pull-up
    
    digitalWrite(stimulator1a, LOW);
    digitalWrite(stimulator1b, LOW);
    digitalWrite(stimulator2a, LOW);
    digitalWrite(stimulator2b, LOW);
    digitalWrite(stimulator3a, LOW);
    digitalWrite(stimulator3b, LOW);
    digitalWrite(led, LOW);

    selecta = random(1, 6); // Generar un número aleatorio entre 1 y 6
    
    Serial.begin(115200);
    Serial.println("Inicio");
}

void loop() {
    int buttonState = digitalRead(buttonPin); // Leer el estado del botón
    
    // Comprobar si el botón está presionado (LOW debido al pull-up)
    if (buttonState == LOW && !buttonPressed) {
        buttonPressed = true;
        digitalWrite(led, HIGH); // Encender el LED
        blnk(selecta); // Ejecutar la secuencia basada en selecta
        delay(200);
    } else if (buttonState == HIGH && buttonPressed) {
        buttonPressed = false;
        digitalWrite(led, LOW); // Apagar el LED
    }
}

void blnk(int sel) {
    switch (sel) {
        case 1:
            for (int i = 0; i < 3; i++) {
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
            for (int i = 0; i < 3; i++) {
                digitalWrite(stimulator2a, LOW);
                digitalWrite(stimulator2b, LOW);
                delay(SAFE_TIME);
                digitalWrite(stimulator2a, HIGH);
                digitalWrite(stimulator2b, LOW);
                delay(T_HIGH);
                digitalWrite(stimulator2a, LOW);
                digitalWrite(stimulator2b, LOW);
                delay(SAFE_TIME);
                digitalWrite(stimulator2a, LOW);
                digitalWrite(stimulator2b, HIGH);
                delay(T_LOW);
            }
            break;
        case 3:
            for (int i = 0; i < 3; i++) {
                digitalWrite(stimulator3a, LOW);
                digitalWrite(stimulator3b, LOW);
                delay(SAFE_TIME);
                digitalWrite(stimulator3a, HIGH);
                digitalWrite(stimulator3b, LOW);
                delay(T_HIGH);
                digitalWrite(stimulator3a, LOW);
                digitalWrite(stimulator3b, LOW);
                delay(SAFE_TIME);
                digitalWrite(stimulator3a, LOW);
                digitalWrite(stimulator3b, HIGH);
                delay(T_LOW);
            }
            break;
        case 4:
            for (int i = 0; i < 6; i++) {
                digitalWrite(stimulator1a, LOW);
                digitalWrite(stimulator1b, HIGH);
                delay(T_LOW);
                digitalWrite(stimulator1a, HIGH);
                digitalWrite(stimulator1b, LOW);
                delay(T_HIGH);
            }
            break;
        case 5:
            for (int i = 0; i < 9; i++) {
                digitalWrite(stimulator2a, HIGH);
                delay(T_HIGH);
                digitalWrite(stimulator2a, LOW);
                delay(SAFE_TIME);
                digitalWrite(stimulator2b, HIGH);
                delay(T_LOW);
                digitalWrite(stimulator2b, LOW);
                delay(SAFE_TIME);
            }
            break;
    }
    digitalWrite(stimulator1a, LOW);
    digitalWrite(stimulator1b, LOW);
    digitalWrite(stimulator2a, LOW);
    digitalWrite(stimulator2b, LOW);
    digitalWrite(stimulator3a, LOW);
    digitalWrite(stimulator3b, LOW);
}
