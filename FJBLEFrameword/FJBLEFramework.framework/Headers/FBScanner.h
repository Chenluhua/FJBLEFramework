//
//  FBScanner.h
//  FJBLEFramework
//
//  Created by 陈泸华 on 16/3/1.
//  Copyright © 2016年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <CoreBluetooth/CBAdvertisementData.h>
#import "FBDeviceConnection.h"

/*
 * Scaner State
 */
typedef enum
{
    SCANNERState_Unknow               = 0,
    SCANNERState_Ready,
    SCANNERState_Begin,
    SCANNERState_Searching,
    SCANNERState_SearchCannel,
    SCANNERState_SearchComplete,
} SCANNERState;

@class FBDeviceConnection;
@interface BLEDevice : NSObject
{
    
}

@property (weak, nonatomic, readonly) FBDeviceConnection * _Nullable fbDeviceConnection;

- (nullable id)initWithPer:(nullable CBPeripheral *)peripheral address:(NSString*)address rssi:(int)deviceRSSI;- (nullable id)initWithUUID:(nullable NSString *)deviceUUID Name:(nullable NSString *)deviceName Rssi:(int)deviceRSSI;
-(nullable NSString*)getName;
-(nullable NSString*)getUUID;
- (nullable NSString*)getAddress;
-(int)getRSSI;
-(nullable id)getPeripheral;
-(BOOL)Compare:(nonnull BLEDevice *)device;
-(void)updata:(nonnull BLEDevice *)device;
-(void)setTag:(int)tag;
-(int)getTag;

@end


@class FBScanner;

@protocol FBScannerDelegate <NSObject>

@required

// callback for centralManager state changed.
- (void)fbScanner:(nullable FBScanner *)scanner cbcManagerStateChanged:(int)state;
- (void)fbScanner:(nullable FBScanner *)scanner stateChanged:(SCANNERState)state;
- (void)fbScanner:(nullable FBScanner *)scanner didFoundBLEDevice:(nullable BLEDevice *)device;
- (void)fbScanner:(nullable FBScanner *)scanner didProgressChanged:(float)progress;

@end


@interface FBScanner : NSObject<CBCentralManagerDelegate>
{
    
}

@property (nonatomic,strong, nullable) id<FBScannerDelegate> delegate;


+ (nullable FBScanner*)SharedFBScanner;
+ (nullable NSString *)getCBCManagerStateString:(int)state;
+ (nullable NSString *)getStateString:(SCANNERState)state;
-(SCANNERState)getState;
- (nullable id)initWithDelegate:(nullable id<FBScannerDelegate>)delegatet;
-(void)StopScan;
- (int)Scan:(nullable id<FBScannerDelegate>)delegatet uuids:(nullable NSArray *)serviceUUIDs options:(nullable NSDictionary *)options;
- (nullable FBDeviceConnection*)connect:(nullable BLEDevice *)device delegate:(nullable id<FBDeviceConnectionDelegate>)delegatet userData:(int)data;
- (nullable FBDeviceConnection *)connectToPeripheral:(CBPeripheral *)peripheral delegate:(nullable id<FBDeviceConnectionDelegate>)delegatet userData:(int)data;
-(BOOL)ReConnect:(nullable FBDeviceConnection *)connection;
-(void)DisconnectD:(nullable BLEDevice *)device;
-(void)DisconnectC:(nullable FBDeviceConnection *)connection;

@end
