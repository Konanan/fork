//
//  worker.h
//  forktest
//
//  Created by wangmeng on 2018/4/29.
//  Copyright © 2018年 cxin. All rights reserved.
//

#ifndef worker_h
#define worker_h

#include <stdio.h>

struct worker {
    int pid;
    char* name;
    char* jobs[1024];
    short job_index;
};

typedef struct worker worker;

//create new worker instance
worker*
worker_new(pid_t pid);

//work do job, talk and produce
void
worker_do_job(worker* w);

//malloc memery
void
worker_produce(worker* w);

//write log
void
worker_talking(worker* w);


#endif /* worker_h */
