void setup() {
  // put your setup code here, to run once:
Serial.begin (115200);
ADCSRA &= ~(bit (ADPS0) | bit (ADPS1) | bit (ADPS2)); // // limpa prescaler bits

ADCSRA |= bit (ADPS0) | bit (ADPS1);                 //   8     
}

void loop() {
  // put your main code here, to run repeatedly:
long t;
double vTeste[1000], vTeste2[1000];                // Teste para mil aquisições 
long t0 = micros();                                  
for (int i = 0; i<1000; i++){                      // Teste para duas leituras nas portas analógicas
vTeste[i]= analogRead(A0);
vTeste2[i]= analogRead(A1);
}
t=micros() - t0;                                   // Faz cálculo de tempo para aquisição
Serial.println(t/1000);                            // Printa na tela o tempo em micro segundos

}
