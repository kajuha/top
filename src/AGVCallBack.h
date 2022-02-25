#pragma once

#define TICK_LOG    0

#include <mecanum/WrapTwist.h>
extern mecanum::WrapTwist rcpl_cmd_vel_;
extern unsigned int rcpl_cmd_vel_flag;
void rcplCmdvelCallBack(const mecanum::WrapTwist rcpl_cmd_vel);