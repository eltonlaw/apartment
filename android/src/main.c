#include <stdio.h>
#include <stdlib.h>
#include <scan.h>
#include <string.h>

void print_help() {
    printf("Available commands: scan\n");
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
   else {
     printf("ERROR: %s is not a valid argument\n", argv[1]);
     print_help();
   }
   return(0);
}
