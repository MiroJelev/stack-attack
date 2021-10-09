#pragma once
#include <string>
#include <vector>

#include "G_texture.h"
#include "Point.h"
#include "init_exception.h"

//class G_texture; 

class G_game_object {
public:
	virtual void move() = 0;
	virtual void handle_event(SDL_Event& e) = 0;

	void gravity();

	Point point();
	Point& point_ref();
	int width()const;
	int height()const;
	void set_width(int n_w);
	void set_height(int n_h);
	int vel_x()const;
	int vel_y()const;
	G_texture& texture(); // for &   see   Grenderer::render_game_object
	SDL_Rect collider();
	SDL_Rect& collider_ref();
	
	void set_vel_x(int new_vel);
	void set_vel_y(int new_vel);

	bool player_dead;

protected:
	G_game_object(Point n_p, int n_w, int n_h);
	//G_game_object(const G_game_object&) = delete;	//surpress copying
	G_game_object& operator=(const G_game_object&) = delete;

	Point m_point;
	int m_w;
	int m_h;
	double m_velocity_x;
	double m_velocity_y;
	SDL_Rect m_collider;

private:
	//check for collision func
	G_texture m_gtexture;
};
