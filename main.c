#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("Usage: filepreview <filename.ext>\n");
        return 1;
    }

    FILE* fin = fopen(argv[1], "r");

    if (!fin) {
        printf("Could not find the file!\n");
        return 1;
    }

    int ch = getc(fin), ln = 1, width;
    double ttll = 1, lnlen;

    while (ch != EOF) {
        if (ch == '\n') {
            ++ttll;
        }
        ch = getc(fin);
    }
    lnlen = log10(ttll);
    width = (int)lnlen + 1;

    rewind(fin);

    ch = getc(fin);
    printf("%*d. ", width, ln);

    while (ch != EOF) {
        if (ch == '\n') {
            printf("\n%*d. ", width, ++ln);
        } else {
            printf("%c", ch);
        }
        ch = getc(fin);
    }
    fclose(fin);
    printf("\n");

    return 0;
}
