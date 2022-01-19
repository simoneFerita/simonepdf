#ifndef _MD5_H_
#define _MD5_H_
#include <stdint.h>

void 
md5(const uint8_t *msg, const unsigned int msgLen, uint8_t *digest);

/** init function for md5_50 which chooses a md5_50 optimised for msgLen, 
    if one is available */
void
md5_50_init(const unsigned int msgLen);

/** md5_50 is basically for(i=0; i<50; i++) { md5(msg, msgLen, msg); } */
void
md5_50(uint8_t *msg, const unsigned int msgLen);

#endif /** _MD5_H_ */
