#include <stdio.h>
#include <libxml/parser.h>

int main(void) {
  const char filename[] = "test.xml";
  xmlDocPtr doc = xmlParseFile(filename);
  if (doc == NULL) {
    fprintf(stdout, "cannot open file %s\n", filename);
    return 1; 
  } if (doc -> version != NULL && doc -> encoding != NULL) 
    fprintf(stdout, "%s file \nencoding is : %s \nversion is : %s\n",
            filename, 
            doc -> encoding, 
            doc -> version);
    else {
      fprintf(stdout, "file %s has incorrect version or encoding", filename);
      return 1;
    }
  xmlFree(doc);
}
