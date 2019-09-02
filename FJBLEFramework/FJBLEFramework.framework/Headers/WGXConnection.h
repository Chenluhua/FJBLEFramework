//
//  WGXConnection.h
//  FJBLEFramework
//
//  Created by 陈泸华 on 2019/8/27.
//  Copyright © 2019年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BLERequest.h"

typedef struct _WGXDatetime {
    unsigned short year;
    Byte month;
    Byte day;
    Byte hour;
    Byte minute;
    Byte second;
} WGXDatetime;

typedef struct _WGXUserInfo {
    unsigned int gender;
    unsigned int age;
    unsigned int height;
    unsigned int weight;
} WGXUserInfo;

@class WGXConnection;
@protocol WGXConnectionDelegate <NSObject>

@required

// callback for centralManager state changed.
- (void) connection:(nullable WGXConnection *)connection didGetHRData:(unsigned short)hr rawData:(NSData * _Nonnull)data;

@end

@interface WGXConnection : NSObject
@property (nonatomic, assign) id <WGXConnectionDelegate> delegate;

-(int)getCalender:(BLERESULTBLOCK _Nullable )resultBlock;
-(int)setCalender:(WGXDatetime *_Nonnull)datetime resultBlock:(BLERESULTBLOCK _Nullable)resultBlock;
-(int)getGoal:(BLERESULTBLOCK _Nullable)resultBlock;
-(int)setGoal:(int)type goal:(int)value resultBlock:(BLERESULTBLOCK _Nullable)resultBlock;
-(int)getUserInfo:(BLERESULTBLOCK _Nullable)resultBlock;
-(int)setUserInfo:(WGXUserInfo *_Nonnull)userInfo resultBlock:(BLERESULTBLOCK _Nullable)resultBlock;
-(int)startHrMeasure:(BLERESULTBLOCK _Nullable)resultBlock;
-(int)stopHrMeasure:(BLERESULTBLOCK _Nullable)resultBlock;

@end
