#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define SLEEP_TIME  5 

int        nap = SLEEP_TIME;

void handler(int sig) {
   nap /= 2;
   if (nap < 1) {
     nap = 1;
   }
}

int main() {
    time_t     now;
    struct tm *t;
    int        remains = 0;

    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    while (1) {
       if (remains == 0) {
         now = time(NULL);
         t = localtime(&now);
         printf("%02d:%02d:%02d beep!\n",
               t->tm_hour, t->tm_min, t->tm_sec);
         remains = sleep(nap);
       } else {
         remains = sleep(remains);
       }
    }
    return 0;
}
