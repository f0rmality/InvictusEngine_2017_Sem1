#pragma once

namespace GAME {
	class Effect
	{
	public:
		Effect();
		~Effect();

		virtual void applyEffect() = 0;
		virtual void postEffect() = 0;
	};

}

