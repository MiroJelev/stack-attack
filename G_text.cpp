#include "G_text.h"


G_text::G_text(Point n_p, int n_w, int n_h, std::string n_t) : G_game_object{ n_p, n_w, n_h } {
	m_font = TTF_OpenFont("lazy.ttf", 28);
	if (m_font == NULL) {
		std::cerr << "Failed to load lazy font! SDL_ttf Error: " << TTF_GetError();
	}
	m_text = n_t;
	m_text_color = { 0,0,0,255 };
}

G_text::~G_text() {
	TTF_CloseFont(m_font);
	m_font = NULL;
}

TTF_Font* G_text::font() {
	return m_font;
}

SDL_Color G_text::get_color() {
	return m_text_color;
}

void G_text::set_text(std::string n_str) {
	m_text = n_str;
}
std::string G_text::get_text() {
	return m_text;
}