const int analogPins[] = {A0, A1, A2, A3, A4, A5, A6, A7}; // A0, A1, A2, ..., A7
const int numAnalogInps = 8;
int Enable = 12;
int i;
int sensorValue;
const int umbral = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(Enable, OUTPUT); // Corregido: LOW no es válido aquí, debe ser INPUT/OUTPUT
  digitalWrite(Enable, LOW); // Apaga el pin Enable inicialmente
}

void loop() {
  for (int i = 0; i < numAnalogInps; i++) {
    sensorValue = analogRead(analogPins[i]); // Lee el valor del pin analógico
    if (sensorValue <= umbral) { // Compara con el umbral
      sensorValue = 1; // Si es menor o igual al umbral, establece el valor a 1
    } else {
      sensorValue = 0; // Opcional: establece el valor a 0 si no cumple el umbral
    }

    // Imprime el resultado en formato "A0:valor,A1:valor,..."
    Serial.print("A");
    Serial.print(i);
    Serial.print(":");
    Serial.print(sensorValue);
    if (i < numAnalogInps - 1) {
      Serial.print(","); // Agrega una coma entre los valores
    }
  }
  Serial.println(); // Salto de línea al final
  delay(1000); // Espera 1 segundo antes de repetir
}
