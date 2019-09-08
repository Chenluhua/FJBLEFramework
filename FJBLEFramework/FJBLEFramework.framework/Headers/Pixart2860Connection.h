//
//  Pixart2860Connection.h
//  FJBLEFramework
//
//  Created by 陈泸华 on 2019/8/27.
//  Copyright © 2019年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BLERequest.h"

typedef struct _Pixart2860Datetime {
    unsigned short year;
    Byte month;
    Byte day;
    Byte hour;
    Byte minute;
    Byte second;
    Byte week;
} Pixart2860Datetime;

typedef struct _Pixart2860Alarm {
    BOOL repeat[7];
    Byte hour;
    Byte minute;
} Pixart2860Alarm;

typedef struct _Pixart2860UserInfo {
    unsigned int gender;
    unsigned int age;
    unsigned int height;
    unsigned int weight;
    unsigned int skinTone;
} Pixart2860UserInfo;

typedef struct _Pixart2860StateConfiguration {
    bool sedentaryNotify;
    bool raiseOnDisplay;
    bool unlockScreenForAndroid;
    bool postureRecognition;
    bool hrDataLogger;
    bool sleepDataLogger;
} Pixart2860StateConfiguration;

#define PIXART2860_SERVICE_UUID       @"0001"

#define GOAL_TYPE_STEP              01
#define GOAL_TYPE_DISTANCE          02
#define GOAL_TYPE_CALORIE           03
#define GOAL_TYPE_ACTIVITY          04

#define MEASUREMENT_TYPE_HR         0x80
#define MEASUREMENT_TYPE_SPO2       0x40
#define MEASUREMENT_TYPE_BP         0x20

#define MEASUREMENT_MODE_STOP               0
#define MEASUREMENT_MODE_START_ONCE         1
#define MEASUREMENT_MODE_START_CONTINUOUS   2

@class Pixart2860Connection;
@protocol Pixart2860ConnectionDelegate <NSObject>

@required

// callback for centralManager state changed.
- (void)connection:(nullable Pixart2860Connection *)connection didGetHRData:(unsigned short)hr rawData:(NSData * _Nonnull)data;
- (void)connection:(nullable Pixart2860Connection *)connection didMeasurementResult:(int)type mode:(int)mode state:(int)state hr:(unsigned short)hr spo2:(int)spo2 dbp:(int)dbp sbp:(int)sbp;

@end

@interface Pixart2860Connection : NSObject
@property (nonatomic, assign) id <Pixart2860ConnectionDelegate> _Nullable delegate;

-(int)getCalender:(BLERESULTBLOCK _Nullable )resultBlock;
-(int)setCalender:(Pixart2860Datetime *_Nonnull)datetime resultBlock:(BLERESULTBLOCK _Nullable)resultBlock;
-(int)getAlarm:(unsigned int)number resultBlock:(BLERESULTBLOCK _Nullable)resultBlock;
-(int)setAlarm:(Pixart2860Alarm *_Nonnull)alerm resultBlock:(BLERESULTBLOCK _Nullable)resultBlock;
-(int)getUserInfo:(BLERESULTBLOCK _Nullable)resultBlock;
-(int)setUserInfo:(Pixart2860UserInfo *_Nonnull)userInfo resultBlock:(BLERESULTBLOCK _Nullable)resultBlock;
-(int)getGoal:(BLERESULTBLOCK _Nullable)resultBlock;
-(int)setGoal:(int)type goal:(int)value resultBlock:(BLERESULTBLOCK _Nullable)resultBlock;
-(int)getStateConfiguration:(BLERESULTBLOCK _Nullable)resultBlock;
-(int)setStateConfiguration:(Pixart2860StateConfiguration *_Nonnull)stateConfiguration resultBlock:(BLERESULTBLOCK _Nullable)resultBlock;
-(int)getDailyActivity:(BLERESULTBLOCK _Nullable)resultBlock;
-(int)measurementTrigger:(int)type mode:(int)mode resultBlock:(BLERESULTBLOCK _Nullable)resultBlock;

@end
