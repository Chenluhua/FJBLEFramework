//
//  BoboFitConnection.h
//  FJBLEFramework
//
//  Created by 陈泸华 on 16/4/18.
//  Copyright © 2016年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FBDeviceConnection.h"


#define BBMODE_OFF      0
#define BBMODE_VIB      1
#define BBMODE_EMS      2
#define BBMODE_EMSVIB   3
#define BBMODE_AUTO     4

@class FBDeviceConnection;
@class BoboFitConnection;

@protocol BoboFitConnectionDelegate <NSObject>

@required

// callback for centralManager state changed.
- (void) bobofConnection:(nullable BoboFitConnection *)bobofConnection level:(int)level;
@end


@interface BoboFitConnection : NSObject

-(FBDeviceConnection * _Nullable)getFBDeviceConnection;
-(BOOL) isConnected;
//-(int) ctrlDevice:(BOOL)bVibOn emsOn:(BOOL)bEmsOn oenOn:(BOOL)bOenOn emsLevel:(int)nEmsLevel;
-(int)setLevel:(int)level;
-(int)getLevel;
-(int)getDeviceMode;
-(int)setDeviceMode:(int)mode;

@end
