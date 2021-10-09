#include "G_renderer_win.h"

G_renderer_win::G_renderer_win(std::string n_win_name, int n_width, int n_height) : G_window(n_win_name, n_width, n_height){
	m_renderer = SDL_CreateRenderer(window(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);//| SDL_RENDERER_PRESENTVSYNC
	if (m_renderer == NULL)
		throw init_exception("Renderer couldn't be initialized!");

	SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	int img_flags = IMG_INIT_PNG;
	if (!(IMG_Init(img_flags) & img_flags)) 
		throw image_init_exception("SDL_image couldn't initialize!");
	
	//linear texture filtering!!

}
G_renderer_win::~G_renderer_win() {
	SDL_DestroyRenderer(m_renderer);
	m_renderer = NULL;
}

void G_renderer_win::render_game_object(G_game_object& game_obj, const SDL_Rect& clip, SDL_RendererFlip& flip) const {

	//SDL_Rect render_quad{(int) game_obj.point().x(), (int)game_obj.point().y(), game_obj.texture().width(), game_obj.texture().height() };
	SDL_Rect render_quad{ (int)game_obj.point().x(), (int)game_obj.point().y(), game_obj.texture().width(), game_obj.texture().height() };

	render_quad.w = game_obj.collider().w;
	render_quad.h = game_obj.collider().h;

	//render_quad.w = clip.w;
	//render_quad.h = clip.h;

	//clipped
	//SDL_RenderCopy(m_renderer, game_obj.texture().texture(), &clip, &render_quad);
	//SDL_RenderCopy(m_renderer, game_obj.texture().texture(), NULL, &render_quad);

	SDL_RenderCopyEx(m_renderer, game_obj.texture().texture(), &clip, &render_quad, 0, NULL, flip);

}

SDL_Renderer* G_renderer_win::renderer()const { return m_renderer; }



void G_renderer_win::load_from_text(G_text& text) {
	SDL_Surface* text_surface = TTF_RenderText_Solid(text.font(), text.get_text().c_str(), text.get_color());
	if (text_surface == NULL) 
		std::cerr << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError();
	else {
		//Create texture from surface pixels
		text.texture().set_texture(SDL_CreateTextureFromSurface(m_renderer, text_surface));
		if (text.texture().texture() == NULL) 
			std::cerr << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError();
		else {
			//Get image dimensions
			text.set_width(text_surface->w);
			text.set_height(text_surface->h);//(text_surface->h);

		}
		//Get rid of old surface
		SDL_FreeSurface(text_surface);
	}


}