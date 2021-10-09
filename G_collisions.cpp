#include "G_collisions.h"

//obj1 aggres obj2 receives
bool G_collisions::check_collision(G_game_object& obj1, G_game_object& obj2) {

	if (obj1.collider().x > obj2.collider().x + obj2.width()) //left
		return false;
		//std::cout << "\nNO COLLISION LEFT\n";

	if (obj1.collider().x + obj1.width() < obj2.collider().x) //right
		return false;
		//std::cout << "\nNO COLLISION Right\n";

	if (obj1.collider().y > obj2.collider().y + obj2.height()) //up
		return false;
		//std::cout << "\nNO COLLISION UP\n";

	if (obj1.collider().y + obj1.height() < obj2.collider().y) //down
		return false;
	//	std::cout << "\nNO COLLISION DOWN\n";

	//resolve collision
	//movement_resolution(obj1, obj2);
	//std::cout << "\nRESOLVE CHECK\n";///////////////////////////////////////////////////////////////////////////////////////////////////////

	return true;
}
void G_collisions::movement_resolution(G_game_object& obj1, G_game_object& obj2) {
	//int collided_x = obj1.point().x();
	//int collided_y = obj1.point().y();

	int un_col_x= obj1.point().x() - obj1.vel_x();
	int un_col_y= obj1.point().y() - obj1.vel_y();

	//std::cout << "\nRESOLVE\n";///////////////////////////////////////////////////////////////////////////////////////////////////////

	//remove ref functions make variables accesable by some other way!!!!!!!!!!
	if ((double)un_col_x + obj1.width() < obj2.point().x()) {	//left
		//obj1.point_ref().set_x(un_col_x);
		//obj1.collider_ref().x = un_col_x;
		obj1.point_ref().set_x(obj2.point().x() - (obj1.width() + 1.));
		obj1.collider_ref().x = obj2.point().x() - (obj1.width() + 1.);
	}
	else if (un_col_x > obj2.point().x() + obj2.width()) {		//right
		obj1.point_ref().set_x(obj2.point().x() + (obj2.width() + 1.));
		obj1.collider_ref().x = obj2.point().x() + (obj2.width() + 1.);
	}
	else if((double)un_col_y + obj1.height() < obj2.point().y()){	//up
		obj1.point_ref().set_y(obj2.point().y() - (obj1.height() + 1.));
		obj1.collider_ref().y = obj2.point().y() - (obj1.height() + 1.);
	}
	else {
		//obj1.point_ref().set_y(obj2.point().y() + (obj2.height() + 1.));
		//obj1.collider_ref().y = obj2.point().y() + (obj2.height() + 1.);
		obj2.point_ref().set_y(0);
		obj2.collider_ref().y = 0;

	}

}


void G_collisions::box_collision_res(G_box& obj1, G_box& obj2) {
	int collided_x = obj1.point().x();
	int collided_y = obj1.point().y();
	int un_col_x = obj1.point().x() - obj1.vel_x();
	int un_col_y = obj1.point().y() - obj1.vel_y();
	if ((double)un_col_x + obj1.width() < obj2.point().x()) {	//left
		//obj1.point_ref().set_x(obj2.point().x() - (obj1.width() + 1.));
		//obj1.collider_ref().x = obj2.point().x() - (obj1.width() + 1.);

		obj2.point_ref().set_x(collided_x + (obj2.width() + 1.));
		obj2.collider_ref().x = collided_x + (obj2.width() + 1.);
	}
	else if (un_col_x > obj2.point().x() + obj2.width()) {		//right
		//obj1.point_ref().set_x(obj2.point().x() + (obj2.width() + 1.));
		//obj1.collider_ref().x = obj2.point().x() + (obj2.width() + 1.);

		obj2.point_ref().set_x(collided_x - (obj2.width() + 1.));
		obj2.collider_ref().x = collided_x - (obj2.width() + 1.);
	}
	else if ((double)un_col_y + obj1.height() < obj2.point().y()) {	//up
		obj1.point_ref().set_y(obj2.point().y() - (obj1.height() + 1.));
		obj1.collider_ref().y = obj2.point().y() - (obj1.height() + 1.);
	}
	else if (un_col_y > obj2.point().y() + obj2.height()) { //down
		obj1.point_ref().set_y(obj2.point().y() + (obj2.height() + 1.));
		obj1.collider_ref().y = obj2.point().y() + (obj2.height() + 1.);
	}
}


