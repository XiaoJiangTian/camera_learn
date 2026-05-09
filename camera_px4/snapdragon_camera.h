#ifndef SNAPDRAGON_CAMERA_H
#define SNAPDRAGON_CAMERA_H

#include <stdbool.h>

// 全局相机设备实例
extern SnapdragonCamera g_snapdragon_camera;

// 高通相机设备结构体
typedef struct {
    int fd;                 // 主设备文件描述符
    int subdev_fd;          // 子设备文件描述符
    int width;              // 图像宽度
    int height;             // 图像高度
    int fps;                // 帧率
    int exposure;           // 曝光值 (0-511)
    int gain;               // 增益值 (0-255)
    bool auto_exposure;     // 自动曝光
    bool initialized;       // 初始化状态
} SnapdragonCamera;

// 高通相机配置结构体
typedef struct {
    int width;              // 图像宽度
    int height;             // 图像高度
    int fps;                // 帧率
    int exposure;           // 曝光值 (0-511)
    int gain;               // 增益值 (0-255)
    bool auto_exposure;     // 自动曝光
} SnapdragonCameraConfig;

// 高通相机信息结构体
typedef struct {
    int width;              // 图像宽度
    int height;             // 图像高度
    int fps;                // 帧率
    int exposure;           // 曝光值
    int gain;               // 增益值
    bool auto_exposure;     // 自动曝光
    bool initialized;       // 初始化状态
} SnapdragonCameraInfo;

/**
 * 初始化高通相机
 * @param config 相机配置
 * @return 0 成功，-1 失败
 */
int SnapdragonCameraInit(SnapdragonCameraConfig *config);

/**
 * 配置高通相机
 * @param camera 相机设备
 * @return 0 成功，-1 失败
 */
int SnapdragonCameraConfigure(SnapdragonCamera *camera);

/**
 * 设置相机分辨率
 * @param camera 相机设备
 * @param width 宽度
 * @param height 高度
 * @return 0 成功，-1 失败
 */
int SnapdragonCameraSetResolution(SnapdragonCamera *camera, int width, int height);

/**
 * 设置相机帧率
 * @param camera 相机设备
 * @param fps 帧率
 * @return 0 成功，-1 失败
 */
int SnapdragonCameraSetFps(SnapdragonCamera *camera, int fps);

/**
 * 设置相机曝光
 * @param camera 相机设备
 * @param exposure 曝光值 (0-511)
 * @return 0 成功，-1 失败
 */
int SnapdragonCameraSetExposure(SnapdragonCamera *camera, int exposure);

/**
 * 设置相机增益
 * @param camera 相机设备
 * @param gain 增益值 (0-255)
 * @return 0 成功，-1 失败
 */
int SnapdragonCameraSetGain(SnapdragonCamera *camera, int gain);

/**
 * 设置自动曝光
 * @param camera 相机设备
 * @param auto_exposure 是否开启自动曝光
 * @return 0 成功，-1 失败
 */
int SnapdragonCameraSetAutoExposure(SnapdragonCamera *camera, bool auto_exposure);

/**
 * 开始相机数据流
 * @param camera 相机设备
 * @return 0 成功，-1 失败
 */
int SnapdragonCameraStart(SnapdragonCamera *camera);

/**
 * 捕获一帧图像
 * @param camera 相机设备
 * @param buffer 图像缓冲区
 * @param buffer_size 缓冲区大小
 * @return 0 成功，-1 失败
 */
int SnapdragonCameraCaptureFrame(SnapdragonCamera *camera, uint8_t *buffer, size_t buffer_size);

/**
 * 停止相机数据流
 * @param camera 相机设备
 * @return 0 成功，-1 失败
 */
int SnapdragonCameraStop(SnapdragonCamera *camera);

/**
 * 关闭相机设备
 * @param camera 相机设备
 * @return 0 成功，-1 失败
 */
int SnapdragonCameraClose(SnapdragonCamera *camera);

/**
 * 获取相机信息
 * @param camera 相机设备
 * @param info 相机信息
 * @return 0 成功，-1 失败
 */
int SnapdragonCameraGetInfo(SnapdragonCamera *camera, SnapdragonCameraInfo *info);

#endif // SNAPDRAGON_CAMERA_H
