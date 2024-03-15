void setup() {
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

}

void loop() {
  
  if (Serial.available()==0){
    Serial.println("plz enter any value ");
    int a;
  a=Serial.read();
  }
  int a;
  if(a==1){
   Serial.print("you are moving forward");
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  
  }
else if(a==2){
  Serial.print("you are moving right");
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  
  }

  else if(a==3){
    Serial.print("you are moving left");
   digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
    }
else if(a==4){
  Serial.print("you are moving back");
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  }

else if(a==5){
  Serial.print("Now the bot is stoped");
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  }

}
