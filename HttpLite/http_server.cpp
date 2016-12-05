//
//  http_server.cpp
//  HttpLite
//
//  Created by LiuYujie on 16/11/16.
//  Copyright © 2016年 LiuYujie. All rights reserved.
//

#include "http_server.hpp"
#include <string.h>
#include <iostream>
#include "request_process.hpp"

HttpServer::HttpServer(char *addr, int port) : SocketServer(addr, port){

}

void HttpServer::start(){
    this->listen(dataProcess);
}

void HttpServer::process(char *data){
    
}

void dataProcess(char *data){
    if(strlen(data) == 0){
        return;
    }
    
    RequestProcess *rp = new RequestProcess(data);
    char *resource = rp->getResource();
    std::cout << resource << std::endl;
    
    char **result = rp->split(resource, " ");
    
    for(int i = 0; i < 3; i++){
        std::cout << result[i] << std::endl;
    }
    //std::cout << result[1] <<  "TEST" << std::endl;
    //std::cout << sizeof(result) << "test" << std::endl;
}

HttpServer::~HttpServer() {
    //std::cout << "die......\n";
}