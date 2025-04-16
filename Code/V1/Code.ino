#include <ESP_FlexyStepper.h>
#include "BluetoothSerial.h" 
#include <ESP32Servo.h>

// О шаговиках
const int MOTOR1_STEP_PIN = 16; // пины первого шаговика
const int MOTOR1_DIRECTION_PIN = 17;

const int MOTOR2_STEP_PIN = 5; // пины второго шаговика
const int MOTOR2_DIRECTION_PIN = 18;

const int MOTOR3_STEP_PIN = 19; // пины третьего шаговика
const int MOTOR3_DIRECTION_PIN = 21;

BluetoothSerial ESP_BT; // класс - блютуз

// О серво
Servo Servo1; 

const int Servo1_PIN = 2; // пины серво
const int Servo2_PIN = 4;

int pos1 = 0; // начальные позиции серво
int pos2 = 0;

// О наличии чашек
const int cup1_pin = 12; // пины чашек
const int cup2_pin = 13;
const int cup3_pin = 14;
const int cup4_pin = 27;

int cup1; // переменные наличия чашек
int cup2;
int cup3;
int cup4;

char Memory1 = 0; // заказ первой чашки
char Memory2 = 0; // заказ второй чашки
char Memory3 = 0; // заказ третьей чашки

ESP_FlexyStepper stepper1;
ESP_FlexyStepper stepper2;
ESP_FlexyStepper stepper3;

void setup() {
  Serial.begin(9600);

  ESP_BT.begin("Blokhin_Team_BT"); 
  Serial.println("Bluetooth Device is Ready to Pair");

  stepper1.connectToPins(MOTOR1_STEP_PIN, MOTOR1_DIRECTION_PIN);
  stepper2.connectToPins(MOTOR2_STEP_PIN, MOTOR2_DIRECTION_PIN);
  stepper3.connectToPins(MOTOR3_STEP_PIN, MOTOR3_DIRECTION_PIN);

  int cup1 = digitalRead(cup1_pin); // проверка наличия чашек
  int cup2 = digitalRead(cup2_pin);
  int cup3 = digitalRead(cup3_pin);
  int cup4 = digitalRead(cup4_pin);
  
  stepper1.setSpeedInStepsPerSecond(200);
  stepper1.setAccelerationInStepsPerSecondPerSecond(200);
  stepper2.setSpeedInStepsPerSecond(200);
  stepper2.setAccelerationInStepsPerSecondPerSecond(200);
  stepper3.setSpeedInStepsPerSecond(200);

  Servo1.setPeriodHertz(50);  
  Servo1.attach(Servo1_PIN, 500, 2400); // на пин "2"
  Serial.println("Vpered, bogatiry");
}

