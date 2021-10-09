#include "G_timer.h"

G_timer::G_timer() {
	m_start_ticks = 0;
	m_paused_ticks = 0;

	m_paused = false;
	m_started = false;
}

void G_timer::start() {
	m_started = true;
	m_paused = false;
	//gets currend clock time
	m_start_ticks = SDL_GetTicks();
	m_paused_ticks = 0;
}
void G_timer::stop() {
	m_started = false;
	m_paused = false;

	m_start_ticks = 0;
	m_paused_ticks = 0;
}
void G_timer::pause() {
	if (m_started && !m_paused) {
		m_paused = true;

		m_paused_ticks = SDL_GetTicks() - m_start_ticks;
		m_start_ticks = 0;
	}
}
void G_timer::unpause() {
	if (m_started && m_paused) {
		m_paused = false;
		//reset starting ticks
		m_start_ticks = SDL_GetTicks() - m_paused_ticks;
		//reset the paused ticks
		m_paused_ticks = 0;
	}
}

Uint32 G_timer::get_ticks() {
	Uint32 time = 0;

	if (m_started) {
		if (m_paused)//return the number of ticks when the timer was paused
			time = m_paused_ticks;
		else//return the current time minus the start time
			time = SDL_GetTicks() - m_start_ticks;
	}
	return time;
}

bool G_timer::is_startd() { return m_started; }
bool G_timer::is_paused() { return m_paused && m_started; }