# godot_finder

Finder addon for Godot 4.2.2 - 4.3

## Usage

```gd
var root = Finder.get_root()

var test1 = Finder.find_child_by_name(root, "Test1")
print(test1)

var test_sprite1 = Finder.find_child_by_type(root, "Sprite2D")
print(test_sprite1)

var sprites = Finder.find_children_by_type(root, "Sprite2D")
print(sprites)
```

## Install

### Copy Files

- Create a `addons/finder` folder in your godot project
- Place `finder.gdextension` in it below:

    ```text
    [configuration]

    entry_symbol = "gdextension_init"
    compatibility_minimum = 4.2

    [libraries]

    macos.debug.x86_64 = "bin/libfinder.macos.debug.x86_64.framework"
    macos.release.x86_64 = "bin/libfinder.macos.release.x86_64.framework"
    macos.debug.arm64 = "bin/libfinder.macos.debug.arm64.framework"
    macos.release.arm64 = "bin/libfinder.macos.release.arm64.framework"
    windows.debug.x86_64 = "bin/libfinder.windows.debug.x86_64.dll"
    windows.release.x86_64 = "bin/libfinder.windows.release.x86_64.dll"
    linux.debug.x86_64 = "bin/libfinder.linux.debug.x86_64.so"
    linux.release.x86_64 = "bin/libfinder.linux.release.x86_64.so"
    linux.debug.arm64 = "bin/libfinder.linux.debug.arm64.so"
    linux.release.arm64 = "bin/libfinder.linux.release.arm64.so"
    linux.debug.rv64 = "bin/libfinder.linux.debug.rv64.so"
    linux.release.rv64 = "bin/libfinder.linux.release.rv64.so"
    ```

- Create a `addons/finder/bin` folder in your godot project
- Place dlls from [Releases](releases) into `bin` folder
- Copy `*.gd` files from [`addons/finder`](project/addons/finder) to `addons/finder` in your godot project

### Enable Plugin

- Enable the plugin in the project settings

## Build and Run

- `git submodule update --init --recursive --recommend-shallow --depth 1`
- `scons`
- `scons target=template_release`
- `godot project/project.godot` (only first time)
- `godot --path project/`
