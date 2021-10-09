#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "G_window.h"
#include "G_game_object.h"
#include "init_exception.h"
#include "G_text.h"


class G_renderer_win : public G_window{
public:
	G_renderer_win(std::string n_win_name, int n_width, int n_height);
	~G_renderer_win();

	void render_game_object (G_game_object& game_obj, const SDL_Rect& clip, SDL_RendererFlip& flip) const;

	SDL_Renderer* renderer()const;

	void load_from_text(G_text& text);


private:
	SDL_Renderer* m_renderer;
};