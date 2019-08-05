#include "DxLib.h"
#include "Player.h"
#include "Info.h"
#include <math.h>

int Player::image;

Player::Player() {
	x = y = 200.0;			// ���W�̏�����
	v = 4;					// ���x�̏�����
	flag = true;			// �L���t���O�𗧂Ă�
	hp_now = hp_max = 300000;	// �̗͂̏�����
	this->SetImage();		// �摜�֘A�̐ݒ�
	this->SetShot();		// �v���C���[�V���b�g�֘A�̐ݒ�
}

void Player::Update() {
	Move();			// �ړ��̍X�V
	this->ShotFire();		// �v���C���[�V���b�g�̔���

	for (int i = 0; i < shot_max; i++) {
		shot[i].Update();
	}
}

// �`��
void Player::Draw() {
	DrawGraph((int)(x - size / 2), (int)(y - size / 2), image, TRUE);		// �v���C���[�̉摜
	DrawCircle((int)x, (int)y, 8, GetColor(200, 100, 100), TRUE, 4);		// �����蔻��̑傫��

	for (int i = 0; i < shot_max; i++) {
		shot[i].Draw();
	}
}

// �����蔻���̏���
void Player::CollisionResult() {
	if (hp_now-- < 0) {
		flag = false;
	}
}

// �摜�֘A�̐ݒ�
void Player::SetImage() {
	size = 64;
	hit_size = 8;
	image = LoadGraph("./images/player.png");
}
// �V���b�g�֘A�̐ݒ�
void Player::SetShot() {
	shot_num = 0;
	shot_span = 0;
	for (int i = 0; i < shot_max; i++) {
		shot[i] = Shot();
	}
}

// �v���C���[����
void Player::Move() {
	double nxv = 0, nyv = 0;	// �ړ��ʕێ��p

	// x�����̈ړ��ʂ̊m�F
	if (GetKey(KEY_INPUT_LEFT)) { nxv -= v; }
	if (GetKey(KEY_INPUT_RIGHT)) { nxv += v; }

	// y�����̈ړ��ʂ̊m�F
	if (GetKey(KEY_INPUT_UP)) { nyv -= v; }
	if (GetKey(KEY_INPUT_DOWN)) { nyv += v; }

	// ���V�t�g�������Ă���Ƃ�������
	if (GetKey(KEY_INPUT_LSHIFT)) {
		nxv /= 2; nyv /= 2;
	}
	// �΂ߕ����̒���
	if (nxv != 0 && nyv != 0) {
		nxv /= sqrt(2); nyv /= sqrt(2);
	}
	// �ړ��ʂ̉��Z
	x += nxv;
	y += nyv;

	// �ړ��͈͂̐����A�͈͊O�ɏo�����͔͈͓��ɖ߂�
	if (y < 0) { y = 0; }
	if (GetHeight() < y) { y = GetHeight(); }
	if (GetWidth() < x) { x = GetWidth(); }
	if (x < 0) { x = 0; }
}

// �V���b�g����
void Player::ShotFire() {
	if (GetKey(KEY_INPUT_Z)) {
		// ���ˊԊushot_span �� 4�ȏ�ɂȂ�����
		if (shot_span++ >= 4) {
			// �v���C���[�̈ʒu����e�𔭎˂���
			shot[shot_num++].Shoot(x, y, 0, -8, false);

			// ���݂̔z��̓Y��shot_num ���v�f��shot_max �ȏ�ɂȂ����� 0 �ɂ���
			if (shot_num >= shot_max) { shot_num = 0; }

			// ���ˊԊushot_span �̃��Z�b�g
			shot_span = 0;
		}
	}
}