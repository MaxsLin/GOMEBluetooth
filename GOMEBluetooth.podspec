Pod::Spec.new do |s|
  s.name         = "GOMEBluetooth"
  s.version      = "3.8.9"
  s.summary      = "sdk"
  s.homepage     = "https://github.com/MaxsLin/GOMEBluetooth"
  s.license      = { :type => "MIT"}
  s.platform     = :ios, "8.0"
  s.authors      = { 'Max Mak' => 'maxmak@maxsmak.com'}
  s.source       = { :git => "https://github.com/MaxsLin/GOMEBluetooth.git", :tag => s.version}
  s.source_files = "*.{h,m,mm,swift}"
  
  s.vendored_frameworks = "Embedded/*.framework"
  s.frameworks = ["CoreBluetooth"]
  s.library = ["sqlite3.0"]
  
  s.pod_target_xcconfig = { 'ENABLE_BITCODE' => 'NO','OTHER_LDFLAGS' => '-ObjC' }
  
#  s.user_target_xcconfig = { 'ENABLE_BITCODE' => 'NO' }

end
