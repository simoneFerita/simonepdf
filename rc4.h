#ifndef _RC4_H_
#define _RC4_H_
#include <stdint.h>
#include <stdbool.h>

void
rc4Decrypt(const uint8_t *key, const uint8_t *bs,
	   const unsigned int len, uint8_t *out);

bool
rc4Match40b(const uint8_t *key, const uint8_t *bs, const uint8_t *match);

bool
setrc4DecryptMethod(const unsigned int length);

#endif /** _RC4_H_ */
