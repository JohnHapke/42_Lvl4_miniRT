Info: https://keepachangelog.com/en/1.0.0/


/* PLEASE ADD THE NEW VERSION ALWAYS ABOVE TO SEE ALWAYS THE NEWEST CHANGES */

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