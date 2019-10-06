# Babel

## Build

### 1) Install [Conan](https://conan.io)

### 2) Add remote bincrafters
```bash
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
```

### 3) Create build directory
```bash
mkdir build && cd build
```

### 4) Install conan dependency
```bash
conan install ..
```

There may be problems during the installation. To solve that, add  ```--build``` with dependency at the end of the command

### 5) Config QT
Add these variables [into your environment](https://unix.stackexchange.com/questions/117467/how-to-permanently-set-environmental-variables)
if your are on linux
```bash
export QT_QPA_PLATFORM_PLUGIN_PATH=$HOME/.conan/data/qt/5.12.5/bincrafters/stable/package/32907dd96d45d2305e039a835e067b78abca2026/plugins
```
Check if these path exist else find them and change the line
```bash
export QT_QPA_FONTDIR=/usr/share/fonts/X11/Type1 (Debian/Ubuntu)
export QT_QPA_FONTDIR=/usr/share/X11/fonts/Type1 (Fedora/OpenSuse/Centos)
```

### 6) Create your own build configuration
To check the configuration of build
```bash
cmake .. -G
```
Build with specify configuration (eg. change "Unix Makefile" by your configuration name)
```bash
cmake .. -G "Unix Makefiles"
```

### 7) Launch the build
If you have Unix Makefiles
```bash
make
```
else if you have Visual studio project, just open and build

### 8) Launch the binary
