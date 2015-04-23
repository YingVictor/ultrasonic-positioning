// Mimics the receiver board, sending a repeating series of four pings
// as if from four transmitter stations to the PSoC, for the PSoC to
// attempt position calculations.

enum {
  RX_PIN = 11,
  NUM_TRANSMITTERS = 4u,
  DURATION = 5000u,  // μs
};

unsigned const long SPACINGS[4] = {100000u, 100000u, 100000u, 700000u};

void setup() {
  pinMode(RX_PIN, OUTPUT);
}

void loop() {
  static unsigned i = 0;
  digitalWrite(RX_PIN, HIGH);
  unsigned long beginning = micros();
  while (micros() - beginning < DURATION)
    ;
  digitalWrite(RX_PIN, LOW);
  unsigned long spacing = SPACINGS[i];
  i = (i + 1) % NUM_TRANSMITTERS;
  while (micros() - beginning < spacing)
    ;
}
