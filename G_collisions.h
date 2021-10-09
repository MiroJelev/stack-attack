#pragma once
#include <SDL.h>

#include "G_dot.h"
#include "G_box.h"

class G_collisions {
public:
	//G_collisions():move_x(0), move_y(0) {}
	G_collisions() {}
	bool check_collision(G_game_object& obj1, G_game_object& obj2);
	void movement_resolution(G_game_object& obj1, G_game_object& obj2);

	//void player_box_res(G_dot& player, G_box& box, G_box& box2);
	void player_box_res(G_dot& player, G_box& box, int obj_pos, std::vector<G_box>& game_objects, int cur_box_count);
		//G_box game_objects[30]	
	void box_collision_res(G_box& obj1, G_box& obj2);

	bool out_of_window_resolve(G_game_object& obj1);

	//bool out_of_window_check(G_game_object& obj1);
private:
	//int move_x;
	//int move_y;
};