#include <AgButton.h>

#define D0    16
#define D1    5
#define D2    4
#define D3    0
#define D4    2
#define D5    14
#define D6    12
#define D7    13
#define D8    15

AgButton Botao(D0);

void setup() {
  Serial.begin(115200);
  // initialize the pushbutton pin as an input:
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
}

void loop() {

  if(Botao.Status)
  {
    digitalWrite(D5, HIGH);
  }
  else
  {
    digitalWrite(D5, LOW);
  }

  if(Botao.PulseDown)
  {
    Serial.println("Pulso Down");
    digitalWrite(D6, LOW);
    digitalWrite(D7, HIGH);
  }

  if(Botao.PulseUp)
  {
    Serial.println("Pulso Up");
    digitalWrite(D6, HIGH);
    digitalWrite(D7, LOW);
  }

  Botao.loop();
}