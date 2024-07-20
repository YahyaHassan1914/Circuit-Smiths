// the setup function runs once when you press reset or power the board
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  static int number = 0;  // static variable to keep track of the current number

  // print the current number
  Serial.println(number);

  // increment the number
  number++;

  // wait for a second (1000 milliseconds)
  delay(1000);
}
