#pragma once
#ifndef BASIC_TYPES_H
#define BASIC_TYPES_H

#include <string>
#include <gl/glew.h>
#include <iostream>
#include <sstream>


//list of graphic primitives

enum class ResourceType {
		RESOURCE_MESH,
		RESOURCE_TEXTURE,
		RESOURCE_SHADER,
		RESOURCE_MATERIAL
};

#endif