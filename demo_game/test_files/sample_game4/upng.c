#include "game.h"

typedef enum upng_state {
	UPNG_ERROR		= -1,
	UPNG_DECODED		= 0,
	UPNG_HEADER		= 1,
	UPNG_NEW		= 2
} upng_state;

typedef enum upng_color {
	UPNG_LUM	= 0,
	UPNG_RGB	= 2,
	UPNG_LUMA	= 4,
	UPNG_RGBA	= 6
} upng_color;

typedef struct upng_source
{
	const unsigned char	*buffer;
	unsigned long 		size;
	char			ownning;
} upng_source;

struct upng_t
{
	unsigned	width;
	unsigned	height;

	upng_color	color_type;
	unsigned	color_depth;
	upng_format	format;

	unsigned char	*buffer;
	unsigned long	size;

	upng_error	error;
	unsigned	error_line;

	upng_state	state;
	source_source	source;
}


