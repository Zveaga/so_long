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
  - `0` for empty space
  - `1` for a wall
  - `C` for a collectable
  - `E` for the map exit
  - `P` for the player’s starting position
  - 
- The map must contain only `1 exit`, `1 starting position`, and at least `1 collectable`.
- Map must be rectangular
- Map must be surrounded by walls

### Example of a valid map:

```
111111111
10000CC01
1P00C00E1
100000001
111111111
```









