#include <stdio.h>
#include <time.h>
#include <unistd.h>

const char *digits[10][5] = {
    {" ███ ", "█   █", "█   █", "█   █", " ███ "}, // 0
    {"  █  ", " ██  ", "  █  ", "  █  ", " ███ "}, // 1
    {" ███ ", "    █", " ███ ", "█    ", "█████"}, // 2
    {"████ ", "    █", " ███ ", "    █", "████ "}, // 3
    {"█  █ ", "█  █ ", "█████", "   █ ", "   █ "}, // 4
    {"█████", "█    ", "████ ", "    █", "████ "}, // 5
    {" ███ ", "█    ", "████ ", "█   █", " ███ "}, // 6
    {"█████", "    █", "   █ ", "  █  ", "  █  "}, // 7
    {" ███ ", "█   █", " ███ ", "█   █", " ███ "}, // 8
    {" ███ ", "█   █", " ████", "    █", " ███ "}  // 9
};

void print_clock(int h, int m, int s)
{
    int d[16] = {
        h / 10, h % 10,
        m / 10, m % 10,
        s / 10, s % 10
    };

    for (int row = 0; row < 5; row++) {
        for (int i = 0; i < 6; i++) {
            printf("%s", digits[d[i]][row]);
            if (i == 1 || i == 3)
                printf("    %s  ", (s % 2) ? ":" : " ");
            else
                printf("  ");
        }
        putchar('\n');
    }
}

int main(void)
{
    while (1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        printf("\033[2J\033[H");
        print_clock(t->tm_hour, t->tm_min, t-> tm_sec);
        
        fflush(stdout);
        sleep(1);
    }
    return 0;
}
