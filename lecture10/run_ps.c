#include <stdio.h>
#include <stdlib.h>

int main() {
    system("ps -opid,ppid,time,comm");
    return 0;
}
