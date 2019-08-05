#include "DxLib.h"
#include "Shot.h"
#include "Info.h"

int Shot::image1 = -1;
int Shot::image2 = -1;

Shot::Shot() {
	x = y = 0.0;
	xv = yv = 0.0;
	flag = true;
	image = false;
	SetImage();
}

void Shot::Update() {
	if (flag) {
		x += xv;
		y += yv;

		// ��ʊO�ɏo���ꍇ�A�����ɂ���
		if (x < 0 || GetWidth() < x || y < 0 || GetHeight() < y) {
			flag = false;
		}
	}
}

void Shot::Draw() {
	if (flag) {
		if (image) {
			DrawGraph((int)(x - size / 2), (int)(y - size / 2), image1, TRUE);
		}
		else {
			DrawGraph((int)(x - size / 2), (int)(y - size / 2), image2, TRUE);
		}
	}
}

// �����蔻���̏���
void Shot::CollisionResult() {
	flag = false;
}

void Shot::SetImage() {
	size = 16;
	hit_size = 8;
	if (image1 == -1) {
		image1 = LoadGraph("./images/shot1.png");
	}
	if (image2 == -1) {
		image2 = LoadGraph("./images/shot2.png");
	}
}

// ���W�A���x�A�摜���w�肵���˂���
void Shot::Shoot(double nx, double ny, double nxv, double nyv, bool fimg) {
	x = nx;
	y = ny;
	xv = nxv;
	yv = nyv;
	image = fimg;
	flag = true;
}