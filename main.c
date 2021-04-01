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

//@ ensures \result == 0;
int hmac(void) {
    ARRAY(hash1, 64);
    ARRAY(hash2, 64);
    ARRAY(key , 64);
    ARRAY(in  , 64);
    int status = 0;

	/*
    Hacl_Hash.c:5628:[value] warning: invalid pointer (void const *)rest.
                     stack: memcpy :: Hacl_Hash.c:5628 <-
                            Hacl_Hash_SHA2_update_last_512 :: Hacl_HMAC.c:432 <-
                            Hacl_HMAC_compute_sha2_512 :: main.c:57 <-
                            hmac
	*/                       
	//         i = 0 generates error ^^^^^ while reading from NULL.
    for(size_t i = 0; i < 64; i++) {
    	hash1[1] = 77;
        crypto_hmac_sha512(hash1, key, i, in, i);
        Hacl_HMAC_compute_sha2_512(hash2, key, i, in, i);
        status |= crypto_verify64(hash1, hash2);
    }
    return status;
}


int main(void) {
	int status = 0;
	
	status |= hmac();
	printf("%s\n", status != 0 ? "FAIL" : "OK");	
	return status;
}
