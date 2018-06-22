#ifndef KOYO_SYSTEM_HEADER_
#define KOYO_SYSTEM_HEADER_

/* 全局配置宏定义 */

/* 1. 系统参数 */
#define MAX_TASK_COUNT    32
#define TOOLS_PER_TASK    16
#define IMAGE_WIDTH       640
#define IMAGE_HEIGHT      480
#define HIST_IMAGE_COUNT  100
#define MIN_SCORE         0
#define MAX_SCORE         100
#define SENSOR_TCP_PORT   1234
#define SENSOR_UDP_PORT   ((unsigned short)45454)
#define SENSOR_TYPE       "VSensor_1.0"
#define DEFAULT_IPADDR    "192.168.1.10"
#define PARAM_TYPE_COUNT  32

/* 2. 进程ID及UNIX域套接字路径 */
#define MGRCENTER         0x01
#define IMAGECAPTURE      0x02
#define IMAGEPROCESS      0x04
#define PARAMCENTER       0x08
#define IOCENTER          0x10
#define UPGRADE          0x20

#define UNIX_MGRCENTER    "/var/unix_socket_mgrcenter"
#define UNIX_IMAGECAPTURE "/var/unix_socket_imagecapture"
#define UNIX_IMAGEPROCESS "/var/unix_socket_imageprocess"
#define UNIX_PARAMCENTER  "/var/unix_socket_paramcenter"
#define UNIX_IOCENTER     "/var/unix_socket_iocenter"
#define UNIX_UPGRADE      "/var/unix_socket_upgrade"



#endif
