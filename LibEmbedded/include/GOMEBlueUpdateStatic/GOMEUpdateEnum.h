//
//  GOMEUpdateEnum.h
//  GOMEBluetoothInternal
//
//  Created by Max Mak on 2019/8/3.
//  Copyright © 2019 Max Mak. All rights reserved.
//

#ifndef GOMEUpdateEnum_h
#define GOMEUpdateEnum_h

/**
 * OTA升级状态枚举
 * OTA upgrade status enumeration
 */
typedef NS_ENUM(NSInteger, GOME_UPDATE_STATE) {
    
    /**
     * 升级初始状态
     * Update initial state
     */
    GOME_UPDATE_START_INIT = 0,
    
    /**
     * 开始进入OTA
     * Start entering OTA
     */
    GOME_UPDATE_START_ENTER_OTA = 1,
    
    /**
     * 已进入OTA
     * Has entered OTA
     */
    GOME_UPDATE_DID_ENTER_OTA,
    
    /**
     * 开始重连设备
     * Start reconnecting devices
     */
    GOME_UPDATE_START_RECONECT_DEVICE,
    
    /**
     * 设备已经重新连接上
     * The device has been reconnected
     */
    GOME_UPDATE_DID_RECONECT_DEVICE,
    /**
     * 开始启动升级固件
     * Start booting the firmware
     */
    GOME_UPDATE_STARTING ,
    
    /**
     * 固件升级中
     * Firmware upgrade
     */
    GOME_UPDATE_UPLOADING,
    
    /**
     * 固件升级完成
     * Firmware upgrade completed
     */
    GOME_UPDATE_COMPLETED,
    
};


/**
 * 设备升级错误类型枚举
 * Device upgrade error type enumeration
 */
typedef NS_ENUM(NSInteger, GOME_UPDATE_ERROR_TYPE) {
    /**
     * 固件包文件不存在
     * The firmware package file does not exist
     */
    GOME_UPDATE_PACKAGE_FILE_NO_EXIST_TYPE = 1,
    
    /**
     * 电量不足不能进入OTA模式
     * Insufficient power can not enter OTA mode
     */
    GOME_UPDATE_ENTER_OTA_LOW_ELECTRICITY_TYPE,
    
    /**
     * 设备不支持OTA升级
     * The device does not support OTA upgrade
     */
    GOME_UPDATE_NO_SUPPORTED_OTA_TYPE,
    
    /**
     * 进入OTA设置参数错误
     * Enter OTA setting parameter error
     */
    GOME_UPDATE_ENTER_OTA_PARAMETER_ERROR_TYPE,
    
    /**
     * 进入OTA失败
     * Entering OTA failed
     */
    GOME_UPDATE_ENTER_OTA_FAILED_TYPE,
    
    /**
     * 进入ota蓝牙重连失败
     * Enter OTA Bluetooth reconnection failed
     */
    GOME_UPDATE_ENTER_OTA_RECONNECT_FAILED_TYPE,
    
    /**
     * 蓝牙断开无法升级
     * Bluetooth disconnect cannot be upgraded
     */
    GOME_UPDATE_BLUETOOTH_DIS_CONNECT_TYPE,
    
    /**
     * 升级固件包失败
     * Upgrade firmware package failed
     */
    GOME_UPDATE_FIRMWARE_FAILED_TYPE,
    
    /*
     * 升级过程中系统蓝牙断开
     * The system bluetooth was disconnected during the upgrade
     */
    GOME_SYSTEM_BLUETOOTH_DISABLED_TYPE,
} ;

/**
 * 设备升级固件包类型
 * Device upgrade dfu firmware type enum
 */
typedef NS_ENUM(NSInteger, GOME_UPDATE_DFU_FIRMWARE_TYPE)  {
    /**
     *
     * Soft device type
     */
    GOME_DFU_FIRMWARE_SOFTDEVICE_TYPE = 1,
    /**
     * 引导装载程序
     * Bootloader type
     */
    GOME_DFU_FIRMWARE_BOOTLOADER_TYPE,
    /**
     *
     * Soft device and bootloader type
     */
    GOME_DFU_FIRMWARE_SOFTDEVICE_BOOTLOADER_TYPE,
    /**
     * 应用程序
     * Application type
     */
    GOME_DFU_FIRMWARE_APPLICATION_TYPE,
};

/**
 * 固件升级使用平台类型
 * Firmware updates use the platform type
 */
typedef NS_ENUM(NSInteger, GOME_UPDATE_PLATFORM_TYPE)  {
    /**
     * nordic 蓝牙升级
     * nordic bluetooth update
     */
    GOME_NORDIC_PLATFORM_TYPE = 0,
    /**
     * realtk 蓝牙升级
     * realtk bluetooth update
     */
    GOME_REALTK_PLATFORM_TYPE,
};


#endif /* GOMEUpdateEnum_h */
