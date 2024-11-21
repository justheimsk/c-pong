# Pong in C with SDL2

A classic Pong game developed in C using the **SDL2** and **SDL2_TTF** libraries for rendering and text handling.

## Features
- A simulation of the classic Pong game.
- Score display on the screen.
- Smooth player controls.
- 2D graphics rendered using SDL2.

## Prerequisites
Before compiling and running the game, make sure you have the following dependencies installed:

### Dependencies
- **SDL2**
- **SDL2_TTF**

### Installing Dependencies
#### On Linux (Debian/Ubuntu)
```bash
sudo apt update
sudo apt install libsdl2-dev libsdl2-ttf-dev
```

#### On macOS

If you use Homebrew:
```bash
brew install sdl2 sdl2_ttf
```

#### On Windows
1. Download the development libraries for SDL2 and SDL2_TTF.
2. Set up your development environment to include the libraries and headers.

### Compilation and Execution
This project includes a Makefile to simplify the compilation process. To compile the game, simply run the following command:
```bash
make
```

### Running the Game

After compiling, run the generated binary:

```bash
make run
```

