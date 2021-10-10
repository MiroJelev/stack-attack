#include <iostream>
#include <vector>
#include <time.h>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "G_window.h"
#include "G_renderer_win.h"
#include "init_exception.h"
#include "G_dot.h"
#include "Point.h"
#include "G_timer.h"
#include "G_collisions.h"
#include "G_box.h"
#include "G_sound.h"

void close() {
	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}


//Collision system
//virtual G_game_object 
//Render clear Render Present functions or 1 function
//see render_game_object SDL_rect argument 

//The Crystal Method - Born Too Slow.mp3

bool Game_over(G_renderer_win& rend_win, SDL_Event& e) {
	SDL_RendererFlip no_flip{ SDL_FLIP_NONE };
	G_box background{ Point{0,0}, 1280, 720 };
	background.texture().load_from_file("backgrounds/game_over2.png", rend_win);
	//SDL_RenderClear(rend_win.renderer());
	//SDL_SetRenderDrawColor(rend_win.renderer(), 0xFF, 0xFF, 0xFF, 0xFF);

	rend_win.render_game_object(background, SDL_Rect{ 0, 0, background.width(), background.height() }, no_flip);

	SDL_RenderPresent(rend_win.renderer());
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) quit = true;
			switch (e.key.keysym.sym)
			{
			case SDLK_1:
				return true;
				break;
			case SDLK_2:
				return false;
				break;
			}
		}
	}
}


