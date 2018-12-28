#include "../header-files/movement.h"
#include "../../c-utils/Interfaces.h"
#include "..\..\c-sdk\IVEngineClient.h"
#include "..\..\c-sdk\IClientMode.h"
void c_movement::auto_hop(CUserCmd* u_cmd, bool duck_in_air) {

	if (!GetAsyncKeyState(VK_SPACE)) return;

	C_BaseEntity* local_player = g_pEntityList->GetClientEntity(g_pEngine->GetLocalPlayer()); int last_in_air_tick;

	if (local_player->GetHealth() <= 0) return; 

	if (!local_player->GetFlags() & FL_ONGROUND) {

		last_in_air_tick = local_player->GetTickBase();

		if (duck_in_air) {
			u_cmd->buttons |= IN_DUCK;
		}

	}

	if (local_player->GetTickBase() > last_in_air_tick) {
		u_cmd->buttons |= IN_JUMP;
	}

}


