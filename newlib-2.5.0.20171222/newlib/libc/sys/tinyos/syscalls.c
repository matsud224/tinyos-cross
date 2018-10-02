/* note these headers are all provided by newlib - you don't need to provide them */
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/times.h>
#include <sys/errno.h>
#include <sys/time.h>
#include <stdio.h>


static inline long syscall0(long syscall) {
  long ret;
  asm volatile ("int $0x80" : "=a" (ret) : "a" (syscall) : "memory");
  return ret;
}

static inline long syscall1(long syscall, long arg1) {
  long ret;
  asm volatile ("int $0x80" : "=a" (ret) : "a" (syscall), "b" (arg1) : "memory");
  return ret;
}

static inline long syscall2(long syscall, long arg1, long arg2) {
  long ret;
  asm volatile ("int $0x80" : "=a" (ret) : "a" (syscall), "b"(arg1), "c"(arg2) : "memory");
  return ret;
}

static inline long syscall3(long syscall, long arg1, long arg2, long arg3) {
  long ret;
  asm volatile ("int $0x80" : "=a" (ret) : "a" (syscall), "b"(arg1), "c"(arg2),
   "d" (arg3) : "memory");
  return ret;
}

/*
static inline long syscall4(long syscall, long arg1, long arg2, long arg3, long arg4) {
  long ret;
  asm volatile ("int $0x80" : "=a" (ret) : "a" (syscall), "b"(arg1), "c"(arg2),
   "d" (arg3), "s" (arg4) : "memory");
  return ret;
}

static inline long syscall5(long syscall, long arg1, long arg2, long arg3, long arg4, long arg5) {
  long ret;
  asm volatile ("int $0x80" : "=a" (ret) : "a" (syscall), "b"(arg1), "c"(arg2),
   "d" (arg3), "s" (arg4), "D" (arg5) : "memory");
  return ret;
}
*/


void _exit(int exit_code) {
  return syscall1(0, exit_code);
}

int close(int file) {
  return syscall1(5, file);
}

int execve(char *name, char **argv, char **env) {
  return syscall3(6, name, argv, env);
}

int fork() {
  return syscall0(7);
}

int fstat(int file, struct stat *st) {
  return syscall2(9, file, st);
}

int getpid() {
  return syscall0(3);
}

int isatty(int file) {
  return syscall1(4, file);
}

int kill(int pid, int sig) {
  return syscall2(10, pid, sig);
}

int link(char *old, char *new) {
  return syscall2(11, old, new);
}

int lseek(int file, int ptr, int dir) {
  return syscall3(12, file, ptr, dir);
}

int open(const char *name, int flags, ...) {
  return syscall2(13, name, flags);
}


int read(int file, char *ptr, int len) {
  return syscall3(2, file, ptr, len);
}

caddr_t sbrk(int incr) {
  return (caddr_t)syscall1(14, incr);
}

int stat(const char *file, struct stat *st) {
  return syscall2(8, file, st);
}

clock_t times(struct tms *buf) {
  return -1;
}

int unlink(char *name) {
  return syscall1(16, name);
}

int wait(int *status) {
  return syscall1(17, status);
}

int write(int file, char *ptr, int len) {
  return syscall3(1, file, ptr, len);
}
int gettimeofday(struct timeval *p, void *z) {
  return -1;
}

int lstat(int file, struct stat *st) {
  return stat(file, st);
}

int chmod(const char *path, mode_t mode) {
  return 0;
}

int access(const char *path, int amode) {
  return 0;
}

mode_t umask(mode_t cmask) {
  return 0777;
}

int fcntl(int fildes, int cmd, ...) {
  return -1;
}

int utime(const char *path, const struct utimbuf *times) {
  return 0;
}

int chown(const char *path, uid_t owner, gid_t group) {
  return 0;
}

int rmdir(const char *path) {
  return unlink(path);
}

long sysconf(int name) {
  return -1;
}

char *getwd(char *buf) {
  return NULL;
}

int chdir(const char *path) {
  return syscall1(29, path);
}

int dup2(int oldfd, int newfd) {
  return syscall2(30, oldfd, newfd);
}

unsigned int sleep(unsigned int seconds) {
  return 0;
}

unsigned alarm(unsigned seconds) {
  return 0;
}

int mknod(const char *pathname, mode_t mode, dev_t dev) {
  return syscall3(31, pathname, mode, dev);
}

int mkdir(const char *path, mode_t mode) {
  return mknod(path, (mode & ~S_IFMT) | S_IFDIR, 0);
}

int pipe(int fildes[2]) {
  return -1;
}

int execvp(const char *file, char *const argv[]) {
  return execve(file, argv, NULL);
}
