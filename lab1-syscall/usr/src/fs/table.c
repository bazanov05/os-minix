    /* no_sys,           /* 71 = sigaction   */
    /* no_sys,          /* 72 = sigsuspend  */
    /* no_sys,          /* 73 = sigpending  */
    /* no_sys,         /* 74 = sigprocmask */
    /* no_sys,           /* 75 = sigreturn   */
    /* no_sys,              /* 76 = reboot  */
    /* do_svrctl,              /* 77 = svrctl  */
    /* no_sys,       /* 78 = SUBTREE_WIDTH   */

// we need to duplicate the call_vec[] in FS but here our new syscall is no_sys
// FS is not responsible for our new syscall that is why is has no pointer to function for it
// arrays' sizes in FS and MM should be similar to dummy check :
//      extern int dummy[sizeof(call_vec) == NCALLS * sizeof(call_vec[0]) ? 1 : -1];
// which checks whether out call_vec[] have the same amount of elements as NCALLS