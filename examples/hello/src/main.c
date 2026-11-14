/* A DOS program built by mcpp: its arguments, a file written and read back, and its status. */
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    int failures = 0;
    printf("hello from dos: %d arguments\n", argc);
    if (argc < 2 || strcmp(argv[argc - 1], "two") != 0) { printf("  FAIL the arguments arrive\n"); ++failures; }
    FILE* f = fopen("NOTE.TXT", "w");
    if (!f) { printf("  FAIL a file is created\n"); return 1; }
    fputs("kept", f);
    fclose(f);
    char back[8] = {0};
    f = fopen("NOTE.TXT", "r");
    if (!f || !fgets(back, sizeof back, f) || strcmp(back, "kept") != 0) { printf("  FAIL a file is read back\n"); ++failures; }
    if (f) fclose(f);
    remove("NOTE.TXT");
    puts(failures ? "FAILED" : "all held");
    return failures ? 1 : 42;
}
