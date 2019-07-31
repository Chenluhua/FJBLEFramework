//
//  AbsFitConnection.h
//  FJBLEFramework
//
//  Created by 陈泸华 on 16/4/4.
//  Copyright © 2016年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FBDeviceConnection.h"

@class FBDeviceConnection;
@class AbsFitConnection;

@protocol AbsFitConnectionDelegate <NSObject>

@required

// callback for centralManager state changed.
- (void) absfConnection:(nullable AbsFitConnection *)absfConnection level:(int)level;
@end


@interface AbsFitConnection : NSObject
@property (nonatomic, assign) id<AbsFitConnectionDelegate> delegate;

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
