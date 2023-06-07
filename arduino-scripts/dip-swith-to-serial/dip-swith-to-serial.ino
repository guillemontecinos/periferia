#define S1 2
#define S2 3
#define S3 4
#define S4 5
int previousStates[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int states[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int inputPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  // Define input pins to read dipswitch
  for(int i = 0; i < 8; i++){
    pinMode(inputPins[i], INPUT);  
  }
  Serial.begin(9600);
  Serial.println("Serial port open");
}

void loop() {
  String word = "";
  boolean newWord = false;
  for(int i = 0; i < 8; i++){
    previousStates[i] = states[i];
    states[i] = digitalRead(inputPins[i]);  
    word += String(states[i]);
    boolean newBit = previousStates[i] != states[i];
    newWord = newWord || newBit;
  }
  if(newWord){
    Serial.println(word);
  }
}
