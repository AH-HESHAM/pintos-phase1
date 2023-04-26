#ifndef FIXED_POINT_H
#define FIXED_POINT_H
#include <stdint.h>

#define FRACTIONAL_BITS 14
typedef int fixed_t;

// Convert an integer to a fixed-point representation
#define convert_to_fp(x) (x * (1 << FRACTIONAL_BITS))

// Take integer part of a floating number
#define takeInt(x) (x >> FRACTIONAL_BITS)

// Convert a fixed-point representation to the nearest integer

#define convert_to_int(x) (x >= 0 ? ((x + (1 << (FRACTIONAL_BITS - 1))) >> FRACTIONAL_BITS) : ((x - (1 << (FRACTIONAL_BITS - 1))) >> FRACTIONAL_BITS))
				

// Add two fixed-point numbers
#define add_two_fp( x,  y) (x + y)

// Add an integer to a fixed-point number
#define add_to_fp( x,  y) (x + (y << FRACTIONAL_BITS))


// Subtract one fixed-point number from another
#define sub_two_fp( x,  y) (x-y)

// Subtract an integer from a fixed-point number
#define sub_from_fp( x,  y) (x - (y << FRACTIONAL_BITS))


// Multiply two fixed-point numbers
#define mul_two_fp( x,  y) ((fixed_t)(((int64_t) x) * y >> FRACTIONAL_BITS))

// Multiply a fixed-point number by an integer
#define mul_to_fp( x,  n) (x * n)


// Divide one fixed-point number by another
#define div_two_fp( x,  y) ((fixed_t)((((int64_t) x) << FRACTIONAL_BITS) / y))


// Divide a fixed-point number by an integer
#define div_to_fp( x,  n) (x/n)

#endif
