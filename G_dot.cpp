#include "G_dot.h"

G_dot::G_dot(Point n_p, int n_w, int n_h) :G_game_object{ n_p, n_w, n_h } {
/*	m_collider.x = n_p.x();
	m_collider.y = n_p.y();
	m_collider.w = n_w;
	m_collider.h = n_h;
	*/
}
void G_dot::move() { // add collision check for walls and other
	G_game_object::m_point.set_x(m_point.x() + G_game_object::m_velocity_x);
	G_game_object::m_collider.x += G_game_object::m_velocity_x;

	
	/*
	if (G_game_object::point().x() < 0) {
		G_game_object::m_point.set_x(0);
		m_collider.x = 0;
	}
	else if ((G_game_object::point().x() + G_game_object::width()) > 1280) {
		G_game_object::m_point.set_x(1280 - (G_game_object::m_w));
		m_collider.x = 1280 - (G_game_object::m_w);
	}
	*/
	


	/*if (G_game_object::m_point.x() < 0)
		G_game_object::m_point.set_x(0);
	else if (G_game_object::m_point.x() > 1280. - width())
		G_game_object::m_point.set_x(1280 - width());
	*/



	G_game_object::m_point.set_y(m_point.y() + G_game_object::m_velocity_y);
	G_game_object::m_collider.y += G_game_object::m_velocity_y;

	/*
	if (G_game_object::point().y() < 0) {
		G_game_object::m_point.set_y(0);
		m_collider.y = 0;
	}
	else if((G_game_object::point().y() + G_game_object::height()) > 720){
		G_game_object::m_point.set_y(720 - (G_game_object::m_h));
		m_collider.y = 720 - (G_game_object::m_h);
	}
	*/




	
	/*if (G_game_object::m_point.y() < 0)
		G_game_object::m_point.set_y(0);
	else if (G_game_object::m_point.y() > 720. - width())
		G_game_object::m_point.set_y(720 - width());
		*/
	/*
	for (int i = 0; i < dot.size(); ++i) {
		if (m_collider.x + width() < dot[i].collider().x)
			continue;
		else if (m_collider.y < dot[i].collider().y + dot[i].height())
			continue;
		else if (m_collider.x > dot[i].collider().x + dot[i].width())
			continue;
		else if (m_collider.y + height() < dot[i].collider().y)
			continue;
		else {
			G_game_object::m_point.set_x(m_point.x() - G_game_object::m_velocity_x);
			m_collider.x -= G_game_object::m_velocity_x;

			G_game_object::m_point.set_y(m_point.y() - G_game_object::m_velocity_y);
			m_collider.y -= G_game_object::m_velocity_y;
		}

	}
	*/




}
void G_dot::handle_event(SDL_Event& e) {
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		//Adjust the velocity
		switch (e.key.keysym.sym) {
		case SDLK_UP: m_velocity_y = 0; m_velocity_y -= MAX_VEL; break;
		case SDLK_DOWN: m_velocity_y += MAX_VEL; break;
		case SDLK_LEFT: m_velocity_x -= MAX_VEL; break;
		case SDLK_RIGHT: m_velocity_x += MAX_VEL; break;
		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
		case SDLK_UP: m_velocity_y += G_dot::MAX_VEL; break;
		case SDLK_DOWN: m_velocity_y -= G_dot::MAX_VEL; break;
		case SDLK_LEFT: m_velocity_x += G_dot::MAX_VEL; break;
		case SDLK_RIGHT: m_velocity_x -= G_dot::MAX_VEL; break;

		}
	}
}