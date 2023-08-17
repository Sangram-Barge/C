#include <stdio.h>
#include <libxml/xmlversion.h>

int main(void) {
  fprintf(stdout, "xml lib version %d \n", LIBXML_VERSION);
  return 0;
}
