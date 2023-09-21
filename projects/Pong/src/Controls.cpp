#include "Controls.h"

namespace Controls {

    bool IsPlayerMoving() {
        return IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN);
    }

    void UpdatePlayerPosition(int& x, int& y, int dx, int dy) {
        if (IsKeyDown(KEY_RIGHT)) { x += dx; }
        if (IsKeyDown(KEY_LEFT)) { x -= dx; }
        if (IsKeyDown(KEY_UP)) { y -= dy; }
        if (IsKeyDown(KEY_DOWN)) { y += dy; }
    }
}
