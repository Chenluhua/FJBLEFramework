//
//  BikeMeterConnection.h
//  FJBLEFramework
//
//  Created by 陈泸华 on 16/4/9.
//  Copyright © 2016年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FBDeviceConnection.h"


struct  _BMSETTINGS {
    int         language;
    int         year;
    int         month;
    int         day;
    int         hour;
    int         minute;
    int         second;
    int         unitType;
    
    float       initialMileage;
    int         initialTimes_hour;
    int         initialTImes_minute;
    
    int         weight;
    int         inspectMileage;
    int         hr;
    int         cadence;
    int         wheelCircumference;
    int         variableSpeed;

    int         chainWheel[3];
    int         flywheel[9];
};
typedef struct _BMSETTINGS BMSETTINGS;

//@class FBDeviceConnection;
@class BikeMeterConnection;

@protocol BikeMeterConnectionDelegate <NSObject>

@required

// callback for centralManager state changed.
- (void) connecting:(nullable BikeMeterConnection *)connection didGetSettings:(int)rsp settings:(nullable BMSETTINGS *)settings;
- (void) connecting:(nullable BikeMeterConnection *)connection didSetSettings:(int)rsp;
- (void) connecting:(nullable BikeMeterConnection *)connection didSyncData:(int)rsp state:(int)state progress:(float)progress;
@end


@interface BikeMeterConnection : NSObject
@property (nonatomic, assign) id<BikeMeterConnectionDelegate> delegate;

-(int)getSettings;
-(int)setSettings:(BMSETTINGS)settings;
-(int)syncDataStart;
-(int)syncDataStop;
-(NSData * _Nullable)getRawData;
-(NSArray * _Nullable)getRecordArray;

@end
