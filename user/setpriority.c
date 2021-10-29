#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(2, "usage: setpriority newPriority pid\n");
        exit(1);
    }
    int newPriority = atoi(argv[1]);
    int pid = atoi(argv[2]);

    int ret = set_priority(newPriority, pid);
    if (ret < 0) {
        fprintf(2, "set_priority: Process not found\n");
        exit(1);
    }
    printf("Priority of pid: [%d] successfully changed from %d to %d\n", pid, ret, newPriority);
    exit(0);
}
