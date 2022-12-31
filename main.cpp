#include <iostream>
#include <math.h>
#include <SDL.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"


using namespace std;
using namespace first;

int main(int argc , char *argv[])
{
	srand(time(NULL));//it enables uss to seed our rand function with different numbers numerous times it operates.. with respect to time

	Screen screen;

	if (screen.init() == false)
	{
		cout << "Error initialising SDL." << endl;
	}

	Swarm swarm;



	while (true)
	{

		int elapsed = SDL_GetTicks();

		swarm.update(elapsed);

		unsigned char green = (1 + sin(elapsed * 0.0002)) * 128;//we add 1 to bring sin max to 2 and min to 0 and hence we can
															   // go upto max of 255 and comeback periodically ,
														// making variable unsigned char further proofs that out value is in between 255 and 0
		unsigned char red = (1 + sin(elapsed * 0.0001)) * 128;
		//we change the multiple of the numbers to keep it out of sync to see different hues....;
		unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;

		const Particle* const pParticles = swarm.getParticle();

		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			Particle particle = pParticles[i];

			int x = particle.m_x  * Screen::SCREEN_HEIGHT/ 2 + Screen::SCREEN_WIDTH/2;
			int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x,y,red,green,blue);


		}
		
		//for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
		//{
		//	for (int x = 0; x < Screen::SCREEN_WIDTH; x++)
		//	{
		//		screen.setPixel(x, y, red, green, blue);//we put green's constant changing value we put in green in the pixel to bring animation;

		//	}
		//}
		screen.boxBlur();


		screen.update();
		if (screen.processEvents() == false)
		{
			break;
		}

	}

	screen.close();


	return 0;
}
