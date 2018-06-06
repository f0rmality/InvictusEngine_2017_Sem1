#pragma once

namespace GAME {
	
	class Skybox
	{
		public:
			Skybox();
			Skybox(unsigned int left, unsigned int back, unsigned int right, unsigned int front, unsigned int top, unsigned int bottom, float s);
			~Skybox();

			unsigned int sides[6];
			float size;

			void drawSkybox();
	};
}


