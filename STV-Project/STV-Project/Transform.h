#pragma once
#include "MemoryListener.h"
#include "Dependencies\glm\glm.hpp"
#include "Dependencies\glm\common.hpp"
#include "Dependencies\glm\mat4x4.hpp"

using namespace glm;

class Transform
{
public:
	Transform();
	Transform(vec3& location);
	Transform(vec3& location, vec3& rotation);
	Transform(vec3& location, vec3& rotation, float scale);
	~Transform();

	vec3 getLERPLocation();
	vec3 getLERPRotation();
	float getLERPScale();
	vec3 getForward() 
	{
		vec3 direction = vec3(
			sin(rotation.y),
			tan(rotation.x),
			cos(rotation.y)
			);

		return normalize(direction);
	}
	mat4& getModelMatrix();

	vec3 location;
	vec3 pivot;
	vec3 rotation;
	float scale;

	Transform* getParent() { return _parent; }
	void setParent(Transform* parent) { _parent = parent; }

	void TransformUpdate();

private:
	mat4 _model_matrix;
	Transform* _parent = nullptr;

	vec3 _last_location;
	vec3 _last_rotation;
	float _last_scale;

	void Init(vec3& location, vec3& rotation, float scale);
};

