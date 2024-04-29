#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    FILE *output_file = fopen("non-ascii.log", "w");
    if (output_file == NULL) {
        printf("Error opening file non-ascii.log\n");
        fclose(input_file);
        return 1;
    }

    setlocale(LC_ALL, "");  // Set locale for multi-byte character handling

    wchar_t wc;
    char c;
    int foundAny = 0;

    while ((wc = fgetwc(input_file)) != WEOF) {
        c = (char)wc;  // Convert wchar_t to char

        if (wc != (wchar_t)c) {  // Check if wchar_t and char values are different
            fwprintf(output_file, L"%lc\n", wc);
            wprintf(L"Non-ASCII character: %lc\n", wc);
            foundAny = 1;
        }
    }

    fclose(input_file);
    fclose(output_file);

    return foundAny; // Return 0 if no non-ASCII characters found, 1 otherwise
}