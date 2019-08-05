#pragma once

#include "Object.h"
#include "Player.h"
#include "Enemy.h"

void InfoInitialize();			// �e�f�[�^�̏�����
void InfoUpdate();				// �e�f�[�^�̍X�V

int GetWidth();					// �E�B���h�E�̉����𓾂�
int GetHeight();				// �E�B���h�E�̏c���𓾂�
int GetStageTime();				// �X�e�[�W���J�n����Ă���̌o�ߎ��Ԃ𓾂�

void KeyUpdate();				// �S�L�[�̏�Ԃ��X�V����
bool GetKey(int key_input);		// �w�肵���L�[�̏�Ԃ��擾����

void Collision(Object *obj1, Object *obj2);		// 2�I�u�W�F�N�g�̂����蔻��

int GetGameScene();			// �Q�[���V�[���̎擾
void SetGameScene(int val);		// �Q�[���V�[���̐ݒ�
