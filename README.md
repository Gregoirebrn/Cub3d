# Cub3D

Cub3D is a 3D graphics project based on the Wolfenstein 3D game engine. It is part of the 42 school curriculum and focuses on implementing a simple raycasting engine using the MinilibX library.

## Features
- **Raycasting Engine** for rendering a 3D world from a 2D map.
- **Smooth Movement & Rotation** allowing simultaneous movement and turning.
- **Wall Collision Detection** to prevent walking through obstacles.
- **MiniLibX Graphics Library** for rendering and event handling.

## Installation
```bash
# Clone the repository
git clone https://github.com/yourusername/cub3d.git
cd cub3d

# Compile the project
make

# Run the game
./cub3D maps/sample_map.cub
```

## Controls
- `W` / `S` : Move Forward / Backward
- `A` / `D` : Strafe Left / Right
- `←` / `→` : Rotate Left / Right
- `ESC` : Quit the game

## Understanding Raycasting
Raycasting is a rendering technique used in early 3D games to create a pseudo-3D effect. It works by sending out rays from the player's perspective, checking where they intersect with walls, and calculating the correct height to draw each wall slice.

### **Raycasting Steps**:
1. **Cast Rays**: For each vertical screen column, cast a ray from the player’s position.
2. **Detect Walls**: Check where the ray collides with a wall in the 2D map.
3. **Calculate Distance**: Use the distance between the player and the wall to determine the height of the wall slice.
4. **Render Scene**: Draw vertical slices of walls based on calculated distances, creating a 3D illusion.

### Short Video of The Game
[Cub_is_cute.webm](https://github.com/user-attachments/assets/ad9655ed-af0b-41dc-846c-7dd0d0912966)
