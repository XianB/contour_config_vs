#ifndef KOYO_PARAMETER_HEADER_
#define KOYO_PARAMETER_HEADER_
//#include <QMetaType>
#include "koyo_system.h"
#include "koyo_types.h"

#define SYSTEMPARAM          0x00
#define CAMERAPARAM          0x01
#define OUTPUTPARAM          0x02
#define CONTOURPARAM         0x03
#define COLORPARAM           0x04
#define WIDTHPARAM           0x05
#define CIRCLEPARAM          0x06
#define MODELPARAM           0x07
#define STATUSPARAM          0x08
#define PICINFO              0X09
#define TASKLIST             0x0a

#define SEARCH_REGION_CIRCLE      0
#define SEARCH_REGION_RECT        1


#define CONTOUR_ACCURACY_LOW      0
#define CONTOUR_ACCURACY_MEDIUM   1
#define CONTOUR_ACCURACY_HIGH     2

typedef struct KOYO_PARAM_ROUTER_
{
    INT8   param_name[64];
    UINT8  param_id;
    UINT8  router;
} Koyo_Param_Router;


static const Koyo_Param_Router g_param_router[] = {
    {"SystemParam",  0x00, PARAMCENTER|MGRCENTER},
    {"CameraParam",  0x01, PARAMCENTER|IOCENTER|IMAGECAPTURE},
    {"OutputParam",  0x02, PARAMCENTER|IOCENTER|IMAGEPROCESS},
    {"ContourParam", 0x03, PARAMCENTER|IMAGEPROCESS},
    {"ColorParam",   0x04, PARAMCENTER|IMAGEPROCESS},
    {"WidthParam",   0x05, PARAMCENTER|IMAGEPROCESS},
    {"CircleParam",  0x06, PARAMCENTER|IMAGEPROCESS},
    {"ModelParam",   0x07, PARAMCENTER|IMAGEPROCESS},
    {"StatusParam",  0x08, PARAMCENTER|MGRCENTER},
    {"PicInfo",      0x09, 0x00},
};

typedef struct KOYO_SYSTEM_PARAMETER_
{
    UINT8  ip_addr[4];
    UINT8  subnet_mask[4];
    UINT8  gateway[4];
    UINT8  mac_addr[6];

    INT8   device_name[16];
    INT8   device_type[16];
    INT8   version[32];
    INT8   sequence[16];

    INT8   input_trigger;               //0x00为高电平，0x01为低电平，0x02为上升沿，0x03为下降沿。
    INT16  input_shieldtime;            //电平触发屏蔽时间。
    INT16  input_delaytime;             //输入延迟时间
    INT8   output_trigger;              //0x00为低电平输出，0x01为高电平输出
    INT8   output_mode;                 //0x00为电平输出，0x01为沿输出
    INT16  output_keeptime;             //输出保持时间，单位是ms
    INT16  output_delaytime;            //输出延时时间，（从收到结果到触发输出）,单位是ms
    INT32  rs232_bitrate;               //0x00~0x?? 波特率50~？
    INT16  rs232_port;                  //0x00~0x08 端口1~9
    INT8   rs232_databit;               //0x00表示5位，0x01表示7位，0x02表示8位
    INT8   check_bit;                   //0x00偶校验 ,0x01奇校验
    INT8   stop_bit;                    //0x00表示1位，0x01表示1.5位，0x02表示2位
} Koyo_System_Parameter;

typedef struct KOYO_CAMERA_PARAMETER_
{
    INT32  trigger_mode;
    INT32  trigger_time;

    /* 手动调节3A参数值 */
    INT32 manual_exptime;
    INT32 manual_gain;  		//曝光增益
    INT16 manual_rgain;		//R通道增益
    INT16 manual_focus;

    /* 上报参数或参数中心下发参数 */
    UINT32  exposure_time;      //曝光时间
    UINT32  a_gain_value;       //模拟增益
    UINT32  d_gain_value;       //数字增益
    UINT32  isp_gain_value;     //isp增益

    UINT32  focus_value;        //焦点

    UINT16  r_gain; 	 		//R通道增益
    UINT16  gr_gain; 	 	    //Gr通道增益
    UINT16  gb_gain; 	 	    //Gb通道增益
    UINT16  b_gain; 	 		//B通道增益
    UINT16	saturation;			//饱和度
    UINT16	CCM[9];				//颜色校正矩阵


    UINT8  vertical_flip;
    UINT8  color_filter;
} Koyo_Camera_Parameter;

