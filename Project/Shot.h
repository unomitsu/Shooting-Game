#pragma once

#include "Object.h"

class Shot : public Object {
	// int size;		// �摜�T�C�Y
	bool image;			// �ǂ���̉摜���Atrue���ԁAfalse����
	static int image1;	// �摜�n���h��1
	static int image2;	// �摜�n���h��2

	void SetImage();	// �摜�֘A�̐ݒ�

public:
	// double x, y;
	// int hit_size;	// �����蔻��̃T�C�Y
	// bool flag;		// �L���t���O
	double xv, yv;		// ������

	Shot();
	void Update();					// �X�V
	void Draw();					// �`��
	void CollisionResult();			// �����蔻���̏���

	void Shoot(double nx, double ny, double nxv, double nvy, bool fimg);	// ���W�A���x�A�摜���w�肵���˂���
};