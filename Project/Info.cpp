#include "DxLib.h"
#include "Info.h"
#include <math.h>

// Info
int g_Width, g_Height;	// �E�B���h�E�̉����Əc��
int g_StageTime;		// �X�e�[�W�V�[���ɕς���Ă���̌o�ߎ���

// Key
static const int KEY_NUM = 256;		// �L�[�z��̍ő�l
char g_Buf[KEY_NUM];				// �L�[�̏�Ԃ�ێ�����z��

int g_GameScene;					// �V�[���Ǘ��p

// �e�f�[�^�̏�����
void InfoInitialize() {
	GetScreenState(&g_Width, &g_Height, NULL);
	g_StageTime = 0;
	g_GameScene = 0;
}
// �e�f�[�^�̍X�V
void InfoUpdate() {
	g_StageTime++;
}

// �E�B���h�E�̉�����Ԃ�
int GetWidth() {
	return g_Width;
}
// �E�B���h�E�̏c����Ԃ�
int GetHeight() {
	return g_Height;
}
// �X�e�[�W���J�n����Ă���̌o�ߎ��Ԃ𓾂�
int GetStageTime() {
	return g_StageTime;
}

// �S�L�[�̏�Ԃ��X�V����
void KeyUpdate() {
	GetHitKeyStateAll(g_Buf);
}
// �w�肵���L�[�̏�Ԃ��擾����
bool GetKey(int key_code) {
	if (g_Buf[key_code]) { return true; }
	return false;
}

// 2�I�u�W�F�N�g�̂����蔻��
void Collision(Object *obj1, Object *obj2) {
	double dx = obj1->x - obj2->x;
	double dy = obj1->y - obj2->y;
	double ds = obj1->hit_size + obj2->hit_size;

	// �L���t���O�������Ă��邩�̊m�F
	if (!obj1->flag || !obj2->flag) {
		return;
	}

	// �O�����̒藝���g�p
	if (pow(dx, 2) + pow(dy, 2) <= pow(ds, 2)) {
		// �����蔻���̏���
		obj1->CollisionResult();
		obj2->CollisionResult();
	}
}

// �Q�[���V�[���̎擾
int GetGameScene() {
	return g_GameScene;
}
// �Q�[���V�[���̐ݒ�
void SetGameScene(int val) {
	g_GameScene = val;
}
