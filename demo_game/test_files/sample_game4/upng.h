#define UPNG_H
#define UPNG_H

/**
 * enum upng_error - an enumeration of variables
 * @UPNG_OK: A successful run or no error was encountered
 * @UPNG_MEMFAIL: Error arising due to failed memory allocarion
 * @UPNG_NOTFOUND: resource not found (file missing)
 * @UPNG_NOTPNG: image data does not have a png header
 * @UPNG_INVALPNG: image data is not a valid png image
 * @UPNG_UNSUPPORTED: critical png chunk type is not supported
 * @UPNG_UNINTERLACED: Image interlacing is unsupported
 * @UPNG_UNFORMATED: Image color is unsupported
 * @UPNG_EPARAM: Invalid parameter to method call
 */

typedef enum upng_error
{
	UPNG_OK =		0,
	UPNG_MEMFAIL =		1,
	UPNG_NOTFOUND		2,
	UPNG_NOTPNG		3,
	UPNG_INVALPNG		4,
	UPNG_UNSUPPORTED	5,
	UPNG_UNINTERLACED	6,
	UPNG_UNFORMATED		7,
	UPNG_EPARAM		8
} upng_error;

/**
 * enum upng_format: upng format
 * @UPNG_BADFORMAT: color is in a bad format
 * @UPNG_RGB8: RGB	 color, 8 bit format
 * @UPNG_RGB16: RGB color 16 bit version
 * @UPNG_LUMINANCE1: color intensity 1
 * @UPNG_LUMINANCE2: color itensity 2
 * @UPNG_LUMINANCE4: color itensity 4
 * @UPNG_LUMINANCE8: color intensity 8
 * @UPNG_LUMINANCE_ALHA1: Alpha itensity 1
 * @UPNG_LUMINANCE_ALPHA2: Alpha itensity 2
 * @UPNG_LUMINANCE_ALPHA4: Alpha itensity 4
 * @UPNG_LUMINANCE_ALPHA8: Alpha itensity 8
 */

typedef enum upng_format
{
	UPNG_BADFORMAT,
	UPNG_RGB8,
	UPNG_RGB16,
	UPNG_LUMINANCE1,
	UPNG_LUMINANCE2,
	UPNG_LUMINANCE4,
	UPNG_LUMINANCE8,
	UPNG_LUMINANCE_ALPHA1,
	UPNG_LUMINANCE_ALPHA2,
	UPNG_LUMINANCE_ALPHA4,
	UPNG_LUMINANCE_ALPHA8
} upng_format;

/*end if*/
