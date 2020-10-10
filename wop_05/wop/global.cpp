#include "global.h"
#include"global.h"
#include <QtMultimedia/QMediaPlayer>
global::global()
{

}
 int e_c_damage=999;//敌机碰撞伤害
 int e_b_damage=2;//敌机子弹伤害
 double mydamage=1;//我的子弹伤害
 int mydamage_t=1;

 int normal_n=0;
 int charge_n=0;
 int float_n=0;
 int big_n=0;
 int boss_n=0;

 int my_hp=20;
 long long int score=0;
 int gold=0;

 int rank=1;
 int hp_k=1;

 QMediaPlayer music;
 QMediaPlayer music_shoot;
 QMediaPlayer music_chijinbi;
 QMediaPlayer music_up;

 bool is_end_show=0;
 bool is_playing=0;
