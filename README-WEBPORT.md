# Geode WebPort — early build experiment

This fork is an experimental effort to investigate whether selected, portable parts of Geode can be adapted for a browser-based Geometry Dash WASM build.

## Current status

The GitHub Actions workflow `.github/workflows/wasm-probe.yml` compiles a tiny C++ probe with Emscripten and uploads the generated JavaScript/WebAssembly files as an Actions artifact. This verifies the build pipeline only; **it does not compile Geode itself**.

## Run the build

1. Open the **Actions** tab.
2. Select **Geode WebPort - Emscripten probe**.
3. Click **Run workflow** and run it on `main`.
4. Open the completed run and download the `geode-webport-wasm-probe` artifact.
5. Extract the ZIP and open `index.html` from a web server/HTTPS origin. Some browser features may not work from `file://`.

The page should report `add(20, 22) = 42`.

## Why this is only a probe

Geode contains platform-specific loader, hooking, and game-integration code. Compiling an isolated C++ file to WASM does not make native hooks, shared libraries, or existing `.geode` mods work in a browser. The next step is to inspect Geode's build dependencies and identify a small component that can be ported without native OS hooks.

## Intended direction

- Keep the original Geode source and license notices intact.
- Identify portable code and browser-specific replacements.
- Build a JavaScript-facing mod API for browser-compatible mods.
- Integrate with a selected Geometry Dash WebAssembly build only after its loading interface and exports are understood.

No compatibility with original `.geode` mods is claimed at this stage.
