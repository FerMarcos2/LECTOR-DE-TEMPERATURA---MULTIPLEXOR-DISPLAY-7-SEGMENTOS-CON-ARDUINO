//Sitio Web con Practicas de Arduino, FPGA, MATLAB y 
//temas sobre Electrónica Digital, Analogica, Procesamiento Digital de Señales, 
//Comunicaciones, etc.
//www.slideshare.net/FerMarcos2

//Sitio Web Curriculum
//www.linkedin.com/in/FerMarcos2

//Canal Youtube
//www.youtube.com/channel/UCLGgLo5SKhDz3cae4YOQosg

void setup(){
  DDRD=B11111111; //Digital Ports 7-1 OUTPUT
  DDRB=B111111;}  //Digital Ports 13-8 OUTPUT
void loop(){
  int itemperatura=analogRead(A0)/2.046;
  String stemperatura=String(itemperatura)+"C";
  for(int i=0;i<stemperatura.length();i++){
    switch(stemperatura[i]){
      case '0':PORTD=B10000001;break;
      case '1':PORTD=B11110011;break;     
      case '2':PORTD=B01001001;break;     
      case '3':PORTD=B01100001;break;
      case '4':PORTD=B00110011;break;
      case '5':PORTD=B00100101;break;
      case '6':PORTD=B00000101;break;
      case '7':PORTD=B11110001;break;
      case '8':PORTD=B00000001;break;
      case '9':PORTD=B00100001;break;
      case 'C':PORTD=B10001101;break;
    }
    if(i==stemperatura.length()-2){PORTD=PORTD-B00000001;}
    int n=pow(2,stemperatura.length()-i-1)+.5;
    PORTB=byte(n);
    delay(5);
    PORTB=B000000;
  }
}
