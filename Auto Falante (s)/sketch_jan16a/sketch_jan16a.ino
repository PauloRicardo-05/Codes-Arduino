#define SPEAKER_PIN 13  // Pino conectado ao resistor e alto-falante

void setup() {
  pinMode(SPEAKER_PIN, OUTPUT);  // Define o pino como saída
}

void loop() {
  // Toca um som de 1000 Hz por 500 ms
  tone(SPEAKER_PIN, 1000); // Gera um tom de 1000 Hz
  delay(500);              // Aguarda 500 ms

  // Para o som por 500 ms
  noTone(SPEAKER_PIN); // Para o tom
  delay(500);          // Aguarda 500 ms

  // Toca um som de 1500 Hz por 300 ms
  tone(SPEAKER_PIN, 1500); // Gera um tom de 1500 Hz
  delay(300);              // Aguarda 300 ms

  // Para o som por 700 ms
  noTone(SPEAKER_PIN); // Para o tom
  delay(700);          // Aguarda 700 ms
}
