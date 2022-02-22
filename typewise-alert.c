#include "typewise-alert.h"
#include <stdio.h>

const char *AlerterMailContent[MAX_BREACH_TYPE]={"Hi, the temperature is too low\n",
                                                 "Hi, the temperature is too high\n",
                                                 "Hi, the temperature is Normal\n"
                                                 };

const struct TemperatureLimit Limit[MAX_COOLING_TYPE]={
  {0,35},
  {0,45},
  {0,40}
};

AlertMessage (*AlerterTarget_FP[MAX_ALERTER_TYPE])(BreachType)={sendToController,sendToEmail};

BreachType inferBreach( BatteryCharacter batteryChar, double temperatureInC) {
  if(Limit[batteryChar.coolingType].LowerLimit > temperatureInC) 
  {
    return TOO_LOW;
  }
  if(Limit[batteryChar.coolingType].UpperLimit < temperatureInC) 
  {
    return TOO_HIGH;
  }
  return NORMAL;
}

AlertMessage checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) 
{
 //Temperature configuration read from cfg file based on cooling type
  BreachType breachType = inferBreach(batteryChar,temperatureInC);
  AlertMessage SentACK =AlerterTarget_FP[alertTarget](breachType);
  
  return SentACK;
}

AlertMessage sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
  return SENTTOCONTROLLER;
}

void SendEmail(const char* AMessageData ,const char* ARecepient )
{
  printf("To: %s\n", ARecepient);
  printf("%s",AMessageData);
  
}
AlertMessage sendToEmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
  SendEmail(AlerterMailContent[breachType],recepient);
  return SENTTOEMAIL;
}
