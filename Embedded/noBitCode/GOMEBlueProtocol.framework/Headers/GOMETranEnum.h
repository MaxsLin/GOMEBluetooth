//
//  GOMETranEnum.h
//  GOMEBluetoothInternal
//
//  Created by Max Mak on 2019/8/7.
//  Copyright © 2019 Max Mak. All rights reserved.
//

#ifndef GOMETranEnum_h
#define GOMETranEnum_h

/**
 压缩类型 | compression type
 */
typedef NS_ENUM(NSInteger, GOME_DATA_TRAN_COMPRESSION_TYPE) {
    /**
     不适用压缩 | no use
     */
    GOME_DATA_TRAN_COMPRESSION_NO_USE_TYPE = 0,
    /**
     zlib压缩 | zlib
     */
    GOME_DATA_TRAN_COMPRESSION_ZLIB_TYPE = 1,
    /**
     fastlz压缩 | fastlz
     */
    GOME_DATA_TRAN_COMPRESSION_FASTLZ_TYPE = 2,
    
};

/**
 文件传输类型 | file transfer type
 */
typedef NS_ENUM(NSInteger, GOME_DATA_FILE_TRAN_TYPE) {
    /**
     AGPS 文件 | AGPS file type
     */
    GOME_DATA_FILE_TRAN_AGPS_TYPE = 1,
    /**
     表盘 文件 | dial file type
     */
    GOME_DATA_FILE_TRAN_DIAL_TYPE = 2,
    /**
      字库 文件 | word file type
    */
    GOME_DATA_FILE_TRAN_WORD_TYPE = 3,
    /**
     图片文件 | photo file type
     */
    GOME_DATA_FILE_TRAN_PHOTO_TYPE = 4
};

/**
 文件传输状态 | file transfer state type
 */
typedef NS_ENUM(NSInteger, GOME_DATA_FILE_TRAN_STATE_TYPE) {
    /**
     文件传输初始值 | transmission init
     */
    GOME_DATA_FILE_TRAN_INIT_TYPE = 0,
    /**
     文件开始传输 | start transmission
     */
    GOME_DATA_FILE_TRAN_START_TYPE = 1,
    /**
     文件传输中 | transmissioning
     */
    GOME_DATA_FILE_TRAN_ING_TYPE = 2,
    /**
     文件传输成功 | transmission success
     */
    GOME_DATA_FILE_TRAN_SUCCESS_TYPE = 3,
    /**
     文件传输失败 | transmission failed
     */
    GOME_DATA_FILE_TRAN_FAILED_TYPE = 4,
    /**
     文件开始写入 | start write
     */
    GOME_DATA_FILE_WRITE_TYPE = 5,
    /**
     文件写入成功 | write success
     */
    GOME_DATA_FILE_WRITE_SUCCESS_TYPE = 6,
    /**
     文件写入失败 | write failed
     */
    GOME_DATA_FILE_WRITE_FAILED_TYPE = 7,
    
};


#endif /* GOMETranEnum_h */
