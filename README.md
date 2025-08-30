# fractal-renderer

Basic program with rendering mandelbrot set and zooming into.

<img width="800" height="600" alt="image" src="https://github.com/user-attachments/assets/2cb5c6de-8b35-4313-8fbe-5da781969887" />

# Usage

```sh
./fractal_renderer
```
Run the programm in exploring mode. This mod allows to move and zoom camera.

```sh
./fractal_renderer <path_to_config_file>
```
Run the program with a specific animation specified by the config file. The config file is a set of lines where each line represents a key frame between which the animation is performed. Every key frame consists of x-position, y-position, zoom.


## Building

```sh
git clone https://github.com/H5JKey/fractal-renderer.git
mkdir build && cd build
cmake ..
cmake --build .
```
