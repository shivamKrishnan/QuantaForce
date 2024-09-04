$libraylibUrl = "https://github.com/raysan5/raylib/releases/download/4.5.0/raylib-4.5.0_win64_mingw-w64.a"
$raylibHeaderUrl = "https://github.com/raysan5/raylib/raw/master/src/raylib.h"
$raymathHeaderUrl = "https://github.com/raysan5/raylib/raw/master/src/raymath.h"
$rlglHeaderUrl = "https://github.com/raysan5/raylib/raw/master/src/rlgl.h"

$libDir = "./lib"
if (-Not (Test-Path -Path $libDir)) {
    New-Item -ItemType Directory -Force -Path $libDir
}

Invoke-WebRequest -Uri $libraylibUrl -OutFile "$libDir/libraylib.a"
Invoke-WebRequest -Uri $raylibHeaderUrl -OutFile "$libDir/raylib.h"
Invoke-WebRequest -Uri $raymathHeaderUrl -OutFile "$libDir/raymath.h"
Invoke-WebRequest -Uri $rlglHeaderUrl -OutFile "$libDir/rlgl.h"

Write-Output "Raylib setup completed. All files have been downloaded to $libDir."
