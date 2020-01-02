//
//  GOMEMakePhotoManager.h
//  GOMEBluetoothInternal
//
//  Created by Max Mak on 2019/12/3.
//  Copyright © 2019 Max Mak. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GOMEMakePhotoManager : NSObject
/**
 * 图片文件传输路径 
 * Transfer file path
 */
@property (nonatomic,copy,nullable) NSString * filePath;

/**
 * 图片传输进度回调 (1-100)
 * file transfer progress (1-100)
 */
@property (nonatomic,copy,nullable) GOMEMakePhotoManager *_Nonnull(^addPhotoProgress)(void(^ _Nullable progressCallback)(int progress));

/**
 * 图片传输完成回调
 * File transfer complete callback
 */
@property (nonatomic,copy,nullable) GOMEMakePhotoManager *_Nonnull(^addPhotoTransfer)(void(^ _Nullable transferComplete)(int errorCode));
/**
 * 初始化制作图片管理对象(单例)
 * Initialize the transfer file management object (singleton)
 */
GOMEMakePhotoManager * _Nonnull initMakePhotoManager(void);

/**
 * 图片开始传输
 * file start transfer
 */
+ (void)startPhotoTransfer;

/**
 * 图片结束传输
 * file stop transfer
 */
+ (void)stopPhotoTransfer;

@end

