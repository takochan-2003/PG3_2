#include "Enemy.h"
#include"stdio.h"

void Enemy::Initialize()
{
    timer = 0;
}

void Enemy::Update()
{
    timer++;
    //2-7の実践
    (this->*enemyMove[static_cast<size_t>(phase_)])(); // shotを呼び出す
}

void Enemy::Draw()
{

}

void Enemy::Approach()
{

   
    if (timer >= 1) {
        printf("APPROACH\n");
        phase_ = Phase::Shot;
    }

}

void Enemy::Shot()
{
   
    if (timer >= 2) {
        printf("SHOT\n");
        phase_ = Phase::Run;
    }
}

void Enemy::Run()
{
    if (timer >= 3) {
        printf("RUN");
    }
}

//フェーズの関数テーブル
void (Enemy::* Enemy::enemyMove[])() = {
    &Enemy::Approach,//接近
    &Enemy::Shot, // 射撃
    &Enemy::Run   // 離脱
};