TIS-INTERP
==========
```
$ tis-interpreter.sh --cc "-I. -I kremlib/dist/minimal" *.c
...
...
...
value] Analyzing a complete application starting at main
[value] Computing initial state
[value] Initial state computed
Hacl_Hash.c:2213:[value] warning: invalid pointer {{ &__malloc_Hacl_HMAC_compute_sha2_512_l390 + {128} }}:
                 the pointer must be valid even though the size is zero.
                 assert((void const *)rest is a valid pointer for reading)
                 stack: memcpy :: Hacl_Hash.c:2213 <-
                        Hacl_Hash_SHA2_update_last_512 :: Hacl_HMAC.c:432 <-
                        Hacl_HMAC_compute_sha2_512 :: main.c:18 <-
                        main
[value] done for function main
$
```
