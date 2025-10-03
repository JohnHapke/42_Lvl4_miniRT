Info: https://keepachangelog.com/en/1.0.0/


/* PLEASE ADD THE NEW VERSION ALWAYS ABOVE TO SEE ALWAYS THE NEWEST CHANGES */

# V01.20

## UNRELEASED
- shading: shading does not currently check for object intersections
- pressing ESC must close the window and quit the program cleanly
- norm compliance is still missing in most of the project:
	changing variables names in parsing -> can not be capital letters (in fcts and color struct)
	debug statements and comments need removal
	function length reduction
- rename parsing function and delete "ft_"
- cyilinder and plane intersection implementation

## FIXED
- parsing/syntax_controler.c -> fixed a minor bug in the parsing that wouldn´t allow negative numbers and a minor bug which allowed wrong object name

# V01.19

## ADDED
- rudimentary intersection function templates for cylinder and plane

## CHANGED
- several files -> Made mlx image be a part of t_rt_data to ensure only one image is used and reused
- added object color to t_hitinfo to generalize the use of calculate_color
- made the calculate_color hitinfo param be a const pointer to optimize

## NOTE
- plane is not properly recognized by the parser and seemingly always spits an error

# V01.18

## CHANGED
- objects/shading.c -> t_color in header changed to double and final_color cast to int for more accuracy and possible bit shifting

# V01.17

## ADDED
- ray_tracer -> intersect_test() this fct goes thorugh the intersect fct_ptr and determines the best t value and calls the calculate_color()-fct to finallz return the color for the pixel
- objects -> folder for the object and color fcts
- sphere_intersection.c -> calculates all necessary values for the intersection and determines/returns best t value for spheres
- shading.c -> calculates the color (ambient/diffuse/final) -> feature to control if there is an object between t and the light is not implemented yet

## CHANGED
- minirt.h -> t_ray color commented and t_hitinfo *bj commented
- main.c / ray_tracer.c -> width & height adapted to 800 & 600
## FIXED
- parsing/light_camera.c -> camera.right and camera.up were in the wrong order and variables were changed -> is fixed and coordinate system is now working correctly

# V01.16

## ADDED
- ray_tracer.c	-> added a generate_ray() function to generate a ray that shoots out of the camera at a correctl angle
- minirt.h		-> added t_hitinfo to be used as return type for intersection functions

# V01.15

## ADDED
- in header t_obj structure as a list added and an enum to define the object type within each t_obj node
- parsing/utils.c added with function to add back the object nodes into the t_obj list

## CHANGED
- parsing output centralized in parsing/utils.c to show that every t_obj *node is correctly allocated and that the list works
- t_rt_data changed -> pointer to object-structures removed and t_obj *obj added to safe all objects in one list, where the intersection fct is included as a fctptr

## FIXED
- in parsing/objects.c & parsing/light_camera.c normalized vector control from range 0.0 - 1.0 fixed to -1.0 - 1.0 as specified in the subject 

## REMOVED
- debug function for parsing in main removed
- debug lines in objects.c removed

# V01.14

## ADDED
- ray_tracer.c	-> added file and implemented basic mlx hook function to create a gradient across the screen
- main.c		-> added a couple lines to open an mlx window

## REMOVED
- minirt.h	-> removed several unnecessary lines including an unused macro

# V01.13

## ADDED
- vector_math.c -> added a multitude of tested and necessary vector math operations
- minirt.h		-> added all new vector math functions and added up and right vectors to t_camera
- Makefile		-> added the new vector_math.c file

## CHANGED
- light_camera.c	-> added normalization to the direction vector of camera, also added up and right vector logic and init
- objects.c			-> added normalization to plane and cylinder. same as above

# V01.12

## ADDED
- vector_math.c -> added several simple, untested vector math functions
- main.c		-> added a debug print function "temp_print_parsing_data(t_rt_data *data)" for later use
- minirt.h		-> added EPSILON macro for more robust float operations

# V01.11

-> parsing should be fully functional now. Tested without minilibx to see if error handling and memory handling is working correctly. With minilibx ocurre a lot of errors but it seems that all of them come from the minilibx as also there are no hooks implemented and no further lib handling.
## ADDED
- ft_control_digits() added to control the line after the identifier

## CHANGED
- control and convertion changed into syntax_controler.c and converter.c -> code improvement done to minimize lines but still space for potential
- utils.c deleted

## FIXED
- ft_parsing_error_handler() changed and added "line" as variable to free it centralized in ft_free_parsing()
- ft_free_parsing improved to minimize errors and centralize freeing
- fd closed and call for gnl(-1) to free buffer -> maybe there is a better way but this works at least
- in main() t_rt_data data -> changed to *data and initialized by ft_calloc() to control values of pointers in data structure
- edge cases added in ft_atof because it lost memory before

# V01.10

## ADDED
- sphere, plane and cylinder are now coded in the parsing part and functional
- ft_free_parsing added in error_handler.c but not fully implemented
- control statements added when necessary after atof and atoi calls

## CHANGED
- all normalized vectors are called norm_vec -> changes made in the header
- structure added in header for colors, to reuse code instead of using in every structure 3x int for R,G,B

## FIXED
- handling of negative values

## SECURITY
- lose of 1 block in every atoi and atof call
- syntax control not robust enough -> will be improved in next versions

# V01.09

## ADDED
- parsing: function for parsing light, camera and amb_light are coded and tested so far

## FIXED
- ft_atof function fixed, bug was in handling the input as an integer without point but which has to be safed as an double
- ft_export_and_convert fct is now for atof and for atoi but is pretty much the same -> IMPROVEMENT NEEDED but functional so far

# V01.08

## ADDED
- parsing/utils -> coded ft_atof() to change a string into a float/double and implemented a function to check if the string is correct
- added a function double ft_export_and_convert(const char *line, int *i) to use for all double input values per line -> can be used for most of the input values

## FIXED
- Makefile -> gnl c-files got deleted by fclean
- Makefile -> to delete the obj/ folder
- fixed in parsing static int ft_control_type_identifier(char *file) -> debug and test cases are working now; ready for test by @Igor

## CHANGED
- parsing -> change of file names, as it makes no sense to have files in parsing/ and call them parsing_something.c 

# V01.07

## ADDED
- src/parsing/ -> error_handler.c , light_camera.c , parsing_handler.c , parsing_object.c
	- parsing initiated but not functional; error message comes at every point
- structures added for mandatory project part
- test.rt added with data from subject to test the progress

## CHANGED
- MLX42 header added in minirt.h
- changed headers from paths to just name (from "../../...h to ...h)
- Makefile slightly changed in handling of object directories and subdirectories, because it was not functional before