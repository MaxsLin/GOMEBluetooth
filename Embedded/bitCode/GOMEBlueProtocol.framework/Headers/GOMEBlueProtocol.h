//
//  GOMEBlueProtocol.h
//  GOMEBlueProtocol
//
//  Created by Max Mak on 2019/5/8.
//  Copyright © 2019 Max Mak. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for GOMEBlueProtocol.
FOUNDATION_EXPORT double GOMEBlueProtocolVersionNumber;

//! Project version string for GOMEBlueProtocol.
FOUNDATION_EXPORT const unsigned char GOMEBlueProtocolVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <GOMEBlueProtocol/PublicHeader.h>

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
