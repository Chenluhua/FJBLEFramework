//
//  FJBLEFramework.h
//  FJBLEFramework
//
//  Created by 陈泸华 on 16/3/1.
//  Copyright © 2016年 陈泸华. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FBTest.h"
#import "FBScanner.h"
#import "FBDeviceConnection.h"
#import "AbsFitConnection.h"
#import "BodyFitConnection.h"
#import "BMRecord.h"
#import "HRMeterConnection.h"
#import "EncrypterConnection.h"
#import "Z602Connection.h"

//! Project version number for FJBLEFramework.
FOUNDATION_EXPORT double FJBLEFrameworkVersionNumber;

//! Project version string for FJBLEFramework.
FOUNDATION_EXPORT const unsigned char FJBLEFrameworkVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <FJBLEFramework/PublicHeader.h>



#define ERCODE_NOERROR              0
#define ERCODE_UNKNOW               1
#define ERCODE_DEVICE_INVALID       2
#define ERCODE_DEVICE_BUSY          3
#define ERCODE_PARAM_INVALID        4
#define ERCODE_TIMEOUT              5



