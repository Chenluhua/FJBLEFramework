//
//  BodyFitConnection.h
//  FJBLEFramework
//
//  Created by 陈泸华 on 16/4/4.
//  Copyright © 2016年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FBDeviceConnection.h"


@class FBDeviceConnection;
@class BodyFitConnection;

@protocol BodyFitConnectionDelegate <NSObject>

@required

// callback for centralManager state changed.
- (void) bodyfConnection:(nullable BodyFitConnection *)bodyfConnection level:(int)level;
@end


@interface BodyFitConnection : NSObject
@property (nonatomic, assign) id<BodyFitConnectionDelegate> delegate;

-(id)initWithFBDConnection:(FBDeviceConnection *)fbdConnection;
- (void)peripheral:(CBPeripheral *)peripheral didUpdateValueForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error;
- (void)peripheral:(CBPeripheral *)peripheral didWriteValueForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error;

-(int) powerOn;
-(int) powerOff;
-(int) pressUpKey;
-(int) pressDownKey;
-(int) readLevel;
-(int) getLevel;
-(void) deviceReady;

@end
