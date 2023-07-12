# Project Setup

1. **Create a new directory for your project.**
2. **Set up the necessary files and folders**, including the main C file, header files, and a Makefile.

# Parsing the Scene File

1. **Write a parser** to read and validate the scene description file (with the .cub extension).
2. **Validate the map and its elements** according to the specified rules.
3. **Extract information** about textures, colors, and the player's starting position.

# Set up the miniLibX

1. **Download and set up the miniLibX library**.
2. **Link the library to your project**.
3. **Initialize the graphical window** using the library.

# Implement Ray-Casting

1. **Understand the principles of ray-casting** for creating a 3D representation.
2. Use the ray-casting algorithm to **calculate the distance of walls** from the player's perspective.
3. Determine the **height of the wall** to be displayed based on the distance calculated.

# Implement Movement and Controls

1. **Handle user input** for moving the player's viewpoint through the maze.
2. Use **arrow keys to look** left and right.
3. Use **W, A, S, and D keys** to move the player forward, left, backward, and right, respectively.
4. Allow the user to **quit the program** by pressing ESC or closing the window.

# Displaying the Scene

1. Map the calculated wall distances to **textures**.
2. Display the **walls and the floor/ceiling** with appropriate colors.
3. Use the **miniLibX functions to render** the scene on the graphical window.