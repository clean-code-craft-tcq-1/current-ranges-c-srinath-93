#ifndef  MONITORBATTERYCHARGING_PRV_
#define  MONITORBATTERYCHARGING_PRV_

/* Enum declarations */
typedef enum
{
  OK_VALID,
  ERROR_INVALID
}retChargeReadingStatus_en;
/* Structure declarations */
typedef struct
{
  int continuousReadingCnt;
  int totalReadingsCnt;
  retChargeReadingStatus_en paramStatus;
}batteryChargeReading_st;



/* function declarations */
batteryChargeReading_st checkBatteryChargeReading(int *chargeReading, int numOfReadings);
#endif
