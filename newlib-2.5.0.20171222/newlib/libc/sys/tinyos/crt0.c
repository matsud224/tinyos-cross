#include <fcntl.h>

extern void exit(int code);
extern int main (int argc, char **argv, char **envp);

void _start(int args) {
  int *top = &args-1;
  int argc = *top;
  char **argv = (char **)(top + 1);
  char **envp = (char **)(argv + argc + 1);
  int ex = main(argc, argv, envp);
  exit(ex);
}
