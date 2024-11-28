# Rotational Donut

## **Overview**
The **Rotational Donut** is a simple ASCII-based rendering program written in C. It visualizes a spinning torus (commonly called a "donut") in the terminal by utilizing mathematical principles of 3D transformations, lighting, and projections. This project demonstrates the power of mathematical calculations in creating visual effects using only basic programming constructs.

---

## **Features**
- Displays a spinning 3D donut in ASCII art.
- Implements a basic 3D engine with depth buffering and projection.
- Visualizes shading using luminance values and ASCII characters.
- Runs in an infinite loop, providing a continuous spinning animation.

---

## **How It Works**
The program calculates the 3D positions of points on a torus and projects them onto a 2D plane for display in the terminal. Each frame:
1. Computes the torus points using trigonometric functions (`sin`, `cos`).
2. Applies rotations around two axes to give the illusion of spinning.
3. Calculates depth (`z-buffer`) and luminance to determine shading and visibility of each point.
4. Renders the ASCII output in the terminal, updating the view in real-time.

---

## **Applications**
This project serves as a demonstration of:
1. **Mathematics in Graphics Programming:** Understanding 3D geometry and projections is foundational in computer graphics.
2. **Resource-Constrained Rendering:** Rendering 3D objects without relying on graphical libraries or hardware acceleration.
3. **Educational Tool:** This program is often used to teach concepts of transformations, rotations, depth buffering, and shading in computer graphics courses.
4. **ASCII Art Projects:** Creating visualizations in environments where graphics support is minimal or unavailable, such as older terminal systems or low-powered devices.

---

## **Code Explanation**
### **Key Variables**
The code uses compact variable names, but here’s a breakdown:

| Variable Name | Meaning/Role                                                                                       |
|---------------|---------------------------------------------------------------------------------------------------|
| `A`, `B`      | Rotation angles around the X-axis and Y-axis. These control the spinning effect of the torus.     |
| `i`, `j`      | Angles that describe the torus’ geometry. `i` iterates through the torus’ cross-section, and `j` through its circumference. |
| `b[1760]`     | The **ASCII output buffer** that holds the characters to be displayed in each frame.               |
| `z[1760]`     | The **depth buffer** that tracks the closest points for each screen pixel to handle occlusion.     |
| `c`, `d`, `e` | Intermediate trigonometric calculations for sine and cosine values.                                |
| `D`           | Inverse depth of a point; used for perspective scaling.                                           |
| `x`, `y`      | Screen coordinates of a projected point.                                                          |
| `o`           | Index in the buffers (`b` and `z`) corresponding to a screen position `(x, y)`.                   |
| `N`           | Luminance index for selecting a shading character from `".,-~:;=!*#$@"`.                          |

---

### **Key Functions**
1. **Trigonometric Calculations:** 
   - Uses `sin` and `cos` to compute rotations and positions in 3D space.
2. **Depth Buffering:**
   - Ensures proper visibility of closer points by comparing the depth (`z[o]`) of each point.
3. **Projection:**
   - Maps 3D points onto a 2D plane using perspective projection, creating the illusion of depth.
4. **ASCII Shading:**
   - Selects characters based on luminance to simulate lighting and create a more realistic effect.

---

## **Requirements**
- **C Compiler**: Any standard C compiler like GCC or Clang.
- **Operating System**: Unix-based systems (Linux, macOS) for compatibility with `\x1b` escape codes and `usleep`. 
  - On Windows, you may need to replace `usleep` with an equivalent function like `Sleep`.

---

## **Usage**
1. Compile the code:
   ```bash
   gcc rotational_donut.c -o donut -lm
