//
//  GOMEWatchDialInfoModel.h
//  GOMEBluetoothInternal
//
//  Created by Max Mak on 2019/8/21.
//  Copyright © 2019 Max Mak. All rights reserved.
//

#if __has_include(<GOMEBluetoothInternal/GOMEBluetoothInternal.h>)
#elif __has_include(<GOMEBlueProtocol/GOMEBlueProtocol.h>)
#else
#import "GOMEBluetoothBaseModel.h"
#endif

@interface GOMEWatchScreenInfoModel : GOMEBluetoothBaseModel
/**
 表盘家族名称 | family name
 */
@property (nonatomic,copy) NSString * familyName;
/**
 宽度 | width
 */
@property (nonatomic,assign) NSInteger width;
/**
 高度 | height
 */
@property (nonatomic,assign) NSInteger height;
/**
 颜色格式 | color format
 */
@property (nonatomic,assign) NSInteger colorFormat;
/**
 尺寸 * 100 | size * 100
 */
@property (nonatomic,assign) NSInteger size;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return GOMEWatchScreenInfoModel
 */
+ (__kindof GOMEWatchScreenInfoModel *)currentModel;

@end

@interface GOMEWatchDialInfoItemModel : GOMEBluetoothBaseModel
/**
 表盘名称（唯一标示） | file name (only sign)
 */
@property (nonatomic,copy) NSString * fileName;

/**
 * 操作 0x00:查询正在使用表盘 0x01:设置表盘 0x02:删除表盘
 * Operation 0x00: query is using the dial 0x01: set the dial 0x02: delete the dial
 */
@property (nonatomic,assign) NSInteger operate;

@end


@interface GOMEWatchDialInfoModel : GOMEBluetoothBaseModel
/**
 * 文件个数
 * file count
 */
@property (nonatomic,assign) NSInteger fileCount;
/**
 * 剩余空间 KB
 * remaining Space
 */
@property (nonatomic,assign) NSInteger remainingSpace;
/**
 * 单个文件最大size  KB
 * file max size
 */
@property (nonatomic,assign) NSInteger fileMaxSize;
/**
 *  当前设置的表盘名称
 *  name of the dial currently set
*/
@property (nonatomic,copy) NSString * currentDialName;
/**
 * 当前手环所有表盘信息集合
 * Current bracelet all dial information set
 */
@property (nonatomic,strong) NSArray <GOMEWatchDialInfoItemModel *>* dialArray;

/**
 * @brief 查询数据库,如果查询不到初始化新的model对象
 * Query the database, if the query does not initialize a new model object
 * @return GOMEWatchDialInfoModel
 */
+ (__kindof GOMEWatchDialInfoModel *)currentModel;

@end