#if 0
typedef struct KOYO_TOOLSLOGIC_
{
    UINT8 tools_state[16];  //16个工具使用：1,不使用：0,反转：2
    UINT8 tools_logic;		   //工具间逻辑
}Koyo_Toolslogic;
#endif

typedef struct KOYO_OUTPUT_PARAMETER_
{
    UINT16 output_line; //GPIO/RS232
    UINT16 output_logic;
    UINT8  output_tool[16];
    UINT8  task_id;		//0~31
    UINT16 reserved;
} Koyo_Output_Parameter;

typedef struct ORI_PIC_
{
    UINT32 visize[2];
    UINT32 stride[2];
    UINT32 width;
    UINT32 height;
    INT8 payload[0];
}Ori_Pic;


typedef struct KOYO_TASK_MODEL_PARAMETER_
{
    INT8 model_path[128];
    INT8 task_name[32];
    INT32 jpegsize;					//jpeg图片大小
    UINT32 visize[2];
    UINT32 stride[2];
    UINT32 width;
    UINT32 height;
    INT8   result_payload[0];		//Jpeg和原始YUV图片
}Koyo_Task_Model_Parameter;

typedef struct KOYO_TOOL_CONTOUR_PARAMETER_
{
    UINT16 detect_region_type;   //检测区域形状
    INT8   tool_name[32];        //工具名称

    /* 矩形检测框参数 */
    UINT16 detect_rect_x0;        //相对左上角圆点坐标左上点横坐标
    UINT16 detect_rect_y0;        //相对左上角圆点坐标左上点纵坐标
    UINT16 detect_rect_x1;        //相对左上角圆点坐标左下点横坐标
    UINT16 detect_rect_y1;        //相对左上角圆点坐标左下点纵坐标
    UINT16 detect_rect_x2;        //相对左上角圆点坐标右下点横坐标
    UINT16 detect_rect_y2;        //相对左上角圆点坐标右下点纵坐标
    UINT16 detect_rect_x3;        //相对左上角圆点坐标右上点横坐标
    UINT16 detect_rect_y3;        //相对左上角圆点坐标右上点纵坐标

    /* 检测圆参数 */
    UINT16 detect_circ_x;        //检测圆心横坐标
    UINT16 detect_circ_y;        //检测圆心纵坐标
    UINT16 detect_circ_radius;   //检测圆半径

    /* 外接矩形区域参数 */
    UINT16 ext_rect_x;	         //检测外接矩形起始点横坐标
    UINT16 ext_rect_y;           //检测外接矩形起始点纵坐标
    UINT16 ext_rect_width;       //检测外接矩形宽度
    UINT16 ext_rect_height;      //检测外接矩形高度

    /* 搜索区域参数 */
    UINT16 search_rect_x;        //搜索区域起始点横坐标
    UINT16 search_rect_y;        //搜索区域起始点纵坐标
    UINT16 search_rect_width;    //搜索区域宽度
    UINT16 search_rect_height;   //搜索区域高度

    UINT8  sensitivity;          //搜索灵敏度
    UINT8  algo_strategy;
    UINT16 angle_range;          //搜索角度范围

    UINT16 top_threshold;        //处理结果阈值上限
    UINT16 bot_threshold;        //处理结果阈值下限

    UINT32 bitmap_total_size;          //位图总大小,单位是bit
    UINT32 template_bitmap_size;   //工具模板位图的大小
 //   UINT32 reserved;//用于结构体内数据的对其操作
    INT8   bitmap_path[128];     //位图路径
    UINT8  bitmaps[0];           //检测区域外接矩形位图,
} Koyo_Tool_Contour_Parameter;
//注册Koyo_Tool_Contour_Parameter可以存储在信号发送时的队列中
//Q_DECLARE_METATYPE(Koyo_Tool_Contour_Parameter)
typedef struct KOYO_TOOL_COLOR_PARAMETER_
{
    UINT16 search_region_type;    //搜索区域形状
    INT8   tool_name[32];         //工具名称

    /* 矩形搜索区域参数 */
    UINT16 search_rect_x0;        //搜索区域左上点横坐标
    UINT16 search_rect_y0;        //搜索区域左上点纵坐标
    UINT16 search_rect_x1;        //搜索区域左下点横坐标
    UINT16 search_rect_y1;        //搜索区域左下点纵坐标
    UINT16 search_rect_x2;        //搜索区域右下点横坐标
    UINT16 search_rect_y2;        //搜索区域右下点纵坐标
    UINT16 search_rect_x3;        //搜索区域右上点横坐标
    UINT16 search_rect_y3;        //搜索区域右上点纵坐标
    UINT16 search_rect_w;        //搜索区域宽
    UINT16 search_rect_h;        //搜索区域高

    /* 圆形搜索区域参数 */
    UINT16 search_circ_x;        //搜索圆心横坐标
    UINT16 search_circ_y;        //搜索圆心纵坐标
    UINT16 search_circ_radius;   //搜索圆半径

    /* 搜索区域外接矩形参数 */
    UINT16 ext_rect_x;	         //搜索区域外接矩形起始点横坐标
    UINT16 ext_rect_y;           //搜索区域外接矩形起始点纵坐标
    UINT16 ext_rect_width;       //搜索区域外接矩形宽度
    UINT16 ext_rect_height;      //搜索区域外接矩形高度

    UINT16 color_x;              //检测颜色坐标的横坐标
    UINT16 color_y;              //检测颜色坐标的纵坐标
    UINT16 color_range;          //检测颜色的上下取值范围

    INT32  pix_count;            //像素个数

    UINT16  hsv_min[3];           //hsv下限
    UINT16  hsv_max[3];           //hsv上限

    UINT16 top_threshold;        //处理结果阈值上限
    UINT16 bot_threshold;        //处理结果阈值下限
} Koyo_Tool_Color_Parameter;

