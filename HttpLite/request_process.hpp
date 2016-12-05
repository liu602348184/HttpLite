//
//  request_process.hpp
//  HttpLite
//
//  Created by LiuYujie on 16/11/30.
//  Copyright © 2016年 LiuYujie. All rights reserved.
//

#ifndef request_process_hpp
#define request_process_hpp

#include <stdio.h>
#define HSIZE 50

class RequestProcess{
public:
    RequestProcess(char*);
    char *getResource();
    char *getSessionId();
    char **split(char*, const char*);
    ~RequestProcess();
private:
    char *p[HSIZE];
};

#endif /* request_process_hpp */
