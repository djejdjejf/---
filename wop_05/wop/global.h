#ifndef GLOBAL_H
#define GLOBAL_H

#include <QtMultimedia/QMediaPlayer>

class global
{
public:
    global();
};
extern int e_c_damage;//敌机碰撞伤害
extern int e_b_damage;//敌机子弹伤害
extern double mydamage;//我的子弹伤害
extern int mydamage_t;//我的总伤害

extern int normal_n;//普通敌机数------1
extern int charge_n;//自杀式敌机数------2
extern int float_n;//悬停敌机数-------3
extern int big_n;//厚血量敌机数-------4
extern int boss_n;//boss数-----------5

extern int my_hp;
extern long long int score;
extern int gold;

extern int rank;
extern int hp_k;

extern QMediaPlayer music;
extern QMediaPlayer music_shoot;
extern QMediaPlayer music_chijinbi;
extern QMediaPlayer music_up;

extern bool is_end_show;
extern bool is_playing;

#endif // GLOBAL_H
