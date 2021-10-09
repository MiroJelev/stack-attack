#include "G_game_object.h"

G_game_object::G_game_object(Point n_p, int n_w, int n_h) :
	m_point(n_p), m_w(n_w), m_h(n_h), m_velocity_x(0), m_velocity_y(0){
	if (m_w < 0 || m_h < 0)
		throw init_exception("game object width and height have to be positive integers!");
	m_gtexture;

	m_collider.x = n_p.x();
	m_collider.y = n_p.y();
	m_collider.w = n_w;
	m_collider.h = n_h;
}

void G_game_object::gravity() {
	if(m_velocity_y < 10)
		m_velocity_y = m_velocity_y + 0.5;
}

Point G_game_object::point() { return m_point; }
Point& G_game_object::point_ref() { return m_point; }
int G_game_object::width()const { return m_w; }
int G_game_object::height()const { return m_h; }
void G_game_object::set_width(int n_w) { m_w = n_w; }
void G_game_object::set_height(int n_h) { m_h = n_h; }
int G_game_object::vel_x()const { return m_velocity_x; }
int G_game_object::vel_y()const { return m_velocity_y; }
G_texture& G_game_object::texture() { return m_gtexture; }
SDL_Rect G_game_object::collider() { return m_collider; }
SDL_Rect& G_game_object::collider_ref() { return m_collider; }

void G_game_object::set_vel_x(int new_vel) {
	m_velocity_x = new_vel;
}
void G_game_object::set_vel_y(int new_vel) {
	m_velocity_y = new_vel;
}