int main(int argc, char* args[]) {
		try {
			srand(time(NULL));
			if (SDL_Init(SDL_INIT_VIDEO) < 0)
				throw init_exception("SDL_INIT_Video failed!");

			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
			{
				throw sound_init_exception("Failed to load beat music! SDL_mixer Error:");
			}
			if (TTF_Init() == -1) {
				std::cerr << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError();
			}
			bool game_end = false;
			while (!game_end) {

				G_sound background_music{ "sound/The Crystal Method - Born Too Slow.mp3" };

				background_music.play_sound();

				G_renderer_win rend_win{ "Test", 1280, 720 };
				G_collisions collisions{};

				G_timer fps_timer{};
				G_timer cap_timer{};
				G_timer box_timer{};
				G_timer game_timer{};
				int target_frame_time = 1000 / 60;


				//game objects initialization
				G_dot gd{ Point{200,200}, 40, 100 };
				gd.texture().load_from_file("textures/player_spritesheet_2.png", rend_win);

				G_box background{ Point{0,0}, 1280, 720 };
				background.texture().load_from_file("backgrounds/painting2.jpg", rend_win);

				/*
				G_box box2{ Point{0,0}, 80,80 };
				box2.texture().load_from_file("textures/box2.jpg", rend_win);
				G_box box3{ Point{20,300}, 80,80 };
				box3.texture().load_from_file("textures/box.jpg", rend_win);
				*/


				G_text score_text{ Point{50,50}, 50, 50, "0" };
				G_text timer_text{ Point{1100,50}, 200, 50, "0" };


				/// i da ubivat geroq ako te go udrqt otgore
				/// kran na kutiikite
				/// vtori kran
				/// 
				/// !!!!!!!!!!!!!!!!!!! (game over) i!!!!!!!!!!!!!!
				/// !!!!!!!!!!!!!!!!!!!nachalen ekran s nastroiki!!!!!!!!!!!!!!!!!!!!
				/// !!!!!!!!!!!!!!!!!izpisvane na timer i score!!!!!!!!!!!!!PISANE NA TEKST 
				/// 
				/// 2 spisaka efektivno pusnati i ne pusnati kutii
				/// eding for za obrabotvane samo na pusnatite i drug za dobavqne razreshavane na ne pusnatite da badat pusnati



				std::vector<G_box> game_objects{ 100, G_box{ Point{20,10}, 80, 80 } };
				int max_box_count = game_objects.size() - 1;
				for (int i = 0; i < max_box_count; ++i) {
					//game_objects.push_back(G_box{ Point{20,10} ,80 ,80 });
					game_objects[i].texture().load_from_file("textures/box.jpg", rend_win);
				}
				//
				SDL_Rect box_texture_clip{ 0, 0, 225, 225 };
				SDL_Rect text_texture_clip{ 0, 0, 300, 200 };

				double avg_fps = 0;
				double frames_count = 0;

				bool quit = false;
				SDL_Event e;

				double add_box_timestamp = 2;//4
				int cur_box_count = 0;
				int needed_box_count = 1;

				//animations vars
				//const int idle_animation_frames = 12;
				//SDL_Rect sprite_clips[idle_animation_frames];
				G_timer animation_timer{};
				animation_timer.start();
				const int away_anim_timestamp = 10;
				int clip = 0;
				int frame = 0;
				int animation_frames = 12;
				bool start_idle_animation = false;
				//
				SDL_RendererFlip no_flip{ SDL_FLIP_NONE };
				SDL_RendererFlip hor_flip{ SDL_FLIP_HORIZONTAL };
				bool flipped = false;

				int game_legth = 2;
				game_legth = game_legth * 60;
				int score = 0;
				box_timer.start();
				fps_timer.start();
				game_timer.start();
				while (!quit) {
					cap_timer.start();

					if (box_timer.get_ticks() / 1000. > add_box_timestamp) {
						std::cout << "__timer__" << box_timer.get_ticks() / 1000. << "\n";
						int last_frame_num_boxes = cur_box_count;
						cur_box_count = 0;
						++needed_box_count;
						for (int i = 0; i < max_box_count; ++i) {	//counting how many boxes are in game
							if (game_objects[i].get_in_game() == true)
								cur_box_count++;
						}
						score = score + last_frame_num_boxes - cur_box_count;
						for (int i = 0; i < max_box_count; ++i) {	//insert box into the game
							if (game_objects[i].get_in_game() == false) {
								game_objects[i].gen_release_place();
								game_objects[i].set_in_game(true);
								++cur_box_count;
								break;
							}
						}
						std::cout << cur_box_count << "\n" << score << "\n";//++ because 1  box is inseted after counting
						box_timer.start();
					}


					while (SDL_PollEvent(&e) != 0) {
						if (e.type == SDL_QUIT) quit = true;
						switch (e.key.keysym.sym)
						{
							//Play high sound effect
						case SDLK_1:
							quit = true;
							game_end = true;
							break;
						case SDLK_2:

							break;
						}
						gd.handle_event(e);
					}

					//double time_step = step_timer.get_ticks() / 1000.;
					gd.move();
					gd.gravity();

					collisions.out_of_window_resolve(gd);
					for (int i = 0; i < max_box_count; ++i) {
						if (game_objects[i].get_in_game() == true && collisions.check_collision(gd, game_objects[i])) {
							collisions.player_box_res(gd, game_objects[i], i, game_objects, max_box_count);//curr
							if (gd.player_dead) {
								game_end = Game_over(rend_win, e);
								quit = true;
								gd.player_dead = false;
							}
						}
					}


					for (int i = 0; i < max_box_count; ++i) {
						if (game_objects[i].get_in_game() == true) {
							game_objects[i].crane_stage();
							game_objects[i].move();
							collisions.out_of_window_resolve(game_objects[i]);
							for (int j = 0; j < max_box_count; ++j) {
								if (game_objects[j].get_in_game() == true && j != i && collisions.check_collision(game_objects[i], game_objects[j]))
									collisions.box_collision_res(game_objects[i], game_objects[j]);
							}


						}

					}


					//destroy boxes in line
					int boxes_in_line = 0;
					for (int elevation = 640; elevation > 0; elevation -= 80) {
						for (int i = 0; i < max_box_count; ++i) {
							if (elevation == game_objects[i].point().y()) {
								++boxes_in_line;
								if (boxes_in_line == 15) {
									for (int i = 0; i < max_box_count; ++i) {
										if (elevation == game_objects[i].point().y()) {
											game_objects[i].reset();
										}
									}
								}
							}
						}
						boxes_in_line = 0;
					}





					//maybe add to a function
					SDL_RenderClear(rend_win.renderer());
					SDL_SetRenderDrawColor(rend_win.renderer(), 0xFF, 0xFF, 0xFF, 0xFF);

					rend_win.render_game_object(background, SDL_Rect{ 0, 0, background.width(), background.height() }, no_flip);


					//jump anim
					if (gd.vel_y() < 0) {
						clip = 225 * 25;
						start_idle_animation = false;
						animation_timer.start();
						frame = 0;
						if (gd.vel_x() < 0)
							flipped = true;
					}
					else
						//move anim
						if (gd.vel_x() != 0 && gd.vel_y() > 0) {
							if (clip < 225 * 12 || clip >225 * 24)
								clip = 2700;
							clip += 225;
							start_idle_animation = false;
							animation_timer.start();
							frame = 0;
							if (gd.vel_x() < 0)
								flipped = true;
						}
					//idle anim
					if (gd.vel_x() == 0 && gd.vel_y() > 0 && !start_idle_animation) {
						clip = 0;
					}
					//idle animation
					if (away_anim_timestamp < animation_timer.get_ticks() / 1000.) {
						start_idle_animation = true;
						animation_timer.start();
					}
					if (start_idle_animation == true && frame / 8 >= 1) {
						clip += 225;
						if (clip > 225 * 12) {
							clip = 0;
							start_idle_animation = false;
						}
						frame = 0;
					}
					++frame;
					//
					if (flipped) {
						rend_win.render_game_object(gd, SDL_Rect{ clip, 0, 225, 383 }, hor_flip);
						flipped = false;
					}
					else {
						rend_win.render_game_object(gd, SDL_Rect{ clip, 0, 225, 383 }, no_flip);
					}



					for (int i = 0; i < max_box_count; ++i) {
						if (game_objects[i].get_in_game() == true)
							rend_win.render_game_object(game_objects[i], box_texture_clip, no_flip);
					}

					
					timer_text.set_text(std::to_string(game_timer.get_ticks()/1000.));
					rend_win.load_from_text(timer_text);
					rend_win.render_game_object(timer_text, text_texture_clip, no_flip);

					score_text.set_text(std::to_string(score));
					rend_win.load_from_text(score_text);
					rend_win.render_game_object(score_text, text_texture_clip, no_flip);

					SDL_RenderPresent(rend_win.renderer());

					// frame rate and frame cap
					++frames_count;
					avg_fps = frames_count / (fps_timer.get_ticks() / 1000.);
					if (avg_fps > 200000)
						avg_fps = 0;
					//std::cout << avg_fps << "\n";
					int time_passed = cap_timer.get_ticks();
					if (time_passed < target_frame_time)
						SDL_Delay(target_frame_time - time_passed);


					if (game_timer.get_ticks() / 1000. > game_legth) {
						game_end = Game_over(rend_win, e);
						quit = true;
					}
				}
			}
		}
		catch (init_exception& e) {
			std::cerr << e.get_message() << "\nError: " << e.what() << "\n";
			close();
			return 1;
		}
		catch (std::exception& e) {
			std::cerr << "Unknown error! Error!" << e.what();
			close();
			return 2;
		}


		close();
	return 0;
}
