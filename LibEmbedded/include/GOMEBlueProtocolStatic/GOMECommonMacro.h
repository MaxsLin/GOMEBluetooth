//
//  GOMECommonMacro.h
//  GOMEBluetoothInternal
//
//  Created by Max Mak on 2019/7/8.
//  Copyright © 2019 Max Mak. All rights reserved.
//

#ifndef GOMECommonMacro_h
#define GOMECommonMacro_h

#if __has_include(<GOMEBluetoothInternal/GOMEBluetoothInternal.h>)
#elif __has_include(<GOMEBlueProtocol/GOMEBlueProtocol.h>)
#else
#import "GOMEBluetoothEngine.h"
#endif

/**
 GOME 当前手环蓝牙引擎 | GOME current bracelet Bluetooth engine
 */
#define GOME_BLUE_ENGINE  [GOMEBluetoothEngine shareInstance]

/**
 GOME 当前手环蓝牙功能列表 | GOME Current Bracelet Bluetooth Feature List
 */
#define __GOME_FUNCTABLE__  GOME_BLUE_ENGINE.managerEngine.funcTableModel

/**
 GOME 当前蓝牙系统管理对象 | GOME Current Bluetooth System Management Object
 */
#define __GOME_MANAGER__  GOME_BLUE_ENGINE.managerEngine.centralManager

/**
 GOME 当前外围设备对象 | GOME Current Peripheral Object
 */
#define __GOME_PERIPHERAL__  GOME_BLUE_ENGINE.managerEngine.peripheral

/**
 GOME 当前外围设备是否连接 | GOME Current Peripheral is connected
 */
#define __GOME_CONNECTED__  GOME_BLUE_ENGINE.managerEngine.connected

/**
 GOME 当前外围设备是否连接中 | GOME Current Peripheral is connecting
 */
#define __GOME_CONNECTING__  GOME_BLUE_ENGINE.managerEngine.connecting

/**
 GOME 当前蓝牙管理中心是否开启 | GOME Current blue manager is powered on
 */
#define __GOME_POWERED_ON__  GOME_BLUE_ENGINE.managerEngine.poweredOn

/**
 GOME 当前手环UUID | GOME Current Bracelet UUID
 */
#define __GOME_UUID__  GOME_BLUE_ENGINE.peripheralEngine.uuidStr

/**
 GOME 当前手环MAC | GOME Current Bracelet MAC
 */
#define __GOME_MAC_ADDR__  GOME_BLUE_ENGINE.peripheralEngine.macAddr

/**
 GOME 当前手环绑定状态 | GOME Current Bracelet Binding Status
 */
#define __GOME_BIND__  GOME_BLUE_ENGINE.peripheralEngine.isBind

/**
 GOME 当前手环配对中状态 | GOME Current Bracelet pairing Status
 */
#define __GOME_PAIRING__  GOME_BLUE_ENGINE.peripheralEngine.isPairing

/**
 GOME 用户ID | GOME User ID
 */
#define __GOME_USER_ID__  GOME_BLUE_ENGINE.userEngine.userId

/**
 GOME 当前手环ota状态 | GOME current bracelet ota status
 */
#define __GOME_OTA__  GOME_BLUE_ENGINE.peripheralEngine.isOta

/**
 GOME 当前手环名字 | GOME Current Bracelet Name
 */
#define __GOME_NAME__  GOME_BLUE_ENGINE.peripheralEngine.deviceName


#endif /* GOMECommonMacro_h */
