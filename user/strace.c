#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    if (argc <= 2) {
        fprintf(2, "usage: strace mask [COMMAND] [ARGS ...]\n");
        exit(1);
    }
    int mask = atoi(argv[1]);
    for (long long i = 0; i < 10000000000; i++)
        i += 0;
    trace(mask);
    char *newCmd[argc - 1];
    for (int i = 2; i < argc; i++)
        newCmd[i - 2] = argv[i];
    newCmd[argc - 2] = 0;
    exec(newCmd[0], newCmd);
    fprintf(2, "exec %s failed\n", newCmd[0]);
    exit(1);
}
