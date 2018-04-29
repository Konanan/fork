//
//  master.c
//  forktest
//
//  Created by wangmeng on 2018/4/30.
//  Copyright © 2018年 cxin. All rights reserved.
//

#include "master.h"

//max worker count
const unsigned char WORKER_COUNT_MAX = 128;
//worker pid array, max 128
static pid_t worker_pids[WORKER_COUNT_MAX] = {};
//current worker index
static unsigned char worker_index = 0;


//create worker time, 5 seconds
const useconds_t TIME_CREATE_WORKER = 1000*1000*10;
//worker do job times
const useconds_t TIME_WORKER_JOB = 1000*1;

//worker pointer
worker *w;

void
master_do_all(){
    master_clean_logs();
    while(1){
        if(WORKER_COUNT_MAX <= worker_index){
            break;
        }
        master_fork_child();
        usleep(TIME_CREATE_WORKER);
    }
    master_kill_all_childs();
    master_clean_logs();
}

void
master_fork_child(){
    pid_t pid = fork();
    if(0 == pid){
        master_make_worker_do_job();
    }else if(0 < pid){
        master_do_something(pid);
    }
}

void
master_make_worker_do_job(){
    pid_t pid = getpid();
    w = worker_new(pid);
    while (1) {
        worker_do_job(w);
        usleep(TIME_WORKER_JOB);
    }
}

void
master_do_something(pid_t pid){
    worker_pids[worker_index] = pid;
    worker_index++;
}

void
master_kill_all_childs(void){
    for (int i=0; i<worker_index; i++) {
        kill(worker_pids[i],SIGTERM);
    }
}

void
master_clean_logs(void){
    system("rm -rf worker_*");
}
