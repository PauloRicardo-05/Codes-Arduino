const int ledPino = 13;  // Pino onde o LED está conectado

void setup() {
  pinMode(ledPino, OUTPUT);  // Configura o pino do LED como saída
  digitalWrite(ledPino, HIGH); // Acende o LED
}

void loop() {
  // Nada a fazer no loop, pois o LED permanece aceso
}