typedef struct KOYO_TOOL_WIDTH_PARAMETER_
{
    INT8   tool_name[32];         //工具名称

    UINT16 rect_x;                //目标矩形中心坐标
    UINT16 rect_y;
    UINT16 rect_width;
    UINT16 rect_height;
    INT32  angle;                 //旋转角度（顺时针为正，水平方向为0度）

    UINT16 detect_width;
    UINT8  sensitivity;
    UINT8  detect_direct;
    UINT16 detect_left;
    UINT16 detect_right;
    UINT16  reserved;

    UINT16 top_threshold;
    UINT16 bot_threshold;
} Koyo_Tool_Width_Parameter;


typedef struct KOYO_TOOL_CIRCLE_PARAMETER_
{
    INT8   tool_name[32];         //工具名称

    UINT16 circle_x;
    UINT16 circle_y;
    UINT16 circle_r;
    UINT16 detect_r;
    UINT8  sensitivity;
    UINT8  detect_method;

    UINT16 top_threshold;
    UINT16 bot_threshold;
} Koyo_Tool_Circle_Parameter;


/* 统计结果 */
typedef struct _STATISTICS_RESULT
{
    UINT32 total_count;           //处理总数
    UINT32 good_count;            //OK总数
    UINT32 bad_count;             //NG总数
    UINT16 max_time;              //处理一帧图片最大时间 单位：ms
    UINT16 min_time;              //处理一帧图片最小时间 单位：ms
    UINT16 ave_time;              //处理一帧图片平均时间 单位：ms
    UINT16 reserved;              //占位
}Statistics_result;


