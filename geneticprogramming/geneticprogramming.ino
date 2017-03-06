
#include <Servo.h>

//Hardware setup - attach servos to the ports
#define NB_SERVOS 4
Servo servo [NB_SERVOS];
int pos[NB_SERVOS];
int port[NB_SERVOS];

// First test - declare an individual with 36 random servo positions
int individual[36];

void setup() {

  //Genetic setup - create initial population of 1 test individual, represented as an array of positions
  port[0]=11;
  port[1]=5;
  port[2]=6;
  port[3]=9;
  randomSeed(analogRead(0));
  int j;
  for (j = 0; j < 36; j ++) {
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
  for (int i = 0; i < 36; i += NB_SERVOS) { // step through the 36 random servo positions, 6 at a time per servo
    for (int servoNb = 0; servoNb < NB_SERVOS; servoNb ++) {
      servo[servoNb].write(individual[i]);
      delay(200);                       // waits 1 s and then move all servos
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
