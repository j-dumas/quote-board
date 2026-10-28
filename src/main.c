#include <pico/stdlib.h>

#include "display.h"

char *message =
    "De la petite fille artiste et spontanee qui nous fait rigoler a la grande "
    "passionnee de litterature, qui est si meticuleuse dans tout ce qu'elle "
    "entreprend, tu as su faire ton chemin.\nJe suis tellement fiere de ce que "
    "tu es devenue et surtout que tu te fasses CONFIANCE.\nGarde ton "
    "magnifique sourire et continue a realiser tes reves.\nMa petite peanut, "
    "mon chaton, ma Gabizou, ma belle Gabee, sache que je serai toujours la "
    "pour toi.\nBon anniversaire de 25 ans!!! Savoure chaque moment. Je t'aime "
    "tres fort.";

int main() {
  stdio_init_all();

  if (init_display() != 0)
    return -1;
  print_message(message, "Mom xxx", "");

  while (true)
    ;

  return 0;
}
