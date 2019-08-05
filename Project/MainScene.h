#pragma once

#include "Player.h"
#include "Enemy.h"
#include "Shot.h"
#include <vector>

// �X�e�[�W�V�[���N���X
class MainScene {
private:
	Player *player;
	Enemy *enemy;

	int enemy_span;					// �e�̔��ˊԊu
	double enemy_shot_base;			// ���ˊp�x
	std::vector<Shot> enemy_shot;	// �G�@�̃V���b�g�z��

public:
	MainScene();
	int Update();	// �X�V
	void Draw();	// �`��

	void StageInitialize();			// �p�����[�^�̏�����
	void StageUpdate();				// �G�@�̃V���b�g�̔��˂���������
};

