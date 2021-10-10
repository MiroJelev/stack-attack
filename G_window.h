#pragma once
#include <SDL2/SDL.h>
#include <iostream>

class G_window {
public:

	//void handle_event(SDL_Event& e);

	//focus functions
	//events?

	SDL_Window* window()const;
	int width()const;
	int height()const;
protected:
	G_window(std::string win_name, int width, int height);
	~G_window();
private:
	int m_w;
	int m_h;
	SDL_Window* m_window;
};
