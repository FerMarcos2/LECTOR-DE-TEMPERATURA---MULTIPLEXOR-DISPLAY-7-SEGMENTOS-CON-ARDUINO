//Sitio Web con Practicas de Arduino, FPGA, MATLAB y 
//temas sobre Electrónica Digital, Analogica, Procesamiento Digital de Señales, 
//Comunicaciones, etc.
//www.slideshare.net/FerMarcos2

//Sitio Web Curriculum
//www.linkedin.com/in/FerMarcos2

//Canal Youtube
//www.youtube.com/channel/UCLGgLo5SKhDz3cae4YOQosg

char num[]={0x81,0xF3,0x49,0x61,0x33,0x25,0x05,0xF1,0x01,0x21};
String snum="";
void setup(){
  DDRD=B11111111; //Digital Ports 7-1 OUTPUT
  DDRB=B111111;}  //Digital Ports 13-8 OUTPUT
void loop(){
  int itemperatura=analogRead(A0)/2.046;
  String stemperatura=String(itemperatura)+"C";
  for(int i=0;i<stemperatura.length();i++){
    if (stemperatura[i]=='C'){PORTD=B10001101;}
    else{ snum=stemperatura[i];
          PORTD=num[snum.toInt()];}
    if(i==stemperatura.length()-2){PORTD=PORTD-B00000001;}
    int n=pow(2,stemperatura.length()-i-1)+.5;
    PORTB=byte(n);
    delay(5);
    PORTB=B000000;
  }
}
