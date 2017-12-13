#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

#define SLEEP_TIME   5

static char *G_signames[] = {"NONE",
                             "SIGHUP",
                             "SIGINT",
                             "SIGQUIT",
                             "SIGILL",
                             "SIGTRAP",
                             "SIGABRT",
                             "SIGEMT",
                             "SIGFPE",
                             "SIGKILL",
                             "SIGBUS",
                             "SIGSEGV",
                             "SIGSYS",
                             "SIGPIPE",
                             "SIGALRM",
                             "SIGTERM",
                             "SIGURG",
                             "SIGSTOP",
                             "SIGTSTP",
                             "SIGCONT",
                             "SIGCHLD",
                             "SIGTTIN",
                             "SIGTTOU",
                             "SIGIO",
                             "SIGXCPU",
                             "SIGXFSZ",
                             "SIGVTALRM",
                             "SIGPROF",
                             "SIGWINCH",
                             "SIGINFO",
                             "SIGUSR1",
                             "SIGUSR2",
                             NULL};

char       whoami[50];

void handler(int sig) {
    if (sig > 0 && sig < 32) {
       printf("%d has received signal %d (%s)\n",
               getpid(),
               sig, G_signames[sig]);
    } else {
       printf("%d Invalid signal %d\n",
              getpid(),
              sig);
    }
}

void handler2(int sig) {
  pid_t pid;
  if ((pid = fork()) == -1) {
    perror("fork()");
    exit(1);
  }
  if (pid == 0) {
    sprintf(whoami, "child (%d)", getpid());
  }
}

int main() {
    int        nap = SLEEP_TIME;
    time_t     now;
    struct tm *t;
    int        remains = 0;
    int        sig;
    pid_t      pid;

    for (sig = 1; sig < 32; sig++) {
      (void)signal(sig, handler);
    }
    (void)signal(SIGCHLD, handler2);
    sprintf(whoami, "parent (%d)", getpid());
    if ((pid = fork()) == -1) {
       perror("fork()");
       exit(1);
    }
    if (pid == 0) {
      sprintf(whoami, "child (%d)", getpid());
    }
    while (1) {
       if (remains == 0) {
          now = time(NULL);
          t = localtime(&now);
          printf("%s %02d:%02d:%02d beep!\n",
                  whoami,
                  t->tm_hour, t->tm_min, t->tm_sec);
          remains = sleep(nap);
        } else {
          remains = sleep(remains - 1);
        }
    }
    return 0;
}
