#include <stdio.h>
#include <libxml/parser.h>

void error(char *s1, char* s2);
int main(void) {
  char *fileName = "test.xml";
  xmlDocPtr doc;
  xmlNodePtr rootNode;
  xmlChar *key;
  if ((doc = xmlParseFile(fileName)) == NULL) error("file %s cannot be opend", fileName);
  if ((rootNode = xmlDocGetRootElement(doc)) == NULL) error("file %s cannot access root", fileName);
  rootNode = rootNode -> children;
  while (rootNode != NULL) {
    if (!xmlStrcmp(rootNode -> name, (xmlChar*)"notes")){ 
      fprintf(stdout, "found node : %s\n", rootNode -> name);
      key = xmlNodeListGetString(doc, rootNode -> children, 1);
      fprintf(stdout, "val for node %s is %s\n", rootNode -> name, key);
      xmlFree(key);
    }
    rootNode = rootNode -> next;
  }
  xmlFreeDoc(doc);
}

void error(char *s1, char *s2) {
  fprintf(stderr, s1, s2);
  fprintf(stderr, "\n", NULL);
  exit(1);
}
