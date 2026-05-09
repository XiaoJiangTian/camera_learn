#ifndef CAMERA_DRIVER_H
#define CAMERA_DRIVER_H

#include <stdbool.h>

// 相机格式定义
typedef enum {
    CAMERA_FORMAT_RAW,
    CAMERA_FORMAT_YUV,
    CAMERA_FORMAT_RGB,
    CAMERA_FORMAT_JPEG
} CameraFormat;

// 相机设备结构体
typedef struct {
    int fd;                 // 设备文件描述符
    int width;              // 图像宽度
    int height;             // 图像高度
    int fps;                // 帧率
    CameraFormat format;    // 图像格式
    bool initialized;       // 初始化状态
} CameraDevice;

// 相机配置结构体
typedef struct {
    int width;              // 图像宽度
    int height;             // 图像高度
    int fps;                // 帧率
    CameraFormat format;    // 图像格式
} CameraConfig;

// 相机信息结构体
typedef struct {
    int width;              // 图像宽度
    int height;             // 图像高度
    int fps;                // 帧率
    CameraFormat format;    // 图像格式
    bool initialized;       // 初始化状态
} CameraInfo;

/**
 * 初始化相机设备
 * @param device_path 设备路径
 * @param config 相机配置
 * @return 0 成功，-1 失败
 */
int CameraInit(const char *device_path, CameraConfig *config);

/**
 * 配置相机参数
 * @param dev 相机设备
 * @return 0 成功，-1 失败
 */
int CameraConfigure(CameraDevice *dev);

/**
 * 开始相机数据流
 * @param dev 相机设备
 * @return 0 成功，-1 失败
 */
int CameraStart(CameraDevice *dev);

/**
 * 捕获一帧图像
 * @param dev 相机设备
 * @param buffer 图像缓冲区
 * @param buffer_size 缓冲区大小
 * @return 0 成功，-1 失败
 */
int CameraCaptureFrame(CameraDevice *dev, uint8_t *buffer, size_t buffer_size);

/**
 * 停止相机数据流
 * @param dev 相机设备
 * @return 0 成功，-1 失败
 */
int CameraStop(CameraDevice *dev);

/**
 * 关闭相机设备
 * @param dev 相机设备
 * @return 0 成功，-1 失败
 */
int CameraClose(CameraDevice *dev);

/**
 * 获取相机设备信息
 * @param dev 相机设备
 * @param info 相机信息
 * @return 0 成功，-1 失败
 */
int CameraGetInfo(CameraDevice *dev, CameraInfo *info);

#endif // CAMERA_DRIVER_H
