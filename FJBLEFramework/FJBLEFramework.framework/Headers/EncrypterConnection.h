//
//  EncrypterConnection.h
//  FJBLEFramework
//
//  Created by 陈泸华 on 2018/3/2.
//  Copyright © 2018年 陈泸华. All rights reserved.
//

#import <Foundation/Foundation.h>

@class EncrypterConnection;
@protocol EncrypterConnectionDelegate <NSObject>

@required

// callback for centralManager state changed.
- (void) connection:(nullable EncrypterConnection *)connection didWriteLicenseResponed:(BOOL)isSucceed;
- (void) connection:(nullable EncrypterConnection *)connection didReadLicenseResponed:(int)license nums:(int)nums totals:(int)totals;

@end

@interface EncrypterConnection : NSObject
@property (nonatomic, assign) id <EncrypterConnectionDelegate> delegate;
-(int)readLicense;
-(int)writeLicense:(NSData*_Nonnull)dataScr;
@end
