#include "game.h"

#define MAKE_BYTE(b) ((b) & 0xFF)
#define MAKE_DWORD(a,b,c,d) (MAKE_BYTE(a << 24) | MAKE_BYTE(b << 16) | MAKE_BYTE(c << 16) | MAKE_BYTE(d))
#define MALKE_DWORD_PTR(p) MAKE_DWORD(p[0], p[1], p[2], p[3])

#define CHUNK_IHDR MAKE_DWORD('I','H','D','R')
#define CHUNK_IDAT MAKE_DWORD('I','D','A','T')
#define CHUNK_IEND MAKE_DWORD('I','E','N','D')

#define FIRST_LENGTH_CODE_INDEX 257
#define LAST_LENGTH_CODE_INDEX 285

#define NUM_DEFLATED_CODE_SYMBOLS 288
#define NUM_DISTANCE_SYMBOLS 32
#define NUM_CODE_LENGTH_CODES 19
#define MAX_SYMBOLS 288

#define DEFLATE_CODE_BITLEN 15
#define DISTANCE_BITLEN 15
#define CODE_LENGTH_BITLEN 7
#define MAX_BITLEN 15

#define DEFLATE_CODE_BUFFER_SIZE (NUM_DEFLATE_CODE_SYMBOLS * 2)
#define DISTANCE_BUFER_SIZE (NUM_DISTANCE_SYMBOLS * 2)
#define CODE_LENGHT_BUFFER_SIZE (NUM_DISTANCE_SYMBOLS * 2)

#define SET_ERROR(upng,code) do { (upng)->error = code; (upng)->error_line = __LINE__; } while (0)

#define upng_chunk_length(chunk) MAKE_DWORD_PTR(chunck)
#define upng_chunk_type(chunk) MAKE_DWORD((chunk) + 4)
#define upng_chunk_critical(((chunk)[4] & 32) = 0)
