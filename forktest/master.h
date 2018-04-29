//
//  master.h
//  forktest
//
//  Created by wangmeng on 2018/4/30.
//  Copyright © 2018年 cxin. All rights reserved.
//

#ifndef master_h
#define master_h

#include "commond.h"
#include "worker.h"

//main loop
void
master_do_all(void);

//worker deal with job
void
worker_do_something(void);

//master deal with job
void
master_do_something(pid_t pid);

//fork child process
void
master_fork_child(void);

//master kill all child process
void
master_kill_all_childs(void);

//clean logs ,like work_1109.log
void
master_clean_logs(void);

//make worker do working
void
master_make_worker_do_job(void);


#endif /* master_h */
