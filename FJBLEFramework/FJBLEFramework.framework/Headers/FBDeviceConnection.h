//
//  FBDeviceConnection.h
//  FJBLEFramework
//
//  Created by 陈泸华 on 16/3/1.
//  Copyright © 2016年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <CoreBluetooth/CBAdvertisementData.h>
#import "AbsFitConnection.h"
#import "BodyFitConnection.h"
#import "BikeMeterConnection.h"
#import "BoboFitConnection.h"
#import "HRMeterConnection.h"
#import "EncrypterConnection.h"
#import "Z602Connection.h"


/*
 * FBDeviceConnection State
 */
typedef enum
{
    FBDState_Unknow               = 0,
    FBDState_Connecting,
    FBDState_Connected,
    FBDState_TimeOut,
    FBDState_Ready,
    FBDState_Disconnected,
} FBDeviceState;

/*
 * FBDeviceMode
 */
typedef enum
{
    FBDMode_Unknow               = 0,
    FBDMode_SkinRunV2,
    FBDMode_AbsFit,
    FBDMode_BodyFit,
    FBDMode_BoboFit,
    FBDMode_BikeMeter,
    FBDMode_HRMeter,
    FBDMode_HREncrypter,
    FBDMode_Z602,
} FBDeviceMode;

@class FBDeviceConnection;
@class AbsFitConnection;
@class BodyFitConnection;
@class BoboFitConnection;
@class BikeMeterConnection;
@class HRMeterConnection;
@class EncrypterConnection;

@protocol FBDeviceConnectionDelegate <NSObject>

@required

// callback for state changed.
- (void) fbDeviceConnection:(nullable FBDeviceConnection *)connection didReadRSSI:(int)rssi;
- (void) fbDeviceConnection:(nullable FBDeviceConnection *)connection stateChanged:(FBDeviceState)state;
- (void) fbDeviceConnection:(nullable FBDeviceConnection *)connection notify:(int)notifyCode attachData:(nullable NSDictionary *)dicAttachData;
- (void) fbDeviceConnection:(nullable FBDeviceConnection *)connection didUpdateBatt:(unsigned int)batt;

@end


@interface FBDeviceConnection : NSObject<CBPeripheralDelegate>
{
}

@property (nonatomic,strong, nullable) id<FBDeviceConnectionDelegate> delegate;
@property (nonatomic, readonly) NSString * _Nonnull deviceName;
@property (nonatomic, readonly) FBDeviceState state;
@property (nonatomic, readonly) NSString * _Nullable firmwareRev;
@property (nonatomic, readonly) unsigned int batteryLevel;

-(FBDeviceMode) getMode;
-(nullable NSString *)getModeText:(FBDeviceMode)mode;
-(nullable NSString *)getStateText:(FBDeviceState)state;
-(nullable NSString *)getUUID;
-(void)ReadRSSI;
-(int)connect:(CBCentralManager * _Nonnull)cbcManager delegate:(nullable id<FBDeviceConnectionDelegate>)delegatet userData:(int)data;
-(int)reConnect;
- (void)disconnect;
-(BOOL)isReady;
-(int)getUserData;
-(void)setTag:(_Nonnull id)tag;
-(_Nonnull id)getTag;
-(void)unInit;

-(AbsFitConnection * _Nullable)getAbsFitConnection;
-(BodyFitConnection * _Nullable)getBodyFitConnection;
-(BoboFitConnection * _Nullable)getBoboFitConnection;
-(BikeMeterConnection * _Nullable)getBikeMeterConnection;
-(HRMeterConnection * _Nullable)getHRMeterConnection;
-(EncrypterConnection * _Nullable)getEncrypterConnection;
-(Z602Connection * _Nullable)getZ602Connection;

@end
