/* 
 *  Light Controlled Vibration Motor
 *  Using ATTINY85 LilyPad / DigiSpark
 *  
 *  Connect light sensor to pin 3
 *  and vibration motor to pin 1
 */

#define VIB_PIN           1   // vib motor / PWM and built-in led
#define AN_PIN            3   // one of the analog inputs

void setup() {  
  pinMode(VIB_PIN, OUTPUT);       // connect a vibro motor or LED
  pinMode(AN_PIN, INPUT);         // connect an analog sensor here, like a LDR
}


void loop() {
  int an_sig, mapped; // define some integer variables that we will use below
  
  an_sig = analogRead(AN_PIN); // read analog sensor
  delay(5); // small delay for stability

  // usually you need to use the map() and constrain() functions
  // to convert the range of the analog sensor to a range of values that you can use
  // Here the functions are "nested". The innermost function (map) is the first one to execute.
  // The result of this function then is passed to the outer function (constrain)
  // Here we map the analog sensor value from a range of 475-605 to 0-255 
  // However, if the analog signal is outside the range of 475-605 then map
  //  will give us a result outside the range of 0-255. This can happen because
  //  analog sensors are often tempramental and inexact.
  // To deal with this, we use constrain to clamp the mapped value to 0-255.
  mapped = constrain(map(an_sig, 475, 605, 0, 255), 0, 255);

  // use the mapped analog value to control the vibro motor strength
  analogWrite(VIB_PIN, mapped); 

  // small delay for stability
  delay(5);
}
