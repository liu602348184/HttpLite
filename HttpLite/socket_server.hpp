//
//  socket_server.hpp
//  HttpLite
//
//  Created by LiuYujie on 16/11/11.
//  Copyright © 2016年 LiuYujie. All rights reserved.
//

#ifndef socket_server_hpp
#define socket_server_hpp

#include <stdio.h>
#include <sys/socket.h>

typedef void(*pProcess)(char*);

class SocketServer{
public:
    SocketServer(char *addr, int port);
    bool listen(pProcess func);
    virtual ~SocketServer();
private:
    struct sockaddr_in *serv_addr;
    int socketfd;
    
};

#endif /* socket_server_hpp */
