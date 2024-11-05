#pragma once
#include <string>
#include <vector>

class Object;

struct SceneData {
	std::string name;
	std::vector<Object> objects;
};
