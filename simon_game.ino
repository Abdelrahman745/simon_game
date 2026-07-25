int buttonLeft  = 3;
int buttonRight = 4;
int buttonUp    = 5;
int buttonDown  = 6;

int ledLeft  = 7;
int ledRight = 8;
int ledUp    = 9;
int ledDown  = 10;

int sequence[100];
int length = 0;
int score = 0;
int speed = 500;

void setup() {
  Serial.begin(9600);
  setupPins();
  askDifficulty();
  addNewStep();
}

void loop() {
  showSequence();
  bool correct = readPlayerInput();

  if (correct) {
    roundWon();
  } else {
    gameOver();
  }
}

void setupPins() {
  pinMode(buttonLeft, INPUT_PULLUP);
  pinMode(buttonRight, INPUT_PULLUP);
  pinMode(buttonUp, INPUT_PULLUP);
  pinMode(buttonDown, INPUT_PULLUP);

  pinMode(ledLeft, OUTPUT);
  pinMode(ledRight, OUTPUT);
  pinMode(ledUp, OUTPUT);
  pinMode(ledDown, OUTPUT);
}

void askDifficulty() {
  Serial.println("Choose difficulty: 1=Easy 2=Medium 3=Hard");

  while (Serial.available() == 0) {
  }

  int choice = Serial.parseInt();

  if (choice == 2) {
    speed = 350;
  } else if (choice == 3) {
    speed = 200;
  } else {
    speed = 500;
  }
}

int getLedForStep(int step) {
  if (step == 0) return ledLeft;
  if (step == 1) return ledRight;
  if (step == 2) return ledUp;
  return ledDown;
}

void addNewStep() {
  sequence[length] = random(0, 4);
  length++;
}

void showSequence() {
  delay(500);

  for (int i = 0; i < length; i++) {
    int led = getLedForStep(sequence[i]);
    digitalWrite(led, HIGH);
    delay(speed);
    digitalWrite(led, LOW);
    delay(200);
  }
}

int waitForButton() {
  unsigned long startTime = millis();

  while (millis() - startTime < 5000) {
    if (digitalRead(buttonLeft) == LOW) return 0;
    if (digitalRead(buttonRight) == LOW) return 1;
    if (digitalRead(buttonUp) == LOW) return 2;
    if (digitalRead(buttonDown) == LOW) return 3;
  }

  return -1;
}

bool readPlayerInput() {
  for (int i = 0; i < length; i++) {
    int pressed = waitForButton();

    if (pressed == -1) {
      return false;
    }

    int led = getLedForStep(pressed);
    digitalWrite(led, HIGH);
    delay(150);
    digitalWrite(led, LOW);

    if (pressed != sequence[i]) {
      return false;
    }
  }

  return true;
}

void roundWon() {
  score++;
  Serial.print("Correct! Score: ");
  Serial.println(score);
  delay(500);
  addNewStep();
}

void gameOver() {
  Serial.print("Game Over! Final score: ");
  Serial.println(score);
  delay(2000);

  length = 0;
  score = 0;
  addNewStep();
}
