#pragma once
#include "Model.h"
#include "Effect.h"
#include <vector>

namespace GAME {
	class EffectedModel :
		public Model
	{
	public:
		EffectedModel(const Vec3 pos_, const Vec3 orientation_);
		~EffectedModel();

		Model* model;
		std::string modelName;
		std::vector<Effect*> effectsList;

		void Render() const override;
	};
}


