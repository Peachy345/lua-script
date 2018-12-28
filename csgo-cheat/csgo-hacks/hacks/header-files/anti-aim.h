#pragma once
#include "../../c-sdk/Vector.h"
#include "../../c-sdk/CInput.h"
#include "../../c-utils/Utils.h"
class c_anti_aim
{
public: 
	void anti_aim_main(CUserCmd* u_cmd);
private:
	float get_base_angle(CUserCmd* u_cmd);

};
