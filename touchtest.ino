// These constants won't change.  They're used to give names
// to the pins used:
const int touchPin = A1;  // Analog input pin that the potentiometer is attached to
const int screenPin = A0;

const int TOUCH_OFF = 0;
const int TOUCH_ON = 1;
const int touchUpperThres = 800;
const int touchBottomThres = 200;

const int SCREEN_OFF = 2;
const int SCREEN_ON = 3;
const int screenUpperThres = 500;
const int screenBottomThres = 300;

int touchState = TOUCH_OFF;
int screenState = SCREEN_OFF;

unsigned long lastTouchRisingTime = 0;
unsigned long lastScreenRisingTime = 0;

void setup() {
   // initialize serial communications at 9600 bps:
   Serial.begin(9600); 
}

void loop() {
   // this takes about 100us. 0-1023 
   delay(1); //analog sensor need rest time.
   int touch = 1023-analogRead(touchPin);          
   int screen = 1023-analogRead(screenPin);
   
   unsigned long currentMicros = micros();
   
   // basic Schmitt trigger
   int newTouchState = touchState; 
   if(touch > touchUpperThres) newTouchState = TOUCH_ON;
   else if(touch < touchBottomThres) newTouchState = TOUCH_OFF;
   
   // basic Schmitt trigger
   int newScreenState = screenState;
   if(screen > screenUpperThres) newScreenState = SCREEN_ON;
   else if(screen < screenBottomThres) newScreenState = SCREEN_OFF;
   
   
   if(newTouchState == TOUCH_ON && touchState == TOUCH_OFF){
       lastTouchRisingTime = currentMicros;
   }
   if(newScreenState == SCREEN_ON && screenState == SCREEN_OFF){
     lastScreenRisingTime = currentMicros;
     if(lastTouchRisingTime != 0 && lastScreenRisingTime > lastTouchRisingTime){
       Serial.println(lastScreenRisingTime - lastTouchRisingTime);
       lastTouchRisingTime = 0;
     }
   }

   if(touchState != newTouchState){
     touchState = newTouchState;
   }
   if(screenState != newScreenState){
     screenState = newScreenState;
   }
}
