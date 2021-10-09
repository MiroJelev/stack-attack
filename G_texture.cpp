#include "G_texture.h"
#include "G_renderer_win.h"

G_texture::~G_texture() {
	SDL_DestroyTexture(m_texture);
	m_texture = NULL;
	m_w = 0;
	m_h = 0;
}

void G_texture::free() {
	//Free texture if it exists
	if (m_texture != NULL) {
		SDL_DestroyTexture(m_texture);
		m_texture = NULL;
		m_w = 0;
		m_h = 0;
	}
}

void G_texture::load_from_file(const std::string& path, const G_renderer_win& renderer) {

	SDL_Texture* new_texture = NULL;

	SDL_Surface* loaded_surface = IMG_Load(path.c_str());
	if (loaded_surface == NULL)
		throw image_init_exception("couldn't load image: " + path);

	SDL_SetColorKey(loaded_surface, SDL_TRUE, SDL_MapRGB(loaded_surface->format, 0, 0xFF, 0xFF));

	//new_texture = SDL_CreateTextureFromSurface(renderer.renderer(), loaded_surface);
	new_texture = SDL_CreateTextureFromSurface(renderer.renderer(), loaded_surface);
	if (new_texture == NULL)
		throw init_exception("Couldn't create texture from " + path);

	SDL_FreeSurface(loaded_surface);

	m_texture = new_texture;
}

void G_texture::set_color(Uint8 red, Uint8 green, Uint8 blue) {
	SDL_SetTextureColorMod(m_texture, red, green, blue);
}
void G_texture::set_blend_mode(SDL_BlendMode blending) {
	SDL_SetTextureBlendMode(m_texture, blending);
}
void G_texture::set_alpha(Uint8 alpha) {
	SDL_SetTextureAlphaMod(m_texture, alpha);
}

SDL_Texture* G_texture::texture() { return m_texture; }
int G_texture::width()const { return m_w; }
int G_texture::height()const { return m_h; }


void G_texture::set_texture(SDL_Texture* n_t) {
	m_texture = n_t;
}