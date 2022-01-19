#ifndef _PDFPASSWORDS_H_
#define _PDFPASSWORDS_H_

#include <stdio.h>
#include "common.h"


void
initPasswords(const passwordMethod pm, FILE *file, const char *wl,
	      const char *cs, const unsigned int minPw,
	      const unsigned int maxPw);

bool
nextPassword(void);

unsigned int
setPassword(uint8_t *outbuf);

bool
pw_loadState(FILE *file, char **wl);

void
pw_saveState(FILE *file);

#endif /** _PDFPASSWORDS_H_ */
