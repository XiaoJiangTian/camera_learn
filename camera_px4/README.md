# PX4 Autopilot 高通芯片相机支持示例

本目录展示了 PX4 Autopilot 如何实现对高通芯片（如 Snapdragon Flight）相机模块的支持。

## 架构概述

PX4 在 Snapdragon Flight 平台上的相机支持主要通过以下组件实现：

1. **相机驱动**：负责与硬件直接交互
2. **MAVLink 相机协议**：用于与地面站和其他组件通信
3. **光流处理**：利用相机数据进行视觉导航

## 核心组件

- `camera_driver.c` - 相机驱动实现
- `snapdragon_camera.c` - 高通芯片相机特定实现
- `mavlink_camera.h` - MAVLink 相机协议定义

## 支持的相机

- **Sony IMX135**：高分辨率相机，用于视频捕获
- **Omnivision OV7251**：光流相机，用于导航

## 编译与运行

在 Snapdragon Flight 平台上：

```bash
# 编译相机驱动
cd camera_px4
make

# 运行光流应用
./optical_flow -r VGA -f 30
```

## 配置参数

- 相机分辨率：VGA (640x480) 或 QVGA (320x240)
- 帧率：30、60 或 90 fps
- 曝光控制：自动或手动
- 增益控制：0-255

## 相关资源

- [PX4 snap_cam 仓库](https://github.com/PX4/snap_cam)
- [Snapdragon Flight 文档](https://github.com/marcozorzi/Devguide/blob/master/en/flight_controller/snapdragon_flight.md)
- [MAVLink 相机协议](https://docs.px4.io/main/en/camera/mavlink_v2_camera.html)
