#include <stdio.h>
#include <curl/curl.h>

int main(void) {
  printf("curl version : %s\n", LIBCURL_VERSION);
  return 0;
}
