#include "DxLib.h"
#include "MainScene.h"
#include "Info.h"

#define _USE_MATH_DEFINES
#include <math.h>

MainScene::MainScene() {
	SetBackgroundColor(100, 100, 100);	// �w�i���D�F�ɂ��܂�
	InfoInitialize();		// �E�B���h�E�T�C�Y�Ȃǂ̏�����
	player = new Player();		// �v���C���[�̏�����
	enemy = new Enemy();		// �G�l�~�[�̏�����
	StageInitialize();
}

int MainScene::Update() {
	InfoUpdate();			// �e�f�[�^�̍X�V
	player->Update();		// �v���C���[�̑���
	enemy->Update();		// �G�l�~�[�̍X�V

	// �V���b�g�̍X�V
	for (auto itr = enemy_shot.begin(); itr != enemy_shot.end();) {
		// �����ȗv�f���폜
		if (!(*itr).flag) {
			itr = enemy_shot.erase(itr);
		}
		// �L���ȗv�f�̍X�V
		else {
			(*itr).Update();
			itr++;
		}
	}

	StageUpdate();	// �X�e�[�W�̍X�V

	// �����蔻��
	// �v���C���[�V���b�g�ƃG�l�~�[
	for (int i = 0; i < player->shot_max; i++) {
		Collision(static_cast<Object*>(&player->shot[i]), static_cast<Object*>(enemy));
	}
	// �v���C���[�ƃG�l�~�[�V���b�g
	for (auto itr = enemy_shot.begin(); itr != enemy_shot.end(); itr++) {
		Collision(static_cast<Object*>(player), static_cast<Object*>(&(*itr)));
	}

	// �I������
	if (player->hp_now <= 0) { return 3; }
	if (enemy->hp_now <= 0) { return 2; }
	return 0;
}

void MainScene::Draw() {
	player->Draw();		// �v���C���[�̕`��
	enemy->Draw();		// �G�l�~�[�̕`��

	// �V���b�g�̍X�V
	for (auto itr = enemy_shot.begin(); itr != enemy_shot.end(); ++itr) {
		(*itr).Draw();
	}

	DrawFormatString(GetWidth()/2 - 40, 0, GetColor(255, 255, 255), "Time : %d", GetStageTime());	// �o�ߎ��Ԃ̕`��
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Player : %d", player->hp_now);					// �v���C���[HP
	DrawFormatString(GetWidth() - 120, 0, GetColor(255, 255, 255), "Enemy : %d", enemy->hp_now);	// �G�l�~�[HP
	DrawFormatString(200, 200, GetColor(255, 255, 255), "shotnum : %d", enemy_shot.size());	// �G�l�~�[HP
}

// 
void MainScene::StageInitialize() {
	enemy_span = 0;
	enemy_shot_base = 0;
}

void MainScene::StageUpdate() {
	// �̗͂������ȏ�̎�
	if (enemy->hp_now > enemy->hp_max / 2) {
		if (enemy_span++ >= 50) {
			double shot_v = 2.0;
			int shot_num = 36;

			for (int i = 0; i < shot_num; i++) {
				double angle = enemy_shot_base + M_PI / 18 * i;

				enemy_shot.push_back(Shot());
				enemy_shot.back().Shoot(
					enemy->x, enemy->y, shot_v * cos(angle), shot_v * sin(angle), true
				);
			}
			enemy_shot_base += 0.1;
			enemy_span = 0;
		}
	}
	// �̗͂������ȉ��̎�
	else {
		double shot_v = 1.0 + GetRand(40) / 10.0;
		int shot_num = 2;

		for (int i = 0; i < shot_num; i++) {
			double angle = M_PI * (GetRand(3600) / 10.0) / 180;

			enemy_shot.push_back(Shot());
			enemy_shot.back().Shoot(
				enemy->x, enemy->y, shot_v * cos(angle), shot_v * sin(angle), true
			);
		}
	}
}
