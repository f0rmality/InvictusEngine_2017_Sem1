#pragma once
#include "Effect.h"

namespace GAME {
	class MaterialEffect :
		public Effect
	{
	public:
		MaterialEffect();
		~MaterialEffect();

		void applyEffect() override;
		void postEffect() override;
	};

}

