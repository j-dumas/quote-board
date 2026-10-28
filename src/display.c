#include <epaper/DEV_Config.h>
#include <epaper/EPD_4in2_V2.h>
#include <epaper/GUI_Paint.h>
#include <stdlib.h>

// For Font12
#define MAX_CHAR_FONT12 (EPD_4IN2_V2_WIDTH / Font12.Width)
#define LINE_HEIGHT_FONT12 (Font12.Height)

static UBYTE *ImageBuf;

int init_display() {
  DEV_Delay_ms(500);

  printf("EPD_4IN2_V2_test Demo\r\n");
  if (DEV_Module_Init() != 0) {
    return -1;
  }

  printf("e-Paper Init and Clear...\r\n");
  EPD_4IN2_V2_Init();
  EPD_4IN2_V2_Clear();

  // Create a new image cache
  UWORD Imagesize =
      ((EPD_4IN2_V2_WIDTH % 8 == 0) ? (EPD_4IN2_V2_WIDTH / 8)
                                    : (EPD_4IN2_V2_WIDTH / 8 + 1)) *
      EPD_4IN2_V2_HEIGHT;
  if ((ImageBuf = (UBYTE *)malloc(Imagesize)) == NULL) {
    printf("Failed to apply for black memory...\r\n");
    return -1;
  }

  return 0;
}

static UWORD draw_line(UWORD y, char *line, uint8_t i) {
  line[i] = '\0';
  Paint_DrawString_EN(0, y, line, &Font12, BLACK, WHITE);
  return y + Font12.Height;
}

static UWORD draw_quote(const char *text) {
  UWORD y = 0;
  char line[MAX_CHAR_FONT12];
  uint8_t i = 0;
  for (const char *p = text; *p; p++) {
    if (*p == '\n' || i == MAX_CHAR_FONT12 - 1) {
      y = draw_line(y, line, i);
      i = 0;
      if (*p == '\n')
        continue;
    }
    line[i++] = *p;
  }

  if (i > 0)
    y = draw_line(y, line, i);

  return y;
}
}

void print_message(char *message) {
  printf("Paint_NewImage\r\n");
  Paint_NewImage(ImageBuf, EPD_4IN2_V2_WIDTH, EPD_4IN2_V2_HEIGHT, 0, WHITE);
  Paint_SelectImage(ImageBuf);
  Paint_Clear(WHITE);

  UWORD y = draw_quote(quote);
  EPD_4IN2_V2_Display_Fast(ImageBuf);
  EPD_4IN2_V2_Sleep();
}
