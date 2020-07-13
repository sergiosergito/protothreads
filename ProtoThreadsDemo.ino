#include <pt.h>
#define ONE_SECOND 1000
#define HALF_SECOND 500
#define QUARTER_OF_A_SECOND 250

int redLED = 10;
int yellowLED = 9;
int greenLED = 8;

struct pt redThread;
struct pt yellowThread;
struct pt greenThread;

void setup() {
  PT_INIT(&redThread);
  PT_INIT(&yellowThread);
  PT_INIT(&greenThread);
}

void loop() {
  parpadeo(&redThread);
  parpadeo2(&yellowThread);
  parpadeo3(&greenThread);
}

void parpadeo(struct pt *protothread){
  PT_BEGIN(protothread);
  static long timeAtMillisTaken = 0;
  pinMode(redLED, OUTPUT);
  do{
      digitalWrite(redLED, HIGH);
      timeAtMillisTaken = millis();
      PT_WAIT_WHILE(protothread, (millis() - timeAtMillisTaken)< ONE_SECOND);
      
      digitalWrite(redLED, LOW);
      timeAtMillisTaken = millis();
      PT_WAIT_UNTIL(protothread, (millis() - timeAtMillisTaken) >= ONE_SECOND);
  }while(true);
  PT_END(protothread);
}

void parpadeo2(struct pt *protothread){
  PT_BEGIN(protothread);
  static long timeAtMillisTaken = 0;
  pinMode(yellowLED, OUTPUT);
  do{
      digitalWrite(yellowLED, HIGH);
      timeAtMillisTaken = millis();
      PT_WAIT_WHILE(protothread, (millis() - timeAtMillisTaken)< HALF_SECOND);
      
      digitalWrite(yellowLED, LOW);
      timeAtMillisTaken = millis();
      PT_WAIT_UNTIL(protothread, (millis() - timeAtMillisTaken) >= HALF_SECOND);
  }while(true);
  PT_END(protothread);
}

void parpadeo3(struct pt *protothread){
  PT_BEGIN(protothread);
  static long timeAtMillisTaken = 0;
  pinMode(greenLED, OUTPUT);
  do{
      digitalWrite(greenLED, HIGH);
      timeAtMillisTaken = millis();
      PT_WAIT_WHILE(protothread, (millis() - timeAtMillisTaken)< QUARTER_OF_A_SECOND);
      
      digitalWrite(greenLED, LOW);
      timeAtMillisTaken = millis();
      PT_WAIT_UNTIL(protothread, (millis() - timeAtMillisTaken) >= QUARTER_OF_A_SECOND);
  }while(true);
  PT_END(protothread);
}
