#include <iostream>
#include <allegro5/allegro.h>

using namespace std;

char MAPA[23][22] =
    {
        "000000000000000000000",
        "011111111111111111110",
        "010000000010000000010",
        "010110111010111011010",
        "010000000000000000010",
        "010110101111101011010",
        "010000100010001000010",
        "011110111010111011110",
        "000010100000001010000",
        "011110101101101011110",
        "000000001000100000000",
        "011110101111101011110",
        "000010100000001010000",
        "011110101111101011110",
        "010000000010000000010",
        "010110111010111011010",
        "010010000000000010010",
        "011010101111101010110",
        "010000100010001000010",
        "010111111010111111010",
        "010000000000000000010",
        "011111111111111111110",
        "000000000000000000000",
};

int main(int argc, char **argv)
{

   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_BITMAP *mapa = NULL;

   al_init();

   display = al_create_display(420, 460);

   mapa = al_create_bitmap(20, 20);

   al_clear_to_color(al_map_rgb(0, 0, 0));

   al_set_target_bitmap(mapa);
   al_clear_to_color(al_map_rgb(0, 0, 60));
   al_set_target_bitmap(al_get_backbuffer(display));

   for (int i = 0; i < 23; i++)
   {
      for (int j = 0; j < 22; j++)
      {
         if (MAPA[i][j] == '1')
         {
            al_draw_bitmap(mapa, j * 20, i * 20, 0);
         }
      }
   }

   al_flip_display();
   al_rest(5.0);

   return 0;
}
