#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static const char* help_string =
    "Usage:\n"
    "  pathend <path> | -\n"
    "  pathend -h | --help\n"
    "\n"
    "Options:\n"
    "  -h --help  show this help\n"
    "  -          use stdin for path";

void display_help()
{
    printf("%s\n", help_string);
}

char* process(char* str)
{
    char* begin = strrchr(str, '/');
    if (begin == NULL)
    {
        // no slashes
        return str;
    }
    else if (strlen(begin) < 2 && str[strlen(str) - 1] == '/')
    {
        // last slash is a trailing slash so let's find it manually due to lack of
        // strnrchr or similar

        // get rid of last character (trailing slash)
        str[strlen(str) - 1] = 0;

        // try again
        begin = strrchr(str, '/');
        if (begin == NULL)
            return str;
        return begin;
    }
    return begin + 1;
}

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        printf("error: missing argument <path>. use -h or --help for usage.\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
        {
            display_help();
            return EXIT_SUCCESS;
        }
        else if (strcmp(argv[i], "-") == 0)
        {
            if (argc > 2)
            {
                printf("too many arguments.\n");
                return EXIT_FAILURE;
            }
            if (!isatty(fileno(stdin)))
            {
                int  i = 0;
                char pipe[65536];
                while (-1 != (pipe[i++] = getchar()))
                    ;
                printf("%s\n", process(pipe));
                return EXIT_SUCCESS;
            }
            else
            {
                fprintf(stderr, "expected tty. non-tty stdin input is not supported.\n");
                return EXIT_FAILURE;
            }
        }
        else
        {
            // path needs to exist in argv now
            printf("%s\n", process(argv[1]));
        }
    }
}

