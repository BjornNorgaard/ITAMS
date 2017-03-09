#ifndef GSM_DRIVER_H_
#define GSM_DRIVER_H_

// main functions
void gsmInit();
void gsmSendSms(char* phonenumber, char* message);

// util functions
void gsmWaitForResponse();
void gsmSetEcho(char echo);
void gsmSetTextMode();
void gsmConfigSms();

#endif /* GSM_DRIVER_H_ */
