#pragma once

#include "G_game_object.h"
class G_box : public G_game_object{
public:
	G_box(Point n_p, int n_w, int n_h);
	void move();	//check virtual in G_game_object class
	void crane_stage();
	void handle_event(SDL_Event& e);
	static const int MAX_BOX_VEL = 10;
	void gen_release_place();
	int release_place;
	
	bool get_released();
	void set_released(bool n_r);

	bool get_in_game();
	void set_in_game(bool n_in_g);

	void reset();

	bool collide;
private:
	bool in_game;
	bool released;
	
};