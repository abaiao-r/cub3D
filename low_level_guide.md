## Project Setup
1. Create a new directory for your project.
2. Set up the necessary files and folders, including the main C file, header files, and a Makefile.

## Parsing the Scene File
1. Write a parser to read and validate the scene description file (.cub extension).
2. Validate the map and its elements:
   - Ensure the map is composed of only valid characters: 0 for an empty space, 1 for a wall, and N/S/E/W for the player's start position and orientation.
   - Ensure the map is closed/surrounded by walls.
   - Handle empty lines and optional elements in any order.
3. **Extract information** about textures, colors, and the player's starting position.

## Set up the miniLibX
1. Download and set up the miniLibX library.
2. Link the library to your project.
3. Initialize the graphical window using the miniLibX library.
4. Manage window events to allow smooth interaction (window switching, minimizing, etc.).

## Implement Ray-Casting
1. Understand the principles of ray-casting for creating a 3D representation.
2. Use ray-casting algorithm to calculate the distance of walls from the player's perspective.
3. Determine the height of the wall to be displayed based on the distance calculated.
4. Display different wall textures based on the wall's facing direction (North, South, East, West).

## Implement Movement and Controls
1. Handle user input for moving the player's viewpoint through the maze:
   - Use arrow keys to look left and right.
   - Use W, A, S, and D keys to move the player forward, left, backward, and right, respectively.
2. Enable the ESC key and clicking on the window's close button to cleanly exit the program.

## Displaying the Scene
1. Map the calculated wall distances to textures.
2. Set the floor and ceiling colors to two different values.
3. Use the miniLibX functions to render the scene with appropriate wall textures, floor, and ceiling colors.
