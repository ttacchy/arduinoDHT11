//Baixar biblioteca DHT Sensor Library ou instalar do gerenciador de bibliotecas da IDE
#include "DHT.h"

#define DHTPIN 6 // o sensor dht11 foi conectado ao pino 6
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup(){
Serial.begin(9600); // inicializa o monitor serial
Serial.println("DHT teste!"); // imprime o texto no serial
dht.begin();
}

void loop(){
//declarar as variáveis para receber os valores
float umidade = dht.readHumidity(); 
float temperatura = dht.readTemperature();
// Se as variáveis temperatura e umidade não forem valores válidos, acusará falha de leitura.
if (isnan(temperatura) || isnan(umidade)){
Serial.println("Falha na leitura do dht11...");
} 
else 
{
// se os valores forem válidos, imprime os dados no monitor serial
Serial.print("Umidade: ");
Serial.print(umidade);
Serial.print(" %t"); //quebra de linha
Serial.print("Temperatura: ");
Serial.print(temperatura);
Serial.println(" °C");
delay(1000); //aguardar 1 segundo
}
}