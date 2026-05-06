# ESP32-S3 Example 2

An ESP-IDF project for the ESP32-S3 demonstrating FreeRTOS tasks and a reusable uptime formatting component.

## Features

- Three concurrent FreeRTOS tasks logging at different intervals (2 s, 5 s, 10 s)
- `utils` component with a `format_uptime()` function that formats seconds as `HH:MM:SS`
- Unit tests for `format_uptime` using GoogleTest (runs on host, no hardware needed)

## Project structure

```
.
├── main/               # App entry point, task definitions
├── components/
│   └── utils/          # format_uptime() component
│       ├── include/uptime.h
│       └── uptime.cpp
└── test/               # GoogleTest host tests for utils
```

## Requirements

- [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/) v5.x
- CMake 3.16+
- A C++17-capable toolchain (host tests only need a standard compiler)

## Build & flash

```bash
idf.py build
idf.py -p /dev/ttyUSB0 flash monitor
```

## Running unit tests

```bash
cd test
cmake -B build && cmake --build build
./build/test_uptime
```
