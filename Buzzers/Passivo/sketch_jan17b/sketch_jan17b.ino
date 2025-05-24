// Pino digital para o buzzer passivo
const int buzzerPin = 8;

void setup() {
  pinMode(buzzerPin, OUTPUT); // Configura o pino como saída
}

void loop() {
  tone(buzzerPin, 1000); // Emite som a 1000 Hz
  delay(1000);           // Mantém o som por 1 segundo
  noTone(buzzerPin);     // Para o som
  delay(1000);           // Mantém o buzzer silencioso por 1 segundo
}
