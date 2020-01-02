//
//  GOMEWatchDialManager.h
//  GOMEBluetoothInternal
//
//  Created by Max Mak on 2019/8/21.
//  Copyright © 2019 Max Mak. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^ _Nullable setComplete)(GOMEWatchDialInfoModel * _Nullable model,int errorCode);

@interface GOMEWatchDialManager : NSObject

/**
 * 表盘文件传输路径 (zip)
 * Transfer file path
 */
@property (nonatomic,copy,nullable) NSString * filePath;

/**
 * 获取当前设备屏幕信息
 * Gets the current device screen information
 */
@property (nonatomic,copy,nullable) GOMEWatchDialManager *_Nonnull(^getDialScreenInfo)(void(^ _Nullable dialScreenCallback)(GOMEWatchScreenInfoModel * _Nullable model,int errorCode));

/**
 * 获取当前设备所有表盘信息
 * Gets all dial information of the current device
 */
@property (nonatomic,copy,nullable) GOMEWatchDialManager *_Nonnull(^getDialListInfo)(void(^ _Nullable dialListCallback)(GOMEWatchDialInfoModel * _Nullable model,int errorCode));

/**
 * 获取当前设备当前表盘信息
 * Gets current dial information of the current device
 */
@property (nonatomic,copy,nullable) GOMEWatchDialManager *_Nonnull(^getCurrentDialInfo)(void(^ _Nullable currentDialCallback)(GOMEWatchDialInfoModel * _Nullable model,int errorCode));

/**
 * 设置当前表盘并回调
 * Set the current dial and call back
 */
@property (nonatomic,copy,nullable) GOMEWatchDialManager *_Nonnull(^setCurrentDial)(setComplete block,GOMEWatchDialInfoItemModel * _Nullable model);

/**
 * 表盘传输进度回调 (1-100)
 * file transfer progress (1-100)
 */
@property (nonatomic,copy,nullable) GOMEWatchDialManager *_Nonnull(^addDialProgress)(void(^ _Nullable progressCallback)(int progress));

/**
 * 表盘传输完成回调
 * File transfer complete callback
 */
@property (nonatomic,copy,nullable) GOMEWatchDialManager *_Nonnull(^addDialTransfer)(void(^ _Nullable transferComplete)(int errorCode));

/**
 * 初始化表盘传输管理对象(单例)
 * Initialize the transfer file management object (singleton)
 */
GOMEWatchDialManager * _Nonnull initWatchDialManager(void);

/**
 * 表盘开始传输
 * file start transfer
 */
+ (void)startDialTransfer;

/**
 * 表盘结束传输
 * file stop transfer
 */
+ (void)stopDialTransfer;

@end
