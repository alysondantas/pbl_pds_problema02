#define D0 2
#define D1 3
#define D2 4
#define D3 5
#define D4 6
#define D5 7
#define D6 8
#define D7 9
#define sinal A0
#define clock_signal A1
#define pwm 11
int bit0;
int bit1;
int bit2;
int bit3;
int bit4;
int bit5;
int bit6;
int bit7;
double clk_signal;
double signalValue_converted;
double input_signal;

void setup(){
  Serial.begin(115200);
  pinMode(D0,INPUT);
  pinMode(D1,INPUT);
  pinMode(D2,INPUT);
  pinMode(D3,INPUT);
  pinMode(D4,INPUT);
  pinMode(D5,INPUT);
  pinMode(D6,INPUT);
  pinMode(D7,INPUT);
  pinMode(pwm,OUTPUT);
  pinMode(13,INPUT);
  pinMode(clock_signal,INPUT);
  pinMode(sinal,INPUT);
  analogWrite(pwm,125);
}

void loop() {
  if(digitalRead(13) == HIGH){
   bit0 = digitalRead(D0);
   bit1 = digitalRead(D1);
   bit2 = digitalRead(D2);
   bit3 = digitalRead(D3);
   bit4 = digitalRead(D4);
   bit5 = digitalRead(D5);
   bit6 = digitalRead(D6);
   bit7 = digitalRead(D7);
   input_signal = ( analogRead(sinal) ) * (0.0049);
   signalValue_converted = ( (bit0*1) + (bit1*2) + (bit2*4) + (bit3*8) + (bit4*16) + (bit5*32) + (bit6*64) + (bit7*128) )*(0.01960);
   Serial.print("Sinal: ");
   Serial.print(input_signal, 5);
   Serial.print(" Sinal Convertido(Voltage): ");
   Serial.print(signalValue_converted, 5);
   Serial.print(" Binário: ");
   Serial.print(bit7);
   Serial.print(bit6);
   Serial.print(bit5);
   Serial.print(bit4);
   Serial.print(bit3);
   Serial.print(bit2);
   Serial.print(bit1);
   Serial.println(bit0);
  }
}
