#define SENSOR_PIN 2
#define PWM_PIN 5

float motor_speed = 0;
byte state = LOW;
float target_speed = 40;

unsigned short paused = 0;

float KP = 0.1;
float KI = 0.31;
float KD = 0.31;

float error = 0;
float integral = 0;
float derivative = 0;
float previous_error = 0;

float output = 0;

unsigned short pwm = 0;

#define SCALAR 22


void setup() {
  // put your setup code here, to run once:
  pinMode(SENSOR_PIN, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(SENSOR_PIN), blink, CHANGE);
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
  TCCR0B = _BV(CS00) | _BV(CS02);
  Serial.begin(57600);
  Serial.print(0);  // To freeze the lower limit
Serial.print(" ");
Serial.print(60);  // To freeze the upper limit
Serial.print(" ");
}

void loop() 
{
//  digitalWrite(LED_BUILTIN, state);
//  if (Serial.available()) 
//  {
//    // read the incoming byte:
//    target_speed = Serial.read();
//    Serial.print("TS ");
//    Serial.println(target_speed, DEC);
//   }
}

void pid()
{
  error = target_speed - motor_speed;
//  Serial.print("E");
//  Serial.println(error);
  integral += error;
//  Serial.print("I");
//  Serial.println(integral);
  derivative = previous_error - error;
//  Serial.print("D");
//  Serial.println(derivative);

  output = (KP * error) + (KI * integral) + (KD * derivative);
//  Serial.print("O");
//  Serial.println(output);
  
  pwm = (unsigned short) (output);
  if(pwm > 255)
  {
    pwm = 255;
  }
//  Serial.println(pwm);
  analogWrite(PWM_PIN, pwm);
  
  previous_error = error;
}

SIGNAL(TIMER0_COMPA_vect) 
{
  Serial.println(motor_speed);
//    Serial.println(target_speed);
//    Serial.println(pwm);
//    Serial.println();
    state = !state;
    pid();
    motor_speed = 0;
} 

void blink() 
{
  motor_speed++;
}
