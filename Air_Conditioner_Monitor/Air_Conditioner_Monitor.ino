#define low HIGH
#define high LOW
//bluetooth
int tx=1;
int rx=0;
char inSerial[15];
float x=25.0;
//**********
int ThermistorPin = A0;
int relay=8;
float Vo;
float R1 = 10000;
float logRth, Rth, T, Tc;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
Serial.begin(9600);
pinMode(relay, OUTPUT);
pinMode(tx, OUTPUT);
pinMode(rx, INPUT);
digitalWrite(relay, low);
}

void loop() {
    int i=0;
    int m=0;
    delay(500);                                         
    if (Serial.available() > 0) {             
       while (Serial.available() > 0) 
       {
         inSerial[i]=Serial.read(); 
         i++;      
       }
       inSerial[i]='\0';
       Check_Protocol(inSerial);
     }




  
  Vo = analogRead(ThermistorPin);
  Rth = R1 * (1023.0 / Vo - 1.0);
  logRth = log(Rth);
  T = (1.0 / (c1 + c2*logRth + c3*logRth*logRth*logRth));
  Tc = T - 273.15; 

  Serial.print("Temperature: "); 
  Serial.print(Tc);
  Serial.println(" C");   
  delay(1000);
  
  if (Tc>x)
  {
    digitalWrite(relay, high);
  }
  else
  {
    digitalWrite(relay, low);
  }
}



void Check_Protocol(char inStr[]){   
  int i=0;
  int m=0;
  Serial.println(" ");
  if(!strcmp(inStr,"20")){
    x=20.0;
    Serial.println("The AC will be turned on at 20 C");
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;}
       
  if(!strcmp(inStr,"25")){
    x=25.0;
    Serial.println("The AC will be turned on at 25 C");
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;}
       
  if(!strcmp(inStr,"30")){
    x=30.0;
    Serial.println("The AC will be turned on at 30 C");
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;}
       
  if(!strcmp(inStr,"35")){
    x=35.0;
    Serial.println("The AC will be turned on at 35 C");
    for(m=0;m<11;m++){
      inStr[m]=0;}
       i=0;}
     
       
    else{
    for(m=0;m<11;m++){
      inStr[m]=0;
    }
    i=0;

}}
