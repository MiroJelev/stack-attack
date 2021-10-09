#pragma once
#include <string>
#include "SDL_ttf.h"
#include "G_texture.h"
#include "G_game_object.h"
#include "init_exception.h"


class G_text : public G_game_object {
public:
	G_text(Point n_p, int n_w, int n_h, std::string n_t);
	~G_text();
	TTF_Font* font();
	SDL_Color get_color();
	void set_text(std::string n_str);
	std::string get_text();

	void move(){}
	void handle_event(SDL_Event& e){}

private:
	TTF_Font* m_font = NULL;
	SDL_Color m_text_color;
	std::string m_text;
	
};


