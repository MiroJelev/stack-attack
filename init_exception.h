#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>


struct init_exception :public std::exception {
	init_exception(const std::string& thrown_mes) : std::exception(), message(thrown_mes) { }
	std::string get_message()const { return message; }
	const char* what() const throw() {
		return SDL_GetError();
	}
	
	std::string message;
};


struct image_init_exception :public std::exception {
	image_init_exception(const std::string& thrown_mes) : std::exception(), message(thrown_mes) { }
	std::string get_message()const { return message; }
	const char* what() const throw() {
		return IMG_GetError();
	}

	std::string message;
};

struct sound_init_exception :public std::exception {
	sound_init_exception(const std::string& thrown_mes) : std::exception(), message(thrown_mes) { }
	std::string get_message()const { return message; }
	const char* what() const throw() {
		return Mix_GetError();
	}

	std::string message;
};

struct text_init_exception :public std::exception {
	text_init_exception(const std::string& thrown_mes) : std::exception(), message(thrown_mes) { }
	std::string get_message()const { return message; }
	const char* what() const throw() {
		return TTF_GetError();
	}

	std::string message;
};
