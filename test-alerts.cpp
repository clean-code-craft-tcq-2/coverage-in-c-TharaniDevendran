#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("Battery character belongs to PASSIVE COOLING -Temperature breach high value")
{
 BatteryCharacter batteryChar = {PASSIVE_COOLING};
  REQUIRE(inferBreach(batteryChar, 36) == TOO_HIGH);
}
TEST_CASE("Battery char belongs to PASSIVE COOLING -Temperature is too low") 
{
 BatteryCharacter batteryChar = {PASSIVE_COOLING};
  REQUIRE(inferBreach(batteryChar, -1) == TOO_LOW);
}
TEST_CASE("Battery char belongs to PASSIVE COOLING -Normal") 
{
 BatteryCharacter batteryChar = {PASSIVE_COOLING};
  REQUIRE(inferBreach(batteryChar, 10) == NORMAL);
}


/*******************************************************************************************/
/******** Battery Character belongs to  HI ACTIVE COOLING and different temperature level***/
/*******************************************************************************************/

TEST_CASE("Battery character belongs to HI ACTIVE COOLING -Temperature breach high value")
{
 BatteryCharacter batteryChar = {HI_ACTIVE_COOLING};
  REQUIRE(inferBreach(batteryChar, 46) == TOO_HIGH);
}
TEST_CASE("Battery char belongs to HI ACTIVE COOLING -Temperature is too low") 
{
 BatteryCharacter batteryChar = {HI_ACTIVE_COOLING};
  REQUIRE(inferBreach(batteryChar, -1) == TOO_LOW);
}
TEST_CASE("Battery char belongs to HI ACTIVE COOLING  -NORMAL") 
{
 BatteryCharacter batteryChar = {HI_ACTIVE_COOLING};
  REQUIRE(inferBreach(batteryChar, 22) == NORMAL);
}

/********************************************************************************************/
/****** Battery Character belongs to  MID ACTIVE COOLING and different temperature level*****/
/********************************************************************************************/


TEST_CASE("Battery character belongs to MED ACTIVE COOLING -Temperature breach high value_1")
{
 BatteryCharacter batteryChar = {MED_ACTIVE_COOLING};
  REQUIRE(inferBreach(batteryChar, 41) == TOO_HIGH);
}
TEST_CASE("Battery character belongs to MED ACTIVE COOLING -Temperature breach high value_2")
{
 BatteryCharacter batteryChar = {MED_ACTIVE_COOLING};
  REQUIRE(inferBreach(batteryChar, 40) == NORMAL);
}
TEST_CASE("Battery char belongs to MED ACTIVE COOLING -Temperature is too low_1") 
{
 BatteryCharacter batteryChar = {MED_ACTIVE_COOLING};
  REQUIRE(inferBreach(batteryChar, -1) == TOO_LOW);
}


TEST_CASE("Battery char belongs to MED ACTIVE COOLING -Temperature is too low_2") 
{
 BatteryCharacter batteryChar = {MED_ACTIVE_COOLING};
  REQUIRE(inferBreach(batteryChar, 0) == NORMAL);
}

TEST_CASE("Battery char belongs to MED ACTIVE COOLING -Temperature in normal") 
{
 BatteryCharacter batteryChar = {MED_ACTIVE_COOLING};
  REQUIRE(inferBreach(batteryChar, 22) == NORMAL);
}

/****************************************************/
/********** TEST Alert message send to controller*****/
/*****************************************************/

TEST_CASE("CheckAndAlert-TOOHIGH -SENTTOCONTROLLER") 
{
  BatteryCharacter batteryChar = {PASSIVE_COOLING};
  REQUIRE(checkAndAlert(TO_CONTROLLER,batteryChar,55) == SENTTOCONTROLLER);
}


/************************************************/
/********** Test Alert message send to Email*****/
/************************************************/
TEST_CASE("CheckAndAlert-TOOHIGH -SENTTOEMAIL") 
{
  BatteryCharacter batteryChar = {PASSIVE_COOLING};
  REQUIRE(checkAndAlert(TO_EMAIL,batteryChar,30) == SENTTOEMAIL);
}
