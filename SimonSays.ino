const int Lastlevel = 6;          //input number of levels +1. Can be changed.
int level = 0;                    //initialized variables
int speedOfLight = 1000;
int sequence[Lastlevel];
int input[Lastlevel];

const int buttonPin = 7;  
const int buttonPin2 = 12;        //Pin buttons assigned to arduino 
const int buttonPin3 = 13;  

void setup() {
  pinMode(2, OUTPUT);             //Set variables to specific values
  pinMode(buttonPin, INPUT);
  digitalWrite(2, LOW);

  pinMode(3, OUTPUT);
  pinMode(buttonPin2, INPUT);
  digitalWrite(3, LOW);

  pinMode(4, OUTPUT);
  pinMode(buttonPin3, INPUT);
  digitalWrite(4, LOW);
}

void loop() {           //loop - calls three methods
  pattern();
  display(); 
  obtaininput();    
}

void pattern(){
randomSeed(millis());                   //create the pattern to be displayed
for(int i = 0; i < Lastlevel; i++){
sequence[i] = random(2,5);              //Randomized between 2 and 5 for pinModes 2, 3, 4
}
}

void display(){                   //Display the created pattern
  
  digitalWrite(2, LOW);             
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
for (int i = 0; i < level; i++)
{ 
  if(sequence[i] == 2){         //First light
    tone(8, 4500);              //Create sound
    delay(200);
    noTone(8);
  }
  if(sequence[i] == 3){       //Second light
    tone(8, 3500);            //Create Sound
    delay(200);
    noTone(8);
  }
  if(sequence[i] == 4){       //Third light
    tone(8, 5500);            //Create sound
    delay(200);
    noTone(8);
  }
digitalWrite(sequence[i], HIGH);  //On/Off specific light
delay(speedOfLight);
digitalWrite(sequence[i], LOW);
delay(200);

}         //Loop back to for loop
}

void obtaininput()                    //userinputs 
{
int ifcorrect = 0;                  //Variable if sequence is correct
for (int i = 0; i < level; i++)
{
ifcorrect = 0;
while(ifcorrect == 0)
{
if (digitalRead(buttonPin) == LOW)  //If first light is LOW
{
digitalWrite(4, HIGH);        //Set light high, position i to light
input[i] = 4;
ifcorrect = 1;
delay(200);

tone(8, 5500);               //Specific audio sound
delay(200);
noTone(8);

if (input[i] != sequence[i])  //If incorrect jump to incorrect 
{
incorrect();
return;
}
digitalWrite(4, LOW);         //Set light low
}
  if (digitalRead(buttonPin2) == LOW)   //If second light is LOW
{
digitalWrite(3, HIGH);      //Set light high, position i to light
input[i] = 3;
ifcorrect = 1;
delay(200);

tone(8, 3500);             //Specific audio sound
delay(200);
noTone(8);

if (input[i] != sequence[i])  //If incorrect jump to incorrect 
{
incorrect();
return;
}
digitalWrite(3, LOW);           //Set light low
}
if (digitalRead(buttonPin3) == LOW) //If third light is LOW
{
digitalWrite(2, HIGH);          //Set light high, position i to light
input[i] = 2;
ifcorrect = 1;
delay(200);

tone(8, 4500);                  //Specific audio sound
delay(200);
noTone(8);

if (input[i] != sequence[i])    //If incorrect jump to incorrect  
{
incorrect();
return;
}
digitalWrite(2, LOW);           //Set light low
}
}
}
correct();
}

void incorrect(){ 
for (int i = 0; i < 3; i++){    //Lights flash three times if input is incorrect
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
delay(200);

tone(8, 10000);                    //Sound if incorrect 
delay(200);                        
noTone(8);

digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
delay(200);
}
level = 0;                  //Reset to first level 
speedOfLight = 1000;        //Reset light speed
}

void correct()                      //Method if input is correct
{
  if (level < Lastlevel){
level++;                            //Increment level
speedOfLight -= 100;                //Decrement light speed
  }
  if(level == Lastlevel){           //If level = last level, jump to win
    win();
  }
digitalWrite(2, LOW);     //Lights flash once if input is correct
digitalWrite(3, LOW);
digitalWrite(4, LOW);
delay(250);
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
delay(500);
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
delay(500);
}

void win(){
    
digitalWrite(2, LOW);   //Reset lights
digitalWrite(3, LOW);
digitalWrite(4, LOW);
delay(2000);


tone(8, 4000);          //Sound to indicate Win
delay(200);
noTone(8);
tone(8, 4000);
delay(200);
noTone(8);
tone(8, 4000);
delay(200);
noTone(8);
tone(8, 4000);
delay(200);
noTone(8);


level = 0;                  //Reset to first level
speedOfLight = 1000;        //Reset light speed

}


