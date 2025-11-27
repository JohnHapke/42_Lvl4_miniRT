# miniRT - A Basic Ray Tracer Implementation

This was a group project developed together with my teammate and team lead Igor ((https://github.com/iherman-p). The project was carried out remotely, and we held regular meetings to synchronize progress. We maintained a changelog to document updates in every commit, and followed a structured versioning approach to ensure clarity and traceability.

## Purpose
> The purpose of the miniRT project is to create a C program that implements a functional ray tracer, providing hands-on experience with 3D mathematics, light physics, and computer graphics algorithms. The program demonstrates understanding of ray-object intersection calculations, lighting models, and image rendering while implementing core ray tracing functionality.

## Explanation of Behavior
miniRT implements a functional ray tracer that generates realistic 3D images. The program:

- Parses scene description files (.rt format) containing geometric objects and lighting information
- Calculates ray-object intersections for spheres, planes, and cylinders
- Implements ambient and diffuse lighting models for realistic shading
- Handles object transformations (translation and rotation)
- Generates hard shadows and proper light interactions
- Renders images in real-time using the MiniLibX graphics library
- Provides interactive window management with proper event handling

## How It Works
### Initialization
The program starts by:

- Parsing the scene description file (.rt format)
- Setting up the MiniLibX graphics library
- Initializing the camera, lights, and geometric objects
- Creating the rendering window

### Ray Tracing Pipeline

- **Scene Parsing**: Reads and validates the .rt file containing scene elements (ambient light, camera, lights, objects).
- **Ray Generation**: For each pixel, generates a ray from the camera through the pixel into the scene.
- **Intersection Calculation**: Tests ray intersections with all objects in the scene (spheres, planes, cylinders).
- **Lighting Calculation**: Applies ambient and diffuse lighting models to determine pixel color.
- **Shadow Calculation**: Traces shadow rays to determine if objects are in shadow.
- **Image Rendering**: Displays the final rendered image in the MiniLibX window.

### Core Features
**Supported Geometric Objects**

- `Spheres` - Defined by center point and diameter
- `Planes` - Defined by a point and normal vector
- `Cylinders` - Defined by center, axis vector, diameter, and height

### Lighting System

- `Ambient Lighting` - Global illumination preventing complete darkness
- `Diffuse Lighting` - Directional lighting based on surface normals
- `Hard Shadows` - Sharp shadow casting from light sources
- `Multiple Light Sources` - Support for multiple point lights

### Scene Elements

- `Camera` - Viewpoint position, orientation, and field of view
- `Ambient Light` - Global lighting ratio and color
- `Point Lights` - Position, brightness, and color
- `Objects` - Geometric primitives with position, orientation, and color

### Transformations

- `Translation` - Moving objects, lights, and camera in 3D space
- `Rotation` - Rotating objects and camera (spheres and lights cannot be rotated)
- `Scaling` - Adjusting object dimensions (diameter for spheres, width/height for cylinders)

## Scene File Format (.rt)
The program accepts scene description files with the following format:
```bash
A 0.2 255,255,255                              # Ambient lighting
C -50,0,20 0,0,1 70                            # Camera
L -40,0,30 0.7 255,255,255                     # Light
pl 0,0,0 0,1.0,0 255,0,225                     # Plane
sp 0,0,20 20 255,0,0                           # Sphere
cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255  # Cylinder
```

## Element Specifications

- `A` - Ambient light: ratio [0.0-1.0], RGB colors [0-255]
- `C` - Camera: position (x,y,z), orientation vector [-1,1], FOV [0-180]
- `L` - Light: position (x,y,z), brightness [0.0-1.0], RGB colors [0-255]
- `pl` - Plane: point (x,y,z), normal vector [-1,1], RGB colors [0-255]
- `sp` - Sphere: center (x,y,z), diameter, RGB colors [0-255]
- `cy` - Cylinder: center (x,y,z), axis vector [-1,1], diameter, height, RGB colors [0-255]

## Window Management

- `ESC key` - Close window and exit program
- `Red cross` - Close window and exit program
- `Window switching` - Maintains fluid window management
- `Minimization` - Proper window state handling

## Compilation and Usage

1. **Compile**: Run `make` to build the program
2. **Execute**: `./miniRT [scene_file.rt]` to render a scene
3. **Usage Examples**:
```bash
$> ./miniRT scenes/simple_scene.rt
$> ./miniRT scenes/multiple_objects.rt
$> ./miniRT scenes/complex_lighting.rt
```

## Key Technical Concepts

- **Ray-Object Intersection**: Mathematical calculations for ray-sphere, ray-plane, and ray-cylinder intersections
- **Vector Mathematics**: 3D vector operations for transformations and lighting calculations
- **Lighting Models**: Implementation of ambient and diffuse lighting (Lambertian reflection)
- **Shadow Calculation**: Ray tracing for shadow determination
- **3D Transformations**: Translation and rotation matrices for object positioning
- **Color Theory**: RGB color mixing and lighting calculations
- **Graphics Programming**: Real-time rendering with MiniLibX
- **Mathematical Formulas**: Implementation of complex geometric and physics equations
- **Memory Management**: Efficient handling of scene data and image buffers
- **Error Handling**: Robust parsing and validation of scene files

## Architecture Highlights

- **Modular Design**: Separate modules for parsing, ray tracing, lighting, and rendering
- **Mathematical Precision**: Accurate implementation of geometric intersection algorithms
- **Optimized Rendering**: Efficient ray tracing pipeline for real-time performance
- **Robust Parsing**: Comprehensive scene file validation with meaningful error messages
- **Memory Safety**: Proper memory management with no leaks
- **Cross-Platform Graphics**: MiniLibX integration for window management and image display

## Requirements

- Compliance with 42 School coding standards (Norm)
- No unexpected crashes (segfaults, bus errors, double frees)
- Proper memory management with no leaks
- Mathematical accuracy in ray tracing calculations
- Support for .rt scene file format
- Real-time rendering capabilities
- Proper window and event management

## Mathematical Foundation
This project implements fundamental computer graphics algorithms including:

- Ray-sphere intersection using quadratic equations
- Ray-plane intersection using dot products
- Ray-cylinder intersection with parametric equations
- Lambertian diffuse lighting model
- Shadow ray calculations
- 3D vector transformations and normalizations


## Sample Scenes
The project includes various scene files demonstrating:

- Simple geometric objects with basic lighting
- Complex multi-object scenes
- Different camera angles and perspectives
- Various lighting configurations
- Shadow and reflection examples


## Grade: 100/100
