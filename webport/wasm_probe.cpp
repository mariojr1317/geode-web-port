#include <emscripten/emscripten.h>

extern "C" {

// Tiny first-stage test: proves the toolchain can compile C++ to WebAssembly.
// This is not the Geode loader and does not load native .geode mods.
EMSCRIPTEN_KEEPALIVE
int add(int a, int b) {
    return a + b;
}

EMSCRIPTEN_KEEPALIVE
const char* webport_version() {
    return "Geode WebPort WASM probe 0.1";
}

}
