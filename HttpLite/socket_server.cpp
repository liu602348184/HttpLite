//
//  socket_server.cpp
//  HttpLite
//
//  Created by LiuYujie on 16/11/11.
//  Copyright © 2016年 LiuYujie. All rights reserved.
//

#include "socket_server.hpp"
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h>
#include <csignal>

#define BUFF_SIZE 1024 * 1024

SocketServer::SocketServer(char *addr, int port){
    this->serv_addr = (struct sockaddr_in*) malloc(sizeof(struct sockaddr_in));
    bzero(this->serv_addr, sizeof(struct sockaddr_in));
    this->serv_addr->sin_family = AF_INET;
    this->serv_addr->sin_addr.s_addr = inet_addr(addr);
    this->serv_addr->sin_port = htons(port);

}

bool SocketServer::listen(pProcess func){
    this->socketfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    bool success = bind(this->socketfd, (struct sockaddr*)this->serv_addr, sizeof(struct sockaddr_in));
    ::listen(this->socketfd, 40);
    //std:: cout << test << "\n";
    socklen_t len = sizeof(this->serv_addr);
    int result;
    char buff[BUFF_SIZE];
    
    while(true){
         //accept(serv_sock, this->serv_addr, &len);
        //accept(<#int#>, struct sockaddr *, <#socklen_t *#>)
        result = accept(socketfd, (struct sockaddr*)this->serv_addr, &len);
        
        if(result <= 0){
            return false;
        }
        
        read(result, buff, BUFF_SIZE);
        func(buff);
        bzero(buff, BUFF_SIZE);
    }
    
    
    return success;
}

SocketServer::~SocketServer(){
    //std::cout << "parent...";
    free(this->serv_addr);
    close(this->socketfd);
}

