#ifndef __SIMPLEOS_H
#define __SIMPLEOS_H

#include <stddef.h>
#include <stdint.h>

#include <fsstat.h>
#include <syscallnum.h>
#include <fs.h>

// esp+4 to skip saved ebp, kernel will skip saved eip itself
#define _syscallbody(syscall_num) \
{\
    asm("mov eax, "#syscall_num"\n"\
    "add esp, 4\n"\
    "int 88\n"\
    "sub esp, 4\n"\
    );\
}

#define _syscall0(syscall_num, retval_type, name) \
retval_type name()\
_syscallbody(syscall_num)

#define _syscall1(syscall_num, retval_type, name, argtype1, arg1) \
retval_type name() \
_syscallbody(syscall_num)

#define _syscall2(syscall_num, retval_type, name, argtype1, arg1, argtype2, arg2) \
retval_type name(argtype1 arg1, argtype2 arg2) \
_syscallbody(syscall_num)

#define _syscall3(syscall_num, retval_type, name, argtype1, arg1, argtype2, arg2, argtype3, arg3) \
retval_type name(argtype1 arg1, argtype2 arg2, argtype3 arg3) \
_syscallbody(syscall_num)

#define _syscall4(syscall_num, retval_type, name, argtype1, arg1, argtype2, arg2, argtype3, arg3, argtype4, arg4) \
retval_type name(argtype1 arg1, argtype2 arg2, argtype3 arg3, argtype4 arg4) \
_syscallbody(syscall_num)

#define _syscall5(syscall_num, retval_type, name, argtype1, arg1, argtype2, arg2, argtype3, arg3, argtype4, arg4, argtype5, arg5) \
retval_type name(argtype1 arg1, argtype2 arg2, argtype3 arg3, argtype4 arg4, argtype5 arg5) \
_syscallbody(syscall_num)

#define _syscall6(syscall_num, retval_type, name, argtype1, arg1, argtype2, arg2, argtype3, arg3, argtype4, arg4, argtype5, arg5, argtype6, arg6) \
retval_type name(argtype1 arg1, argtype2 arg2, argtype3 arg3, argtype4 arg4, argtype5 arg5, argtype6 arg6) \
_syscallbody(syscall_num)


#endif