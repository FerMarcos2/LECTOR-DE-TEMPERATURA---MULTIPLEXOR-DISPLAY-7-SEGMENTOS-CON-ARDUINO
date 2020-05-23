//Sitio Web con Practicas de Arduino, FPGA, MATLAB y 
//temas sobre Electrónica Digital, Analogica, Procesamiento Digital de Señales, 
//Comunicaciones, etc.
//www.slideshare.net/FerMarcos2

//Sitio Web Curriculum
//www.linkedin.com/in/FerMarcos2

//Canal Youtube
//www.youtube.com/channel/UCLGgLo5SKhDz3cae4YOQosg

void setup(){
  analogReference(INTERNAL); //Configure the analog port for read of 0V to 1.1V
  DDRD=B11111111; //Digital Ports 7-1 OUTPUT
  DDRB=B111111;}  //Digital Ports 13-8 OUTPUT
void loop(){
  int imedicion=analogRead(A0)/9.3; 
  String smedicion=String(imedicion)+"C";
  for(int i=0;i<smedicion.length();i++){
    switch(smedicion[i]){
      case '0':PORTD=B01111110;break;
      case '1':PORTD=B00001100;break;     
      case '2':PORTD=B10110110;break;     
      case '3':PORTD=B10011110;break;
      case '4':PORTD=B11001100;break;
      case '5':PORTD=B11011010;break;
      case '6':PORTD=B11111010;break;
      case '7':PORTD=B00001110;break;
      case '8':PORTD=B11111110;break;
      case '9':PORTD=B11011110;break;
      case 'C':PORTD=B01110010;break;
    }
    if(i==smedicion.length()-2){PORTD=PORTD+B00000001;}
    int n=pow(2,smedicion.length()-i-1)+.5;
    PORTB=B111111-byte(n);
    delay(5);
    PORTB=B111111;
  }
}
