# YunaWrite

**YunaWrite is a blank paper**


*This is a lightweight command-line file manager and sandbox written in pure C++*

## Explain

The core code is safe(maybe😂), while all behavior is controlled by plain text files. This allows you to modify the system name, prompt, colors, and even the patch history without recompiling

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Features

- **Configurable via txt**: Change the prompt, system name, and colors instantly using `setting.txt`, `prompt.txt`, `osname.txt`, etc.
- **Virtual Sandbox (`virfl`)**: Test files safely in memory.
- **Universal Opener (`opexe`)**: Open any file or directory directly.
- **Compiler Interfaces**: Generate batch/shell scripts for C (`cbat`), C++ (`cpp`), Python (`py`), and JavaScript (`js`).
- **Self-Healing**: Missing configuration files are automatically recreated.

## Build

```bash
g++ -std=c++20 src/main.cpp -o yuna