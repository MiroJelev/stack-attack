#pragma once
#include <SDL.h>

class G_timer {
public:
	G_timer();

	void start();
	void stop();
	void pause();
	void unpause();

	Uint32 get_ticks();

	bool is_startd();
	bool is_paused();
private:
	Uint32 m_start_ticks;

	Uint32 m_paused_ticks;

	bool m_paused;
	bool m_started;
};