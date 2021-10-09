#include <iostream>
#include <SDL.h>
#include "G_window.h"
#include "init_exception.h"


G_window::G_window(std::string win_name, int n_width, int n_height): m_w(n_width), m_h(n_height) {
	if (n_width < 0 || n_height < 0)
		throw init_exception("G_window width/height params must be positive ints!");

	m_window = SDL_CreateWindow(win_name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
								m_w, m_h, SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
	if (m_window == NULL)
		throw std::exception("Window couldn't be created!");
	
}
G_window::~G_window() {
	SDL_DestroyWindow(m_window);
	m_window = NULL;
}

//void G_window::handle_event(SDL_Event& e);


SDL_Window* G_window::window()const { return m_window; }
int G_window::width()const { return m_w; }
int G_window::height()const { return m_h; }