
#include <Servo.h>

//Hardware setup - attach servos to the ports
Servo servo1, servo2, servo3, servo4, servo5, servo6;
int pos1, pos2, pos3, pos4, pos5, pos6;

// First test - declare an individual with 36 random servo positions
int individual[36];

void setup() {

  //Genetic setup - create initial population of 1 test individual, represented as an array of positions

  randomSeed(analogRead(0));
  int j;
  for (j = 0; j < 36; j += 1) {
    individual[j] = random(256);
  }
  
  // attach the servos to the board:
  servo1.attach(3);  
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);
  servo6.attach(11);

}

void loop() {
  // put your main code here, to run repeatedly:

  /* Run the test individual */
  for (int i = 0; i < 36; i += 6) { // step through the 36 random servo positions, 6 at a time per servo
    servo1.write(individual[i]);
    servo2.write(individual[i+1]);
    servo3.write(individual[i+2]);
    servo4.write(individual[i+3]);
    servo5.write(individual[i+4]);
    servo6.write(individual[i+5]);
    delay(1000);                       // waits 1 s and then move all servos
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
