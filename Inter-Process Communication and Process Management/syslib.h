#ifndef SYSLIB_H
#define SYSLIB_H

#define MAX_MBOXEN 16
#define MAX_MBOX_LENGTH 32
#define MAX_MESSAGE_LENGTH 128

int do_mbox_open(const char* name);
int do_mbox_close(int mbox);
int do_mbox_send(int mbox, void* buf, int size);
int do_mbox_recv(int mbox, void* buf, int size);
int do_mbox_is_full(int mbox);
char get_char();

#endif
