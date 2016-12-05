
//
//  request_process.cpp
//  HttpLite
//
//  Created by LiuYujie on 16/11/30.
//  Copyright © 2016年 LiuYujie. All rights reserved.
//

#include "request_process.hpp"
#include <string.h>
#include <iostream>

RequestProcess::RequestProcess(char *requestHeader){
    const char *d = "\n";
    char *c = strtok(requestHeader, d);
    this->p[0] = (char*) malloc(strlen(c));
    memcpy(this->p[0], c, strlen(c));
    
    for(int i = 1; i < HSIZE; i++){
        c = strtok(NULL, d);
        
        if(c == NULL){
            this->p[i] = NULL;
            break;
        }
        
        this->p[i] = (char*) malloc(strlen(c));
        memcpy(this->p[i], c, strlen(c));
        //std::cout << p << std::endl;
        
    }
}

char* RequestProcess::getResource(){
    return this->p[0];
}

char** RequestProcess::split(char *str, const char *op){
    size_t len = strlen(str);
    char **pstr = (char**) malloc(len * sizeof(char*));
    char *c = strtok(str, op);
    pstr[0] = (char*) malloc(strlen(c) + 1);
    memset(pstr[0], '\0', strlen(c) + 1);
    memcpy(pstr[0], c, strlen(c));
    //std::cout << pstr[0] << std::endl;
    int i = 1;
    
    while(true){
        c = strtok(NULL, op);
        
        //std::cout << c << std::endl;
        if(c == NULL){
            break;
        }
        
        //pstr++;
        pstr[i] = (char*) malloc(strlen(c) + 1);
        memset(pstr[i], '\0', strlen(c) + 1);
        memcpy(pstr[i], c, strlen(c));
        //std::cout << pstr[i] << std::endl;
        i++;
    }
    //exit(0);
    return pstr;
}

char* RequestProcess::getSessionId(){
    return "";
}

RequestProcess::~RequestProcess(){
    for(int i = 0; i < HSIZE; i++){
        delete[] *this->p;
    }
}