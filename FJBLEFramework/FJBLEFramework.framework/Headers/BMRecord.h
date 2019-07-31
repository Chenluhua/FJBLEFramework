//
//  BMRecord.h
//  FJBLEFramework
//
//  Created by 陈泸华 on 16/4/16.
//  Copyright © 2016年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BMRecord : NSObject

@property (atomic, readonly) UInt16 year;
@property (atomic, readonly) UInt8 month;
@property (atomic, readonly) UInt8 day;
@property (atomic, readonly) UInt8 hour;
@property (atomic, readonly) UInt8 minute;
@property (atomic, readonly) UInt8 second;

@property (atomic, readonly) float mileage;
@property (atomic, readonly) int durationHour;
@property (atomic, readonly) int durationMinute;
@property (atomic, readonly) float maxSpeed;
@property (atomic, readonly) float averageSpeed;
@property (atomic, readonly) int maxHr;
@property (atomic, readonly) int averageHr;
@property (atomic, readonly) int maxCadence;
@property (atomic, readonly) int averageCadence;
@property (atomic, readonly) float calories;
@property (atomic, readonly) float fat;
@property (atomic, readonly) float maxSlope;
@property (atomic, readonly) float maxElevation;
@property (atomic, readonly) float altitude;
@property (atomic, readonly) float airPressure;
@property (atomic, readonly) float minAirPressure;


@end
