int ledPin=13;
int alu=0;
String readString;
int flag=0;
int a,b,c,d,e,v,w,x,y,z;
int m=0;
int n=1; 
int o=2;
int p=3;
int q=4;
boolean tank_full = false;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT); 
  pinMode(m,INPUT);
  pinMode(n,INPUT);
  pinMode(o,INPUT);
  pinMode(p,INPUT);
  pinMode(q,INPUT); 
}

void loop() {
  while(Serial.available()) {
    delay(3);
    char c = Serial.read();
    readString += c;
  }
  if(readString.length() >0) {
    if(tank_full == false)
    {
    if(readString == "on")
    {
      digitalWrite(ledPin, HIGH);
    }alu=1;
    }
    
    if (readString == "off" || alu==0)
    {  
      digitalWrite(ledPin, LOW);
    }
    readString="";
  }
  
  
  
  a=analogRead(m);
  b=analogRead(n);
  c=analogRead(o);
  d=analogRead(p);
  e=analogRead(q);
  v=map(a,0,1000,0,30);
  w=map(b,0,1000,0,30);
  x=map(c,0,1000,0,30);
  y=map(d,0,1000,0,30);
  z=map(e,0,1000,0,30);
 
  if(v>0)
  {
    flag=1;
   
  } 
  
   if(v>0&&w>0)
       {
       flag=2;
       
       }
 
  if(v>0&&w>0&&x>0)
flag=3;
 
  if(v>0&&w>0&&x>0&&y>0)
flag=4;
 
  if(v>0&&w>0&&x>0&&y>0&&z>0)
flag=5;

  switch (flag)
    {
      case 1:
       Serial.println("< 25%");
      //Serial.println(v);
      delay(1000);
      break;
      
      case 2:
       Serial.println("26% - 50%");
      //Serial.println(w);
      delay(1000);
      break;
      
      case 3:
      Serial.println("51% - 75%");
      delay(1000);
      break;
      
      case 4:
      Serial.println("76% - 95%");
      delay(1000);
      break;
      
      case 5:
      Serial.println("96% - 100% : PUMP OFF");
      delay(1000);
      tank_full = true;
      if(alu==1)
       {  
         digitalWrite(ledPin, LOW);

       }          alu=0;
      break;
     
      
    }
    
    
    
}

