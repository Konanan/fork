//
//  worker.c
//  forktest
//
//  Created by wangmeng on 2018/4/29.
//  Copyright © 2018年 cxin. All rights reserved.
//

#include "worker.h"
#include <string.h>
#include <stdlib.h>


worker*
worker_new(pid_t pid){
    worker* w = (worker*)malloc(sizeof(worker));
    
    w->name = (char*)malloc(sizeof(char)*128);
    memset(w->name,0,128);
    sprintf(w->name, "worker_%d",pid);
    
    w->job_index = 0;
    w->pid = pid;
    return w;
}

void
worker_do_job(worker* w){
    worker_talking(w);
    worker_produce(w);
}

void
worker_produce(worker* w){
    if(1024 > w->job_index){
        w->jobs[w->job_index] = malloc(sizeof(char)*128);
        w->job_index++;
    }
}

void
worker_talking(worker* w){
    char syslog[128];
    sprintf(syslog, "echo worker pid:%d > worker_%d.log" ,w->pid, w->pid);
    system(syslog);
}

