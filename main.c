#include <stdio.h>

// Russian Peasant Multiplication (Already efficient, just cleaned up)
unsigned int multiply(unsigned int a, unsigned int b) {
    unsigned int res = 0;
    while (b > 0) {
        if (b & 1) res += a;
        a <<= 1;
        b >>= 1;
    }
    return res;
}

// Optimized Binary Division (O(log N))
unsigned int divide(unsigned int dividend, unsigned int divisor) {
    if (divisor == 0) return 0; // Basic error handling
    
    unsigned int quotient = 0;
    unsigned int temp = 0;

    // Iterate from the most significant bit down to 0
    for (int i = 31; i >= 0; i--) {
        // Check if (temp + (divisor << i)) <= dividend safely
        // We use a long long or a check to prevent overflow during the shift
        if (((unsigned long long)divisor << i) <= dividend) {
            dividend -= (divisor << i);
            quotient |= (1U << i);
        }
    }
    return quotient;
}

// Linear Interpolation: y2 = y1 + (x2 - x1) * (y3 - y1) / (x3 - x1)
unsigned int Interpolate(unsigned int x1, unsigned int x2, unsigned int x3,
                         unsigned int y1, unsigned int y3) {
    unsigned int dx21 = x2 - x1;
    unsigned int dx31 = x3 - x1;
    unsigned int dy31 = (y3 > y1) ? (y3 - y1) : (y1 - y3);

    unsigned int num = multiply(dx21, dy31);
    unsigned int fraction = divide(num, dx31);

    // Handle both upward and downward slopes
    return (y3 > y1) ? (y1 + fraction) : (y1 - fraction);
}

int main() {
    unsigned int x1 = 100, x2 = 300, x3 = 500;
    unsigned int y1 = 31415, y3 = 161111;

    unsigned int result = Interpolate(x1, x2, x3, y1, y3);
    
    // Result should be exactly 96263
    printf("Interpolated value: %u\n", result);

    return 0;
}
