#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#define FRACTIONAL_BITS 14

// Convert an integer to a fixed-point representation
int convert_to_fp(int x) {
    return x * (1 << FRACTIONAL_BITS);
}

// Convert a fixed-point representation to the nearest integer
int convert_to_int(int x) {
    
    if (x >= 0) {
        return (x + (1 << (FRACTIONAL_BITS - 1))) >> FRACTIONAL_BITS;
    } else {
        return (x - (1 << (FRACTIONAL_BITS - 1))) >> FRACTIONAL_BITS;
    }
    
}

// Add two fixed-point numbers
int add_two_fp(int x, int y) {
    return x + y;
}

// Add an integer to a fixed-point number
int add_to_fp(int x, int y) {
    return x + (y << FRACTIONAL_BITS);
}

// Subtract one fixed-point number from another
int sub_two_fp(int x, int y) {
    return x - y;
}

// Subtract an integer from a fixed-point number
int sub_from_fp(int x, int y) {
    return x - (y << FRACTIONAL_BITS);
}

// Multiply two fixed-point numbers
int mul_two_fp(int x, int y) {
    return ((int64_t) x) * y >> FRACTIONAL_BITS;
}

// Multiply a fixed-point number by an integer
int mul_to_fp(int x, int n) {
    return x * n;
}

// Divide one fixed-point number by another
int div_two_fp(int x, int y) {
    return ((int64_t) x) << FRACTIONAL_BITS / y;
}

// Divide a fixed-point number by an integer
int div_to_fp(int x, int n) {
    return x / n;
}

#endif
