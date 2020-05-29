
// Programa para teste de onda quadrada e sua saída através de um filtro butterworth de grau 2
// Saída deve ser uma onda senoidal com a frequência de corte

void setup() {
  // put your setup code here, to run once:
  
Serial.begin (115200);             // Inicia porta serial

//ADCSRA &= ~(bit (ADPS0) | bit (ADPS1) | bit (ADPS2)); // // limpa prescaler bits

//ADCSRA |= bit (ADPS0) | bit (ADPS1);                     //  seta prescaler de 128(padrão) para 8 bits (6.5µs, porém em testes o valor foi de 17µs)
}
void loop() {
  // put your main code here, to run repeatedly:


float F, gain;
F =17.0*pow(10,-6);      // Freq. de Amostragem
gain = 1.33779;          // Ganho baseaedo em programa do MATLAB
//t = 0:(1/Fs):0.05;
float freq=4000;         // Freq. desejada para filtro
float x, y;
int a;
a=0;
x=y=0.0;
float x1,x2,x3,x4,y1,y2,y3,y4;      // Variáveis para armazenar valores passados
x1=x2=x3=x4=y1=y2=y3=y4=0.0;


for (float t = 0; t< 0.05; t = t+F){
    
    x = sin(2*PI*freq*t)+sin(2*PI*3*freq*t)/3+sin(2*PI*5*freq*t)/5;         // Onda quadrada com grau 5
    //Serial.println(x);                                                    // Saída da onda
    
    if (a>4){
      y =  0.0001*x - 0.0002*x2 + 0.0001*x4 + 3.6131*y1 - 5.2337*y2+ 3.5590*y3 - 0.9702*y4;       // Equação do filtro
      Serial.println(gain*y);                                                                     // Saída do filtro com ganho
          y4=y3;
          y3=y2;
          y2=y1;
          y1=y;
    }
    x4=x3;
    x3=x2;
    x2=x1;
    x1=x;
    a=a+1;
 }

delay(10000000);
}
