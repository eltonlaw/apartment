// NOTE: run `make tooling` if getting CCLS warnings
#include <stdio.h>
#include <ctype.h>
#include <http.h>
#include <stdlib.h>
#include <scan.h>
#include <string.h>

void print_help() {
    printf("Available commands: scan, http\n");
}

int main(int argc, char** argv) {
   if (argc == 1) {
       printf("No argument passed to command.\n");
       print_help();
       exit(0);
   }
   if (strcmp(argv[1], "scan") == 0) {
       scan_devices();
   }
   else if (strcmp(argv[1], "http") == 0) {
       HTTPResponse res = http_client(argv);
       printf("Response Code: %d\n", res.response_code);
   }
   else {
     printf("ERROR: <%s> is not a valid argument\n", argv[1]);
     print_help();
   }
   return(0);
}
