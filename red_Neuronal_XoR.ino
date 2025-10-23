// Pines a Utilizar en la práctica
const int pinBtn1 = 21;
const int pinBtn2 = 5;
const int pinLED = 23;
int x1, x2;

// Función sigmoide logística
float sigmoid(float x) {
  return 1.0 / (1.0 + (float)exp(-x));
}

// Red neuronal XOR
int xorNN(int x1, int x2) {
  // capa oculta
  float h1 = sigmoid(-2.69 * x1 - 2.80 * x2 - 2.21);
  float h2 = sigmoid(-3.39 * x1 - 4.56 * x2 + 4.76);

  // Neurona de salida
  float out = sigmoid(-4.91 * h1 + 4.95 * h2 - 2.28);

  // Umbralización
  if (out >= 0.35) {
    return 1; // Si la salida es mayor o igual a 0.35
  } else {
    return 0; // Si la salida es menor a 0.35
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(pinBtn1, INPUT_PULLUP);
  pinMode(pinBtn2, INPUT_PULLUP);
  pinMode(pinLED, OUTPUT);
}

void loop() {
  Serial.print("x1: ");
  Serial.print(digitalRead(pinBtn1));
  Serial.print(" | x2: ");
  Serial.println(digitalRead(pinBtn2));
  delay(500);

  // Leer botones (LOW = presionado) y convertir a entradas bipolares
  if (digitalRead(pinBtn1) == LOW) {
    x1 = 1;    // Botón presionado
  } else {
    x1 = -1;   // Botón no presionado
  }

  if (digitalRead(pinBtn2) == LOW) {
    x2 = 1;    // Botón presionado
  } else {
    x2 = -1;   // Botón no presionado
  }

  // Calcular salida XOR
  int salida = xorNN(x1, x2);

  // LED encendido/apagado según salida
  digitalWrite(pinLED, salida);
}