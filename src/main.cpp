/*
Stub_SoF2GT - Example stub plugin for SOF2GT_QMM
Copyright 2025-2026
https://github.com/thecybermind/stub_sof2gt/
3-clause BSD license: https://opensource.org/license/bsd-3-clause

Created By:
	Kevin Masterson < k.m.masterson@gmail.com >

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <qmmapi.h>
#include <sof2gt_api.h>

#include "version.h"
#include "game.h"
#include "main.h"

pluginres_t* g_result = nullptr;
plugininfo_t g_plugininfo = {
	QMM_PIFV_MAJOR,									// plugin interface version major
	QMM_PIFV_MINOR,									// plugin interface version minor
	"Stub_SoF2GT",									// name of plugin
	STUB_SOF2GT_VERSION,							// version of plugin
	"Example SoF2MP_QMM plugin",					// description of plugin
	STUB_SOF2GT_BUILDER,							// author of plugin
	"https://github.com/thecybermind/stub_sof2gt/",	// website of plugin
	"STUB_SOF2GT",									// log tag
};
eng_syscall_t g_syscall = nullptr;
mod_vmMain_t g_vmMain = nullptr;
pluginfuncs_t* g_pluginfuncs = nullptr;
pluginvars_t* g_pluginvars = nullptr;

sof2gt_pluginvars_t* sof2gt_pluginvars = nullptr;

// log level to use for all trace logging
const int loglevel = QMMLOG_INFO;
// should we ignore outputting repeated GT_vmMain calls?
bool ignore_hotpath = true;


C_DLLEXPORT void QMM_Query(plugininfo_t** pinfo) {
	// give QMM our plugin info struct
	QMM_GIVE_PINFO();
}


C_DLLEXPORT int QMM_Attach(eng_syscall_t engfunc, mod_vmMain_t modfunc, pluginres_t* presult, pluginfuncs_t* pluginfuncs, pluginvars_t* pluginvars) {
	QMM_SAVE_VARS();

	// make sure this DLL is loaded only in the right engine
	if (strcmp(QMM_GETGAMEENGINE(PLID), GAME_STR) != 0)
		return 0;

	return 1;
}


C_DLLEXPORT void QMM_Detach() {
}


C_DLLEXPORT intptr_t QMM_vmMain(intptr_t cmd, intptr_t* args) {
	QMM_RET_IGNORED(0);
}


C_DLLEXPORT intptr_t QMM_syscall(intptr_t cmd, intptr_t* args) {
	QMM_RET_IGNORED(0);
}


C_DLLEXPORT intptr_t QMM_vmMain_Post(intptr_t cmd, intptr_t* args) {
	QMM_RET_IGNORED(0);
}


C_DLLEXPORT intptr_t QMM_syscall_Post(intptr_t cmd, intptr_t* args) {
	QMM_RET_IGNORED(0);
}


static intptr_t last_cmd = -1;
static bool is_ignoring_syscalls = false;
intptr_t SOF2GT_GT_vmMain(intptr_t cmd, intptr_t* args) {
	if (cmd == GAMETYPE_INIT) {
		// example showing writing to QMM log on initialization
		QMM_WRITEQMMLOG(PLID, QMM_VARARGS(PLID, "Stub_SoF2GT loaded! Game engine: %s\n", QMM_GETGAMEENGINE(PLID)), QMMLOG_INFO);
	}

	// ignore repeated GAMETYPE_RUN_FRAME calls
	if (last_cmd == cmd && cmd == GAMETYPE_RUN_FRAME) {
		is_ignoring_syscalls = true;
	}
	else {
		const char* msgname = gt_mod_msgname(cmd);
		QMM_WRITEQMMLOG(PLID, QMM_VARARGS(PLID, "SOF2GT_GT_vmMain(%s)\n", msgname), loglevel);
	}
	last_cmd = cmd;

	SOF2GT_RET_IGNORED(0);
}


intptr_t SOF2GT_GT_vmMain_Post(intptr_t cmd, intptr_t* args) {
	if (!is_ignoring_syscalls) {
		const char* msgname = gt_mod_msgname(cmd);
		QMM_WRITEQMMLOG(PLID, QMM_VARARGS(PLID, "SOF2GT_GT_vmMain_Post(%s)\n", msgname), loglevel);
	}

	is_ignoring_syscalls = false;

	SOF2GT_RET_IGNORED(0);
}


intptr_t SOF2GT_GT_syscall(intptr_t cmd, intptr_t* args) {
	if (is_ignoring_syscalls)
		SOF2GT_RET_IGNORED(0);

	const char* msgname = gt_eng_msgname(cmd);
	if (cmd == GT_REGISTERSOUND ||
	    cmd == GT_REGISTEREFFECT ||
	    cmd == GT_REGISTERICON ||
	    cmd == GT_USETARGETS) {
		QMM_WRITEQMMLOG(PLID, QMM_VARARGS(PLID, "SOF2GT_GT_syscall(%s, \"%s\")\n", msgname, (char*)args[0]), loglevel);
	}
	else if (cmd == GT_REGISTERITEM ||
	         cmd == GT_REGISTERTRIGGER ||
	         cmd == GT_TEXTMESSAGE ||
	         cmd == GT_RADIOMESSAGE) {
		QMM_WRITEQMMLOG(PLID, QMM_VARARGS(PLID, "SOF2GT_GT_syscall(%s, %d, \"%s\")\n", msgname, args[0], (char*)args[1]), loglevel);
	}
	else {
		QMM_WRITEQMMLOG(PLID, QMM_VARARGS(PLID, "SOF2GT_GT_syscall(%s)\n", msgname), loglevel);
	}
	SOF2GT_RET_IGNORED(0);
}


intptr_t SOF2GT_GT_syscall_Post(intptr_t cmd, intptr_t* args) {
	if (is_ignoring_syscalls)
		SOF2GT_RET_IGNORED(0);

	const char* msgname = gt_eng_msgname(cmd);
	if (cmd == GT_REGISTERSOUND ||
	    cmd == GT_REGISTEREFFECT ||
	    cmd == GT_REGISTERICON ||
	    cmd == GT_USETARGETS) {
		QMM_WRITEQMMLOG(PLID, QMM_VARARGS(PLID, "SOF2GT_GT_syscall_Post(%s, \"%s\")\n", msgname, (char*)args[0]), loglevel);
	}
	else if (cmd == GT_REGISTERITEM ||
	         cmd == GT_REGISTERTRIGGER ||
	         cmd == GT_TEXTMESSAGE ||
		     cmd == GT_RADIOMESSAGE) {
		QMM_WRITEQMMLOG(PLID, QMM_VARARGS(PLID, "SOF2GT_GT_syscall_Post(%s, %d, \"%s\")\n", msgname, args[0], (char*)args[1]), loglevel);
	}
	else {
		QMM_WRITEQMMLOG(PLID, QMM_VARARGS(PLID, "SOF2GT_GT_syscall_Post(%s)\n", msgname), loglevel);
	}
	SOF2GT_RET_IGNORED(0);
}


C_DLLEXPORT void QMM_PluginMessage(plid_t from_plid, const char* message, void* buf, intptr_t buflen, int is_broadcast) {
	// SOF2GT is attaching, save the variables and send it our hook functions
	if (!strcmp(message, "SOF2GT_Attach")) {
		SOF2GT_SAVE_VARS();
		SOF2GT_GIVE_FUNCS();
	}
}