/*
void G_collisions::player_box_res(G_dot& player, G_box& box) {
	int un_col_box_y = box.point().y() - box.vel_y();
	///aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	int collided_x = player.point().x();
	int collided_y = player.point().y();

	int un_col_x = player.point().x() - player.vel_x();
	int un_col_y = player.point().y() - player.vel_y();

	//remove ref functions make variables accesable by some other way!!!!!!!!!!
	if ((double)un_col_x + player.width() < box.point().x()) {	//left
		//player.point_ref().set_x(box.point().x() - (player.width() + 1.));
		//player.collider_ref().x = box.point().x() - (player.width() + 1.);

		box.point_ref().set_x(collided_x + player.width() + 1);
		box.collider_ref().x = collided_x + player.width() + 1;
	}
	else if (un_col_x > box.point().x() + box.width()) {		//right
		player.point_ref().set_x(box.point().x() + (box.width() + 1.));
		//player.collider_ref().x = box.point().x() + (box.width() + 1.);
		
		box.point_ref().set_x(collided_x - box.width() - 1);
		box.collider_ref().x = collided_x - box.width() - 1;

	}
	else if ((double)un_col_y + player.height() < box.point().y()) {	//up
		player.point_ref().set_y(box.point().y() - (player.height() + 1.));
		player.collider_ref().y = box.point().y() - (player.height() + 1.);
	}
	else if((double)un_col_y > un_col_box_y + box.height()){		//down
		//player.point_ref().set_y(box.point().y() + (box.height() + 1.));
		//player.collider_ref().y = box.point().y() + (box.height() + 1.);
		box.point_ref().set_y(0);
		box.collider_ref().y = 0;
		std::cout << "\n\n\n\n\\n VLEZNAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n\n\n\n\\n\n";

	}
}
*/
	//	G_box game_objects[30]			
void G_collisions::player_box_res(G_dot& player, G_box& box, int obj_pos, std::vector<G_box>& game_objects, int cur_box_count) {
	//box
	int un_col_box_x = box.point().x() - box.vel_x();
	int un_col_box_y = box.point().y() - box.vel_y();
	//player
	int collided_x = player.point().x();
	int collided_y = player.point().y();

	int un_col_x = player.point().x() - player.vel_x();
	int un_col_y = player.point().y() - player.vel_y();

	//remove ref functions make variables accesable by some other way!!!!!!!!!!
	if ((double)un_col_y + player.height() < box.point().y()) {	//up
		player.point_ref().set_y(box.point().y() - (player.height() + 1.));
		player.collider_ref().y = box.point().y() - (player.height() + 1.);
	}
	else if (collided_y > (double)un_col_box_y + box.height()) {		//down		using collided_y because of gravity
		//player.point_ref().set_y(box.point().y() + (box.height() + 1.));
		//player.collider_ref().y = box.point().y() + (box.height() + 1.);
		/*box.point_ref().set_x(20);
		box.collider_ref().y = 20;

		box.point_ref().set_y(10);
		box.collider_ref().y = 10;

		box.set_released(false);*/
		if (player.vel_y() > 4) {
			std::cout << "\n\nPlayer died!!!\n\n";
			player.player_dead = true;
		}
		
		box.reset();
	}
	else if ((double)un_col_x + player.width() < box.point().x()) {	//left
		//player.point_ref().set_x(box.point().x() - (player.width() + 1.));
		//player.collider_ref().x = box.point().x() - (player.width() + 1.);

		box.collider_ref().y = box.collider().y - box.height();	//top pinn
		bool pinned_top = false;
		for (int i = 0; i < cur_box_count; ++i) {
			if (game_objects[i].get_in_game() == true && i != obj_pos && check_collision(box, game_objects[i])) {
				player.point_ref().set_x(box.point().x() - (player.width() + 1.));
				player.collider_ref().x = box.point().x() - (player.width() + 1.);
				pinned_top = true;
			}
		}
		box.collider_ref().y = box.collider().y + box.height();
		if (pinned_top == false) {



			box.point_ref().set_x(collided_x + player.width() + 1);
			box.collider_ref().x = collided_x + player.width() + 1;

			for (int i = 0; i < cur_box_count; ++i) {
				if (game_objects[i].get_in_game() == true && i != obj_pos && check_collision(box, game_objects[i])) {
					box.point_ref().set_x(game_objects[i].point().x() - (box.width() + 1.));
					box.collider_ref().x = game_objects[i].point().x() - (box.width() + 1.);

					player.point_ref().set_x(box.point().x() - (player.width() + 1.));
					player.collider_ref().x = box.point().x() - (player.width() + 1.);
				}
				//if(game_objects[i].get_in_game() == true && )
				if (out_of_window_resolve(box)) {
					//out_of_window_resolve(box);
					player.point_ref().set_x(un_col_box_x - player.width() - 1);
					player.collider_ref().x = un_col_box_x - player.width() - 1;
				}
			}
		}
	}
	else if (un_col_x > box.point().x() + box.width()) {		//right
		//player.point_ref().set_x(box.point().x() + (box.width() + 1.));
		//player.collider_ref().x = box.point().x() + (box.width() + 1.);

		box.collider_ref().y = box.collider().y - box.height();	//top pinn
		bool pinned_top = false;
		for (int i = 0; i < cur_box_count; ++i) {
			if (game_objects[i].get_in_game() == true && i != obj_pos && check_collision(box, game_objects[i])) {
				player.point_ref().set_x(box.point().x() + (box.width() + 1.));
				player.collider_ref().x = box.point().x() + (box.width() + 1.);
				pinned_top = true;
			}
		}
		box.collider_ref().y = box.collider().y + box.height();
		if (pinned_top == false) {


			box.point_ref().set_x(collided_x - box.width() - 1);
			box.collider_ref().x = collided_x - box.width() - 1;

			for (int i = 0; i < cur_box_count; ++i) {
				if (game_objects[i].get_in_game() == true && i != obj_pos && check_collision(box, game_objects[i])) {
					box.point_ref().set_x(game_objects[i].point().x() + (box.width() + 1.));
					box.collider_ref().x = game_objects[i].point().x() + (box.width() + 1.);

					player.point_ref().set_x(box.point().x() + (box.width() + 1.));
					player.collider_ref().x = box.point().x() + (box.width() + 1.);
				}
				if (out_of_window_resolve(box)) {
					//out_of_window_resolve(box);
					player.point_ref().set_x(un_col_box_x + box.width() + 1);
					player.collider_ref().x = un_col_box_x + box.width() + 1;
				}
			}
		}

	}


}



