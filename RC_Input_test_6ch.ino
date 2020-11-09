// This program is used to receive the input values from the radio-control 
// transmitter/receiver and output the values to the Serial connection
// for analysis in how to condition and map these values

//Input channel pin assignment
const int ch[10] = {2, 4, 7, 8, 12, 13};

//Initialize storage for input channel signal value
int input[10] = {0, 0, 0, 0, 0, 0};

void setup() {
  //Initialze serial communication at 9600 bits per second  
  Serial.begin(9600);

  //Set RX input pins
  pinMode(ch[0], INPUT);
  pinMode(ch[1], INPUT);
  pinMode(ch[2], INPUT);
  pinMode(ch[3], INPUT);
  pinMode(ch[4], INPUT);
  pinMode(ch[5], INPUT);
}

void loop() {
  //Read and output each RX channel individually
  for(int i = 0; i<6; i++)
  {
    //Read in value from RX
    readChannel(i);

    //Write RX value to Serial connection to PC
    serialInputWrite(i);
  }
  Serial.println();
}

//Read in pulse width values from RX
void readChannel(int in)
{
  input[in] = pulseIn(ch[in],HIGH);
}

//Write out signal data to Serial connection
void serialInputWrite(int in)
{
  Serial.print("Ch");
  Serial.print(in+1);
  Serial.print(": ");
  Serial.print(input[in]);
  Serial.print(" | ");
}
