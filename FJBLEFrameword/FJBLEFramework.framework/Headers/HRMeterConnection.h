//
//  HRMeterConnection.h
//  FJBLEFramework
//
//  Created by 陈泸华 on 16/7/31.
//  Copyright © 2016年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FBDeviceConnection.h"




@class HRMeterConnection;
@protocol HRMeterConnectionDelegate <NSObject>

@required

// callback for centralManager state changed.
- (void) connecting:(nullable HRMeterConnection *)connection didGetHRData:(unsigned short)hr rawData:(NSData * _Nonnull)data;
- (void) connecting:(nullable HRMeterConnection *)connection didUpdateBatt:(unsigned int)batt;
- (void) connecting:(nullable HRMeterConnection *)connection didUpdateString:(NSString * _Nonnull)string;
- (void) connecting:(nullable HRMeterConnection *)connection didUpdateRawData:(NSData * _Nonnull)data flag:(int)flag;

@end


@interface HRMeterConnection : NSObject
@property (nonatomic, assign) id <HRMeterConnectionDelegate> delegate;
-(unsigned int)getBatteryLevel;
-(int)enableOhr;
-(BOOL)isEnableOhr;

@end
