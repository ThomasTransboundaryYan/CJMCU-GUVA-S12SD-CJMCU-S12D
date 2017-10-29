int sensorValue;
long sum = 0;
int vout = 0;
int uv = 0;

void setup() {
  Serial.begin(9600);
}

void loop()
{
  sensorValue = 0;
  sum = 0;
  for (int i = 0 ; i < 1024 ; i++ )
  {
    sensorValue = analogRead(A0);
    sum = sensorValue + sum;
    delay(2);
  }
  vout = sum >> 10;
  vout = vout * 4980.0 / 1024;
  Serial.print("The Photocurrent value:");
  Serial.print(vout);
  Serial.println("mV");
  if (vout < 50) {
    uv = 0;
  }
  else if (vout < 227) {
    uv = 1;
  }
  else if (vout < 318) {
    uv = 2;
  }
  else if (vout < 408) {
    uv = 3;
  }
  else if (vout < 503) {
    uv = 4;
  }
  else if (vout < 606) {
    uv = 5;
  }
  else if (vout < 696) {
    uv = 6;
  }
  else if (vout < 795) {
    uv = 7;
  }
  else if (vout < 881) {
    uv = 8;
  }
  else if (vout < 976) {
    uv = 9;
  }
  else if (vout < 1079) {
    uv = 10;
  }
  else {
    uv = 11;
  }
  delay(20);
  Serial.print("UV Index = ");
  Serial.println(uv);
}
