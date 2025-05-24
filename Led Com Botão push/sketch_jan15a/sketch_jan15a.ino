const int botaoPino = 2;  // Pino onde o botão está conectado
const int ledPino = 13;   // Pino onde o LED está conectado
int estadoBotao = 0;      // Variável para armazenar o estado do botão

void setup() {
  pinMode(botaoPino, INPUT);   // Configura o pino do botão como entrada
  pinMode(ledPino, OUTPUT);    // Configura o pino do LED como saída
  digitalWrite(ledPino, LOW);  // Garante que o LED comece apagado
}

void loop() {
  // Ler o estado do botão
  estadoBotao = digitalRead(botaoPino);

  // Se o botão estiver pressionado, acende o LED
  if (estadoBotao == HIGH) {
    digitalWrite(ledPino, HIGH); // Acende o LED
  } else {
    digitalWrite(ledPino, LOW);  // Apaga o LED
  }
}
