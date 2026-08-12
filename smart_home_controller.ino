/*
  ======================================================
  Project: Smart Home & Safety System
  Author: Mostafa Magdy
  Description: Integrated Arduino system for smart lighting, 
               hazard detection (gas/temp/switch), and 
               a manual counter using a 7-segment display.
  ======================================================
*/

#define pot A0 
#define led_1 10
#define led_2 5
#define led_3 6
#define light_sensor A1

#define buzz 11
#define gas_sensor A2
#define temp_sensor A3
#define slide_switch 4
#define led_4 2

#define button_down A4
#define button_up A5
#define a 1
#define b 0
#define c 13
#define d 12
#define e 9
#define f 7
#define g 8

unsigned long previousMillis = 0;
const unsigned long interval = 500;
bool alarmState = false;

int pot_reading;
int light_intensity;
int sun_light;

int gas_reading;
int temp_reading;
int switch_state;

int down_state;
int up_state;
int last_up = 0;
int last_down = 0;
int counter;

void setup()
{
    pinMode(led_1, OUTPUT); 
    pinMode(led_2, OUTPUT); 
    pinMode(led_3, OUTPUT); 

    pinMode(buzz, OUTPUT);
    pinMode(slide_switch, INPUT);
    pinMode(led_4, OUTPUT);

    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    pinMode(g, OUTPUT);

    pinMode(button_down, INPUT);
    pinMode(button_up, INPUT);
}

void loop()
{
  unsigned long currentMillis = millis();

  sun_light = analogRead(light_sensor);

  if (sun_light <= 940)
  {
    pot_reading = analogRead(pot);
    light_intensity = map(pot_reading, 0, 1023, 0, 255);
    analogWrite(led_1, light_intensity);
    analogWrite(led_2, light_intensity);
    analogWrite(led_3, light_intensity);    
  }
  else
  {
    analogWrite(led_1, 0);
    analogWrite(led_2, 0);
    analogWrite(led_3, 0);
  }

  gas_reading = analogRead(gas_sensor);
  temp_reading = analogRead(temp_sensor);
  switch_state = digitalRead(slide_switch);

  if (gas_reading >= 540 || temp_reading >= 227 || switch_state == HIGH)
  {
    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;
        alarmState = !alarmState;

        if (alarmState)
        {
            digitalWrite(led_4, HIGH);
            tone(buzz, 2500);
        }
        else
        {
            digitalWrite(led_4, LOW);
            noTone(buzz);
        }
    }
  }
  else
  {
    digitalWrite(led_4, LOW);
    noTone(buzz);
    alarmState = false;
  }

  up_state = digitalRead(button_up);
  down_state = digitalRead(button_down);

  if (up_state == HIGH && last_up == LOW) {
       counter++;
       if (counter > 9) counter = 0; 
  } 
  last_up = up_state;

  if (down_state == HIGH && last_down == LOW) {
       counter--;
       if (counter < 0) counter = 9; 
  }
  last_down = down_state;

  displayDigit(counter);
  delay(80);
}

// Function to facilitate 7-segment display
void displayDigit(int num) {

  if (num == 0) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
  }
  else if (num == 1) {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  else if (num == 2) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  }
  else if (num == 3) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  }
  else if (num == 4) {
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  else if (num == 5) {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  else if (num == 6) {
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  else if (num == 7) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  else if (num == 8) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  else if (num == 9) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
}
