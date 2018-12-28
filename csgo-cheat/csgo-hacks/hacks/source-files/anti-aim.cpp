#include "..\header-files\anti-aim.h"
#include "..\..\c-sdk\IClientMode.h"
void c_anti_aim::anti_aim_main(CUserCmd* u_cmd) {

	for (int i = 0; 64 > i; ++i) {
		C_BaseEntity* entity = g_pEntityList->GetClientEntity(i);
		
	    C_BaseEntity* local_player = g_pEntityList->GetClientEntity(g_pEngine->GetLocalPlayer());

		if (!entity || entity->GetHealth() <= 0 || !local_player || local_player->GetHealth() <= 0 || entity->IsDormant() || entity->GetTeam() == local_player->GetTeam()) continue;


	}
}
