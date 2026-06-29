# cub3d — École 42

> A raycasting-based 3D game engine inspired by Wolfenstein 3D, built with MiniLibX.

---

## Description

`cub3d` renders a 3D maze from a first-person perspective using the **raycasting** technique. A 2D map is parsed from a `.cub` configuration file and rendered in real time, with textured walls depending on their cardinal direction.

Built in collaboration with **elaudrez**.

---

## Features

### Mandatory
- First-person 3D rendering via raycasting (DDA algorithm)
- Distinct wall textures for North, South, East, and West faces
- Configurable floor and ceiling colors
- Player movement: `W A S D`
- Camera rotation: left and right arrow keys

### Bonus
- **Wall collision** — the player cannot walk through walls
- **Minimap** — an overhead view of the map displayed in the corner, showing the player's position and orientation in real time
- **Mouse rotation** — moving the mouse left and right rotates the camera

---

## Map format

Maps are passed as a `.cub` file:

```bash
./cub3d maps/map.cub
```

### Configuration elements

| Identifier | Description |
|---|---|
| `NO ./path` | Texture for north-facing walls |
| `SO ./path` | Texture for south-facing walls |
| `WE ./path` | Texture for west-facing walls |
| `EA ./path` | Texture for east-facing walls |
| `F r,g,b` | Floor color |
| `C r,g,b` | Ceiling color |

### Map characters

| Character | Description |
|---|---|
| `0` | Empty floor |
| `1` | Wall |
| `N` `S` `E` `W` | Player start position and facing direction |

### Map rules

- Must be enclosed by walls on all sides
- Must contain exactly one player starting position
- All textures and colors must be defined before the map
- Invalid files print `Error` to stderr and exit

---

## Controls

| Key / Input | Action |
|---|---|
| `W A S D` | Move forward, left, backward, right |
| Left / Right arrows | Rotate camera |
| Mouse movement | Rotate camera (bonus) |
| `ESC` | Quit |
| Close window | Quit |

---

## How raycasting works

For each vertical column of pixels on the screen, a ray is cast from the player's position in the direction of that column. The algorithm (DDA — Digital Differential Analysis) steps through the map grid and detects the first wall the ray hits, then calculates how far away it is. The closer the wall, the taller the vertical stripe drawn on screen — creating the illusion of depth.

Each stripe is then textured based on which wall face was hit (N/S/E/W) and where exactly on that wall the ray landed.

---

## Files

| File | Description |
|---|---|
| `main.c` | Entry point and initialization |
| `parsing.c` | `.cub` file parsing and validation |
| `raycasting.c` | DDA algorithm and wall rendering |
| `textures.c` | Texture loading and mapping |
| `player.c` | Movement, rotation, collision |
| `minimap.c` | Minimap rendering (bonus) |
| `mouse.c` | Mouse input handling (bonus) |
| `cub3d.h` | Header |
| `Makefile` | Build rules |

---

## Compilation & Usage

```bash
make
./cub3d maps/map.cub
```

Bonus:
```bash
make bonus
./cub3d_bonus maps/map.cub
```

---

## Dependencies

Requires the **MiniLibX** library. On Linux:

```bash
sudo apt-get install libxext-dev libxrandr-dev libx11-dev libbsd-dev libssl-dev
```

---

## Authors

- lenouille
- elaudrez

---

## École 42

Project completed as part of the École 42 curriculum. No external game engine or graphics framework — rendering is done entirely from scratch using MiniLibX.
