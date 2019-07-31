//
//  Z602Connection.h
//  FJBLEFramework
//
//  Created by 陈泸华 on 2019/4/1.
//  Copyright © 2019年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Request.h"

typedef struct _Z602Alarm {
    Byte number;
    BOOL repeat[7];
    Byte hour;
    Byte minute;
    char message[14];
} Z602Alarm;

typedef struct _Z602Datetime {
    unsigned short year;
    Byte month;
    Byte day;
    Byte hour;
    Byte minute;
    Byte second;
} Z602Datetime;

typedef struct _Z602GeneralSettings {
    int unitSystem;
    int language;
    int timeFormat;
    BOOL isHandleBright;
    BOOL enable24HourHr;
    BOOL enableANCSCall;
    BOOL enableANCSMsg;
} Z602GeneralSettings;

typedef struct _Z602UserProfile {
    unsigned int birthYear;
    unsigned int birthMonth;
    unsigned int birthDay;
    unsigned int gender;
    double weight;
    unsigned int height;
    unsigned int MHR;
    unsigned int RHR;
} Z602UserProfile;

typedef struct _Z602SilentSetting {
    BOOL enable;
    Byte startHour;
    Byte startMinute;
    Byte endHour;
    Byte endMinute;
} Z602SilentSetting;

typedef struct _Z602SedentaryTime {
    unsigned int durationMinute;
    Byte startHour;
    Byte startMinute;
    Byte endHour;
    Byte endMinute;
} Z602SedentaryTime;

typedef struct _Z602StreamingData {
    BOOL hasExerciseData;                   /* 是否有锻练数据 */
    BOOL enableHr;                          /* 是否开启心率 */
    BOOL isCharging;                        /* 是否充电中 */
    UInt8 heartRate;                        /* 心率值，0未开启或正在获取，1〜30手环不在腕上，其它为心率值 */
    UInt8 steps1s;                          /* 每秒步数 */
    UInt8 activity1s;                       /* 每秒活动值 */
    UInt32 totalSteps;                      /* 总步数 */
} Z602StreamingData;

typedef struct _Z602DailyData {
    UInt32 index;                           /* 序列号 */
    UInt16 year;                            /* 时间 */
    UInt8 month;
    UInt8 day;
    UInt32 steps;                           /* 总步数 */
    UInt32 calories;                        /* 卡路里 */
    UInt32 distance;                        /* 路程 */
    UInt32 sleeps;                          /* 睡眠时间 (分钟)*/
    UInt8 step[1440];                       // 每个一分钟的步数，
                                            // 若>=250 则为睡眠，睡眠分为 4 个等级，
                                            // 250 到 253 分别对深睡和浅睡 level2，浅睡level1 和清醒。
    UInt8 hr[1440];                         // 平均心率，若为 0，表示没有开启心率功能，
                                            // 若为大于等于 1，小于 30，表示心率开启了，但是 手表不在手腕上
} Z602DailyData;

typedef struct _Z602ExerciseData {
    UInt32 index;                           /* 序列号 */
    UInt16 year;                            /* 时间 */
    UInt8 month;
    UInt8 day;
    UInt32 steps;                           /* 总步数 */
    UInt32 calories;                        /* 卡路里 */
    UInt32 distance;                        /* 路程 */
    UInt32 sleeps;                          /* 睡眠时间 (分钟)*/
    UInt8 step[1440];                       // 每个一分钟的步数，
    // 若>=250 则为睡眠，睡眠分为 4 个等级，
    // 250 到 253 分别对深睡和浅睡 level2，浅睡level1 和清醒。
    UInt8 hr[1440];                         // 平均心率，若为 0，表示没有开启心率功能，
    // 若为大于等于 1，小于 30，表示心率开启了，但是 手表不在手腕上
} Z602ExerciseData;

#define Z602_SERVICE_UUID       @"94D0FD00-6CAC-4767-BA69-E14A97D337D2"

typedef void(^BEGINBLOCK)(void);
typedef void(^PROGRESSBLOCK)(float progress);
typedef void(^ERRORBLOCK)(int code, NSString *msg);
typedef void(^COMPLETEBLOCK)(int type, NSData *rawData, NSValue *value);

@class Z602Connection;
@class FBDeviceConnection;
typedef void(^STREAMINGDATAARRIVED)(Z602Connection *connection, Z602StreamingData *streamingData);

@interface Z602Connection : NSObject
@property (nonatomic, readonly) BOOL isPaired;

-(int)askPair:(RESULTBLOCK)resultBlock;
-(int)factoryGetSN:(RESULTBLOCK)resultBlock;
-(int)factorySetSN:(unsigned int)sn resultBlock:(RESULTBLOCK)resultBlock;
-(int)normalModeSetSN:(unsigned int)sn resultBlock:(RESULTBLOCK)resultBlock;
-(int)testReset:(RESULTBLOCK)resultBlock;
-(int)testMotorLed:(BOOL)on resultBlock:(RESULTBLOCK)resultBlock;
-(int)setBleName:(BOOL)bAttachSn name:(NSString *)name resultBlock:(RESULTBLOCK)resultBlock;
-(int)getAlarm:(unsigned int)number resultBlock:(RESULTBLOCK)resultBlock;
-(int)setAlarm:(Z602Alarm *)alerm resultBlock:(RESULTBLOCK)resultBlock;
-(int)getCalender:(RESULTBLOCK)resultBlock;
-(int)setCalender:(Z602Datetime *)datetime resultBlock:(RESULTBLOCK)resultBlock;
-(int)setGeneralSettings:(Z602GeneralSettings *)settings resultBlock:(RESULTBLOCK)resultBlock;
-(int)getGeneralSettings:(RESULTBLOCK)resultBlock;
-(int)getUserProfile:(RESULTBLOCK)resultBlock;
-(int)setUserProfile:(Z602UserProfile *)profile resultBlock:(RESULTBLOCK)resultBlock;
-(int)getSedentaryTime:(RESULTBLOCK)resultBlock;
-(int)setSedentaryTime:(Z602SedentaryTime *)sedentary resultBlock:(RESULTBLOCK)resultBlock;
-(int)getSilentSetting:(RESULTBLOCK)resultBlock;
-(int)setSilentSetting:(Z602SilentSetting *)setting resultBlock:(RESULTBLOCK)resultBlock;
-(int)getDailyRecord:(int)nDayIndex beginBlock:(BEGINBLOCK)beginBlock progressBlock:(PROGRESSBLOCK)progressBlock errorBlock:(ERRORBLOCK)errorBlock completeBlock:(COMPLETEBLOCK)completeBlock;
-(int)getExerciseData:(BOOL)isDelAfterCompletion beginBlock:(BEGINBLOCK)beginBlock progressBlock:(PROGRESSBLOCK)progressBlock errorBlock:(ERRORBLOCK)errorBlock completeBlock:(COMPLETEBLOCK)completeBlock;;
-(int)enableStream:(STREAMINGDATAARRIVED)block;
-(int)disableStream;

@end
