#pragma once
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include "init_exception.h"

class G_sound {
public:
	G_sound(std::string name);
	~G_sound();//Mix_FreeMusic(g_music);
			 //g_music = NULL;

	void play_sound();

private:
	Mix_Music* music = NULL;
};


/* main button clicked
//if there is no music playing
if (Mix_PlayingMusic() == 0) {
	//Play the music
	Mix_PlayMusic(g_music, -1);
}
//If music is being played
*/


/*		load mediq
g_music = Mix_LoadMUS("The Crystal Method - Born Too Slow.mp3");
	if (g_music == NULL) {
		std::cerr << "Failed to load beat music! SDL_mixer Error: " << Mix_GetError();
		success= false;
	}
*/
