# So_long

## Key Concepts
- Colors
- Images
- Textures
- Algorithms
- Working with external graphical library

## How To play
Clone the repository:
```
git clone git@github.com:Zveaga/so_long.git
```
Move inside the directory:
```
cd so_long
```
Compile:
```
make
```
This will create an executable called `so_long`.

Run it:
```
./so_long maps/map.ber
```
To change the map, replace "maps/map.ber" with the path to another map as long as it respects the rules.

## Map rules
- Map can only contain the following 5 characters:
  1. `0` for empty space
  2. `1` for a wall
  3. `C` for a collectable
  4. `E` for the map exit
  5. `P` for the player’s starting position


