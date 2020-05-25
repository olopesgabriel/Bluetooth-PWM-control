#define PPWM 11    
int pwm = 0;
char t;

void setup(){ 
    pinMode(PPWM, OUTPUT);
    Serial.begin(9600);
}   
  
void loop(){   
      if(Serial.available()){
        t = Serial.read();        
      }
      if(t == 'a'){
        ligar_motor();
      }
      if(t == 'd'){
        desligar_motor();
      }
      t = 'c';
}

void ligar_motor(){
  if(pwm >= 256){
    pwm = 255;
    analogWrite(PPWM, pwm);
  }else
  if(pwm < 256){
    pwm += 17;
    analogWrite(PPWM, pwm);
    Serial.println("PWM | Comando");
    Serial.print(pwm);
    Serial.print("      ");
    Serial.println(t);
  } 
}

void desligar_motor(){
  if(pwm <= 0){
    pwm = 0;
    analogWrite(PPWM, pwm);
  }else
  if(pwm > 0){
    pwm -= 17;
    analogWrite(PPWM, pwm);
    Serial.print(pwm);
    Serial.print("      ");
    Serial.println(t);
  }
}
