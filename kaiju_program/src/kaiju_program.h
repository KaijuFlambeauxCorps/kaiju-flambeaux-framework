// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#pragma once

#include "Arduino.h"
#include "cplusplus.h"
//add your includes for the project here

#include "Playlist.h"

//end of add your includes here
#ifdef __cplusplus
extern "C"
{
#endif
    void loop();
    void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project here
void addPatternsToPlaylist();

