#pragma once
#include "dllincludes.h"

#include "utils/io.h"
#include "utils/event.h"

#include "drm.h"
#include "launcher.h"
#include "memory.h"
#include "modules.h"
#include "proxy_info.h"
#include "ue_types.h"

#include "modules/asi_loader.h"
#include "modules/launcher_args.h"


extern IO::RuntimeLogger   GLogger;        // logger used throughout the dll
extern AppProxyInfo        GAppProxyInfo;  // game version, executable path, window title
extern ModuleList<64>      GModules;       // console enabler, asi loader, launcher arg tool are all registered as modules
