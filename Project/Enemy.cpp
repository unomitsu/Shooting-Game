#include "DxLib.h"
#include "Enemy.h"
#include "Info.h"

int Enemy::image;

Enemy::Enemy() {
	x = GetWidth() / 2;		// x���W�̏�����
	y = 50.0;				// y���W�̏�����
	xv = yv = 0.0;			// ������
	hp_now = hp_max = 100;	// �̗�
	flag = true;			// �L���t���O�𗧂Ă�
	this->SetImage();		// �摜�֘A�̐ݒ�
}

void Enemy::Update() {
	x += xv;
	y += yv;
}

void Enemy::Draw() {
	// �G�l�~�[�̉摜�̕`��
	DrawGraph((int)(x - size / 2), (int)(y - size / 2), image, TRUE);
}
// �����蔻���̏���
void Enemy::CollisionResult() {
	if (hp_now-- < 0) {
		flag = false;
	}
}

// �摜�֘A�̐ݒ�
void Enemy::SetImage() {
	size = 64;
	hit_size = 32;
	image = LoadGraph("./images/enemy.png");
}