//
//  Request.h
//  ApredCloudSDK
//
//  Created by 陈泸华 on 17/2/21.
//  Copyright © 2017年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSInteger, BLEREQRESULT) {
    BLE_REQRET_UNKNOW = 0,                       // unknow
    BLE_REQRET_READY,                            // ready
    BLE_REQRET_WAITING,                          // waiting
    BLE_REQRET_SENDED,                           // 已发送
    BLE_REQRET_TIMEOUT,                          // timeout
    BLE_REQRET_SUCCEED,                          // succeed
    BLE_REQRET_UNPAIRED,                         // 未配对
    BLE_REQRET_FAILED,                           // failed
};

@class BLERequest;
typedef void(^BLERESULTBLOCK)(BLERequest *request);

@interface BLERequest : NSObject
@property (nonatomic, readonly) unsigned int            requestId;
@property (nonatomic, readonly) BLEREQRESULT            result;
@property (nonatomic, readonly) NSMutableDictionary *   respDictionary;
@end
