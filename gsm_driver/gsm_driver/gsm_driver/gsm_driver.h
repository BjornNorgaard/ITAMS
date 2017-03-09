#ifndef GSM_DRIVER_H_
#define GSM_DRIVER_H_

// main functions
void gsmInit();

// util functions
void gsmWaitForResponse();
void gsmSetEcho(unsigned char echo);
void gsmSetTextMode();
void gsmConfigSms();

#endif /* GSM_DRIVER_H_ */
