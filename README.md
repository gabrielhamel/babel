# Babel

## Build

### 1) Install [Conan](https://conan.io) and [QT 5.12.5](https://wiki.qt.io/Special:Search/Install_Qt_5)

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

### 5) Create your own build configuration
To check the configuration of build
```bash
cmake .. -G
```
Build with specify configuration (eg. change "Unix Makefile" by your configuration name)
```bash
cmake .. -G "Unix Makefiles"
```

### 6) Launch the build
If you have Unix Makefiles
```bash
make
```
else if you have Visual studio project, just open and build

### 8) Launch the binary
