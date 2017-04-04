
#include <Servo.h>

//Hardware setup - attach servos to the ports
#define NB_SERVOS 6
#define NB_POS 20
Servo servo [NB_SERVOS];
int pos[NB_SERVOS];
int port[NB_SERVOS];

// First test - declare an individual with 36 random servo positions
int individual[NB_SERVOS * NB_POS];

void setup() {

  Serial.begin(9600);
  //Genetic setup - create initial population of 1 test individual, represented as an array of positions
  port[0]=11;
  port[1]=5;
  port[2]=6;
  port[3]=9;
  port[4]=3;
  port[5]=10;
  randomSeed(analogRead(0));
  int j;
  for (j = 0; j < NB_SERVOS * NB_POS; j ++) {
    individual[j] = random(180);
  }
  
  // attach the servos to the board:
  for (int idx =0; idx < NB_SERVOS; idx ++){
     servo[idx].attach(port[idx]);  
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  /* Run the test individual */
  for (int i = 0; i < NB_POS; i ++) { // step through the 36 random servo positions, 6 at a time per servo
    for (int servoNb = 0; servoNb < NB_SERVOS; servoNb ++) {
      String val = String("Servo : ") + servoNb + String(" - Pos : ") + individual[NB_SERVOS * i + servoNb];
      Serial.println(val);
      servo[servoNb].write(individual[NB_SERVOS * i + servoNb]);
      delay(100);                       // waits 1 s and then move all servos
    }
  }

//Fitness evaluation
//- take 4 random individuals as input  
//- evaluate their fitness and store it

//- selection - which individuals were better?
//-good enough solution?

//- false - create new generation with genetic operators
//- mutation (randomly change registers in the individual)
//- cross fertilization (swap a random middle segment between two best individuals)
//- replace the 2 worst algorithms with the children of the 2 best
//- go back to fitness evaluation
//-true - end

}
