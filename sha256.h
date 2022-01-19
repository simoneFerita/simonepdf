#ifndef _SHA256_H_
#define _SHA256_H_

#include <stdint.h>

void sha256(const uint8_t *msg, const int msgLen, uint8_t *hash);
void sha256f(const uint8_t *msg, const int msgLen, uint8_t *hash);

#endif /** _SHA256_H_ */
