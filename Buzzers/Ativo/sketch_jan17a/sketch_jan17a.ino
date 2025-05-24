// Pino digital para o buzzer ativo
const int buzzerPin = 8;

void setup() {
  pinMode(buzzerPin, OUTPUT); // Configura o pino como saída
}

void loop() {
  digitalWrite(buzzerPin, HIGH); // Liga o buzzer
  delay(1000);                   // Mantém ligado por 1 segundo
  digitalWrite(buzzerPin, LOW);  // Desliga o buzzer
  delay(1000);                   // Mantém desligado por 1 segundo
}
