#include "EffectedModel.h"

using namespace GAME;

EffectedModel::EffectedModel(const Vec3 pos_, const Vec3 orientation_) : Model(pos_, orientation_)
{
	
}


EffectedModel::~EffectedModel()
{
}

void EffectedModel::Render() const {
	//normal stuff but apply effects here
}
