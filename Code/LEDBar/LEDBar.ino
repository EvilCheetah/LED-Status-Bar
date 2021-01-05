const int MIN_PIN  = 2;
const int MAX_PIN  = 10;
const int DATA_PIN = A1;

void initialState(bool);
void loadingBar(bool);
void blinking();

void setup() {
  Serial.begin(9600);
  for (int i = MIN_PIN; i <= MAX_PIN; i++)
    pinMode(i, OUTPUT);
  pinMode(DATA_PIN, INPUT);
}

void loop() {
  float reading = map(analogRead(DATA_PIN), 0, 1023, 0, 100);
  
  int percentage = reading / 10;
  for (int i = MIN_PIN; i <= MAX_PIN; ++i)
    digitalWrite(i, LOW);
  
  for (int i = 0; i <= percentage; ++i)
  {
    digitalWrite(i, HIGH);
  }
  delay(0.5);
//  
//  char userChoice;
//  Serial.print("Choose the mode.\n");
//  Serial.print("[^] - Regular\n[!] - Inverse\n[&] - Blinking\n");
//
//  
//  while ( !Serial.available() );
//  userChoice = Serial.read();
//  
//  switch(userChoice)
//  {
//    case '^':
//      loadingBar(true);
//      break;
//    case '!':
//      loadingBar(false);
//      break;
//    case '&':
//      blinking();
//      break;
//    default:
//      Serial.print("Try again!");
//      break;
//  }
}


void LEDState(bool initState)
{
  for (int i = MIN_PIN; i <= MAX_PIN; i++)
    digitalWrite(i, initState);
}

void loadingBar(bool LedIsOn)
{
  //initialState(!LedIsOn);
  for (int i = 2; i <= 10; i++)
  {
    for (int j = i; j <= 10; j++)
    {
      digitalWrite(j, LedIsOn);
      delay(500);
      digitalWrite(j, !LedIsOn);
    }
    delay(500);
    digitalWrite(i, LedIsOn);
    delay(500);
  }
}

void blinking()
{
  bool state = true;
  for (int i = 0; i < 6; i++)
  {
    for (int j = 2; j <= 10; j++)
      digitalWrite(j, state);

    delay(500);
    state = !state;
  }
}
