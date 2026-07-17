#include <Arduino_RouterBridge.h>
#include <Arduino_LED_Matrix.h>
#include "digits.h"

Arduino_LED_Matrix matrix;

void setup()
{
  matrix.begin();
  Bridge.begin();
}

void loop()
{
  String digitString;
  bool ok=Bridge.call("get_digit").result(digitString);
  if(ok)
  {
    int currentDigit=digitString.toInt();
    switch(currentDigit)
    {
      case 0:
        matrix.loadPixels((uint8_t*)digit_zero,sizeof(digit_zero));
        break;
  
      case 1:
        matrix.loadPixels((uint8_t*)digit_one,sizeof(digit_one));
        break;
  
      case 2:
        matrix.loadPixels((uint8_t*)digit_two,sizeof(digit_two));
        break;
  
      case 3:
        matrix.loadPixels((uint8_t*)digit_three,sizeof(digit_three));
        break;
  
      case 4:
        matrix.loadPixels((uint8_t*)digit_four,sizeof(digit_four));
        break;
  
      case 5:
        matrix.loadPixels((uint8_t*)digit_five,sizeof(digit_five));
        break;
  
      case 6:
        matrix.loadPixels((uint8_t*)digit_six,sizeof(digit_six));
        break;
  
      case 7:
        matrix.loadPixels((uint8_t*)digit_seven,sizeof(digit_seven));
        break;
  
      case 8:
        matrix.loadPixels((uint8_t*)digit_eight,sizeof(digit_eight));
        break;
  
      case 9:
        matrix.loadPixels((uint8_t*)digit_nine,sizeof(digit_nine));
        break;
  
      default:
        matrix.loadPixels((uint8_t*)minus_one,sizeof(minus_one));
        break;
      }
  }
  delay(200);
}
