// Configuración de los pines analógicos
const int analogPins[] = {A0, A1, A2, A3, A4, A5, A6, A7}; // Pines analógicos conectados a OUT1-OUT8
const int numAnalogInps = 8; // Número de sensores

// Pin ENABLE (si existe)
int Enable = 12;

void setup() {
  Serial.begin(9600); // Inicia la comunicación serial
  pinMode(Enable, OUTPUT); // Configura el pin Enable como salida
  digitalWrite(Enable, HIGH); // Activa los sensores (si es necesario)
}

void loop() {
  // Lee y muestra los valores de cada sensor
  for (int i = 0; i < numAnalogInps; i++) {
    int rawValue = analogRead(analogPins[i]); // Lee el valor bruto del sensor
    Serial.print("Sensor ");
    Serial.print(i + 1); // Numeración de los sensores (1 a 8)
    Serial.print(": ");
    Serial.println(rawValue); // Imprime el valor bruto
  }

  Serial.println(); // Salto de línea para separar las lecturas
  delay(500); // Espera 500 ms antes de la siguiente lectura
}
