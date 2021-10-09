#pragma once
#include "init_exception.h"

class Point {
public:
	Point(double n_x, double n_y): m_x(n_x), m_y(n_y) {
		if (m_x < 0 || m_y < 0)
			throw init_exception("Point coordinates must be positive ints !");
	}

	double x()const { return m_x; }
	double y()const { return m_y; }
	void set_x(int x) { m_x = x; }
	void set_y(int y) { m_y = y; }

private:
	double m_x, m_y;
};