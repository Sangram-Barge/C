#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>

void error(char *s1, char *s2);
static void crawl(xmlNodePtr node);

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
  crawl(node);
  xmlFreeDoc(doc);
}

void error(char *s1, char *s2) {
  fprintf(stderr, s1, s2);
  fprintf(stderr, "\n", NULL);
  exit(1);
}

static void crawl(xmlNodePtr node) {
  xmlNodePtr current;
  xmlChar *attribute;
  for (current = node; current; current = current -> next) {
    if (current -> type == XML_ELEMENT_NODE) {
      fprintf(stdout, "%s\n", current -> name);
      attribute = xmlGetProp(current, (xmlChar *)"type");
      if (attribute != NULL) fprintf(stdout, "attr : %s\n", attribute);
      xmlFree(attribute);
    }
    crawl(current -> children);
  }
}
