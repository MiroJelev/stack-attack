#pragma once

#include "G_game_object.h";

class G_dot : public G_game_object {
public:
	G_dot(Point n_p, int n_w, int n_h);
	static const int MAX_VEL = 10;
	void move();	//check virtual in G_game_object class
	void handle_event(SDL_Event& e); //check virtual in G_game_object class
	//SDL_Rect collider();
private:
	//bool check_collision(const G_game_object& object);
	//SDL_Rect m_collider;
};