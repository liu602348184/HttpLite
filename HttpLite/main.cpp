//
//  main.cpp
//  HttpLite
//
//  Created by LiuYujie on 16/11/11.
//  Copyright © 2016年 LiuYujie. All rights reserved.
//

#include <iostream>
#include "http_server.hpp"

void sigfunc(int);
HttpServer *http;

int main(int argc, const char * argv[]) {
    signal(SIGINT, sigfunc);
    http = new HttpServer((char*)"0.0.0.0", 8002);
    http->start();
    
    return 0;
}

void sigfunc(int signo){
    if(signo == SIGINT){
        delete http;
        exit(signo);
    }
}