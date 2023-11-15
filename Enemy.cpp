#include "Enemy.h"
#include"stdio.h"

void Enemy::Initialize()
{
    timer = 0;
}

void Enemy::Update()
{
    timer++;
    //2-7�̎��H
    (this->*enemyMove[static_cast<size_t>(phase_)])(); // shot���Ăяo��
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

//�t�F�[�Y�̊֐��e�[�u��
void (Enemy::* Enemy::enemyMove[])() = {
    &Enemy::Approach,//�ڋ�
    &Enemy::Shot, // �ˌ�
    &Enemy::Run   // ���E
};