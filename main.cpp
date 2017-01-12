#include <cstdio>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

const int ESCAPE = 27;

int main(int argc, char ** argv) {
	al_init();

	// anti-aliasing
	al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
	al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);

	ALLEGRO_DISPLAY *display = al_create_display(1280, 720);

	if (!display) {
		printf("Unable to create display\n");
		return 1;
	}

	ALLEGRO_COLOR black = al_map_rgba(0, 0, 0, 255);

	al_clear_to_color(black);

	// apply clear
	al_flip_display();

	// draw white line on middle of display
	ALLEGRO_COLOR white = al_map_rgba(255, 255, 255, 255);

	al_draw_line(0, 720 / 2, 1280, 720 / 2, white, 1.0);

	// draw blue rect on top left corner
	ALLEGRO_COLOR blue = al_map_rgba(0, 0, 255, 255);

	al_draw_rectangle(1, 1, 50, 50, blue, 1.0);

	// draw red filled rect on top right corner
	ALLEGRO_COLOR red = al_map_rgba(255, 0, 0, 255);

	al_draw_filled_rectangle(1230, 0, 1280, 50, red);

	// draw green circle
	ALLEGRO_COLOR green = al_map_rgba(0, 255, 0, 255);

	al_draw_circle(1280 / 2, 720 / 4, 120, green, 5.0);

	// apply changes
	al_flip_display();


	// wait Esc+Return to leave
	char c;

	while (true) {
		c = getchar();

		if (c == ESCAPE) {
			break;
		}
	}

	return 0;
}
