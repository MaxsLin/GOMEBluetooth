//
//  GOMELogEnum.h
//  GOMEBluetoothInternal
//
//  Created by Max Mak on 2019/8/3.
//  Copyright © 2019 Max Mak. All rights reserved.
//

#ifndef GOMELogEnum_h
#define GOMELogEnum_h

/**
 * 记录日志类型
 * Log type
 */
typedef NS_ENUM(NSInteger, GOME_RECORD_LOG_TYPE)  {
    /**
     * 手动连接手环
     * Manually connect the bracelet
     */
    GOME_MANUAL_CONNECT_LOG = 1,
    /**
     * 自动连接手环
     * Automatic connection bracelet
     */
    GOME_AUTO_CONNECT_LOG,
    /**
     * 手环绑定
     * Bracelet binding
     */
    GOME_BIND_DEVICE_LOG,
    /**
     * 手环解绑
     * Untie the bracelet
     */
    GOME_UNBIND_DEVICE_LOG,
    /**
     * 同步配置
     * Synchronous configuration
     */
    GOME_SYNC_CONFIG_LOG,
    /**
     * 同步健康
     * Synchronous Health
     */
    GOME_SYNC_HEALTH_LOG,
    /**
     * 同步健康 步数
     * Synchronous Health Steps
     */
    GOME_SYNC_HEALTH_SPORT_LOG,
    /**
     * 同步健康 睡眠
     * Synchronized Health Sleep
     */
    GOME_SYNC_HEALTH_SLEEP_LOG,
    /**
     * 同步健康 心率
     * Synchronized Health Heart Rate
     */
    GOME_SYNC_HEALTH_HR_LOG,
    /**
     * 同步健康 血压
     * Synchronized Health Blood Pressure
     */
    GOME_SYNC_HEALTH_BP_LOG,
    /**
     * 同步 血氧
     * Synchronized blood oxygen
     */
    GOME_SYNC_BLOOD_OXYGEN_LOG,
    /**
     * 同步 压力
     * Synchronized Pressure
     */
    GOME_SYNC_PRESSURE_LOG,
    /**
     * 同步 游泳
     * Synchronized Swimming
     */
    GOME_SYNC_SWIMMING_LOG,
    /**
     * 同步活动
     * Synchronous activity
     */
    GOME_SYNC_ACTIVITY_LOG,
    /**
     * 同步gps
     * Synchronous gps
     */
    GOME_SYNC_GPS_LOG,
    /**
     * 同步结束
     * End of synchronization
     */
    GOME_SYNC_COMPLETE_LOG,
    /**
     * 蓝牙写入数据
     * Bluetooth write data
     */
    GOME_WRITE_DATA_LOG,
    /**
     * 蓝牙接收数据
     * Bluetooth receiving data
     */
    GOME_RECEIVE_DATA_LOG,
    /**
     * 手环开始升级
     * The bracelet starts to upgrade
     */
    GOME_START_UPDATE_LOG,
    /**
     * 手环升级失败
     * Failed to upgrade the bracelet
     */
    GOME_UPDATE_FAILED_LOG,
    /**
     * 手环升级成功
     * Bracelet upgraded successfully
     */
    GOME_UPDATE_SUCCESS_LOG,
    /**
     * 手环启动配对
     * Bracelet starts pairing
     */
    GOME_PAIRING_START_LOG,
    /**
     * 手环配对失败
     * Bracelet pairing failed
     */
    GOME_PAIRING_FAILED_LOG,
    /**
     * 手环配对后重连失败
     * The bracelet failed to reconnect after pairing
     */
    GOME_PAIRING_RECONNECT_FAILED_LOG,
    /**
     * 手环配对后重连成功
     * The bracelet successfully to reconnect after pairing
     */
    GOME_PAIRING_RECONNECT_SUCCESS_LOG,
    /**
     * 手环配对后启动设置子开关
     * After the bracelet is paired, start the setting sub-switch
     */
    GOME_PAIRING_RECONNECT_SET_SUB_SWITCH_LOG,
    /**
     * 手环配对后设置子开关失败
     * Failed to set sub-switch after bracelet pairing
     */
    GOME_PAIRING_RECONNECT_SET_SUB_SWITCH_FAILED_LOG,
    /**
     * 手环配对后设置子开关成功
     * Set the sub-switch successfully after the bracelet is paired
     */
    GOME_PAIRING_RECONNECT_SET_SUB_SWITCH_SUCCESS_LOG,
    /**
     * 协议库日志记录
     * protocol c log
     */
    GOME_PROTOCOL_C_LOG
};


#endif /* GOMELogEnum_h */
