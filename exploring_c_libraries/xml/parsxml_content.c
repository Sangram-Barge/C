#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>

void error(char *s1, char *s2);

int main(void) {
  char *fileName = "test.xml";
  xmlDocPtr doc;
  xmlNodePtr node;
  doc = xmlParseFile(fileName);
  if (doc == NULL) error("unable to open file %s", fileName);
  if ((node = xmlDocGetRootElement(doc)) == NULL) {
    error("doc %s is empty", fileName);
    xmlFreeDoc(doc);
  }
  fprintf(stdout, "node name : %s \n", node -> name);
}

void error(char *s1, char *s2) {
  fprintf(stderr, s1, s2);
  fprintf(stderr, "\n", NULL);
  exit(1);
}
