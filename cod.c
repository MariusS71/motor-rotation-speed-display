int RPM;
float totalPassedTime = 0.0;
float lastInterruptTime = 0.0;
float currentTime = 0.0;
void setup() {

  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(5,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), countEncoderPulse, RISING);
 
}

void countEncoderPulse()
{
  	currentTime = micros();
	lastInterruptTime = currentTime - totalPassedTime;
  	totalPassedTime= currentTime;

}

void loop() {
  	delay(10);
  	RPM = round((1/lastInterruptTime)*70300);
  	decToBin(8,RPM%10);//a2a cifra a rpm
  	digitalWrite(12,HIGH);//comutam displayul
  	digitalWrite(13,LOW);
  	delay(10);
  	decToBin(8,RPM/10);//prima cifra a rpm
  	digitalWrite(13,HIGH);//comutam displayul
  	digitalWrite(12,LOW);

  	
  	
}
void decToBin(int pin, int nr) {
int i,d;
for(i = 3; i>=0; i--)
	{
     d = nr >> i;
	 if(d & 1 ) 
		digitalWrite(i+pin,HIGH);	
	 else 
		digitalWrite(i+pin,LOW);
			

	}
}

