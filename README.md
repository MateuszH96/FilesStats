# Folder Statisctic



## Compile project

in build folder(CMake)
```bash
cmake ..
cmake --build .
```
in main folder
```bash
g++ main.cpp ReadFile.cpp ReadDirectory.cpp -o FileStats -std=c++17 -Wall
```

## Uruchomienie projektu

curren folder
```bash
./FileStats
```
other folder

```bash
./FileStats "path to folder"
```
example
```bash
./FileStats "/home/mateusz/Desktop/CountFilesInFolder"
```

## Author

Mateusz Hamera
