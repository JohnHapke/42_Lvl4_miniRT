Info: https://keepachangelog.com/en/1.0.0/


/* PLEASE ADD THE NEW VERSION ALWAYS ABOVE TO SEE ALWAYS THE NEWEST CHANGES */

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