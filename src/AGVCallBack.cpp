#include "AGVCallBack.h"

mecanum::WrapTwist rcpl_cmd_vel_;
unsigned int rcpl_cmd_vel_flag;
void rcplCmdvelCallBack(const mecanum::WrapTwist rcpl_cmd_vel) {
    rcpl_cmd_vel_ = rcpl_cmd_vel;

    rcpl_cmd_vel_flag = 1;
    # if 0
#define STEP_TIME 1
    static double time_cur = ros::Time::now().toSec();
    static double time_pre = time_cur;

    time_cur = ros::Time::now().toSec();
    if (time_cur - time_pre > STEP_TIME) {
        time_pre = time_cur;
    }
    #endif

    #if TICK_LOG
    static double time_cur = ros::Time::now().toSec();
    static double time_pre = time_cur;
    static uint32_t count = 0;

    time_cur = ros::Time::now().toSec();

    printf("%s count: %05d, time_diff(ms): %lf, ts: %lf\n", __FUNCTION__, count++, time_cur-time_pre, time_cur);
    time_pre = time_cur;
    #endif
}