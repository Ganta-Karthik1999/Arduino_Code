int red, green, blue;
const int x = 3;
const int y = 5;
const int z = 6;
void setup() {
  Serial.begin(9600);
  Serial.println("RGB COLOURS");
  pinMode(x, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(z, OUTPUT);

}

void loop() {
  red = Serial.parseInt();
  green = Serial.parseInt();
  blue = Serial.parseInt();

  if (Serial.read()== '\n') {
    int red = 255 - constrain(red, 0, 255);
    int green = 255 - constrain(green, 0, 255);
    int blue = 255 - constrain(blue, 0, 255);

    analogWrite(x, red);
    analogWrite(y, green);
    analogWrite(z, blue);
  }

}
