#include <epaper/EPD_4in2_V2.h>

int main(void) {
  DEV_Delay_ms(500);

  DEV_Module_Init();
  EPD_4IN2_V2_Init();
  EPD_4IN2_V2_Clear();
  EPD_4IN2_V2_Sleep();

  printf("Display cleared. Safe to store.\n");

  return 0;
}
