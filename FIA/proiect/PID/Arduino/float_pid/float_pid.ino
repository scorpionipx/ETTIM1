#define SENSOR_PIN 2
#define PWM_PIN 5

volatile long int motor_speed = 0;
byte state = LOW;
long int target_speed = 30;

unsigned short paused = 0;

long int KP = 1;
long int KI = 1;
long int KD = 1;

long int error = 0;
long int integral = 0;
long int derivative = 0;
long int previous_error = 0;

long int output = 0;

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
  error <<= SCALAR;
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
  
  output >>= SCALAR;
  
  
  pwm = output;
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
