//
//  http_server.hpp
//  HttpLite
//
//  Created by LiuYujie on 16/11/16.
//  Copyright © 2016年 LiuYujie. All rights reserved.
//

#ifndef http_server_hpp
#define http_server_hpp

#include <stdio.h>
#include "socket_server.hpp"

void dataProcess(char*);

class HttpServer : public SocketServer{
public:
    HttpServer(char *addr, int port);
    void start();
    virtual ~HttpServer();
private:
    void process(char*);
};

#endif /* http_server_hpp */
