FORWARD _PROTOTYPE( int is_parent_in_subqueue, (int begin, int end, int queue[], int p_idx) );

/* Private function that checks whether parent id is present in queue */
PRIVATE int is_parent_in_subqueue(begin, end, queue, p_idx)
int begin;
int end;
int queue[];
int p_idx;
{
    while (begin < end) {
        if (queue[begin] == p_idx) {
            return 1;
        }
        begin++;
    }
    return 0;
}

PUBLIC int do_subtree_width()
{
    int start_pid = mm_in.m1_i1;
    int parent_idx = -1;
    int root_idx = -1;
    int queue[NR_PROCS];
    int begin = 0;
    int level_end = 1;
    int end = 1;
    int max_len = 1;
    int i;

    /* Invalid argument */
    if (start_pid <= 0){
        return (EINVAL);
    }

    /* find root id based on it's PID */
    for (i = 0; i < NR_PROCS; i++) {
        if ((mproc[i].mp_flags & IN_USE) && (mproc[i].mp_pid == start_pid)) {
            root_idx = i;
            break;
        }
    }

    /* No Such Process with given PID */
    if (root_idx == -1) {
        return (ESRCH);
    }

    queue[0] = root_idx;

    while (begin < end) {
        level_end = end;    /* level_end = the end of prev level */
        for (i = 0; i < NR_PROCS; i++) {
            /* 
               add proces index to queue if:
               1. it is still in use - slot is not empty 
               2. it's index != parent's index(for MM)
               3. it's parent is present in queue
            */
            parent_idx = mproc[i].mp_parent;
            if ((mproc[i].mp_flags & IN_USE) &&
                (i != parent_idx) &&
                (is_parent_in_subqueue(begin, level_end, queue, parent_idx) == 1)) {
                /* 
                   defence from cycles 
                   end can reach NR_PROCS 
                   if A is B's parent, and B is A's parent
                */
                if(end >= NR_PROCS) { break; }
                queue[end] = i;
                end++;
            }
        }
        if (end - level_end > max_len) {
            max_len = end - level_end;
        }
        begin = level_end;
    }

    return (max_len);
}