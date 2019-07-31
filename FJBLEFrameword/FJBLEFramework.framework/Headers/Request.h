//
//  Request.h
//  ApredCloudSDK
//
//  Created by 陈泸华 on 17/2/21.
//  Copyright © 2017年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSInteger, REQRESULT) {
    REQRET_UNKNOW = 0,                       // unknow
    REQRET_READY,                            // ready
    REQRET_WAITING,                          // waiting
    REQRET_SENDED,                           // 已发送
    REQRET_TIMEOUT,                          // timeout
    REQRET_SUCCEED,                          // succeed
    REQRET_UNPAIRED,                         // 未配对
    REQRET_FAILED,                           // failed
};

@class Request;
typedef void(^RESULTBLOCK)(Request *request);

@interface Request : NSObject
@property (nonatomic, readonly) unsigned int            requestId;
@property (nonatomic, readonly) REQRESULT               result;
@property (nonatomic, readonly) NSMutableDictionary *   respDictionary;
@end
