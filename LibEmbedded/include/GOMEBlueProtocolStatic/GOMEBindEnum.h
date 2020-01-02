//
//  GOMEBindEnum.h
//  GOMEBluetoothInternal
//
//  Created by Max Mak on 2019/8/3.
//  Copyright © 2019 Max Mak. All rights reserved.
//

#ifndef GOMEBindEnum_h
#define GOMEBindEnum_h

/**
 * 绑定状态枚举
 * Binding status enumeration
 */
typedef NS_ENUM(NSInteger, GOME_BIND_STATUS) {
    /**
     * 绑定失败
     * Binding failed
     */
    GOME_BLUETOOTH_BIND_FAILED = 0,
    
    /**
     * 绑定成功
     * Binding succeeded
     */
    GOME_BLUETOOTH_BIND_SUCCESS,
    
    /**
     * 已经绑定
     * Already bound
     */
    GOME_BLUETOOTH_BINDED,
    
    /**
     * 需要授权绑定
     * Need authorization binding
     */
    GOME_BLUETOOTH_NEED_AUTH,
    
    /**
     * 拒绝绑定
     * Rejected binding
     */
    GOME_BLUETOOTH_REFUSED_BINDED,
    
};

#endif /* GOMEBindEnum_h */
