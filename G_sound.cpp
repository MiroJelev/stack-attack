#include "G_sound.h"

G_sound::G_sound(std::string name) {
	music = Mix_LoadMUS(name.c_str());
	if (music == NULL) {
		//std::cerr << "Failed to load beat music! SDL_mixer Error: " << Mix_GetError();
		throw sound_init_exception("Failed to load beat music! SDL_mixer Error:");
	}
}
G_sound::~G_sound() {
	Mix_FreeMusic(music);
	music = NULL;
}

void G_sound::play_sound() {
	//if there is no music playing
	if (Mix_PlayingMusic() == 0) {
		//Play the music
		Mix_PlayMusic(music, -1);
	}
}