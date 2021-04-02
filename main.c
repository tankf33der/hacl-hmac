#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "Hacl_HMAC.h"
#include "Hacl_Hash.h"

#define ARRAY(name, size) \
    uint8_t name[size]; \
    for(size_t i = 0; i < size; i++) name[i] = i;

int main(void) {
    ARRAY(hash, 64);
    ARRAY(key , 64);
    ARRAY(in  , 64);

    Hacl_HMAC_compute_sha2_256(hash, key, 64, in, 0);

    // OK
    // Hacl_HMAC_compute_sha2_512(hash, key, 64, in, 1);

	return 0;
}
