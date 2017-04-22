float Htime=0;
float Ltime=0;
float Ttime=0;
float frequency;
float capacitance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(P2_1, INPUT);
  Serial.println("capacitance=");

}

void loop() {
  // put your main code here, to run repeatedly:
 
  for(int i=0;i<5;i++)
  {

  Ltime+=pulseIn(P2_1,HIGH);
  Htime+=pulseIn(P2_1,LOW);
  }
 
Ltime/=5;
Htime/=5;

Ttime=Htime+Ltime;
frequency=1000000/Ttime;

capacitance=(1044*1000000)/(20800*frequency);
capacitance/=0.067;
Serial.print(capacitance);
Serial.print("pF\n");
delay(500);

Htime=0;
Ltime=0;
}
