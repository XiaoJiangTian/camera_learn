#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "snapdragon_camera.h"

int main(int argc, char *argv[])
{
    SnapdragonCameraConfig config = {
        .width = 640,
        .height = 480,
        .fps = 30,
        .exposure = 100,
        .gain = 50,
        .auto_exposure = false
    };

    SnapdragonCameraInfo info;
    uint8_t *buffer = NULL;
    size_t buffer_size;

    // 解析命令行参数
    if (argc > 1) {
        config.width = atoi(argv[1]);
    }
    if (argc > 2) {
        config.height = atoi(argv[2]);
    }
    if (argc > 3) {
        config.fps = atoi(argv[3]);
    }

    // 初始化相机
    printf("Initializing Snapdragon camera...\n");
    if (SnapdragonCameraInit(&config) < 0) {
        fprintf(stderr, "Failed to initialize camera\n");
        return EXIT_FAILURE;
    }

    // 获取相机信息
    if (SnapdragonCameraGetInfo(&g_snapdragon_camera, &info) < 0) {
        fprintf(stderr, "Failed to get camera info\n");
        SnapdragonCameraClose(&g_snapdragon_camera);
        return EXIT_FAILURE;
    }

    printf("Camera info:\n");
    printf("  Resolution: %dx%d\n", info.width, info.height);
    printf("  FPS: %d\n", info.fps);
    printf("  Exposure: %d\n", info.exposure);
    printf("  Gain: %d\n", info.gain);
    printf("  Auto exposure: %s\n", info.auto_exposure ? "on" : "off");

    // 计算缓冲区大小 (假设 YUV420 格式)
    buffer_size = info.width * info.height * 3 / 2;
    buffer = (uint8_t *)malloc(buffer_size);
    if (!buffer) {
        fprintf(stderr, "Failed to allocate buffer\n");
        SnapdragonCameraClose(&g_snapdragon_camera);
        return EXIT_FAILURE;
    }

    // 开始相机流
    if (SnapdragonCameraStart(&g_snapdragon_camera) < 0) {
        fprintf(stderr, "Failed to start camera stream\n");
        free(buffer);
        SnapdragonCameraClose(&g_snapdragon_camera);
        return EXIT_FAILURE;
    }

    // 捕获几帧图像
    for (int i = 0; i < 5; i++) {
        printf("Capturing frame %d...\n", i + 1);
        if (SnapdragonCameraCaptureFrame(&g_snapdragon_camera, buffer, buffer_size) < 0) {
            fprintf(stderr, "Failed to capture frame\n");
            break;
        }
        printf("Frame %d captured successfully\n", i + 1);
        // 简单延迟
        usleep(100000);
    }

    // 停止相机流
    if (SnapdragonCameraStop(&g_snapdragon_camera) < 0) {
        fprintf(stderr, "Failed to stop camera stream\n");
    }

    // 清理资源
    free(buffer);
    SnapdragonCameraClose(&g_snapdragon_camera);

    printf("Camera demo completed\n");
    //yes
    return EXIT_SUCCESS;
}
