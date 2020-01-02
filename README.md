
![image](/images/logo.png)

# GOMEBluetooth 、GOMEBlueProtocol 、GOMEBlueUpdate
>GOMEBluetooth, GOMEBlueProtocol, GOMEBlueUpdate适用于iOS设备和国美智慧城公司的手环实现蓝牙连接控制框架库。基于iOS系统的蓝牙框架，扩展了蓝牙扫描、连接、绑定、控制、设置、读取、监听等功能的抽象。利用c编写的协议库实现蓝牙数据的转换和数据同步过程的逻辑处理，减少了蓝牙通信的错误，提高了蓝牙通信的速度和精度。这个功能丰富的API很容易使用，而且非常好用.

## 开始
* 下载 [GOMEBluetooth](https://github.com/MaxsLin/GOMEBluetooth/archive/master.zip) 并引入到项目中;
 
## 版本
| SDK 版本 | iOS最低版本| 描述 |
| :------:| :------: |------|
| 3.3.8| iOS 8.0 |add v3 health data sync|
| 3.3.9| iOS 8.0 |add dial transmission xcode 11.2.1|

## 配置

* 项目配置
  <br>![image](/images/2.png)
  <br>
  <br>![image](/images/3.png)
  <br>
  <br>![image](/images/4.png)
  <br>
  <br>![image](/images/5.png)
  <br>
* 系统依赖
  <br>![image](/images/8.png)
  <br>
  
## 结构

```
1、GOMEBluetooth 
#import <GOMEBluetooth/GOMEBlueEnum.h>
#import <GOMEBluetooth/GOMEPeripheralModel.h>
#import <GOMEBluetooth/GOMEBluetoothManager.h>

2、GOMEBlueUpdate 
#import <GOMEBlueUpdate/GOMEUpdateEnum.h>
#import <GOMEBlueUpdate/GOMEUpdateFirmwareManager.h>

3、GOMEBlueProtocol 
#import <GOMEBlueProtocol/GOMESyncEnum.h>
#import <GOMEBlueProtocol/GOMELogEnum.h>
#import <GOMEBlueProtocol/GOMEBindEnum.h>
#import <GOMEBlueProtocol/GOMETranEnum.h>
#import <GOMEBlueProtocol/GOMECommonMacro.h>

#import <GOMEBlueProtocol/GOMEBluetoothBaseModel.h>
#import <GOMEBlueProtocol/GOMESyncSwimDataModel.h>
#import <GOMEBlueProtocol/GOMESyncSpo2DataModel.h>
#import <GOMEBlueProtocol/GOMESyncPressureDataModel.h>
#import <GOMEBlueProtocol/GOMESyncActivityDataModel.h>
#import <GOMEBlueProtocol/GOMESyncBpDataModel.h>
#import <GOMEBlueProtocol/GOMESyncHeartRateDataModel.h>
#import <GOMEBlueProtocol/GOMESyncSleepDataModel.h>
#import <GOMEBlueProtocol/GOMESyncSportDataModel.h>
#import <GOMEBlueProtocol/GOMESyncGpsDataModel.h>
#import <GOMEBlueProtocol/GOMEDataExchangeModel.h>
#import <GOMEBlueProtocol/GOMEGetInfoBluetoothModel.h>
#import <GOMEBlueProtocol/GOMESetInfoBluetoothModel.h>
#import <GOMEBlueProtocol/GOMECalculateBluetoothModel.h>
#import <GOMEBlueProtocol/GOMEWeightBluetoothModel.h>
#import <GOMEBlueProtocol/GOMEWatchDialInfoModel.h>


#import <GOMEBlueProtocol/GOMESyncManager.h>
#import <GOMEBlueProtocol/GOMEBluetoothEngine.h>
#import <GOMEBlueProtocol/GOMEBluetoothServices.h>
#import <GOMEBlueProtocol/GOMEErrorCodeToStr.h>
#import <GOMEBlueProtocol/GOMERecordDeviceLog.h>
#import <GOMEBlueProtocol/GOMEBlueDataResponse.h>

#import <GOMEBlueProtocol/GOMEFoundationCommand.h>
#import <GOMEBlueProtocol/GOMEDataMigrationManager.h>
#import <GOMEBlueProtocol/GOMETransferFileManager.h>
#import <GOMEBlueProtocol/GOMEWatchDialManager.h>
#import <GOMEBlueProtocol/GOMEMakePhotoManager.h>
```
## API介绍

* [1.0 历史数据迁移](#1.0)  
* [2.0 注册服务](#2.0)  
* [3.0 启动蓝牙管理](#3.0) 
* [4.0 手环绑定](#4.0) 
* [5.0 数据同步](#5.0) 
* [6.0 数据查询](#6.0) 

## <span id="1.0">历史数据迁移</span>
* <p>只有在旧的项目中需要做数据迁移，旧的数据库需要迁移到新的数据库中，优化数据库的操作，减少数据冗余，提高程序性能。在执行数据迁移之前，需要确定旧数据库是否存在，在数据迁移之后，需要传入一组不能删除的目录名，以确保数据完整性。迁移完成后，将删除未保留的数据，并将旧数据库复制到新目录中，可以通过该路径获取新目录</p>

```objc
  if ([GOMEDataMigrationManager isNeedMigration]) {
        [GOMEDataMigrationManager dataMigrationProgressBlock:^(float progress) {
            
        }];
        [GOMEDataMigrationManager dataMigrationWithFileNames:@[@"user directory name"]
                                              completeBlock:^(BOOL isSuccess) {
            
        }];
        [GOMEDataMigrationManager dataMigrationStart];
    }
```
* <p>上传数据库文件，以保存和更新。下载的数据库是一个需要首先迁移的旧数据库。迁移完成后，本地新数据库被传输到json文件并上传到服务器。如果将数据作为json文件下载，则首先合并新数据库，然后将合并后的json文件传输到服务器.</p>

```objc
 [GOMEDataMigrationManager dataToJsonFileProgressBlock:^(float progress) {
        
  }];
 [GOMEDataMigrationManager dataToJsonFileCompleteBlock:^(BOOL isSuccess, NSString *newDirePath) {
        
 }];
 //Directory path for downloaded JSON files
 [GOMEDataMigrationManager dataToJsonFileStart:@""];
```
## <span id="2.0">注册服务</span>
* <p>注册服务，控制SDK运行日志输出和协议库。阿里云日志暂时无效。注意:蓝牙设置需要在注册服务时添加一个连续的后台配置.</p>

```objc

#ifdef DEBUG
    registrationServices().outputSdkLog(YES).outputProtocolLog(YES).startScanBule(^(GOMEGetDeviceInfoBluetoothModel * _Nullable model) {
        //You can use your own bluetooth management here
        if(__GOME_BIND__)[GOMEBluetoothManager startScan];
        else [GOMEBluetoothManager refreshDelegate];
    });
#else
    registrationServices().outputSdkLog(NO).outputProtocolLog(NO).startScanBule(^(GOMEGetDeviceInfoBluetoothModel * _Nullable model) {
        //You can use your own bluetooth management here
        if(__GOME_BIND__)[GOMEBluetoothManager startScan];
        else [GOMEBluetoothManager refreshDelegate];
    });
#endif
```
## <span id="3.0">启动蓝牙管理</span>
* <p>当您应用一个未连接的绑定设备时，您需要创建一个视图控制器来实现SDK蓝牙代理。扫描外围设备，代理将返回设备集合，在列表中显示，选择需要连接的设备，连接成功后返回设备信息和设备是否处于OTA模式，连接失败会有一个错误回调。默认扫描信号滤波参数为80，自动扫描连接超时时间为20秒。</p>

```objc
<GOMEBluetoothManagerDelegate>
[GOMEBluetoothManager shareInstance].delegate = self;
[GOMEBluetoothManager shareInstance].rssiNum = 100;

#pragma mark === GOMEBluetoothManagerDelegate ===
- (BOOL)bluetoothManager:(GOMEBluetoothManager *)manager
           centerManager:(CBCentralManager *)centerManager
    didConnectPeripheral:(CBPeripheral *)peripheral
               isOatMode:(BOOL)isOtaMode
{
  //Device connected successfully
}

- (void)bluetoothManager:(GOMEBluetoothManager *)manager
              allDevices:(NSArray<GOMEPeripheralModel *> *)allDevices
              otaDevices:(NSArray<GOMEPeripheralModel *> *)otaDevices
{
  //Scanning peripherals
}

- (void)bluetoothManager:(GOMEBluetoothManager *)manager
          didUpdateState:(GOME_BLUETOOTH_MANAGER_STATE)state
{
    //Bluetooth manages center state
}

- (void)bluetoothManager:(GOMEBluetoothManager *)manager
  connectPeripheralError:(NSError *)error
{
    //Returns an error
}
```
## <span id="4.0">手环绑定</span>

* <p>设备在连接状态下，绑定设备初始化“gomesetbindinginfo蓝牙thmodel”对象，来绑定命令，返回绑定状态和命令错误代码，绑定状态分为:绑定、已绑定、绑定失败、成功需要授权绑定、拒绝绑定。“需要授权绑定”模式需要用户填写授权码，并点击ok，才能绑定设备。授权信息仅存储在“需要授权绑定”模式下;其他绑定则不是。</p>

```objc
GOMESetBindingInfoBluetoothModel * model = [[GOMESetBindingInfoBluetoothModel alloc]init];
    __weak typeof(self) weakSelf = self;
    [GOMEFoundationCommand bindingCommand:model callback:^(GOME_BIND_STATUS status, int errorCode) {
        __strong typeof(self) strongSelf = weakSelf;
        if (errorCode == 0) {
            if (status == GOME_BLUETOOTH_BIND_SUCCESS) { //bind success
            
            }else if (status == GOME_BLUETOOTH_BINDED) { //binded
                
            }else if (status == GOME_BLUETOOTH_BIND_FAILED) { //bind failed
                
            }else if (status == GOME_BLUETOOTH_NEED_AUTH) { //bind need auth
                [strongSelf showAuthView];
            }else if (status == GOME_BLUETOOTH_REFUSED_BINDED) { //refused binded
                
            }
        }else { //bind failed
            
        }
    }];
    
     __weak typeof(self) weakSelf = self;
GOMESetBindingInfoBluetoothModel * model = [GOMESetBindingInfoBluetoothModel currentModel];
model.authCode = codeStr;
[GOMEFoundationCommand setAuthCodeCommand:model callback:^(int errorCode) {
    __strong typeof(self) strongSelf = weakSelf;
    if (errorCode == 0) {
    
    }else {
        
    }
}];
    
```
## <span id="5.0">数据同步</span>

* <p>同步设备数据是一个非常重要的功能。同步过程建议不要执行其他命令，即使它们是无效的。同步配置是在连接设备的第一次成功绑定之后执行的。否则，NO是不同步的。在同步过程中返回进度，并在每个项同步后返回一个完成块。根据同步状态判断，同步已经完成，同步过程中将返回同步日志。</p>

```objc
initSyncManager().wantToSyncType = GOME_WANT_TO_SYNC_CONFIG_ITEM_TYPE | GOME_WANT_TO_SYNC_HEALTH_ITEM_TYPE
    | GOME_WANT_TO_SYNC_ACTIVITY_ITEM_TYPE | GOME_WANT_TO_SYNC_GPS_ITEM_TYPE;
 
initSyncManager().isSave = YES;
 initSyncManager().addSyncComplete(^(GOME_SYNC_COMPLETE_STATUS stateCode) {
               
 }).addSyncProgess(^(GOME_CURRENT_SYNC_TYPE type, float progress) {
               
 }).addSyncFailed(^(int errorCode) {
               
 }).mandatorySyncConfig(YES or NO);
 [GOMESyncManager startSync];
```
## <span id="6.0">数据查询</span>
* <P>蓝牙命令初始化模型的一般方法是在每个类对象中“(__kindof GOMEBluetoothBaseModel*)currentModel”。如果查询未能初始化新模型对象，此方法将首先查询数据库。同步数据是用于在每个模型类中查询数据的一种封装方法。只有封装的方法查询才有详细的数据，而自定义查询方法查询的数据没有详细的数据。建议数据库操作不要删除数据库数据，只插入和更新数据。当前数据只能在同步完成后查询。未同步的数据仍然在手环中，并且无法在本地查询数据。</P>

```objc
1、活动数据查询

 + (__kindof GOMESyncActivityDataInfoBluetoothModel *)queryOneActivityDataWithTimeStr:(NSString *)timeStr macAddr:(NSString *)macAddr;

 + (NSArray <__kindof GOMESyncActivityDataInfoBluetoothModel *>*)queryOneDayActivityDataWithMacAddr:(NSString *)macAddr year:(NSInteger)year
 month:(NSInteger)month day:(NSInteger)day;                                     

+ (NSArray <__kindof GOMESyncActivityDataInfoBluetoothModel *>*)queryOnePageActivityDataWithPageIndex:(NSInteger)pageIndex
numOfPage:(NSInteger)numOfPage macAddr:(NSString *)macAddr;                                                             

+ (NSArray <__kindof GOMESyncActivityDataInfoBluetoothModel *>*)queryAllTrajectorySportActivitysWithMac:(NSString *)macAddr;

+ (NSArray <__kindof GOMESyncActivityDataInfoBluetoothModel *>*)queryAllLightSportActivitysWithMac:(NSString *)macAddr;

2、血压查询

+ (NSArray <NSArray<__kindof GOMESyncBpDataInfoBluetoothModel *>*> *)queryOneYearBloodPressuresWithYear:(NSInteger)year macAddr:(NSString *)macAddr isQueryItems:(BOOL)isQuery;

+ (NSArray <__kindof GOMESyncBpDataInfoBluetoothModel *>*)queryOneMonthBloodPressuresWithYear:(NSInteger)year month:(NSInteger)month
macAddr:(NSString *)macAddr datesOfMonth:(NSArray <NSString *>**)dates isQueryItems:(BOOL)isQuery;                                                                        

+ (NSArray <__kindof GOMESyncBpDataInfoBluetoothModel *>*)queryOneWeekBloodPressuresWithWeekIndex:(NSInteger)weekIndex weekStartDay:(NSInteger)weekStartDay macAddr:(NSString *)macAddr datesOfWeek:(NSArray <NSString *>**)dates isQueryItems:(BOOL)isQuery;                                                                                 
+ (__kindof GOMESyncBpDataInfoBluetoothModel *)queryOneDayBloodPressureDetailWithMac:(NSString *)macAddr year:(NSInteger)year
month:(NSInteger)month day:(NSInteger)day;                                                                    

+ (__kindof GOMESyncBpDataInfoBluetoothModel *)queryLastDayBloodPressureDetailWithMac:(NSString *)macAddr;

+ (NSArray <__kindof GOMESyncBpDataInfoBluetoothModel *>*)queryAllBloodPressuresWithMac:(NSString *)macAddr;

3、心率查询

+ (NSArray <NSArray<__kindof GOMESyncHrDataInfoBluetoothModel *>*> *)queryOneYearHearRatesWithYear:(NSInteger)year macAddr:(NSString *)macAddr isQueryItems:(BOOL)isQuery;

+ (NSArray <__kindof GOMESyncHrDataInfoBluetoothModel *>*)queryOneMonthHearRatesWithYear:(NSInteger)year month:(NSInteger)month
macAddr:(NSString *)macAddr datesOfMonth:(NSArray <NSString *>**)dates isQueryItems:(BOOL)isQuery;                                                                                                      
+ (NSArray <__kindof GOMESyncHrDataInfoBluetoothModel *>*)queryOneWeekHearRatesWithWeekIndex:(NSInteger)weekIndex weekStartDay:(NSInteger)weekStartDay macAddr:(NSString *)macAddr datesOfWeek:(NSArray <NSString *>**)dates isQueryItems:(BOOL)isQuery;                                                                   
+ (__kindof GOMESyncHrDataInfoBluetoothModel *)queryOneDayHearRatesDetailWithMac:(NSString *)macAddr year:(NSInteger)year month:(NSInteger)month day:(NSInteger)day;
                                                                         
+ (NSArray <__kindof GOMESyncHrDataInfoBluetoothModel *>*)queryAllHearRatesWithMac:(NSString *)macAddr;

4、睡眠查询

+ (NSArray <NSArray <__kindof GOMESyncSleepDataInfoBluetoothModel *>*>*)queryOneYearSleepsWithYear:(NSInteger)year macAddr:(NSString *)macAddr isQueryItems:(BOOL)isQuery;

+ (NSArray <__kindof GOMESyncSleepDataInfoBluetoothModel *>*)queryOneMonthSleepsWithYear:(NSInteger)year month:(NSInteger)month
macAddr:(NSString *)macAddr datesOfMonth:(NSArray <NSString *>**)dates isQueryItems:(BOOL)isQuery;
                                                                                                                                            
+ (NSArray <__kindof GOMESyncSleepDataInfoBluetoothModel *>*)queryOneWeekSleepsWithWeekIndex:(NSInteger)weekIndex weekStartDay:(NSInteger)weekStartDay macAddr:(NSString *)macAddr datesOfWeek:(NSArray <NSString *>**)dates isQueryItems:(BOOL)isQuery;
                                                                                                                                            
+ (__kindof GOMESyncSleepDataInfoBluetoothModel *)queryOneDaySleepsDetailWithMac:(NSString *)macAddr year:(NSInteger)year month:(NSInteger)month day:(NSInteger)day;
                                                                         
+ (NSArray <__kindof GOMESyncSleepDataInfoBluetoothModel *>*)queryAllSleepsWithMac:(NSString *)macAddr;

5、运动查询

+ (NSArray <NSArray <__kindof GOMESyncSportDataInfoBluetoothModel *> *>*)queryOneYearSportsWithYear:(NSInteger)year macAddr:(NSString *)macAddr isQueryItems:(BOOL)isQuery;

+ (NSArray <__kindof GOMESyncSportDataInfoBluetoothModel *>*)queryOneMonthSportsWithYear:(NSInteger)year month:(NSInteger)month
macAddr:(NSString *)macAddr datesOfMonth:(NSArray <NSString *>**)dates isQueryItems:(BOOL)isQuery;
                                                                                                                                             
+ (NSArray <__kindof GOMESyncSportDataInfoBluetoothModel *>*)queryOneWeekSportsWithWeekIndex:(NSInteger)weekIndex weekStartDay:(NSInteger)weekStartDay macAddr:(NSString *)macAddr datesOfWeek:(NSArray <NSString *>**)dates isQueryItems:(BOOL)isQuery;
                                                                                                                                                  
+ (__kindof GOMESyncSportDataInfoBluetoothModel *)queryOneDaySportDetailWithMac:(NSString *)macAddr year:(NSInteger)year month:(NSInteger)month day:(NSInteger)day;

+ (NSArray <__kindof GOMESyncSportDataInfoBluetoothModel *>*)queryAllSportsWithMac:(NSString *)macAddr;

6、GPS 查询


+ (__kindof GOMESyncGpsDataInfoBluetoothModel *)queryOneActivityCoordinatesWithTimeStr:(NSString *)timeStr macAddr:(NSString *)macAddr;


+ (BOOL)queryActivityHasCoordinatesWithTimeStr:(NSString *)timeStr macAddr:(NSString *)macAddr;
```
