# godot_finder

Finder addon for Godot 4.2.2 - 4.3

## Install

- create a `addons` folder in your godot project
- place `finder.gdextension` below:

    ```text
    [configuration]

    entry_symbol = "gdextension_init"
    compatibility_minimum = 4.2

    [libraries]

    macos.debug = "bin/libfinder.macos.debug.framework"
    macos.release = "bin/libfinder.macos.release.framework"
    windows.debug.x86_64 = "bin/libfinder.windows.debug.x86_64.dll"
    windows.release.x86_64 = "bin/libfinder.windows.release.x86_64.dll"
    linux.debug.x86_64 = "bin/libfinder.linux.debug.x86_64.so"
    linux.release.x86_64 = "bin/libfinder.linux.release.x86_64.so"
    linux.debug.arm64 = "bin/libfinder.linux.debug.arm64.so"
    linux.release.arm64 = "bin/libfinder.linux.release.arm64.so"
    linux.debug.rv64 = "bin/libfinder.linux.debug.rv64.so"
    linux.release.rv64 = "bin/libfinder.linux.release.rv64.so"
    ```

- create a `bin` folder in your godot project
- place dlls from [Releases](releases) into `bin` folder

## Build and Run

- `git submodule update --init --recursive --recommend-shallow --depth 1`
- `scons`
- `scons target=template_release`
- `godot project/project.godot` (only first time)
- `godot --path project/`