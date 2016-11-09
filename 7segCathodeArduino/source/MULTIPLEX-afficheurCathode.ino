/*
 * Made by Leo Smith
 * form the 22 October 2016 at 00:00 to the 22 October 2016 at 00:56
 *
 * We are using a 7 segment display with common cathode
 * so to turn on a segment you have to send a LOW and to turn of
 * a HIGH
 */

/*
 * Creating my own enum var for the fun and to improve
 * readability of the code
 */
enum { off = false, on = true };  // this works in c99 standard

/*
 * Constant Variables
 */
const int piNum = 7;
const int DP = 11;            // this is the dp--+
const int pinOut[piNum] = {  4,      //  -       |
                           6, 5,     // | |      |
                             7,      //  -       |
                           8, 9,     // | |      |
                            10 };    //  - . <---+

/*
 * Function Prototypes
 */
void startup();
void dispNumber(int , bool);

#ifdef DEBUG
void reset();
#endif

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
/* Setup function executes once and then goes to loop
 *             __
  ______ _____/  |_ __ ________
 /  ___// __ \   __\  |  \____ \
 \___ \\  ___/|  | |  |  /  |_> >
/____  >\___  >__| |____/|   __/
     \/     \/           |__|     */
void setup()
{
  for(int i = 0; i < piNum; i++){
    pinMode(pinOut[i], OUTPUT);
  }
  pinMode(DP, OUTPUT);

  for(int i = 0; i < piNum; i++){
    digitalWrite(pinOut[i], HIGH);
  }
  digitalWrite(DP, HIGH);

  startup();
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
/* Main loop, it constantly executes
 *.__
  |  |   ____   ____ ______
  |  |  /  _ \ /  _ \\____ \
  |  |_(  <_> |  <_> )  |_> >
  |____/\____/ \____/|   __/
                     |__|    */
void loop()
{
  dispNumber(4, on);
  delay(100);
  dispNumber(4, off);
  delay(50);
  dispNumber(4, on);
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
/*
 * Fonction code
 */

/*
 * Startup function to check for deffects
 */
void startup()
{
  /*
   * Make each segment blink to check
   * for hardware defects
   */
  for(int i = 0; i < piNum ; i++){
    digitalWrite(pinOut[i], LOW);
    delay(100);
    digitalWrite(pinOut[i], HIGH);
  }

  /*
   * Make DP blink 3 times to tell that
   * the startup check is finished
   */
  for(int i = 0; i < 3; i++) {
    digitalWrite(DP, LOW);
    delay(100);
    digitalWrite(DP, HIGH);
  }
}

/*
 * Reset function only used for debug
 */
void reset()
{
  #ifdef DEBUG
  for(int i = 0; i < piNum; i++){
    digitalWrite(pinOut[i], HIGH);
    Serial.println("pin No %d : %d", i, pinOut[i]);
  }
  digitalWrite(DP, HIGH);
  Serial.println("Num of pins %d, DP pin: %d", piNum, DP);
  #endif
}

/*
 * Display number function
 */
void dispNumber(int num, bool flag)
{

  if(num == 0){

    for(int i = 0; i < piNum; i++){
      if(pinOut[i] != 7)
        digitalWrite(pinOut[i], (flag) ? LOW : HIGH);
    }

  } else if(num == 1) {

    for(int i = 0; i < piNum; i++){
      if(pinOut[i] == 5 || pinOut[i] == 9)
        digitalWrite(pinOut[i], (flag) ? LOW : HIGH);
    }

  } else if(num == 2) {

    for(int i = 0; i < piNum; i++){
      if(pinOut[i] == 4 || pinOut[i] == 5 || pinOut[i] == 7 || pinOut[i] == 8 || pinOut[i] == 10)
        digitalWrite(pinOut[i], (flag) ? LOW : HIGH);
    }

  } else if(num == 3) {

    for(int i = 0; i < piNum; i++){
      if(pinOut[i] == 4 || pinOut[i] == 5 || pinOut[i] == 7 || pinOut[i] == 9 || pinOut[i] == 10)
        digitalWrite(pinOut[i], (flag) ? LOW : HIGH);
    }

  } else if(num == 4) {

    for(int i = 0; i < piNum; i++){
      if(pinOut[i] == 6 || pinOut[i] == 5 || pinOut[i] == 7 || pinOut[i] == 9)
        digitalWrite(pinOut[i], (flag) ? LOW : HIGH);
    }

  } else if(num == 5) {

    for(int i = 0; i < piNum; i++){
      if(pinOut[i] == 4 || pinOut[i] == 6 || pinOut[i] == 7 || pinOut[i] == 9 || pinOut[i] == 10)
        digitalWrite(pinOut[i], (flag) ? LOW : HIGH);
    }

  } else if(num == 6) {

    for(int i = 0; i < piNum; i++){
      if(pinOut[i] != 5)
        digitalWrite(pinOut[i], (flag) ? LOW : HIGH);
    }

  } else if(num == 7) {

    for(int i = 0; i < piNum; i++){
      if(pinOut[i] == 4 || pinOut[i] == 5 || pinOut[i] == 9)
        digitalWrite(pinOut[i], (flag) ? LOW : HIGH);
    }

  } else if(num == 8) {

    for(int i = 0; i < piNum; i++){
      digitalWrite(pinOut[i], (flag) ? LOW : HIGH);
    }

  } else if(num == 9) {

    for(int i = 0; i < piNum; i++){
      if(pinOut[i] != 8)
        digitalWrite(pinOut[i], (flag) ? LOW : HIGH);
    }

  } else {
    startup();    // upon error execute the startup function
  }

}
