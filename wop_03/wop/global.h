#ifndef GLOBAL_H
#define GLOBAL_H


class global
{
public:
    global();
};
extern int e_c_damege;//敌机碰撞伤害
extern int e_b_damage;//敌机子弹伤害
extern int  mydamge;//我的子弹伤害

extern int normal_n;//普通敌机数------1
extern int charge_n;//自杀式敌机数------2
extern int float_n;//悬停敌机数-------3
extern int big_n;//厚血量敌机数-------4
extern int boss_n;//boss数-----------5

extern long long int score;

#endif // GLOBAL_H
