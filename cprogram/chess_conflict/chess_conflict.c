#include <stdlib.h>
#include <stdio.h>
#define HALF_BYTE_LENGTH 4
#define FULLMASK 255
#define LMASK ((FULLMASK) << HALF_BYTE_LENGTH)
#define RMASK ((FULLMASK) >> (HALF_BYTE_LENGTH))
#define GRIDW 3
#define LGET(b) (b >> HALF_BYTE_LENGTH)
#define RGET(b) (b & RMASK)
#define LSET(b,n)  (b = (((n) << HALF_BYTE_LENGTH) | (b & RMASK)))
#define RSET(b,n)  (b = ( (b & LMASK) | (n)))

int main()
{
	unsigned char b;
	for(LSET(b,1); LGET(b) <= GRIDW * GRIDW; LSET(b, LGET(b)+1))
			for(RSET(b,1); RGET(b) <= GRIDW * GRIDW; RSET(b, RGET(b)+1))
				if(LGET(b)%GRIDW != RGET(b)%GRIDW)
					printf("A=%d, B=%d\n",LGET(b), RGET(b));

	return 0;
}
