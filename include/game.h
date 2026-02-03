/*
Stub_SoF2GT - Example stub plugin for SOF2GT_QMM
Copyright 2025-2026
https://github.com/thecybermind/stub_sof2gt/
3-clause BSD license: https://opensource.org/license/bsd-3-clause

Created By:
    Kevin Masterson < k.m.masterson@gmail.com >

*/

#ifndef STUB_SOF2GT_GAME_H
#define STUB_SOF2GT_GAME_H

#if defined(GAME_SOF2MP)
    #include <sof2mp/game/g_local.h>
    #include <game_sof2mp.h>
    #define GAME_STR "SOF2MP"
#else
#error This plugin is only made for Soldier of Fortune 2 Multiplayer!
#endif


inline const char* gt_mod_msgname(intptr_t msg) {
    switch (msg) {
    case GAMETYPE_INIT:
        return "GAMETYPE_INIT";
    case GAMETYPE_START:
        return "GAMETYPE_START";
    case GAMETYPE_RUN_FRAME:
        return "GAMETYPE_RUN_FRAME";
    case GAMETYPE_EVENT:
        return "GAMETYPE_EVENT";
    default:
        return "unknown";
    }
}


inline const char* gt_eng_msgname(intptr_t msg) {
	switch (msg) {
	case GT_PRINT:
		return "GT_PRINT";
	case GT_ERROR:
		return "GT_ERROR";
	case GT_MILLISECONDS:
		return "GT_MILLISECONDS";
	case GT_CVAR_REGISTER:
		return "GT_CVAR_REGISTER";
	case GT_CVAR_UPDATE:
		return "GT_CVAR_UPDATE";
	case GT_CVAR_SET:
		return "GT_CVAR_SET";
	case GT_CVAR_VARIABLE_INTEGER_VALUE:
		return "GT_CVAR_VARIABLE_INTEGER_VALUE";
	case GT_CVAR_VARIABLE_STRING_BUFFER:
		return "GT_CVAR_VARIABLE_STRING_BUFFER";
	case GT_MEMSET:
		return "GT_MEMSET";
	case GT_MEMCPY:
		return "GT_MEMCPY";
	case GT_STRNCPY:
		return "GT_STRNCPY";
	case GT_SIN:
		return "GT_SIN";
	case GT_COS:
		return "GT_COS";
	case GT_ATAN2:
		return "GT_ATAN2";
	case GT_SQRT:
		return "GT_SQRT";
	case GT_ANGLEVECTORS:
		return "GT_ANGLEVECTORS";
	case GT_PERPENDICULARVECTOR:
		return "GT_PERPENDICULARVECTOR";
	case GT_FLOOR:
		return "GT_FLOOR";
	case GT_CEIL:
		return "GT_CEIL";
	case GT_TESTPRINTINT:
		return "GT_TESTPRINTINT";
	case GT_TESTPRINTFLOAT:
		return "GT_TESTPRINTFLOAT";
	case GT_ACOS:
		return "GT_ACOS";
	case GT_ASIN:
		return "GT_ASIN";
	case GT_MATRIXMULTIPLY:
		return "GT_MATRIXMULTIPLY";
	case GT_TEXTMESSAGE:
		return "GT_TEXTMESSAGE";
	case GT_RESETITEM:
		return "GT_RESETITEM";
	case GT_GETCLIENTNAME:
		return "GT_GETCLIENTNAME";
	case GT_REGISTERSOUND:
		return "GT_REGISTERSOUND";
	case GT_STARTGLOBALSOUND:
		return "GT_STARTGLOBALSOUND";
	case GT_REGISTERITEM:
		return "GT_REGISTERITEM";
	case GT_RADIOMESSAGE:
		return "GT_RADIOMESSAGE";
	case GT_REGISTERTRIGGER:
		return "GT_REGISTERTRIGGER";
	case GT_GETCLIENTITEMS:
		return "GT_GETCLIENTITEMS";
	case GT_DOESCLIENTHAVEITEM:
		return "GT_DOESCLIENTHAVEITEM";
	case GT_ADDTEAMSCORE:
		return "GT_ADDTEAMSCORE";
	case GT_ADDCLIENTSCORE:
		return "GT_ADDCLIENTSCORE";
	case GT_RESTART:
		return "GT_RESTART";
	case GT_REGISTEREFFECT:
		return "GT_REGISTEREFFECT";
	case GT_PLAYEFFECT:
		return "GT_PLAYEFFECT";
	case GT_REGISTERICON:
		return "GT_REGISTERICON";
	case GT_USETARGETS:
		return "GT_USETARGETS";
	case GT_GETCLIENTORIGIN:
		return "GT_GETCLIENTORIGIN";
	case GT_GIVECLIENTITEM:
		return "GT_GIVECLIENTITEM";
	case GT_TAKECLIENTITEM:
		return "GT_TAKECLIENTITEM";
	case GT_SPAWNITEM:
		return "GT_SPAWNITEM";
	case GT_STARTSOUND:
		return "GT_STARTSOUND";
	case GT_GETTRIGGERTARGET:
		return "GT_GETTRIGGERTARGET";
	case GT_GETCLIENTLIST:
		return "GT_GETCLIENTLIST";
	case GT_SETHUDICON:
		return "GT_SETHUDICON";
	default:
		return "unknown";
	}
}


#endif // STUB_SOF2GT_GAME_H
