int MaxPins = 13;
int MinPins = 13;

void setup() {
  Serial.begin(9600);
  Serial.println("Setup is klaar!");
  Serial.print("Min pins: ");
  Serial.println(MinPins);
  Serial.print("Max pins: ");
  Serial.println(MaxPins);
  int pins = MaxPins;
  while(pins >= MinPins) {
    pinMode(pins, OUTPUT);
    pins--;
  }
  //pinMode(13, INPUT_PULLUP);
}