void loop() {
  if (ESP_BT.available()){

    // Создаем массив для хранения 4 символов
    char myArray[4];

    // Считываем первые 4 символа
    for (int i = 0; i < 4; i++) {
      if (ESP_BT.available() > 0) { // Проверяем, есть ли еще доступные символы
        myArray[i] = ESP_BT.read();
      } else {
        // Если символов меньше 4, заполняем остаток нулями (или другим символом)
        myArray[i] = '\0'; // Null terminator для обозначения конца строки
      }
    }

    char R1 = myArray[0];
    char R2 = myArray[1];
    char R3 = myArray[2];
    char R4 = myArray[3];
    
    while (cup1 == 1) {
      
      switch (R1) {
        case 'A':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);   
          stepper1.moveRelativeInSteps(3000);
          delay(500);
          Serial.print("svobodnaya kassa");
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
          Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'B':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);       
          stepper3.moveRelativeInSteps(2400);
          delay(500);
          Serial.print("svobodnaya kassa");
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
            Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'C':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);
          stepper2.moveRelativeInSteps(600);
          delay(500);
          Serial.print("svobodnaya kassa");
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
            Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'D':

          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);
          stepper1.moveRelativeInSteps(4800);
          stepper2.moveRelativeInSteps(1200);
          delay(500);
          Serial.print("svobodnaya kassa");  
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
            Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'E':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);        
          stepper1.moveRelativeInSteps(1800);
          stepper3.moveRelativeInSteps(3000);
          delay(500);
          Serial.print("svobodnaya kassa"); 
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
            Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'F':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);       
          stepper1.moveRelativeInSteps(2100);
          stepper2.moveRelativeInSteps(600);
          stepper3.moveRelativeInSteps(2700);
          delay(500);
          break;
      }
    }

    while (cup2 == 1) {
      
      switch (R2) {
        case 'A':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);   
          stepper1.moveRelativeInSteps(3000);
          delay(500);
          Serial.print("svobodnaya kassa");
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
          Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'B':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);       
          stepper3.moveRelativeInSteps(2400);
          delay(500);
          Serial.print("svobodnaya kassa");
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
            Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'C':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);
          stepper2.moveRelativeInSteps(600);
          delay(500);
          Serial.print("svobodnaya kassa");
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
            Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'D':

          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);
          stepper1.moveRelativeInSteps(4800);
          stepper2.moveRelativeInSteps(1200);
          delay(500);
          Serial.print("svobodnaya kassa");  
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
            Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'E':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);        
          stepper1.moveRelativeInSteps(1800);
          stepper3.moveRelativeInSteps(3000);
          delay(500);
          Serial.print("svobodnaya kassa"); 
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
            Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'F':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);       
          stepper1.moveRelativeInSteps(2100);
          stepper2.moveRelativeInSteps(600);
          stepper3.moveRelativeInSteps(2700);
          delay(500);
          break;
          
        default:
        
          Serial.println(".");
          delay(1000);
          break;
      }
    }

    while (cup3 == 1) {
      
      switch (R3) {
        case 'A':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);   
          stepper1.moveRelativeInSteps(3000);
          delay(500);
          Serial.print("svobodnaya kassa");
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
          Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'B':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);       
          stepper3.moveRelativeInSteps(2400);
          delay(500);
          Serial.print("svobodnaya kassa");
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
            Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'C':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);
          stepper2.moveRelativeInSteps(600);
          delay(500);
          Serial.print("svobodnaya kassa");
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
            Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'D':

          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);
          stepper1.moveRelativeInSteps(4800);
          stepper2.moveRelativeInSteps(1200);
          delay(500);
          Serial.print("svobodnaya kassa");  
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
            Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'E':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);        
          stepper1.moveRelativeInSteps(1800);
          stepper3.moveRelativeInSteps(3000);
          delay(500);
          Serial.print("svobodnaya kassa"); 
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
            Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'F':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);       
          stepper1.moveRelativeInSteps(2100);
          stepper2.moveRelativeInSteps(600);
          stepper3.moveRelativeInSteps(2700);
          delay(500);
          break;
          
        default:
        
          Serial.println(".");
          delay(1000);
          break;
      }
    }

    while (cup4 == 1) {
      
      switch (R4) {
        case 'A':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);   
          stepper1.moveRelativeInSteps(3000);
          delay(500);
          Serial.print("svobodnaya kassa");
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
          Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'B':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);       
          stepper3.moveRelativeInSteps(2400);
          delay(500);
          Serial.print("svobodnaya kassa");
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
            Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'C':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);
          stepper2.moveRelativeInSteps(600);
          delay(500);
          Serial.print("svobodnaya kassa");
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
            Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'D':

          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);
          stepper1.moveRelativeInSteps(4800);
          stepper2.moveRelativeInSteps(1200);
          delay(500);
          Serial.print("svobodnaya kassa");  
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
            Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'E':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);        
          stepper1.moveRelativeInSteps(1800);
          stepper3.moveRelativeInSteps(3000);
          delay(500);
          Serial.print("svobodnaya kassa"); 
          for (pos1 = 180; pos1 >= 0; pos1 -= 1) { 
            Servo1.write(pos1);
          }
          delay(500);
          break;
          
        case 'F':
        
          Serial.print("zakaz prinyat");
          for (pos1 = 0; pos1 <= 180; pos1 += 1){ 
            Servo1.write(pos1);     
          }
          delay(500);       
          stepper1.moveRelativeInSteps(2100);
          stepper2.moveRelativeInSteps(600);
          stepper3.moveRelativeInSteps(2700);
          delay(500);
          break;
          
        default:
        
          Serial.println(".");
          delay(1000);
          break;
      }
    }
  }
}