/* 轮廓工具处理结果 */
typedef struct _CONTOUR_RESULT
{

    UINT16 detect_region_type;    //检测框形状

    /* 矩形检测框参数 */
    UINT16 detect_rect_x0;        //检测矩形框左上点横坐标（相对全局）
    UINT16 detect_rect_y0;        //检测矩形框左上点纵坐标（相对全局）
    UINT16 detect_rect_x1;        //检测矩形框左下点横坐标（相对全局）
    UINT16 detect_rect_y1;        //检测矩形框左下点纵坐标（相对全局）
    UINT16 detect_rect_x2;        //检测矩形框右下点横坐标（相对全局）
    UINT16 detect_rect_y2;        //检测矩形框右下点纵坐标（相对全局）
    UINT16 detect_rect_x3;        //检测矩形框右上点横坐标（相对全局）
    UINT16 detect_rect_y3;        //检测矩形框右上点纵坐标（相对全局）

    /* 检测圆参数 */
    UINT16 detect_circ_x;        //检测圆心横坐标
    UINT16 detect_circ_y;        //检测圆心纵坐标
    UINT16 detect_circ_radius;   //检测圆半径

    /* 模板外接矩形区域参数 */
    UINT16 ext_rect_x;	         //模板外接矩形起始点横坐标
    UINT16 ext_rect_y;           //模板外接矩形起始点纵坐标
    UINT16 ext_rect_width;       //模板外接矩形宽度
    UINT16 ext_rect_height;      //模板外接矩形高度

    /* 搜索区域参数 */
    UINT16 search_rect_x;        //搜索区域起始点横坐标
    UINT16 search_rect_y;        //搜索区域起始点纵坐标
    UINT16 search_rect_width;    //搜索区域宽度
    UINT16 search_rect_height;   //搜索区域高度

    UINT16 bitmap_size;           //实际位图大小(模板外接矩形位图,不足8的倍数补足8位)单位是bit
}Contour_Result;

/* 颜色面积工具处理结果 */
typedef struct _COLOR_RESULT
{

    UINT16 search_region_type;   //搜索区域形状

    /* 矩形搜索区域参数 */
    UINT16 search_rect_x0;        //搜索区域左上点横坐标
    UINT16 search_rect_y0;        //搜索区域左上点纵坐标
    UINT16 search_rect_x1;        //搜索区域左下点横坐标
    UINT16 search_rect_y1;        //搜索区域左下点纵坐标
    UINT16 search_rect_x2;        //搜索区域右下点横坐标
    UINT16 search_rect_y2;        //搜索区域右下点纵坐标
    UINT16 search_rect_x3;        //搜索区域右上点横坐标
    UINT16 search_rect_y3;        //搜索区域右上点纵坐标

    /* 圆形搜索区域参数 */
    UINT16 search_circ_x;        //搜索圆心横坐标
    UINT16 search_circ_y;        //搜索圆心纵坐标
    UINT16 search_circ_radius;   //搜索圆半径

    /* 搜索区域外接矩形参数 */
    UINT16 ext_rect_x;	         //搜索区域外接矩形起始点横坐标
    UINT16 ext_rect_y;           //搜索区域外接矩形起始点纵坐标
    UINT16 ext_rect_width;       //搜索区域外接矩形宽度
    UINT16 ext_rect_height;      //搜索区域外接矩形高度

    UINT16 min_hsv[3];           //提取颜色hsv下阈值
    UINT16 max_hsv[3];           //提取颜色hsv上阈值
    UINT32 pix_count;            //颜色像素数
    UINT16 bitmap_size;          //实际位图大小(搜索区域外接矩形位图,不足8的倍数补足8位),单位是bit

    UINT8 tool_IsOk;
    UINT8 tool_value;
}Color_Result;

/* 宽度工具处理结果 */
typedef struct _WIDTH_RESULT
{
    UINT16 x;                    //用户选择区域中心x坐标
    UINT16 y;                    //用户选择区域中心y坐标
    UINT16 height;               //用户选择区域高度
    UINT16 width;                //用户选择区域宽度
    INT32  angle;                //用户选择旋转角度
    INT16  detect_width;
    UINT16 line_amount;          //线的数量
    UINT8  direct;               //in->out?(1) or out->in(0)
    UINT16 detect_left;
    UINT16 detect_right;
    UINT16 width_edge[2];        //两条边的横坐标
    UINT8 value;
    INT32 result_len;
    UINT16 reserved;
    UINT8 sensitivity;
    UINT16 bot_thershold;
    UINT16 top_thershold;
    UINT8 if_detetct_width_success;	//是否检测到合法的宽度
    UINT8 if_tool_success;			//参数宽度与检测到的宽度是否在参数灵敏度规定的范围内。100*(1-abs(dp-dd)/dp) > sensitivity。
    // dp为参数宽度，dd为检测到的宽度。
    //UINT8 result_body[0];       	//结果数组，包含width*sizeof(UINT32)的分数、line_amount*sizeof(UINT16)的检测到的边的横坐标,
}Width_Result;

