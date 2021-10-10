#pragma once
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "init_exception.h"
//#include "G_renderer_win.h"

class G_renderer_win;//forward declaration to remove dependecy to G_renderer_win when creating G_texture

class G_texture {
public:
	G_texture() : m_texture(NULL), m_w(0), m_h(0){  }
	~G_texture();

	void load_from_file(const std::string& path, const G_renderer_win& renderer);

	void set_color(Uint8 red, Uint8 green, Uint8 blue);

	void set_blend_mode(SDL_BlendMode blending);

	void set_alpha(Uint8 alpha);

	void free();

	//render???

	SDL_Texture* texture();
	void set_texture(SDL_Texture* n_t);
	int width()const;
	int height()const;

private:
	SDL_Texture* m_texture;

	int m_w;
	int m_h;
};
