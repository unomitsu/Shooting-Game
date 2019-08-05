#pragma once
#include "Object.h"
#include "Shot.h"

// �v���C���[�N���X
class Player : public Object {
private:
	// int size;			// �摜�T�C�Y
	static int image;		// �摜�n���h��

	int shot_num;			// �V���b�g ���݂̔z��̓Y��
	int shot_span;			// �V���b�g ���ˊԊu

	void SetImage();	// �摜�֘A�̐ݒ�
	void SetShot();		// �V���b�g�֘A�̐ݒ�
	void Move();		// �v���C���[����
	void ShotFire();	// �v���C���[�V���b�g����

public:
	// double x, y;
	// int hit_size;		// �����蔻��̃T�C�Y
	// bool flag;			// �L���t���O
	double v;			// �ړ����x
	int hp_now, hp_max;	// �̗�(���ݒl�A�ő�l)

	static const int shot_max = 20;	// �V���b�g�z��̗v�f��
	Shot shot[shot_max];	// �V���b�g�z��

	Player();
	void Update();		// �X�V
	void Draw();		// �`��
	void CollisionResult();		// �����蔻���̏���
};
