#pragma once
#include "Object.h"

// �G�l�~�[�N���X
class Enemy : public Object {
private:
	// int size;		// �摜�T�C�Y
	static int image;	// �摜�n���h��

	void SetImage();	// �摜�֘A�̐ݒ�

public:
	// double x, y;		// x���W�Ay���W
	// int hit_size;	// �����蔻��̃T�C�Y
	// bool flag;		// �L���t���O
	double xv, yv;		// x�����̑����ʁAy�����̑�����
	int hp_now, hp_max;	// �̗�(���ݒl�A�ő�l)

	Enemy();
	void Update();	// �X�V
	void Draw();	// �`��
	void CollisionResult();		// �����蔻���̏���
};