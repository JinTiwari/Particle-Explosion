#pragma once

namespace first
{
	struct Particle //making a class a struct changes its default settings to public 
	{ 
		double m_x;
		double m_y;
		
	private:
		double m_speed;
		double m_direction;
	private:
		void init();
	public:
		Particle();
		virtual ~Particle();
		void update(int interval); 
	};
}
