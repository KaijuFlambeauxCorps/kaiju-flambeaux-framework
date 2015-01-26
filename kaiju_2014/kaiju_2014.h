// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _kaiju_2014_H_
#define _kaiju_2014_H_
#include "Arduino.h"
//add your includes for the project kaiju_2014 here

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

//add your function definitions for the project kaiju_2014 here
void addPatternsToPlaylist(Playlist* playlist);

//Do not add code below this line
#endif /* _kaiju_2014_H_ */
