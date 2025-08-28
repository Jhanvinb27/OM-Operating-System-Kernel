#include "syslib.h"
#include "scheduler.h"
#include "queue.h"

int do_mbox_open(const char* name) { return 0; }
int do_mbox_close(int mbox) { return 0; }
int do_mbox_send(int mbox, void* buf, int size) { return 0; }
int do_mbox_recv(int mbox, void* buf, int size) { return 0; }
int do_mbox_is_full(int mbox) { return 0; }
char get_char() { return 0; }
