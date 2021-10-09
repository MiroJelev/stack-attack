#include "G_box.h"

G_box::G_box(Point n_p, int n_w, int n_h):G_game_object(n_p, n_w, n_h) {
	G_game_object::m_velocity_x = 10;
	release_place = rand() % 1000 + 180;
	//release_place = 1000;
	released = false;
	collide = false;
	in_game = false;

	player_dead = false;
}

void G_box::move() {	//check virtual in G_game_object class

	m_point.set_x(m_point.x() + G_game_object::vel_x());
	G_game_object::m_collider.x += G_game_object::m_velocity_x;

	m_point.set_y(m_point.y() + G_game_object::vel_y());
	G_game_object::m_collider.y += G_game_object::m_velocity_y;

}
void G_box::crane_stage() {
	if (released == false) {
		//std::cout << "\n" << release_place << "\n";
		G_game_object::m_velocity_y = 0;
		if (G_game_object::m_point.x() > release_place - 20. && G_game_object::m_point.x() < release_place + 20.) {
			G_game_object::m_velocity_x = 0;
			released = true;
			collide = true;
		}
		else if(m_velocity_x < MAX_BOX_VEL){
			G_game_object::m_velocity_x += MAX_BOX_VEL;
			in_game = true;
			//gen_release_place();
		}
	}else
		G_game_object::gravity();
}
//mahni
void G_box::gen_release_place() {
	release_place = rand() % 1000 + 180;
}

void G_box::handle_event(SDL_Event& e) { }


void G_box::set_released(bool n_r) {
	released = n_r;
}

bool G_box::get_released() {
	return released;
}

bool G_box::get_in_game() {
	return in_game;
}

void G_box::set_in_game(bool n_in_g) {
	in_game = n_in_g;
}

void G_box::reset() {
	G_game_object::m_point.set_x(20);
	G_game_object::m_collider.x = 20;
	G_game_object::m_point.set_y(10);
	G_game_object::m_collider.y = 20;

	release_place = rand() % 1000 + 180;
	G_game_object::m_velocity_x = 10;
	G_game_object::m_velocity_y = 0;
	collide = false;
	released = false;
	in_game = false;
}