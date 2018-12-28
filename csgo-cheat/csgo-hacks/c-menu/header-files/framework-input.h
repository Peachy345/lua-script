#pragma once
#include "../../c-sdk/Vector.h"
#include "../../c-sdk/ISurface.h"

class cheat_ui_input
{
public:
	int get_id(const char* name);
	Vector2D bounds_id[1000];
	float slider_drag_distance;
	bool clicked_in_bounds(Vector2D bounds1, Vector2D bounds2, const char* input_type);
	float last_drag_pos();

};