#ifndef _PDFCRACK_H_
#define _PDFCRACK_H_

#include <stdio.h>
#include "common.h"

bool
initPDFCrack(const EncData *e, const uint8_t *upw, const bool user,
	     const char *wl, const passwordMethod pm, FILE *file,
	     const char *cs, const unsigned int minPw,
	     const unsigned int maxPw, const bool perm);

bool
loadState(FILE *file, EncData *e, char **wl, bool *user);

void
saveState(FILE *file);

void
cleanPDFCrack(void);

bool
runCrackRev2(void);

bool
runCrackRev2_o(void);

bool
runCrackRev2_of(void);

bool
runCrackRev3(void);

bool
runCrackRev3_o(void);

bool
runCrackRev3_of(void);

bool
runCrackRev5_o(void);

bool
runCrackRev5(void);

void
runCrack(void);

bool
printProgress(void);

unsigned int
getNrProcessed(void);


#endif /** _PDFCRACK_H_ */

