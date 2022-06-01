#include <raylib.h>
#include "main.h"
#include "utils.h"

int UTIL_CACHE_w = 0;
int UTIL_CACHE_h = 0;
Vector2 UTIL_CACHE_pos = {0,0};
bool isFullScreen = false;


void toggleFullscreen() {
    if (isFullScreen) {
        returnToPrevScreen();
    } else {
        fullscreen();
    }
}

void fullscreen() {

	// caching the previous values;

	UTIL_CACHE_h = GetScreenHeight();
	UTIL_CACHE_w = GetScreenWidth();
	UTIL_CACHE_pos = GetWindowPosition();

	// switching to fullscreen;

	int m = GetCurrentMonitor();
	int w  = GetMonitorWidth(m);
	int h  = GetMonitorHeight(m);	

	SetWindowPosition(0, 0);
	SetWindowSize(w, h);

	isFullScreen = true;
}

void returnToPrevScreen() {
	SetWindowPosition(UTIL_CACHE_pos.x, UTIL_CACHE_pos.y);
	SetWindowSize(UTIL_CACHE_w, UTIL_CACHE_h);
	isFullScreen = false;
}

void reTargetGrid() {
	extern int TILE_W;
	extern int TILE_H;

	int w  = GetScreenWidth();
	int h  = GetScreenHeight();	

	TILE_W = w / TILES_COUNT_C;
	TILE_H = h / TILES_COUNT_R;
}