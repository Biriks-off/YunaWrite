# YunaWrite

**Libre plug-ins and sandboxes**

## Features

- **Libre Plug-ins**: `opexe` (Open anything), `mail` (Edit your own txt news), `setting` (Edit txt config for colors).
- **Sandbox**: `virfl` (A safe virtual file system). Delete System32 all you want. The real system stays safe.
- **Self-healing**: Delete the `setting.txt` or `mail.txt`? The program automatically recreates them.
- **Smart Input**: Press `Ctrl+Z` (Windows) / `Ctrl+D` (Linux/macOS) to instantly return or cancel. Never crash.
- **Compiler as Plugin**: Use `cpp` to auto-generate `.bat`, `.command`, or `.sh` scripts for GCC/Clang.

## Build & Run

Run the `.exe` directly, or compile the single `.cpp` file with any standard C++20 compiler (GCC/Clang recommended).

## Plug-ins Philosophy

Mechanism and Strategy separation. You don't need to touch the source code. Just edit the `.txt` files to change the system.