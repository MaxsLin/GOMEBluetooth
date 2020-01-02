//
//  GOMEBluetoothManager.h
//  VeryfitSDK
//
//  Created by Max Mak on 2018/6/4.
//  Copyright © 2018年 Max Mak. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#if __has_include(<GOMEBluetoothInternal/GOMEBluetoothInternal.h>)
#elif __has_include(<GOMEBluetooth/GOMEBluetooth.h>)
#else
#import "GOMEBlueEnum.h"
#import "GOMEPeripheralModel.h"
#endif

@class GOMEBluetoothManager;

@protocol GOMEBluetoothManagerDelegate<NSObject>

/**
 * @brief 扫描所有外围设备 | Scan all peripherals
 * @param manager GOME蓝牙管理中心 | GOME Bluetooth Management Center
 * @param allDevices 扫描所有外围设备(包括OTA设备集合) | Scan all peripherals (including OTA device collections)
 * @param otaDevices OTA 设备集合 | OTA Device Collection
 */
- (void)bluetoothManager:(GOMEBluetoothManager *)manager
              allDevices:(NSArray <GOMEPeripheralModel *>*)allDevices
              otaDevices:(NSArray <GOMEPeripheralModel *>*)otaDevices;


/**
 * @brief 连接设备成功回调 | Connected device successfully callback
 * @param manager GOME蓝牙管理中心 | GOME Bluetooth Management Center
 * @param centerManager 蓝牙管理中心 | Bluetooth Management Center
 * @param peripheral 外围设备 | Peripherals
 * @param isOtaMode 连接是否在OTA模式 | Is the connection in OTA mode?
 * @return 是或否 | yes or no
 */
- (BOOL)bluetoothManager:(GOMEBluetoothManager *)manager
           centerManager:(CBCentralManager *)centerManager
    didConnectPeripheral:(CBPeripheral *)peripheral
               isOatMode:(BOOL)isOtaMode;

/**
 * @brief 蓝牙管理状态 | Bluetooth management status
 * @param manager GOME蓝牙管理中心 | GOME Bluetooth Management Center
 * @param state 状态 | Status
 */
- (void)bluetoothManager:(GOMEBluetoothManager *)manager
          didUpdateState:(GOME_BLUETOOTH_MANAGER_STATE)state;

/**
 * @brief 连接设备错误回调,当解绑设备断开连接时不会回调此方法
 * Connection Device Error Callback,This method is not called back when the unbound device is disconnected.
 * @param manager GOME蓝牙管理中心 | GOME Bluetooth Management Center
 * @param error 错误信息 | Error message
 */
- (void)bluetoothManager:(GOMEBluetoothManager *)manager
  connectPeripheralError:(NSError *)error;

@end

@interface GOMEBluetoothManager : NSObject

/**
 设置代理 | Setting up the agent
 */
@property (nonatomic,weak) id<GOMEBluetoothManagerDelegate> delegate;

/**
 * 自动扫描连接超时时长 默认 20
 * Auto Scan Connection Timeout Duration Default 20
 */
@property (nonatomic,assign) NSInteger timeout;

/**
 * 设置扫描过滤信号弱的设备 默认值 80 大于80会被过滤
 * Set the device with weak scan filtering signal. Default value 80 is greater than 80 will be filtered.
 */
@property (nonatomic,assign) NSInteger rssiNum;

/**
 * 是否启动超时,间隔扫描 默认 yes 默认10秒间隔扫描一次
 * Whether to start timeout, interval scan Default yes Default scan at 10-second intervals
 */
@property (nonatomic,assign) BOOL isIntervalScan;

/**
 * 是否需要重连机制 默认 YES 如果设置 NO 断线后不会重连
 * Whether a reconnect mechanism is required,if NO set,connection will not be reconnected
 */
@property (nonatomic,assign) BOOL isReconnect;

/**
 * 设置扫描间隔时长 默认 10秒 如果不启动超时间隔扫描，则无效
 * Set the scan interval to 10 seconds by default.if timeout interval scanning is not started, it is not valid.
 */
@property (nonatomic,assign) NSInteger autoScanInterval;

/**
 蓝牙扫描设备模式 | Bluetooth Scanning Device Mode
 */
@property (nonatomic,assign,readonly) GOME_SCAN_DEVICE_MODE scanMode;

/**
 蓝牙管理连接状态 | Bluetooth management connection status
 */
@property (nonatomic,assign,readonly) GOME_BLUETOOTH_MANAGER_STATE  state;

/**
 蓝牙连接错误码 | Bluetooth connection error code
 */
@property (nonatomic,assign,readonly) GOME_BLUETOOTH_CONNECT_ERROR_TYPE errorCode;

/**
 * 手动点击连接设备的总时长
 * Total time to manually click on the connected device
 */
@property (nonatomic,assign,readonly) NSInteger manualConnectTotalTime;

/**
 * 自动扫描到成功连接设备的总时长
 * Total time from automatic scanning to successful connection to the device
 */
@property (nonatomic,assign,readonly) NSInteger autoConnectTotalTime;

/**
 * @brief 初始化GOME蓝牙管理中心对象
 * Initialize GOME the Bluetooth Management Center object
 * @return GOMEBluetoothManager
 */
+ (__kindof GOMEBluetoothManager *)shareInstance;

/**
 * @brief 初始化系统蓝牙管理中心对象并刷新蓝牙代理
 * Initializes the system bluetooth management center object and refreshes the bluetooth delegate
 */
+ (void)refreshDelegate;

/**
 开始扫描 | Start scanning
 */
+ (void)startScan;

/**
 停止扫描 | Stop scanning
 */
+ (void)stopScan;

/**
 * @brief 1、普通模式下选择外围设备连接 2、ota模式下选择外围设备连接
 * 1. Select peripheral device connection in normal mode
 * 2. Select peripheral device connection in ota mode
 * @param model GOMEPeripheralModel 对象 | GOMEPeripheralModel object
 */
+ (void)connectDeviceWithModel:(GOMEPeripheralModel *)model;

/**
 断开当前外围设备的连接 | Disconnect the current peripheral device
 */
+ (void)cancelCurrentPeripheralConnection;

@end

