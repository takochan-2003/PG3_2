#pragma once

class Enemy {
public:

	void Initialize();

	void Update();

	void Draw();

private:
	void Approach();
	void Shot();
	void Run();

	static void (Enemy::* enemyMove[])(); // メンバ関数ポインタ

	enum class Phase {
		Approach,
		Shot,
		Run
	};

	Phase phase_ = Phase::Approach;

	int timer = 0;

};