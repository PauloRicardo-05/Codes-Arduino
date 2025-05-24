#include <Servo.h>  // Biblioteca para controle do servo

// Pinos do sensor ultrassônico
const int trigPin = 9;
const int echoPin = 10;

// Pino do LED
const int ledPin = 13;

// Criação do objeto servo
Servo meuServo;

void setup() {
  // Configurações dos pinos
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Inicializando o servo no pino 6
  meuServo.attach(6);

  // Inicializando a comunicação serial (opcional para depuração)
  Serial.begin(9600);
}

void loop() {
  for (int angulo = 0; angulo <= 180; angulo += 10) {
    meuServo.write(angulo);  // Move o servo para o ângulo atual
    delay(500);  // Atraso para dar tempo ao sensor

    long distancia = medirDistancia();  // Medir distância do objeto
    
    // Exibe a distância no Monitor Serial (opcional)
    Serial.print("Distancia: ");
    Serial.println(distancia);

    // Se a distância for menor ou igual a 10 cm, acende o LED
    if (distancia <= 10 && distancia != -1) {
      digitalWrite(ledPin, HIGH);  // Acende o LED
    } else {
      digitalWrite(ledPin, LOW);   // Apaga o LED
    }

    delay(500);  // Pequeno atraso entre leituras
  }

  // Servo retorna para a posição inicial
  for (int angulo = 180; angulo >= 0; angulo -= 10) {
    meuServo.write(angulo);  // Move o servo para o ângulo atual
    delay(500);  // Atraso para dar tempo ao sensor

    long distancia = medirDistancia();  // Medir distância do objeto
    
    Serial.print("Distancia: ");
    Serial.println(distancia);

    if (distancia <= 10 && distancia != -1) {
      digitalWrite(ledPin, HIGH);  // Acende o LED
    } else {
      digitalWrite(ledPin, LOW);   // Apaga o LED
    }

    delay(500);
  }
}

// Função para medir a distância usando o sensor ultrassônico
long medirDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duracao = pulseIn(echoPin, HIGH, 30000);  // Tempo do pulso de retorno
  long distancia = duracao * 0.034 / 2;          // Converter o tempo em distância (cm)

  // Se a distância for inválida, retorna -1
  if (distancia <= 0 || distancia > 400) {
    return -1;
  }

  return distancia;
}