/*
void G_collisions::player_box_res(G_dot& player, G_box& box , G_box& box2) {
	//box
	int un_col_box_x = box.point().x() - box.vel_x();
	int un_col_box_y = box.point().y() - box.vel_y();
	//player
	int collided_x = player.point().x();
	int collided_y = player.point().y();

	int un_col_x = player.point().x() - player.vel_x();
	int un_col_y = player.point().y() - player.vel_y();

	//remove ref functions make variables accesable by some other way!!!!!!!!!!
	 if ((double)un_col_y + player.height() < box.point().y()) {	//up
	player.point_ref().set_y(box.point().y() - (player.height() + 1.));
	player.collider_ref().y = box.point().y() - (player.height() + 1.);
	}
	else if (collided_y > (double)un_col_box_y + box.height()) {		//down		using collided_y because of gravity
		//player.point_ref().set_y(box.point().y() + (box.height() + 1.));
		//player.collider_ref().y = box.point().y() + (box.height() + 1.);
		box.point_ref().set_y(0);
		box.collider_ref().y = 0;
	}
	else if ((double)un_col_x + player.width() < box.point().x()) {	//left
		//player.point_ref().set_x(box.point().x() - (player.width() + 1.));
		//player.collider_ref().x = box.point().x() - (player.width() + 1.);

		box.point_ref().set_x(collided_x + player.width() + 1);
		box.collider_ref().x = collided_x + player.width() + 1;

		if (check_collision(box, box2)) {
			box.point_ref().set_x(box2.point().x() - (box.width() + 1.));
			box.collider_ref().x = box2.point().x() - (box.width() + 1.);

			player.point_ref().set_x(box.point().x() - (player.width() + 1.));
			player.collider_ref().x = box.point().x() - (player.width() + 1.);
		}
		if (out_of_window_resolve(box)) {
			//out_of_window_resolve(box);
			player.point_ref().set_x(un_col_box_x - player.width() - 1);
			player.collider_ref().x = un_col_box_x - player.width() - 1;
		}
	}
	else if (un_col_x > box.point().x() + box.width()) {		//right
		//player.point_ref().set_x(box.point().x() + (box.width() + 1.));
		//player.collider_ref().x = box.point().x() + (box.width() + 1.);

		box.point_ref().set_x(collided_x - box.width() - 1);
		box.collider_ref().x = collided_x - box.width() - 1;

		if (check_collision(box, box2)) {
			box.point_ref().set_x(box2.point().x() + (box.width() + 1.));
			box.collider_ref().x = box2.point().x() + (box.width() + 1.);

			player.point_ref().set_x(box.point().x() + (box.width() + 1.));
			player.collider_ref().x = box.point().x() + (box.width() + 1.);
		}
		if (out_of_window_resolve(box)) {
			//out_of_window_resolve(box);
			player.point_ref().set_x(un_col_box_x + box.width() + 1);
			player.collider_ref().x = un_col_box_x + box.width() + 1;
		}

	}
	



}
*/


/*
bool G_collisions::out_of_window_check(G_game_object& obj1) {
	if (obj1.point().x() < 0)				//left
		return true;
	else if ((obj1.point_ref().x() + obj1.width()) > 1280)	//right
		return true;

	if (obj1.point_ref().y() < 0)		//up
		return true;
	else if ((obj1.point_ref().y() + obj1.height()) > 720)	//down
		return true;

	return false;
}
*/

bool G_collisions::out_of_window_resolve(G_game_object& obj1) {
	bool is_collided = false;
	if (obj1.point().x() < 0) {				//left
		obj1.point_ref().set_x(0);
		obj1.collider_ref().x = 0;
		is_collided = true;
	}
	else if ((obj1.point_ref().x() + obj1.width()) > 1280) {	//right
		obj1.point_ref().set_x(1280 - (obj1.width()));
		obj1.collider_ref().x = 1280 - (obj1.width());
		is_collided = true;
	}

	if (obj1.point_ref().y() < 0) {			//up
		obj1.point_ref().set_y(0);
		obj1.collider_ref().y = 0;
		is_collided = true;
	}
	else if ((obj1.point_ref().y() + obj1.height()) > 720) {	//down
		obj1.point_ref().set_y(720 - (obj1.height()));
		obj1.collider_ref().y = 720 - (obj1.height());
		is_collided = true;
	}

	return is_collided;
}