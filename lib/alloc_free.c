#define ALLOCSIZE 10000 /* alloc buffer size */
#define NULLL 0 /* error return */

static char allocbuff[ALLOCSIZE]; /* alloc buffer of 1000 size */
static char *allocp = allocbuff; /* alloc pointer */

void freee(char *p);
char *alloc(int n);

char *alloc(int n) {
  if (allocp + n <= allocbuff + ALLOCSIZE) {
    allocp += n;
    return (allocp - n);
  }
  return NULLL;
}

void freee(char *p) {
  if (p >= allocbuff && p <= allocbuff + ALLOCSIZE) allocp = p;
}
