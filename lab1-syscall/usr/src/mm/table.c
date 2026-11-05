    /* do_sigaction,           /* 71 = sigaction   */
    /* do_sigsuspend,          /* 72 = sigsuspend  */
    /* do_sigpending,          /* 73 = sigpending  */
    /* do_sigprocmask,         /* 74 = sigprocmask */
    /* do_sigreturn,           /* 75 = sigreturn   */
    /* do_reboot,              /* 76 = reboot  */
    /* do_svrctl,              /* 77 = svrctl  */
    /* do_subtree_width,       /* 78 = SUBTREE_WIDTH   */

// so we need to add our new syscall to MM's call_vec array
// call_vec[] contains pointers to methods that might be called when syscall is called