/* 直径工具处理结果 */
typedef struct _CIRCLE_
{
    INT16 center_x;
    INT16 center_y;
    INT16 radius;
    INT16 reserved;
}Circle_;

/*直径工具预处理结构体*/
typedef struct _CIRCLE_RESULT
{
    UINT16  user_x;                      //用户选择区域圆心x坐标
    UINT16  user_y;                      //用户选择区域圆心y坐标
    UINT16  user_r;                      //用户选择区域圆半径
    UINT16  circle_amount;               //检测出来的圆的数量
    Circle_ circle[10];                  //一张图片最多只检测10个圆。
}Circle_Result;

/* 每个处理结果头部 */
typedef struct RESULT_HEAD_
{
    INT32  tool_id;                              //ID类型待确认。
    INT8   tool_name[32];                        //工具名称
    INT16  tool_value;                           //工具结果评分
    INT16  tool_IsOk;                            //工具结果是否OK
    INT32  tool_type;                            //工具类型
    UINT16 top_threshold;						//阈值上限
    UINT16 bot_threshold;						//阈值下限
    UINT16 score_hist[201];						//评分直方图

    union
    {
        Contour_Result       contour_result;    //轮廓工具
        Color_Result         color_result;      //颜色面积工具
        Width_Result         width_result;      //宽度工具
        Circle_Result        circle_result;     //圆工具
    };

}Result_Head;

/* 共享缓存区一块的头部信息 */
typedef struct PIC_INFO_
{
    Statistics_result   statistics_result;    //统计结果
    INT32              	resultIsOK;           //检测结果
    INT32               bufferindex;          //共享缓存区的索引
    INT32              	jpegsize;             //图片大小
    UINT32		        timecost;	          //耗时
    INT32 				result_amount;        //结果总数
    Result_Head        	result[16];           //各个工具结果数据
    UINT32				result_payloadsize;   //jpeg图片数据和位图数据总大小
    INT8               	result_payload[0];    //jpeg图片数据和位图数据
}Pic_Info;

typedef struct BMP_MODEL_
{
    UINT32 bmp_size;          //bmp模板图片大小
    UINT8  task_id;			  //模板图片对应任务id
    INT8   bmp_payload[0];	  //bmp图片起始地址
}Bmp_Model;

typedef struct KOYO_STATUS_PARAMETER{
    INT32 cur_task_id;
    INT16 cur_sys_status;
    INT16 has_tool;
}Koyo_Status_Parameter;

typedef struct KOYO_TASK_LIST{
    INT8  task_id[32];          // 1表示当前任务为有效任务，0表示无效任务。
    INT8  task_name[32][32];
}Koyo_Task_List;

typedef struct KOYO_PARAM_HEAD_
{
    UINT8  task_id;		//0~31
    UINT8  tool_id;		//0~15
    UINT16 tool_type;	//工具类型
    UINT32 parambody_len;
    UINT8  parambody[0];	//具体参数
} Koyo_Param_Head;

typedef struct KOYO_ALL_PARAMETERS_
{
    Koyo_Param_Head *system_param;
    Koyo_Param_Head *status_param;
    Koyo_Param_Head *camera_param[MAX_TASK_COUNT];
    Koyo_Param_Head *output_param[MAX_TASK_COUNT];
    Koyo_Param_Head *tool_param[MAX_TASK_COUNT][TOOLS_PER_TASK];
    Koyo_Param_Head *task_model_param[MAX_TASK_COUNT];
} Koyo_All_Parameters;

#endif
