#pragma once

typedef enum 
{
  SENTTOCONTROLLER,
  SENTTOEMAIL
}AlertMessage;

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL,
  MAX_ALERTER_TYPE
} AlertTarget;

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING,
  MAX_COOLING_TYPE
} CoolingType;

typedef struct {
  CoolingType coolingType;
} BatteryCharacter;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH,
  MAX_BREACH_TYPE
} BreachType;

struct TemperatureLimit
{
  int LowerLimit;
  int UpperLimit;
};

BreachType inferBreach( BatteryCharacter batteryChar, double temperatureInC);

AlertMessage checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

AlertMessage sendToController(BreachType breachType);
AlertMessage sendToEmail(BreachType breachType);

extern const char *AlerterMailContent[MAX_BREACH_TYPE];
extern const struct TemperatureLimit Limit[MAX_COOLING_TYPE];
