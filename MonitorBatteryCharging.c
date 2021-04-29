#include <stdio.h>
#include "catch.hpp"
#include"MonitorBatteryCharging_prv.h"

batteryChargeReading_st checkBatteryChargeReading(int *chargeReading, int numOfReadings)
{
  int loopCntr = 0;
  int continuousReading =1, tempVar, retStatus;
  batteryChargeReading_st batteryChargeDetails;
  batteryChargeDetails.paramStatus = OK_VALID;
  tempVar = chargeReading[loopCntr];
  for(;loopCntr<numOfReadings;loopCntr++)
  {
    if((tempVar+1) == chargeReading[loopCntr+1])
    {
      continuousReading++; /* denotes continuous reading are present */
    }
    tempVar = chargeReading[loopCntr];
  }
  if((loopCntr == 0) || (chargeReading == NULL))
  {
    batteryChargeDetails.paramStatus = ERROR_INVALID;
  }
  batteryChargeDetails.continuousReadingCnt = continuousReading;
  batteryChargeDetails.totalReadingsCnt = loopCntr;
  return batteryChargeDetails;
}